// #include <zz00_my_main_lang.hpp>
#include <main_header.hpp>


/* tokenize
    input: string, char
    token the line received from the parseline method with various checks and transformation
    output: boolean
*/
bool Lexer::tokenize(std::string &str, const char& delimiter)
{
    rm_parenthesis(str);
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter))
    {
        // quick patch: need to refactor
        if (token == S_CHARACTERS_COMMENT)
        {
            return true;
        }
        if (token.empty() || token == "\n" || token == "\r" || token == "\r\n")
        {
           continue;
        }
        token = trim(token);
        if (token == "")
        {
            continue;
        }
        if (token.find(S_ACC_QUIT) != std::string::npos)
        {
            generateStandaloneToken(token);
            return false;
        }
        // if (token.find(S_FILE_EXT) != std::string::npos)
        // {
            // TokeniseFile(token);
        // }
        // end of patch
        tokens.push_back(token);
        if (token == S_CHARACTERS_ENDINSTR)
        {
            return false; 
        }
    }
    return true;
}

/* tokenizeFile
    input: string, char
    Replace the std::cin stream by a filestream and execute parseline;
    output: boolean
*/
bool Lexer::tokeniseFile(const std::string& token)
{
    bool result = false;
    std::ifstream file(token);
    if (!file.is_open())
    {
        std::cerr << "INVALID FILE: " << token << std::endl;
        return false;
    }
    inputPtr = &file;
    result = parseLine();
    file.close();
    return result;
}

/*  generateStandaloneToken
    input: string
        generate a standalone tokens and instruction to bypass process
        use to generate a quit token that will handle ctrl+d or quit to quit the VM; 
    output: boolean
*/
void Lexer::generateStandaloneToken(const std::string& token)
{
    tokens.push_back(token);
    InstrPair pair;
    storeToken(token, S_CATEGORY_ACC , pair);
    tmp = pair.getPair();
    instructions.push_back(tmp);
}


/*  parseLine
    input: coming from stream
        - split incoming stream into lines to be processed and tokenize;
        - Used to generate a quit token that will handle ctrl+d or quit to quit the VM;
    output: exit_status from the Parser;
*/
int Lexer::parseLine()
{
    std::string line;
    bool loop = true;
    while (loop && std::getline(*inputPtr, line))
    {
        loop = tokenize(line, CHAR_SPACE);
        distributeTokens();
    }
    if (inputPtr == &std::cin && inputPtr->eof()) 
    {
        std::cout << "EOF (Ctrl+D) detected." << std::endl;
        generateStandaloneToken(S_CHARACTERS_ENDINSTR);
    }
    return Parser::validateInstructions(instructions);
}


int Lexer::parseCmd(std::string& cmd)
{
    tokenize(cmd, CHAR_SPACE);
    distributeTokens();
    return Parser::validateInstructions(instructions);
}




/*  createInstr_ACC
    input: string, empty pair instruction
        Create a type token
    output: nil;
*/
void Lexer::createInstr_ACC(const std::string& token, InstrPair& pair)
{
    
    if (token == S_ACC_CDUP)
    {
        pair.first(token);
        readyStatus = true;
    }
    else if (token == S_ACC_REIN)
    {
        pair.first(token);
        readyStatus = true;
    }
    else if (token == S_ACC_EXIT)
    {
        pair.first(token);
        readyStatus = true;
    }
    else
    {
        pair.first(token);
        readyStatus = false;
        acceptUserArg = true;
    }
}



/*  createInstr_TPC
    input: string, empty pair instruction
        Create a keyword token with optinonal arguments (limited to two)
    output: nil;
*/
void Lexer::createInstr_TPC(const std::string& token, InstrPair& pair)
{
    if (token == S_TPC_PORT)
    {
        pair.first(token);
        readyStatus = false;
        acceptUserArg = true;
    } 
    else
    {
        pair.first(token);
        readyStatus = true;
    }
}


/*  createInstr_FSC
    input: string, empty pair instruction
        Create a keyword token with optinonal arguments (limited to two)
    output: nil;
*/
void Lexer::createInstr_FSC(const std::string& token, InstrPair& pair)
{
    if (token == S_FCS_RETR)
    {
        pair.first(token);
        readyStatus = false;
        acceptUserArg = true;
    }
    else
    {
        pair.first(token);
        readyStatus = true;
    }
}


void Lexer::createDigitInstr(const std::string& token, InstrPair& pair)
{
    ValPair_t valuePair;
    valuePair.first = token;
    pair.second(valuePair);
    readyStatus = true;
}

void Lexer::storeUserArg(const std::string& token, InstrPair& pair)
{
    ValPair_t valuePair;
    valuePair.first = token;
    pair.second(valuePair);
    acceptUserArg = false;
    readyStatus = true;
}

 /*  doNothing
    input: nil
        Placeholder for characters tokens;
    output: nil;
*/
void Lexer::doNothing(const std::string& token, InstrPair& pair)
{
}

 /*  createPair
    input: string, string, instruction
        Find the matching category in the unordered_map and execute the corresponding function ptr;
    output: nil;
*/
void Lexer::createPair(const std::string& instructionType, const std::string& token, InstrPair& pair)
{
    if (funcPtrMap.find(instructionType) != funcPtrMap.end())
    {
        (this->*funcPtrMap[instructionType])(token, pair);
    } 
    else
    {
        throw LexerError("INVALID TOKEN CATEGORY\n");
    }
}

/*  createPair
    input: string, string, matching tokenSet
        look for the token in the matching category
    output: bool;
*/
bool Lexer::isValidToken(const std::string& token, const std::string& setName, const SetVariant_t& tokenSet)
{
    bool match = false;
    std::visit([&](const auto& set)
    {
        if (set.find(token) != set.end())
        {
            match = true;
        }
    }, tokenSet);

    if (setName == S_CATEGORY_DIGITS && match == false)
    {
        match = isValidNum(token);
    }
    return match;
}

bool Lexer::isValidString(const std::string& str)
{
    std::regex pattern(VALID_PATTERN);
    return std::regex_match(str, pattern);
}


/*  createPair
    input: string, string, empty instruction
        store the token in the right category and process the instruction;
    output: bool;
*/
void Lexer::storeToken(const std::string& token, const std::string& setName,  InstrPair& pair)
{
    std::shared_ptr<std::string> newToken = std::make_shared<std::string>(token.c_str());
    
    if (acceptUserArg == true)
    {
            storeUserArg(token.c_str(), pair);
    }
    else
    {
        auto it = categoryMap.find(setName);
        createPair(it->first, token.c_str(), pair);
        it->second.push_back(newToken);
        tokens.pop_back();
    }
}

    // for (const auto& token : tokens)
    // {
    // std::cout << "'" << token << "'" << std::endl;
    // }
    // std::cout << "Before popping: " << tokens.size() << std::endl;
    // std::cout << "After popping: " << tokens.size() << std::endl;


/*  distributeTokens
    input: nil
        validate tokens,
        create instruction
        store token for user diagnostic
        store instruction;
    output: mil;
*/
void Lexer::distributeTokens()
{
    InstrPair pair;
    bool match;
    int index = 0;
    for (const auto& token : tokens)
    {
        match = false;
        for (const auto& [setName, tokenSet] : tokenMap)
        {
            match = isValidToken(token, setName, tokenSet);
            if (acceptUserArg == true)
            {
                match = isValidString(token);
            }
            if (match)
            {
                storeToken(token, setName, pair);
                if (readyStatus == true)
                {
                    tmp = pair.getPair();
                    instructions.push_back(tmp);
                    readyStatus = false;
                }
                break;
            }
        }
    }
}

/*  distributeTokens
    input: nil
        clear all variables fomr object;
    output: mil;
*/

void Lexer::clear()
{
    tokens.clear();
    instructions.clear();
    AccessControlCommandsVec.clear();
    TransfertParameterCommandsVec.clear();
    FTPservicesCommandsVec.clear();
    charactersVec.clear();
    digitsVec.clear();
    tmp = TokPair_t();
    readyStatus = false; 
}


PairVec_t Lexer::getInstrVec() const
{
    return instructions;
}

void Lexer::printVec()
{
    std::cout << std::endl;
    std::cout << "--------Inspecting TOKENS on each CATEGORIES--------" << std::endl;
    // std::cout << S_CATEGORY_CHARACTERS << ":\t ";
    // for (size_t i = 0; i < charactersVec.size(); ++i)
    // {
    //     std::cout << *charactersVec[i] << "\t ";
    // }
    // std::cout << std::endl;

    // std::cout << S_CATEGORY_KEYWORDS << ":\t ";
    // for (size_t i = 0; i < keywordsVec.size(); ++i)
    // {
    //     std::cout << *keywordsVec[i] << "\t ";
    // }
    // std::cout << std::endl;

    // std::cout << S_CATEGORY_TYPES << ":\t\t ";
    // for (size_t i = 0; i < typesVec.size(); ++i)
    // {
    //     std::cout << *typesVec[i] << "\t ";
    // }
    // std::cout << std::endl;

    // std::cout << S_CATEGORY_DIGITS << ":\t\t ";
    // for (size_t i = 0; i < digitsVec.size(); ++i)
    // {
    //     std::cout << *digitsVec[i] << "\t ";
    // }
    std::cout << std::endl;
    std::cout << "-------------------End of inspection----------------" << std::endl;
    std::cout << std::endl;
}
