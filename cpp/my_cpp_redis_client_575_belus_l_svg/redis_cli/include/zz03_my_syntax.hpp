#ifndef MY_SYNTAX_HEADER_
#define MY_SYNTAX_HEADER_
// #include <main_header.hpp>

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

namespace UsrIn
{
    class Syntax
    {
        protected:
            TokVec_t         tokens;

            TokPair_t        tmp;

            PairVec_t        instructions;

            SharedTokVec_t   commonVec;
            SharedTokVec_t   digitsVec;
            SharedTokVec_t   charactersVec;

            SharedTokVec_t   TypeOneVec;
            SharedTokVec_t   TypeTwoVec;
            SharedTokVec_t   TypeThreeVec;

            inline static const std::unordered_set<std::string> digits = // lol no
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


            inline static const std::unordered_set<std::string> characters =
            {
                S_CHARACTERS_NEWLINE,
                S_CHARACTERS_COMMENT,
                S_CHARACTERS_DECPOINT,
                S_CHARACTERS_ENDINSTR
            };


            inline static const std::unordered_set<std::string> common = 
            {
                S_COMMON_QUIT,
                S_COMMON_EXIT
            };


            inline static const std::unordered_set<std::string> TypeOne =
            { 
                S_TYP1_NAME,
                S_TYP1_NAME
            };


            inline static const std::unordered_set<std::string> TypeTwo =
            { 
                S_TYP2_NAME
            };


            inline static const std::unordered_set<std::string> TypeThree =
            { 
                S_TYP3_NAME           
            };


            //help find the corresponding token static set
            inline static const std::unordered_map<std::string, SetVariant_t> tokenMap =
            {
                { S_CATEGORY_CHARACTERS,     characters         },
                { S_CATEGORY_DIGITS,         digits             },
                { S_CATEGORY_COMMON,         common             },

                { S_CATEGORY_TYP1,           TypeOne            },
                { S_CATEGORY_TYP2,           TypeTwo            },
                { S_CATEGORY_TYP3,           TypeThree          }
            };

            //help find the corresponding token vector
            std::unordered_map<std::string, SharedTokVec_t&> categoryMap =
            {
                { S_CATEGORY_CHARACTERS,     charactersVec          },
                { S_CATEGORY_DIGITS,         digitsVec              },
                { S_CATEGORY_COMMON,         commonVec              },

                { S_CATEGORY_TYP1,           TypeOneVec             },
                { S_CATEGORY_TYP2,           TypeTwoVec             },
                { S_CATEGORY_TYP3,           TypeThreeVec           }
            };

            public:
            Syntax(){}
            ~Syntax(){}
    };
}


#endif
