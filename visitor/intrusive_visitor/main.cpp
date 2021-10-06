#include <iostream>
#include <ostream>
#include <sstream>
struct Expression 
{
    virtual ~Expression() = default;
    virtual void print(std::ostringstream& oss) = 0;
};

struct DoubleExpression : Expression 
{
    double value;

    DoubleExpression(double value) : value(value) {}

    void print(std::ostringstream& oss) override 
    {
        oss << value;
    }
};

struct AdditionExpression : Expression 
{
    Expression *left, *right;

    AdditionExpression(Expression *left, Expression *right)
        : left(left), right(right) {}

    ~AdditionExpression() 
    {
        delete left;
        delete right;
    }

    void print(std::ostringstream& oss) override
    {
        oss << "(";
        left->print(oss);
        oss << "+";
        right->print(oss);
        oss << ")";
    }
};


int main(int ac, char* av[]) 
{
    auto e = new AdditionExpression{
        new DoubleExpression{1},
        new AdditionExpression{
            new DoubleExpression{2},
            new DoubleExpression{3}
        }
    };

    // (1+(2+3))
    std::ostringstream oss;
    e->print(oss);
    std::cout << oss.str() << std::endl;

    delete e;

    return 0;
}