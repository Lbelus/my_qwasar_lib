#ifndef __MAIN_HEADERFILE_
#define __MAIN_HEADERFILE_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#include <my_uri_structs.h>
#include <my_string.h>
#include <my_error_handler.h>
#include <my_linkedlist.h>
#include <my_parser.h>



#define ANSWER_BUFFER_SIZE 4096
#define __PORT__ "80"

uri_s_t init_my_curl(uri_s_t  uri, char* user_arg);
int     my_curl(uri_s_t  uri);
int     clean_my_curl(uri_s_t  uri);
int     perform_get_request(char* domain,  char* get);
int     send_get_req(char* get, int sockfd);
int     connect_to_server(int sockfd, struct addrinfo* servinfo);
int     r_socket_w_out(int sockfd);

#endif