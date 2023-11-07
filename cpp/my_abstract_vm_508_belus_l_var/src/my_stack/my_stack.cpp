#include <my_stack.hpp>

    MyStack::MyStack()
    {
        data.reserve(100);
    }

    MyStack::~MyStack(){}

    void MyStack::push(VariantType token)
    {
        data.push_back(token);
    }

    VariantType MyStack::execute(const std::string& str, ToVariantFunc cmd)
    {
    	return cmd(str);
    }

    void MyStack::convertToPush(const std::string& type, const std::string& value)
    {
        std::map<std::string, ToVariantFunc> dispatchMap = {
            { INT_8_S,   sToVariantType<int8_t>  },
            { INT_16_S,  sToVariantType<int16_t> },
            { INT_32_S,  sToVariantType<int32_t> },
            { FLOAT_S,   sToVariantType<float>   },
            { DOUBLE_S,  sToVariantType<double>  }
        };

        auto it = dispatchMap.find(type);
        if (it != dispatchMap.end()) // If found
        {
            auto val = execute(value, it->second);
            push(val);
        }
    }

    VariantType MyStack::pop()
    {
        VariantType value = data.back();
        data.pop_back();
        return value;
    }

    // void MyStack::dump() const
    // {
    //     std::cout << "Exploring stack from top :" << data.size() << std::endl;
    //     for (const auto& item : data)
    //     {
    //         std::visit([](auto&& arg)
    //         {
    //             using T = std::decay_t<decltype(arg)>;
    //             if constexpr (std::is_same_v<T, int8_t>)
    //             {
    //                 std::cout << static_cast<int>(arg);
    //             }
    //             else
    //             {
    //                 std::cout << arg;
    //             }
    //         }, item);
    //         std::cout << "-";
    //     }
    //     std::cout << std::endl;
    // }
    void MyStack::dump() const
    {
        std::cout << "Exploring stack :" << data.size() << std::endl;

        // Reverse iterate over the data
        for (auto it = data.rbegin(); it != data.rend(); ++it)
        {
            std::visit([](auto&& arg)
            {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, int8_t>)
                {
                    std::cout << static_cast<int>(arg);
                }
                else
                {
                    std::cout << arg;
                }
            }, *it);
            std::cout << "-";
        }
        std::cout << std::endl;
    }


    bool MyStack::isEmpty()
    {
        return data.empty();
    }

    void MyStack::assert(const VariantType& val)
    {
        if (isEmpty())
        {
            throw StackError("Stack empty.");
        }
        const VariantType& topValue = data.back();
        bool isEqual = std::visit(
            [](auto&& arg1, auto&& arg2) -> bool {
                using T1 = std::decay_t<decltype(arg1)>;
                using T2 = std::decay_t<decltype(arg2)>;
                if constexpr (std::is_same_v<T1, T2>)
                {
                    return arg1 == arg2;
                }
                else
                {
                    return false;
                }
            },
            topValue, val
        );
        if (!isEqual)
        {
            throw StackError("Top does not match");
        }
    }

    void MyStack::convertToAssert(const std::string& type, const std::string& value)
    {
        std::map<std::string, ToVariantFunc> dispatchMap = {
            { INT_8_S,   sToVariantType<int8_t>  },
            { INT_16_S,  sToVariantType<int16_t> },
            { INT_32_S,  sToVariantType<int32_t> },
            { FLOAT_S,   sToVariantType<float>   },
            { DOUBLE_S,  sToVariantType<double>  }
        };

        auto it = dispatchMap.find(type);
        if (it != dispatchMap.end()) // If found
        {
            auto val = execute(value, it->second);
            assert(val);
        }
    }

    bool MyStack::HasEnoughOperand()
    {
        if (data.size() >= 2)
        {
            return true;
        }
        return false;
    }

    void MyStack::add()
    {
        if (!HasEnoughOperand())
        {
            throw StackError("Not Enough Operand");
        };
        auto val_01 = pop();
        auto val_02  = pop();
        auto genericAdd = [](auto a, auto b) { return a + b; };
        VariantType result = std::visit(
            [&](auto&& arg1, auto&& arg2) -> VariantType {
                return genericAdd(arg1, arg2);
            }, 
            val_01, val_02
        );
        push(result);
    }

    void MyStack::sub()
    {
        if (!HasEnoughOperand())
        {
            throw StackError("Not Enough Operand");
        };
        auto val_01 = pop();
        auto val_02  = pop();
        auto genericSub = [](auto a, auto b) { return a - b; };
        VariantType result = std::visit(
            [&](auto&& arg1, auto&& arg2) -> VariantType {
                return genericSub(arg1, arg2);
            }, 
            val_01, val_02
        );
        push(result);
    }

    void MyStack::mul()
    {
        if (!HasEnoughOperand())
        {
            throw StackError("Not Enough Operand");
        };
        auto val_01 = pop();
        auto val_02  = pop();
        auto genericMul = [](auto a, auto b) { return a * b; };
        VariantType result = std::visit(
            [&](auto&& arg1, auto&& arg2) -> VariantType {
                return genericMul(arg1, arg2);
            }, 
            val_01, val_02
        );
        push(result);
    }

    void MyStack::div()
    {
        if (!HasEnoughOperand())
        {
            throw StackError("Not Enough Operand");
        };
        auto val_01 = pop();
        auto val_02  = pop();
        auto genericMul = [](auto a, auto b) { return a / b; };
        VariantType result = std::visit(
            [&](auto&& arg1, auto&& arg2) -> VariantType {
                if (arg2 == 0) 
                {
                    throw StackError("Divide by zero");
                }
                return genericMul(arg1, arg2);
            }, 
            val_01, val_02
        );
        push(result);
    }

    // void MyStack::mod()
    // {
    //     if (!HasEnoughOperand())
    //     {
    //         throw StackError("Not Enough Operand");
    //     };
    //     auto val_01 = pop();
    //     auto val_02 = pop();
    //     auto genericMod = [](auto&& arg1, auto&& arg2) -> VariantType {
    //         using T1 = std::decay_t<decltype(arg1)>;
    //         using T2 = std::decay_t<decltype(arg2)>;

    //         if constexpr (std::is_integral_v<T1> && std::is_integral_v<T2> && std::is_same_v<T1, T2>) 
    //         {
    //             if (arg2 == 0) 
    //             {
    //                 throw StackError("Divide by zero");
    //             }
    //             return arg1 % arg2;
    //         }
    //         else 
    //         {
    //             throw StackError("Type not valid for comparison");
    //         }
    //     };
    //     VariantType result = std::visit(genericMod, val_01, val_02);
    //     push(result);
    // }

//     void MyStack::mod()
// {
//     if (!HasEnoughOperand())
//     {
//         throw StackError("Not Enough Operand");
//     };
//     auto val_01 = pop();
//     auto val_02 = pop();
//     auto genericMod = [](auto&& arg1, auto&& arg2) -> VariantType {
//         int32_t operand1 = static_cast<int32_t>(arg1);
//         int32_t operand2 = static_cast<int32_t>(arg2);

//         if (operand2 == 0) 
//         {
//             throw StackError("Divide by zero");
//         }
//         return operand1 % operand2;
//     };
//     VariantType result = std::visit(genericMod, val_01, val_02);
//     push(result);
// }

void MyStack::mod()
{
    if (!HasEnoughOperand())
    {
        throw StackError("Not Enough Operand");
    };
    auto val_01 = pop();
    auto val_02 = pop();

    auto genericMod = [](auto&& arg1, auto&& arg2) -> VariantType {
        using T1 = std::decay_t<decltype(arg1)>;
        using T2 = std::decay_t<decltype(arg2)>;

        if (arg2 == 0) 
        {
            throw StackError("Divide by zero");
        }

        if constexpr (std::is_integral_v<T1> && std::is_integral_v<T2>) 
        {
            return arg1 % arg2;
        }
        else 
        {
            throw StackError("Type not valid for comparison");
        }
    };

    VariantType result = std::visit(genericMod, val_01, val_02);
    push(result);
}

    void MyStack::print()
    {
        if (isEmpty())
        {
            throw StackError("Stack empty");
        }

        VariantType topValue = data.back();
        if (std::holds_alternative<int8_t>(topValue))
        {
            char ch = static_cast<char>(std::get<int8_t>(topValue));
            std::cout << ch << std::endl;
        }
        else
        {
            assert(int8_t{});
        }
    }

    void MyStack::clear()
    {
        data.clear();
    }
