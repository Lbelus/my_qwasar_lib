#ifndef MY_LANG_PARAM_
#define MY_LANG_PARAM_
#include <main_header.hpp>

// #include <zz00_my_main_lang.hpp>
/*
*SP = space
*CRLF Carriage Return Line Feed

            USER <SP> <username> <CRLF>
            PASS <SP> <password> <CRLF>
            ACCT <SP> <account-information> <CRLF>
            CWD  <SP> <pathname> <CRLF>
            CDUP <CRLF>
            SMNT <SP> <pathname> <CRLF>
            QUIT <CRLF>
            REIN <CRLF>

            PORT <SP> <host-port> <CRLF>
            PASV <CRLF>
            TYPE <SP> <type-code> <CRLF>
            STRU <SP> <structure-code> <CRLF>
            MODE <SP> <mode-code> <CRLF>

            RETR <SP> <pathname> <CRLF>
            STOR <SP> <pathname> <CRLF>
            STOU <CRLF>
            APPE <SP> <pathname> <CRLF>
            ALLO <SP> <decimal-integer>
                [<SP> R <SP> <decimal-integer>] <CRLF>
            REST <SP> <marker> <CRLF>
            RNFR <SP> <pathname> <CRLF>
            RNTO <SP> <pathname> <CRLF>
            ABOR <CRLF>
            DELE <SP> <pathname> <CRLF>
            RMD  <SP> <pathname> <CRLF>
            MKD  <SP> <pathname> <CRLF>
            PWD  <CRLF>
            LIST [<SP> <pathname>] <CRLF>
            NLST [<SP> <pathname>] <CRLF>
            SITE <SP> <string> <CRLF>
            SYST <CRLF>
            STAT [<SP> <pathname>] <CRLF>
            HELP [<SP> <string>] <CRLF>
            NOOP <CRLF>

            <username> ::= <string>
            <password> ::= <string>
            <account-information> ::= <string>
            <string> ::= <char> | <char><string>
            <char> ::= any of the 128 ASCII characters except <CR> and
            <LF>
            <marker> ::= <pr-string>
            <pr-string> ::= <pr-char> | <pr-char><pr-string>
            <pr-char> ::= printable characters, any
                          ASCII code 33 through 126
            <byte-size> ::= <number>
            <host-port> ::= <host-number>,<port-number>
            <host-number> ::= <number>,<number>,<number>,<number>
            <port-number> ::= <number>,<number>
            <number> ::= any decimal integer 1 through 255
            <form-code> ::= N | T | C
            <type-code> ::= A [<sp> <form-code>]
                          | E [<sp> <form-code>]
                          | I
                          | L <sp> <byte-size>
            <structure-code> ::= F | R | P
            <mode-code> ::= S | B | C
            <pathname> ::= <string>
            <decimal-integer> ::= any decimal integer
*/



#define EXIT_INSTRUCTION        1
#define NEXT_INSTRUCTION        0

#define CHAR_SPACE              ' '
#define CHAR_OPARENTHESIS       '('
#define CHAR_CPARENTHESIS       ')'
#define CHAR_DECPOINT           '.'

#define S_CATEGORY_CHARACTERS   "characters"
#define S_CATEGORY_ACC          "AccessControlCommands"
#define S_CATEGORY_TPC          "TransfertParameterCommands"
#define S_CATEGORY_FSC          "FTPservicesCommands"
#define S_CATEGORY_DIGITS       "digits"


#define S_CHARACTERS_NEWLINE    "#"
#define S_CHARACTERS_COMMENT    ";"
#define S_CHARACTERS_DECPOINT   "."
#define S_CHARACTERS_ENDINSTR   ";;"
#define S_CHARACTERS_SPACE      " "

// ACCESS CONTROL COMMANDS
#define S_ACC_USER              "USER"
#define S_ACC_PASS              "PASS"
#define S_ACC_ACCT              "ACCT"
#define S_ACC_CWD               "CWD"
#define S_ACC_CDUP              "CDUP"
#define S_ACC_SMNT              "SMNT"
#define S_ACC_QUIT              "QUIT"
#define S_ACC_REIN              "REIN"
#define S_ACC_EXIT              "EXIT"


// TRANSFERT PARAMETER COMMANDS
#define S_TPC_PORT              "PORT"
#define S_TPC_PASV              "PASV"
#define S_TPC_TYPE              "TYPE"
#define S_TPC_STRU              "STRU"
#define S_TPC_MODE              "MODE"


// FTP SERVICE COMMANDS
#define S_FCS_RETR              "RETR"
#define S_FCS_STOR              "STOR"
#define S_FCS_STOU              "STOU"
#define S_FCS_APPE              "APPE"
#define S_FCS_ALLO              "ALLO"
#define S_FCS_REST              "REST"
#define S_FCS_RFNR              "RFNR"
#define S_FCS_RNTO              "RNOT"
#define S_FCS_ABOR              "ABOR"
#define S_FCS_DELE              "DELE"
#define S_FCS_RMD               "RMD"
#define S_FCS_MKD               "MKD"
#define S_FCS_PWD               "PWD"
#define S_FCS_LIST              "LIST"
#define S_FCS_NLST              "NLST"
#define S_FCS_SITE              "SITE"
#define S_FCS_SYST              "SYST"
#define S_FCS_STAT              "STAT"
#define S_FCS_HELP              "HELP"
#define S_FCS_NOOP              "NOOP"


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

#define VALID_PATTERN           "[\\w!@#\\$%^&*()_.,]+"


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
