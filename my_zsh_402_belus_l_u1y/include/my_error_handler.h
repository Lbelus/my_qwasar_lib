#ifndef __ERROR_HANDLER_
#define __ERROR_HANDLER_

#include <main_header.h>

#define HARD_SIZE_LIMIT         2 * 1024 * 1024
#define ARG_SIZE                2
#define ERR_MSG_MAX_ARG         "bad user arg"
#define SIZE_ERR_MSG_MAX        13
#define OVERFLOW                "OVERFLOWING\n"
#define SIZE_OVERF              12
#define UNDERFLOW               "UNDERFLOWING\n"
#define SIZE_UNDERFLOW          13
#define MEM_POOL_ALLOC          "Cannot allocate memory pool\n"
#define SIZE_MSG_ALLOC          28
#define MEM_POOL_SPACE          "Mem pool has no more space\n"
#define SIZE_MSG_SPACE          27
#define PERF_LIMIT              99
#define ERR_MESSAGE_WIN         "1: Ressource analysis unavailable on windows\n"
#define ERR_MESSAGE_WIN_SIZE    45
#define ERR_MESSAGE_MACOS       "1: Ressource analysis unavailable on mac os\n"
#define ERR_MESSAGE_MACOS_SIZE  44
#define RESS_ERROR              "NOK\n1: no more resources available on computer\n"
#define RESS_ERROR_LEN          47
#define CPU_SIZE_ARR            11
#define CPU_LEN_STR             12
#define _ENOPATH_               "Cannot find PATH"
#define _ENOPATH_SIZE_          17               
#define _EVALNULL_              "Value is NULL"
#define _EVALNULLSIZE_          14
#define _SEGMSG_                "segmentation fault\n"
#define _SEGMSG_size            19
#define ECMDNOTFOUND            "command not found\n"
#define SCMDNOTFOUND            18
#define _EPWDNOSET_             "cd: OLDPWD not set\n"
#define _EPWDNOSETSIZE_         19


int     welcome_error(int val);
int     error_handler();
void    segfault_msg();
int     linux_cpu_perf();
int     linux_mem_perf();
int     operating_sys();

#endif