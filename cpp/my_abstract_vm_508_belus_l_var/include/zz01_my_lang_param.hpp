#ifndef MY_LANG_PARAM_
#define MY_LANG_PARAM_

#include <zz00_my_main_lang.hpp>
/*
    BNF notation : 
        <program> ::= {<line>} [";;"]
        <line> ::= <instruction> "#" | <comment> "#" | "#"
        <instruction> ::= <keyword> [<value>]
        <keyword> ::= "push" | "pop" | "dump" | "assert" | "add" | "sub" | "div" | "mod" | "print" | "exit"
        <value> ::= <value_type> "(" <number> ")"
        <value_type> ::= "int8" | "int16" | "int32" | "float" | "double"
        <number> ::= {<digit>} ["." {<digit>}]
        <digit> ::= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
        <comment> ::= ";" {<any_character_except_newline_or_semicolon>} [";"]
*/
#define EXIT_INSTRUCTION        1

#define CHAR_SPACE              ' '
#define CHAR_OPARENTHESIS       '('
#define CHAR_CPARENTHESIS       ')'
#define CHAR_DECPOINT           '.'

#define S_FILE_EXT              ".avm"

#define S_CATEGORY_CHARACTERS   "characters"
#define S_CATEGORY_KEYWORDS     "keywords"
#define S_CATEGORY_TYPES        "types"
#define S_CATEGORY_DIGITS       "digits"

#define S_CHARACTERS_NEWLINE    "#"
#define S_CHARACTERS_COMMENT    ";"
#define S_CHARACTERS_DECPOINT   "."
#define S_CHARACTERS_ENDINSTR   ";;"

#define S_KEYWORD_PUSH          "push"
#define S_KEYWORD_POP           "pop"
#define S_KEYWORD_DUMP          "dump"
#define S_KEYWORD_ASSERT        "assert"
#define S_KEYWORD_ADD           "add"
#define S_KEYWORD_SUB           "sub"
#define S_KEYWORD_MUL           "mul"
#define S_KEYWORD_DIV           "div"
#define S_KEYWORD_MOD           "mod"
#define S_KEYWORD_PRINT         "print"
#define S_KEYWORD_EXIT          "exit"
#define S_KEYWORD_QUIT          "quit"

#define S_INT_8                 "int8"
#define S_INT_16                "int16"
#define S_INT_32                "int32"
#define S_FLOAT                 "float"
#define S_DOUBLE                "double"

#define S_DIGIT_0               "0"
#define S_DIGIT_1               "1"
#define S_DIGIT_2               "2"
#define S_DIGIT_3               "3"
#define S_DIGIT_4               "4"
#define S_DIGIT_5               "5"
#define S_DIGIT_6               "6"
#define S_DIGIT_7               "7"
#define S_DIGIT_8               "8"
#define S_DIGIT_9               "9"

using SharedToken_t     = std::shared_ptr<std::string>;

using TokVec_t          = std::vector<std::string>;
using SharedTokVec_t    = std::vector<SharedToken_t>;

using ValPair_t         = std::pair<std::string, std::optional<std::string>>;
using TokPair_t         = std::pair<std::string, std::optional<ValPair_t>>;
using PairVec_t         = std::vector<TokPair_t>;

using SetVariant_t = std::variant<
    // std::unordered_set<char>,
    std::unordered_set<std::string>
>;

/*
    class InstrPair
    input: nil
    Provide a structure to receive tokens and organise them in the form of an instruction
    rely on a double pair instr is pair<str, pair<str, str>>
    output instruction
*/


class InstrPair
{
    private:
        bool        readyStatus;
        TokPair_t   instr;
    public:

        InstrPair() : readyStatus(false){}

        void first(std::string keyword)
        {
            instr.first = keyword;
        }

        void second(ValPair_t value)
        {
            instr.second = value;
        }

        void third(std::string digit)
        {
            instr.second->second = digit;
        }

        const TokPair_t getPair() const
        {
            return instr;
        }

        ~InstrPair(){}
};

#endif
