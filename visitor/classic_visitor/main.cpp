#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

struct DoubleExpression;
struct AdditionExpression;
struct SubtractionExpression;
struct ExpressionVisitor
{
    virtual void visit(DoubleExpression *de) = 0;
    virtual void visit(AdditionExpression *ae) = 0;
    virtual void visit(SubtractionExpression *ae) = 0;
};

struct ExpressionPrinter : ExpressionVisitor
{
    std::ostringstream oss;
    std::string str() const { return oss.str(); }

    void visit(DoubleExpression *de) override;
    void visit(AdditionExpression *ae) override;
    void visit(SubtractionExpression *ae) override;
};

struct ExpressionEvaluator : ExpressionVisitor
{
    double result;

    void visit(DoubleExpression *de) override;
    void visit(AdditionExpression *ae) override;
    void visit(SubtractionExpression *ae) override;
};

struct Expression 
{
    virtual ~Expression() = default;
    virtual void accept(ExpressionVisitor* visitor) = 0;

    // virtual void print(std::ostringstream& oss) = 0;
};

struct DoubleExpression : Expression 
{
    double value;

    DoubleExpression(double value) : value(value) {}

    // void print(std::ostringstream& oss) override 
    // {
    //     oss << value;
    // }

    void accept(ExpressionVisitor *visitor) override
    {
        visitor->visit(this);
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

    // void print(std::ostringstream& oss) override
    // {
    //     oss << "(";
    //     left->print(oss);
    //     oss << "+";
    //     right->print(oss);
    //     oss << ")";
    // }

    void accept(ExpressionVisitor *visitor) override
    {
        visitor->visit(this);
    }

};

struct SubtractionExpression : Expression 
{
    Expression *left, *right;

    SubtractionExpression(Expression *left, Expression *right)
        : left(left), right(right) {}

    ~SubtractionExpression() 
    {
        delete left;
        delete right;
    }

    void accept(ExpressionVisitor *visitor) override
    {
        visitor->visit(this);
    }

};

// separation of concern for the printing functionality
// struct ExpressionPrinter
// {
//     std::ostringstream oss;


//     std::string str() const 
//     {
//         return oss.str();
//     }

//     void print(Expression* e) 
//     {
//         if (auto de = dynamic_cast<DoubleExpression*>(e)) 
//         {
//             oss << de->value;
//         } else if (auto ae = dynamic_cast<AdditionExpression*>(e))
//         {
//             oss << "(";
//             print(ae->left);
//             oss << "+";
//             print(ae->right);
//             oss << ")";
//         }
//     }
// };


int main(int ac, char* av[]) 
{
    auto e = new AdditionExpression{
        new DoubleExpression{1},
        new SubtractionExpression{
            new DoubleExpression{2},
            new DoubleExpression{4}
        }
    };

    // (1+(2+3))
    // std::ostringstream oss;
    // e->print(oss);
    // std::cout << oss.str() << std::endl;

    // ExpressionPrinter ep;
    // ep.print(e);
    // std::cout << ep.str() << std::endl;


    // auto ep = new ExpressionPrinter();
    // e->accept(ep);
    // std::cout << ep->str() << std::endl;

    ExpressionPrinter ep;
    ep.visit(e);
    std::cout << ep.str() << std::endl;

    ExpressionEvaluator ev;
    ev.visit(e);
    std::cout << "result: " << ev.result << std::endl;

    delete e;

    return 0;
}

void ExpressionPrinter::visit(DoubleExpression *de) {
    oss << de->value;
}

void ExpressionPrinter::visit(AdditionExpression *ae) {
    bool need_braces = dynamic_cast<AdditionExpression*>(ae->right);
    if (need_braces) oss << "(";
    ae->left->accept(this);
    oss << "+";
    ae->right->accept(this);
    if (need_braces) oss << ")";
}

void ExpressionPrinter::visit(SubtractionExpression *se) {
    bool need_braces = dynamic_cast<SubtractionExpression*>(se->right);
    if (need_braces) oss << "(";
    se->left->accept(this);
    oss << "-";
    se->right->accept(this);
    if (need_braces) oss << ")";
}

void ExpressionEvaluator::visit(DoubleExpression *de) {
    result = de->value;
}

void ExpressionEvaluator::visit(AdditionExpression *ae) {
    ae->left->accept(this);
    auto temp = result;
    ae->right->accept(this);
    result = temp + result;
}

void ExpressionEvaluator::visit(SubtractionExpression *se) {
    se->left->accept(this);
    auto temp = result;
    se->right->accept(this);
    result = temp - result;
}