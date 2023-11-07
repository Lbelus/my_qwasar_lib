
#ifndef __URI_STRUCTS_HEADER_
#define __URI_STRUCTS_HEADER_

#ifndef PROTOCOL_ENUM
#define PROTOCOL_ENUM
enum protocol
{
    PROTOCOL_HTTP,
    PROTOCOL_HTTPS,
    PROTOCOL_UNKNOWN,
};
typedef enum protocol protocol_enum;
#endif

#ifndef PARSED_URL
#define PARSED_URL
struct parsed_url_struct
{
  char* domain;
  char* path;
  char* req;
};
typedef struct parsed_url_struct url_p_s_t;
#endif


#ifndef PARSED_URI
#define PARSED_URI
typedef struct parsed_uri_struct
{
    char* scheme;
    char* authority;
    char* path;
    char* query;
    char* fragment;
    char* req;
};
typedef struct parsed_uri_struct uri_p_s_t;
#endif


#ifndef URI_ENUM
#define URI_ENUM
enum uri_type_enum
{
    URI = 1,
    URL
};
typedef enum uri_type_enum uri_enum_t;
#endif

#ifndef URI_STRUCT
#define URI_STRUCT
struct uri_struct
{
    uri_enum_t type_uri;
    union {
        uri_p_s_t* uri;
        url_p_s_t* url;
    } uri_union;
};
typedef struct uri_struct uri_s_t;
#endif


#endif