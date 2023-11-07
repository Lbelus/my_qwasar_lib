#ifndef MY_SYNTAX_HEADER_
#define MY_SYNTAX_HEADER_

#include <zz00_my_main_lang.hpp>

/*
    Class Syntax
    input: Nil
        Provide structure to the language in order to be tokenized by the lexer and then parsed
            - is called from other classes;
            - unordered set provide a fast look up data structure 
            to find equivalent and perfom validity checks; 
    output : Nil
*/


class Syntax
{
    protected:
        TokVec_t         tokens;

        TokPair_t        tmp;
        bool             readyStatus;

        PairVec_t        instructions;

        SharedTokVec_t   charactersVec;
        SharedTokVec_t   keywordsVec;
        SharedTokVec_t   typesVec;
        SharedTokVec_t   digitsVec;

        inline static const std::unordered_set<std::string> characters =
        {
            S_CHARACTERS_NEWLINE,
            S_CHARACTERS_COMMENT,
            S_CHARACTERS_DECPOINT,
            S_CHARACTERS_ENDINSTR
        };

        inline static const std::unordered_set<std::string> keywords =
        { 
            S_KEYWORD_PUSH,
            S_KEYWORD_POP,
            S_KEYWORD_DUMP,
            S_KEYWORD_ASSERT,
            S_KEYWORD_ADD,
            S_KEYWORD_SUB,
            S_KEYWORD_MUL,
            S_KEYWORD_DIV,
            S_KEYWORD_MOD,
            S_KEYWORD_PRINT,
            S_KEYWORD_EXIT,
            S_KEYWORD_QUIT
        };

        inline static const std::unordered_set<std::string> types =
        { 
            S_INT_8,
            S_INT_16,
            S_INT_32,
            S_FLOAT,
            S_DOUBLE
        };

        inline static const std::unordered_set<std::string> digits = 
        {
            S_DIGIT_0,
            S_DIGIT_1,
            S_DIGIT_2,
            S_DIGIT_3,
            S_DIGIT_4,
            S_DIGIT_5,
            S_DIGIT_6,
            S_DIGIT_7,
            S_DIGIT_8,
            S_DIGIT_9
        };

        //help find the corresponding token static set
        inline static const std::unordered_map<std::string, SetVariant_t> tokenMap =
        {
            { S_CATEGORY_CHARACTERS, characters },
            { S_CATEGORY_KEYWORDS,   keywords   },
            { S_CATEGORY_TYPES,      types      },
            { S_CATEGORY_DIGITS,     digits     }
        };

        //help find the corresponding token vector
        std::unordered_map<std::string, SharedTokVec_t&> categoryMap =
        {
            { S_CATEGORY_CHARACTERS,  charactersVec },
            { S_CATEGORY_KEYWORDS,    keywordsVec   },
            { S_CATEGORY_TYPES,       typesVec      },
            { S_CATEGORY_DIGITS,      digitsVec     }
        };

        public:
        Syntax(){}
        ~Syntax(){}
};

#endif
