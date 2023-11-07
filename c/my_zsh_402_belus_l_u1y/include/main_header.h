#ifndef __MAIN_HEADERFILE_
#define __MAIN_HEADERFILE_
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>

#include <unistd.h> /* for fork */
#include <sys/types.h> /* for pid_t */
#include <sys/wait.h> /* for wait */
#include <sys/stat.h>
#include <dirent.h> // not a sycall
#include <errno.h>
#include <malloc.h>


#include <my_readline.h>
#include <my_stdio.h>
#include <my_string.h>
#include <my_stdlib.h>
#include <my_parser.h>
#include <my_unistd.h>
#include <my_error_handler.h>
#include <non_standard_header.h>
#include <my_cmd_invite.h>
#include <my_env.h>
#include <my_execute.h>

#endif