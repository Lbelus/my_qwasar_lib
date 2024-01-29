#ifndef MY_MAIN_SERVER
#define MY_MAIN_SERVER


#include <main_header.hpp>


#define RW_SIZE 512
#define BYTE_MAX_PLUS_ONE 256

#define S_CS_150 "150 File status: ok\n\r"
#define S_CS_200 "200: Command okay.\n\r"
#define S_CS_220 "220: Service ready for new user.\r\n"
#define S_CS_221 "221 Goodbye.\r\n"
#define S_CS_207 "227EnteringPassiveMode("
#define S_CS_226 "226 transfer complete\n\r"
#define S_CS_230 "230: Anonymous access granted\n\r"
#define S_CS_502 "502: Command not implemented.\n\r"
#define S_CS_530 "530 Not logged in\n\r"
#define S_CS_550 "550: File not found.\r\n"

#endif