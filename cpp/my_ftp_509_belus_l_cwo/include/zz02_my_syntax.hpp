#ifndef MY_SYNTAX_HEADER_
#define MY_SYNTAX_HEADER_
#include <main_header.hpp>


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

        SharedTokVec_t   AccessControlCommandsVec;
        SharedTokVec_t   TransfertParameterCommandsVec;
        SharedTokVec_t   FTPservicesCommandsVec;
        SharedTokVec_t   digitsVec;
        SharedTokVec_t   charactersVec;


        inline static const std::unordered_set<std::string> AccessControlCommands =
        { 
            S_ACC_USER,             
            S_ACC_PASS,             
            S_ACC_ACCT,             
            S_ACC_CWD,             
            S_ACC_CDUP,             
            S_ACC_SMNT,             
            S_ACC_QUIT,
            S_ACC_REIN,
            S_ACC_EXIT
        };


        inline static const std::unordered_set<std::string> TransfertParameterCommands =
        { 
            S_TPC_PORT,
            S_TPC_PASV,
            S_TPC_TYPE,
            S_TPC_STRU,
            S_TPC_MODE
        };


        inline static const std::unordered_set<std::string> FTPservicesCommands =
        { 
            S_FCS_RETR,              
            S_FCS_STOR,              
            S_FCS_STOU,              
            S_FCS_APPE,              
            S_FCS_ALLO,              
            S_FCS_REST,              
            S_FCS_RFNR,              
            S_FCS_RNTO,              
            S_FCS_ABOR,              
            S_FCS_DELE,              
            S_FCS_RMD,              
            S_FCS_MKD,              
            S_FCS_PWD,              
            S_FCS_LIST,              
            S_FCS_NLST,              
            S_FCS_SITE,              
            S_FCS_SYST,              
            S_FCS_STAT,              
            S_FCS_HELP,              
            S_FCS_NOOP              
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


        inline static const std::unordered_set<std::string> characters =
        {
            S_CHARACTERS_NEWLINE,
            S_CHARACTERS_COMMENT,
            S_CHARACTERS_DECPOINT,
            S_CHARACTERS_ENDINSTR
        };


        //help find the corresponding token static set
        inline static const std::unordered_map<std::string, SetVariant_t> tokenMap =
        {
            { S_CATEGORY_ACC,           AccessControlCommands           },
            { S_CATEGORY_TPC,           TransfertParameterCommands      },
            { S_CATEGORY_FSC,           FTPservicesCommands             },
            { S_CATEGORY_CHARACTERS,    characters                      },
            { S_CATEGORY_DIGITS,        digits                          }
        };


        //help find the corresponding token vector
        std::unordered_map<std::string, SharedTokVec_t&> categoryMap =
        {
            { S_CATEGORY_ACC,           AccessControlCommandsVec        },
            { S_CATEGORY_TPC,           TransfertParameterCommandsVec   },
            { S_CATEGORY_FSC,           FTPservicesCommandsVec          },
            { S_CATEGORY_CHARACTERS,    charactersVec                   },
            { S_CATEGORY_DIGITS,        digitsVec                       }
        };


        public:
        Syntax(){}
        ~Syntax(){}
};

#endif
