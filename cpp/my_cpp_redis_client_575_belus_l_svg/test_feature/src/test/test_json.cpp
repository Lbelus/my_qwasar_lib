#include <main_header.hpp>

int test_json()
{
    using json = nlohmann::json;
    // create an empty structure (null)
    json j;

    // add a number that is stored as double (note the implicit conversion of j to an object)
    j["pi"] = 3.141;

    // add a Boolean that is stored as bool
    j["happy"] = true;

    // add a string that is stored as std::string
    j["name"] = "Niels";

    // add another null object by passing nullptr
    j["nothing"] = nullptr;

    // add an object inside the object
    j["answer"]["everything"] = 42;

    // add an array that is stored as std::vector (using an initializer list)
    j["list"] = { 1, 0, 2 };

    // add another object (using an initializer list of pairs)
    j["object"] = { {"currency", "USD"}, {"value", 42.99} };

    std::cout << j <<std::endl;

    return EXIT_SUCCESS;
}


int googletest_json(std::string jsonStr)
{
    using json = nlohmann::json;
    // create an empty structure (null)
    json j1;
    json j2 = json::parse(jsonStr);

    // add a number that is stored as double (note the implicit conversion of j to an object)
    j1["pi"] = 3.141;

    // add a Boolean that is stored as bool
    j1["happy"] = true;

    // add a string that is stored as std::string
    j1["name"] = "Niels";

    // add another null object by passing nullptr
    j1["nothing"] = nullptr;

    // add an object inside the object
    j1["answer"]["everything"] = 42;

    // add an array that is stored as std::vector (using an initializer list)
    j1["list"] = { 1, 0, 2 };

    // add another object (using an initializer list of pairs)
    j1["object"] = { {"currency", "USD"}, {"value", 42.99} };

    // explicit conversion to string
    std::string str1 = j1.dump();
    std::string str2 = j2.dump();
    return str1 == str2;
}