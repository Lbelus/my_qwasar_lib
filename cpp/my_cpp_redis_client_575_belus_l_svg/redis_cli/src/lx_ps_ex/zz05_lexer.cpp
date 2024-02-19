#include <zz00_my_main_lang.hpp>

namespace UsrIn
{
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
            if (token.find(S_COMMON_QUIT) != std::string::npos)
            {
                generateStandaloneToken(token, S_CATEGORY_COMMON);
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
    void Lexer::generateStandaloneToken(const std::string& token, const std::string& category)
    {
        tokens.push_back(token);
        InstrPair pair;
        storeToken(token, category , pair);
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
            std::cout << "EOF (Ctrl+D) instruction : QUIT" << std::endl;
            generateStandaloneToken(S_CHARACTERS_ENDINSTR, S_CATEGORY_CHARACTERS);
        }
        return Parser::validateInstructions(instructions);
    }


    int Lexer::parseCmd(std::string& cmd)
    {
        tokenize(cmd, CHAR_SPACE);
        distributeTokens();
        return Parser::validateInstructions(instructions);
    }

     /*  createPair
        input: string, string, instruction
            Find the matching category in the unordered_map and execute the corresponding function ptr;
        output: nil;
    */
    void Lexer::createPair(const std::string& instructionType, const std::string& token, InstrPair& pair)
    {
        std::cout << instructionType << std::endl;
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
            std::cout << setName << std::endl;
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

        charactersVec.clear();
        digitsVec.clear();
        commonVec.clear();

        TypeOneVec.clear();
        TypeTwoVec.clear();
        TypeThreeVec.clear();

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
        std::cout << "--------Inspecting TOKENS on each CATEGORIES--------\n" << std::endl;     


    for (const auto& pair : categoryMap)
    {
        std::cout << "Key: " << pair.first << ", Value: " << std::endl;
        for (const auto& strPtr : pair.second)
        {
            if (strPtr)
            {
                std::cout << *strPtr << " ";
            }
        }
        std::cout << std::endl;
    }
        std::cout << "\n-------------------End of inspection----------------\n" << std::endl;
    }

}
