template <typename T>
T MyStack::sToVariantType(const std::string str)
{
    T val;
    auto [ptr, errorCode] = std::from_chars(str.data(), str.data() + str.size(), val);
    if (errorCode == std::errc())
    {
        return val;
    }
    else
    {
        throw StackError("Error in conversion of type\n");
    }
}
