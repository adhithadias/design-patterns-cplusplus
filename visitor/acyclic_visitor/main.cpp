

#include <sstream>
#include <string>
#include <iostream>
template <typename Visitable>
struct Visitor
{
    virtual void visit(Visitable& obj) = 0;
};

struct VisitorBase 
{
    virtual ~VisitorBase() = default;
};

struct Expression 
{
    virtual ~Expression() = default;

    // we want to make sure VisitorBase is of some type we expect
    // we use a dynamic cast to make sure of it
    virtual void accept(VisitorBase& obj) 
    // now implementing the accept method in the class hierarchy is not a must
    {
        using EV = Visitor<Expression>;
        if (auto ev = dynamic_cast<EV*>(&obj)) { // we verify the visitor base
            ev->visit(*this);
        }
    }
};

struct DoubleExpression : Expression
{
    double value;

    DoubleExpression(double value) : value(value) {}
    
    // we want to make sure VisitorBase is of some type we expect
    // we use a dynamic cast to make sure of it
    virtual void accept(VisitorBase& obj)
    {
        // DoubleExpressionVisitor
        using DEV = Visitor<DoubleExpression>;
        if (auto dev = dynamic_cast<DEV*>(&obj)) { // we verify the visitor base
            dev->visit(*this);
        }
    }
};

struct AdditionExpression : Expression
{
    Expression *left, *right;

    AdditionExpression(Expression* left, Expression* right) : left(left), right(right) {}

    ~AdditionExpression()
    {
        delete left;
        delete right;
    }
    
    // we want to make sure VisitorBase is of some type we expect
    // we use a dynamic cast to make sure of it
    virtual void accept(VisitorBase& obj)
    {
        // DoubleExpressionVisitor
        using AEV = Visitor<AdditionExpression>;
        if (auto aev = dynamic_cast<AEV*>(&obj)) { // we verify the visitor base
            aev->visit(*this);
        }
    }
};

// Visitor base has nothing in it. 
// It is just a marker for visitors
struct ExpressionPrinter : VisitorBase,
    Visitor<DoubleExpression>,
    Visitor<AdditionExpression>
{
    void visit(AdditionExpression &obj) override // overloads predicated by out inherits
    {
        oss << "(";
        obj.left->accept(*this);
        oss << "+";
        obj.right->accept(*this);
        oss << ")";

    }

    void visit(DoubleExpression &obj) override // overloads predicated by out inherits
    {
        oss << obj.value;
    }
    
    std::string str()
    {
        return oss.str();
    }

private:
    std::ostringstream oss;
};

int main(int ac, char* av[]) 
{
    AdditionExpression* e = new AdditionExpression{
        new DoubleExpression{1},
        new AdditionExpression{
            new DoubleExpression{2},
            new DoubleExpression{3}
        }
    };

    ExpressionPrinter ep;
    ep.visit(*e);
    std::cout << ep.str() << std::endl;

    return 0;
}