#ifndef __ERROR_HANDLER_
#define __ERROR_HANDLER_

#define ARG_SIZE            2
#define ERR_MSG_MAX_ARG     "bad user arg"
#define SIZE_ERR_MSG_MAX    13
#define OVERFLOW            "OVERFLOWING\n"
#define SIZE_OVERF          12
#define UNDERFLOW           "UNDERFLOWING\n"
#define SIZE_UNDERFLOW      13
#define MEM_POOL_ALLOC      "Cannot allocate memory pool\n"
#define SIZE_MSG_ALLOC      28
#define MEM_POOL_SPACE      "Mem pool has no more space\n"
#define SIZE_MSG_SPACE      27
int     welcome_error(int val);

#endif