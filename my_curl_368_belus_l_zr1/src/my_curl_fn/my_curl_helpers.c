#include <main_header.h>

/*
################ init_my_curl #################
# This function initializes a 'my_curl' request based on the given URI and user argument.
# @return {uri_s_t} Initialized uri_s_t structure
*/
uri_s_t init_my_curl(uri_s_t  uri, char* user_arg)
{
    uri.type_uri = 0;
    if (is_not_url(user_arg))
    {
        /* placeHolder to handle URI */
        return uri;
    }
    else
    {
        if (get_protocol_from_url(user_arg))
        {
            /* placeHolder to handle HTTPS or unknow protocols */
            return uri;
        }
        else
        {
            uri.type_uri = URL;
            uri.uri_union.url = my_url_parser(user_arg);
            return uri;
        }
    }
    return uri;
}

/*
################ my_curl #################
# This function performs a curl-like request using the provided uri_s_t structure.
# @return {int} Status of the request (EXIT_FAILURE or the result of perform_get_request)
*/
int my_curl(uri_s_t  uri)
{
    int exit_status = 1;
    
    if (uri.type_uri == 0)
    {
        return EXIT_FAILURE;
    }
    if (uri.type_uri == URL)
    {
        url_p_s_t* url_s = uri.uri_union.url;
        exit_status = perform_get_request(url_s->domain, url_s->req);
        return exit_status;
    }
    return EXIT_FAILURE;
}

/*
################ clean_my_curl #################
# This function cleans up resources associated with the provided uri_s_t structure.
# @return {int} Status of the cleanup (EXIT_FAILURE or EXIT_SUCCESS)
*/
int clean_my_curl(uri_s_t  uri)
{
    if (uri.type_uri == 0)
    {
        return EXIT_FAILURE;
    }
    else if (uri.type_uri == URL)
    {
        url_p_s_t* url_s = uri.uri_union.url;
        free_url_struct(url_s);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}