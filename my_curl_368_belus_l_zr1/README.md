# Welcome to My Curl
***

## Task

The task is to create a my_curl command that functions like the UNIX command curl. my_curl is a tool designed to fetch data from a server, specifically via the HTTP protocol. The command should work without user interaction; it takes an URL as parameter and prints out the HTML content of the web page. 

## Description

This project involves three main functions - init_my_curl, my_curl, and clean_my_curl.

The init_my_curl function initializes a 'my_curl' request based on the given URI and user argument. If the user argument is not a URL or uses a protocol other than HTTP, the function handles these cases accordingly.

The my_curl function performs a curl-like request using the provided uri_s_t structure, calling the perform_get_request function which connects to the server, sends a GET request, reads the server's response and writes it to the standard output.

The clean_my_curl function cleans up resources associated with the provided uri_s_t structure.

The project makes use of socket programming to handle HTTP requests and responses.

The project has been developped to meet but requirements only but is leaving structs and branching paths available for further updates.

## Installation

To install this project, follow these steps:

- Clone the repository to your local machine.
- In your terminal, navigate to the project folder.
- Run ``make`` command to compile the project. This will generate the executable my_curl.
- Run ``fclean`` to clean the build dir and the all binaries. 

## Usage
To use my_curl, use the following command format:

```sh
./my_curl <URL>
```
Replace <URL> with the web address from which you want to fetch data. For example:
```sh
./my_curl http://www.columbia.edu/~fdc/sample.html
```
This will display the HTML content of the specified web page in the terminal.


### The Core Team
* [Lorris BELUS](//github.com/Lbelus) - Developer


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
