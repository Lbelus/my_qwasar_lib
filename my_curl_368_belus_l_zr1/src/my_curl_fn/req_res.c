#include <main_header.h>

/*
################ send_get_req #################
# Sends a GET request to a socket identified by the sockfd parameter.
# The function also checks for errors, and if an error occurs, it prints out the error message and the error code.
# @return {int} Returns EXIT_SUCCESS if the request is sent successfully, otherwise returns EXIT_FAILURE.
*/
int send_get_req(char* get, int sockfd)
{
  int len = my_strlen(get);
  int err_code;
  err_code = send(sockfd, get, len, 0);
  if (err_code == -1)
  {
    perror(ESENDREQUEST);
    printf("errcode: %d", errno);
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

// /*
// ################ r_socket_w_out #################
// # Reads data from a socket, identified by the sockfd parameter, and writes the read data to the standard output.
// # Once all the data is read, the socket is closed.
// # @return {void}
// */

node_t* set_http_responser_header(int sockfd)
{
	char* 	str  = NULL;
	node_t* head = NULL;
	node_t* tmp  = NULL;
	int index = 0;
    while ((str = my_readline(sockfd)) != NULL 
	&& my_strcmp(str, "\r") != 0)
    {
		tmp = create_node(str);
		head = insert_at_head(&head, tmp);
		index += 1;
		free(str);
	}
	flush_buffer();
	free(str);
	return head;
}

int r_socket_w_out(int sockfd)
{
	node_t* head = NULL;
	node_t* tmp  = NULL;
	char* 	str  = NULL;
    char 	buffer[ANSWER_BUFFER_SIZE];
	int 	size_read = 0;
	init_my_readline();
	head = set_http_responser_header(sockfd);
	my_memset(buffer, 0, ANSWER_BUFFER_SIZE); 
 	while (size_read = read(sockfd, buffer, ANSWER_BUFFER_SIZE))
 	{
    	write(STDOUT_FILENO, buffer, size_read);
    	my_memset(buffer, 0, ANSWER_BUFFER_SIZE);
   	}
	free_llist(head);
  	close(sockfd);
	return EXIT_SUCCESS;
}

// /*
// ################ connect_to_server #################
// # Connects a socket, identified by the sockfd parameter, to a server defined by the servinfo parameter.
// # If the connection fails, the function prints an error message, frees the servinfo structure, and closes the socket.
// # @return {int} Returns EXIT_SUCCESS if the socket is connected successfully, otherwise returns EXIT_FAILURE.
// */
int connect_to_server(int sockfd, struct addrinfo* servinfo)
{
	if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1)
	{
		perror("Error: could not connect socket");
    	freeaddrinfo(servinfo);
    	close(sockfd);
    	return EXIT_FAILURE;
  	}
  	return EXIT_SUCCESS;
}

// /*
// ################ perform_get_request #################
// # Performs a GET request on the specified domain with the provided GET request string.
// # The response from the server is printed to the standard output.
// # @return {int} Returns 0 after successfully executing the function.
// */
int perform_get_request(char* domain,  char* get)
{
  	int sockfd;
  	int err_code;
  	struct addrinfo hints, *servinfo;
  	my_memset(&hints, 0, sizeof hints);
  	hints.ai_family = AF_INET;
  	hints.ai_socktype = SOCK_STREAM;
  	err_code = getaddrinfo(domain, __PORT__, &hints, &servinfo);
  	if (check_error_code(err_code, domain))
  	{
    	return EXIT_FAILURE;
  	}
  	sockfd = socket(AF_INET, SOCK_STREAM, 0);
  	connect_to_server(sockfd, servinfo);
  	freeaddrinfo(servinfo);
  	if (send_get_req(get, sockfd))
  	{
    	return EXIT_FAILURE;
  	}
  	r_socket_w_out(sockfd);
  	return EXIT_SUCCESS;
}