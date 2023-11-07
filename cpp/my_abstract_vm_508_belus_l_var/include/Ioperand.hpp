#ifndef IOPERAND_HEADER_
#define IOPERAND_HEADER_

// IOperand.hpp
#include <string>
#include <vector>
#include <limits>

// Define the eOperandType Enum
enum class eOperandType
{
    Int8,
    Int16,
    Int32,
    Float,
    Double
};

// Define the IOperand Interface
class IOperand
{
public:
    virtual std::string const & toString() const = 0;

    virtual int           getPrecision() const = 0;
    virtual eOperandType  getType() const = 0;

    virtual IOperand* operator+(const IOperand &rhs) const = 0;
    // virtual IOperand* operator-(const IOperand &rhs) const = 0;
    // virtual IOperand* operator*(const IOperand &rhs) const = 0;
    // virtual IOperand* operator/(const IOperand &rhs) const = 0;
    // virtual IOperand* operator%(const IOperand &rhs) const = 0;

    virtual ~IOperand() {}
};


class Int8 : public IOperand
{
    private:
    int8_t value;
    Int8() {};

    public:
        Int8(const std::string & str)
        {
            int32_t tmp = std::stoi(str);
            if (tmp < std::numeric_limits<int8_t>::min()
                || tmp > std::numeric_limits<int8_t>::max())
            {
                throw std::out_of_range("Value out of Int8 range");
            }
            value = static_cast<int8_t>(tmp);
        }

        virtual std::string const & toString() const override
        {
            static std::string str = std::to_string(value);
            return str;
        }

        virtual int getPrecision() const override
        {
            return static_cast<int>(eOperandType::Int8);
        }

        virtual eOperandType getType() const override
        {
            return eOperandType::Int8;
        }

        virtual IOperand* operator+(const IOperand &rhs) const override
        {
            switch (rhs.getType()) 
            {
                case eOperandType::Int8:
                {
                    int16_t result = static_cast<int16_t>(value) + static_cast<int16_t>(dynamic_cast<const Int8&>(rhs).value);
                    if (result < std::numeric_limits<int8_t>::min() || result > std::numeric_limits<int8_t>::max())
                    {
                        throw std::runtime_error("Overflow in Int8 addition");
                    }
                    return new Int8(std::to_string(result));
                }
                case eOperandType::Int16:
                    // return dynamic_cast<const Int16&>(rhs) + (*this);
                case eOperandType::Int32:
                    // return dynamic_cast<const Int32&>(rhs) + (*this);
                case eOperandType::Float:
                    // return dynamic_cast<const Float&>(rhs) + (*this);
                case eOperandType::Double:
                    // return dynamic_cast<const Double&>(rhs) + (*this);
                default:
                    throw std::runtime_error("Unknown operand type");
            }
        }
        virtual ~Int8() {}
};


class OperandFactory
{
    private:
        IOperand* createInt8(const std::string & value)
        {
            return new Int8(value);
        }   
        IOperand* createInt16(const std::string & value)
        {
            // return new Int16(value);
        }
        IOperand* createInt32(const std::string & value)
        {
            // return new Int32(value);
        }
        IOperand* createFloat(const std::string & value)
        {
            // return new Float(value);
        }
        IOperand* createDouble(const std::string & value)
        {
            // return new Double(value);
        }

    public:
    IOperand* createOperand(eOperandType type, const std::string & value)
    {
        switch (type)
        {
            case eOperandType::Int8:
                return createInt8(value);
            case eOperandType::Int16:
                // return createInt16(value);
            case eOperandType::Int32:
                // return createInt32(value);
            case eOperandType::Float:
                // return createFloat(value);
            case eOperandType::Double:
                // return createDouble(value);
            default:
                throw std::runtime_error("Invalid operand type");
        }
    }
};

class MyAbstractVM
{
private:
    std::vector<IOperand*> stack;
    OperandFactory factory;

public:
    void push(eOperandType type, const std::string & value)
    {
        IOperand* operand = factory.createOperand(type, value);
        stack.push_back(operand);
    }

    void pop()
    {
        if (stack.empty())
        {
            throw std::runtime_error("Pop operation on an empty stack");
        }
        delete stack.back(); // Free memory
        stack.pop_back();
    }

    ~MyAbstractVM()
    {
        for (IOperand* operand : stack)
        {
            delete operand;
        }
    }
};

// #include <vector>
// #include <cstdint>

// enum class eOperandType
// {
//     Int8,
//     Int16,
//     Int32,
//     Float,
//     Double
// };

// class IOperand
// {
//     private : 
//     std::string str;
    
//     public:

//         virtual std::string const & toString() const;

//         virtual int           getPrecision() const = 0;
//         virtual eOperandType  getType() const = 0;

//         virtual IOperand *  operator+(const IOperand &rhs) const = 0;
//         virtual IOperand *  operator-(const IOperand &rhs) const = 0;
//         virtual IOperand *  operator*(const IOperand &rhs) const = 0;
//         virtual IOperand *  operator/(const IOperand &rhs) const = 0;
//         virtual IOperand *  operator%(const IOperand &rhs) const = 0;

//         virtual ~IOperand() {}
// };

// class Int8 : public IOperand
// {
//     private:
//     int8_t value;
//     Int8() {};

//     public:
//         Int8(const std::string & str)
//         {
//             int32_t tmp = std::stoi(str);
//             if (tmp < std::numeric_limits<int8_t>::min()
//                 || tmp > std::numeric_limits<int8_t>::max())
//             {
//                 throw std::out_of_range("Value out of range for Int8");
//             }
//             value = static_cast<int8_t>(tmp);
//         }

//         virtual std::string const & toString() const override
//         {
//             static std::string str = std::to_string(value);
//             return str;
//         }

//         virtual int getPrecision() const override
//         {
//             return static_cast<int>(eOperandType::Int8);
//         }

//         virtual eOperandType getType() const override
//         {
//             return eOperandType::Int8;
//         }

//         virtual IOperand* operator+(const IOperand &rhs) const override
//         {
//             switch (rhs.getType()) 
//             {
//                 case eOperandType::Int8:
//                 {
//                     int16_t result = static_cast<int16_t>(value) + static_cast<int16_t>(dynamic_cast<const Int8&>(rhs).value);
//                     if (result < std::numeric_limits<int8_t>::min() || result > std::numeric_limits<int8_t>::max()) {
//                         throw std::runtime_error("Overflow in Int8 addition");
//                     }
//                     return new Int8(std::to_string(result));
//                 }
//                 case eOperandType::Int16:
//                     return dynamic_cast<const Int16&>(rhs) + (*this);
//                 case eOperandType::Int32:
//                     return dynamic_cast<const Int32&>(rhs) + (*this);
//                 case eOperandType::Float:
//                     return dynamic_cast<const Float&>(rhs) + (*this);
//                 case eOperandType::Double:
//                     return dynamic_cast<const Double&>(rhs) + (*this);
//                 default:
//                     throw std::runtime_error("Unknown operand type");
//             }
//         }

//         virtual IOperand* operator-(const IOperand &rhs) const override
//         {
//             switch (rhs.getType()) 
//             {
//                 case eOperandType::Int8:
//                 {
//                     int16_t result = static_cast<int16_t>(value) - static_cast<int16_t>(dynamic_cast<const Int8&>(rhs).value);
//                     if (result < std::numeric_limits<int8_t>::min() || result > std::numeric_limits<int8_t>::max()) {
//                         throw std::runtime_error("Overflow in Int8 addition");
//                     }
//                     return new Int8(std::to_string(result));
//                 }
//                 case eOperandType::Int16:
//                     return dynamic_cast<const Int16&>(rhs) + (*this);
//                 case eOperandType::Int32:
//                     return dynamic_cast<const Int32&>(rhs) + (*this);
//                 case eOperandType::Float:
//                     return dynamic_cast<const Float&>(rhs) + (*this);
//                 case eOperandType::Double:
//                     return dynamic_cast<const Double&>(rhs) + (*this);
//                 default:
//                     throw std::runtime_error("Unknown operand type");
//             }
//         }

//         virtual IOperand* operator/(const IOperand &rhs) const override
//         {
//             switch (rhs.getType()) 
//             {
//                 case eOperandType::Int8:
//                 {
//                     int16_t result = static_cast<int16_t>(value) / static_cast<int16_t>(dynamic_cast<const Int8&>(rhs).value);
//                     if (result < std::numeric_limits<int8_t>::min() || result > std::numeric_limits<int8_t>::max()) {
//                         throw std::runtime_error("Overflow in Int8 addition");
//                     }
//                     return new Int8(std::to_string(result));
//                 }
//                 case eOperandType::Int16:
//                     return dynamic_cast<const Int16&>(rhs) + (*this);
//                 case eOperandType::Int32:
//                     return dynamic_cast<const Int32&>(rhs) + (*this);
//                 case eOperandType::Float:
//                     return dynamic_cast<const Float&>(rhs) + (*this);
//                 case eOperandType::Double:
//                     return dynamic_cast<const Double&>(rhs) + (*this);
//                 default:
//                     throw std::runtime_error("Unknown operand type");
//             }
//         }


//         virtual IOperand* operator*(const IOperand &rhs) const override
//         {
//             switch (rhs.getType()) 
//             {
//                 case eOperandType::Int8:
//                 {
//                     int16_t result = static_cast<int16_t>(value) * static_cast<int16_t>(dynamic_cast<const Int8&>(rhs).value);
//                     if (result < std::numeric_limits<int8_t>::min() || result > std::numeric_limits<int8_t>::max()) {
//                         throw std::runtime_error("Overflow in Int8 addition");
//                     }
//                     return new Int8(std::to_string(result));
//                 }
//                 case eOperandType::Int16:
//                     return dynamic_cast<const Int16&>(rhs) + (*this);
//                 case eOperandType::Int32:
//                     return dynamic_cast<const Int32&>(rhs) + (*this);
//                 case eOperandType::Float:
//                     return dynamic_cast<const Float&>(rhs) + (*this);
//                 case eOperandType::Double:
//                     return dynamic_cast<const Double&>(rhs) + (*this);
//                 default:
//                     throw std::runtime_error("Unknown operand type");
//             }
//         }

//         virtual IOperand* operator%(const IOperand &rhs) const override
//         {
//         switch (rhs.getType())
//         {
//             case eOperandType::Int8:
//             {
//                 int result = value % dynamic_cast<const Int8&>(rhs).value;
//                 return new Int8(std::to_string(result));
//             }
//             case eOperandType::Int16:
//                 // Convert the Int8 operand to Int16 and then perform the modulo operation
//                 return dynamic_cast<const Int16&>(rhs) % (*this);
//             case eOperandType::Int32:
//                 // Convert the Int8 operand to Int32 and then perform the modulo operation
//                 return dynamic_cast<const Int32&>(rhs) % (*this);
//             case eOperandType::Float:
//             case eOperandType::Double:
//                 throw std::runtime_error("Modulo operation not defined for floating point types");
//             default:
//                 throw std::runtime_error("Unknown operand type");
//         }
//     }

//         virtual ~Int8() {}
// };

// class OperandFactory
// {
//     private:
//         IOperand* createInt8(const std::string & value)
//         {
//             return new Int8(value);
//         }   
//         IOperand* createInt16(const std::string & value)
//         {
//             return new Int16(value);
//         }
//         IOperand* createInt32(const std::string & value)
//         {
//             return new Int32(value);
//         }
//         IOperand* createFloat(const std::string & value)
//         {
//             return new Float(value);
//         }
//         IOperand* createDouble(const std::string & value)
//         {
//             return new Double(value);
//         }

//     public:
//     IOperand* createOperand(eOperandType type, const std::string & value)
//     {
//         switch (type)
//         {
//             case eOperandType::Int8:
//                 return createInt8(value);
//             case eOperandType::Int16:
//                 return createInt16(value);
//             case eOperandType::Int32:
//                 return createInt32(value);
//             case eOperandType::Float:
//                 return createFloat(value);
//             case eOperandType::Double:
//                 return createDouble(value);
//             default:
//                 throw std::runtime_error("Invalid operand type");
//         }
//     }
// };


// class MyAbstractVM
// {
//     private:
//         std::vector<IOperand*> stack;
//         OperandFactory factory;

//     public:
//         void push(eOperandType type, const std::string & value)
//         {
//             IOperand* operand = factory.createOperand(type, value);
//             stack.push_back(operand);
//         }

//         void pop()
//         {
//             if (stack.empty()) 
//             {
//                 throw std::runtime_error("Pop operation on an empty stack");
//             }
//             delete stack.back(); // Free memory
//             stack.pop_back();
//         }

//         ~MyAbstractVM()
//         {
//             for (IOperand* operand : stack)
//             {
//                 delete operand;
//             }
//         }
// };

#endif