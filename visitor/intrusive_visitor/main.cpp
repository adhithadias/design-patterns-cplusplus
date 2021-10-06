struct Expression 
{
    virtual ~Expression() = default;
};

struct DoubleExpressoin : Expression 
{
    double value;

    DoubleExpressoin(double value) : value(value) {}
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
};


int main(int ac, char* av[]) 
{

    return 0;
}