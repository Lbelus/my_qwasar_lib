#ifndef __ERROR_HANDLER_
#define __ERROR_HANDLER_

#include <main_header.h>

#define ESENDREQUEST         "Error: could not send get request"
#define EINCOMPLREQ          "Error: Get request incomplete"
#define ERESOLVEHOST         "could not resolve host: "
#define ERESOLVEHOST_SIZE    24
#define ENOTURL              "Argument is not an URL\n"
#define ENOTURL_SIZE         24

int     is_request_complete(char* path, char* domain, int len);
void    log_host_error(char* domain);
int     is_not_url(char* uri);
int     check_error_code(int err_code, char* domain);

#endif