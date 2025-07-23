#include <iostream>
#include <memory>
#include <string>

class Expression {
public:
    virtual int Evaluate() const = 0;
    virtual std::string ToString() const = 0;
    virtual ~Expression() {}
};

using ExpressionPtr = std::shared_ptr<Expression>;

class Constant: public Expression {
private:
    int value;
public:
    Constant(int x): value(x) {}

    int Evaluate() const override {
        return value;
    }

    std::string ToString() const override {
        return std::to_string(value);
    }
};

ExpressionPtr Const(int x) {
    return std::make_shared<Constant>(x);
}

class Summ: public Expression {
private:
    ExpressionPtr lhs;
    ExpressionPtr rhs;
public:
    Summ(const ExpressionPtr& lhs, const ExpressionPtr& rhs): lhs(lhs), rhs(rhs) {}

    int Evaluate() const override {
        return lhs->Evaluate() + rhs->Evaluate();
    }

    std::string ToString() const override {
        using namespace std::literals;
        return lhs->ToString() + " + "s + rhs->ToString();
    }
};

ExpressionPtr Sum(const ExpressionPtr& lhs, const ExpressionPtr& rhs) {
    return std::make_shared<Summ>(lhs, rhs);
}

class Production: public Expression {
private:
    ExpressionPtr lhs;
    ExpressionPtr rhs;
public:
    Production(const ExpressionPtr& lhs, const ExpressionPtr& rhs): lhs(lhs), rhs(rhs) {}

    int Evaluate() const override {
        return lhs->Evaluate() * rhs->Evaluate();
    };

    std::string ToString() const override {
        using namespace std::literals;
        std::string first;
        std::string second;

        if (dynamic_cast<Summ*>(lhs.get())) first = "("s + lhs->ToString() + ")"s;
        else first = lhs->ToString();
        
        if (dynamic_cast<Summ*>(rhs.get())) second = "("s + rhs->ToString() + ")"s;
        else second = rhs->ToString();

        return first + " * "s + second;
    }
};

ExpressionPtr Product(const ExpressionPtr& lhs, const ExpressionPtr& rhs) {
    return std::make_shared<Production>(lhs, rhs);
}

//#include "your_code.h"

int main() {
    ExpressionPtr ex1 = Sum(Product(Const(3), Const(4)), Const(5));
    std::cout << ex1->ToString() << "\n";  // 3 * 4 + 5
    std::cout << ex1->Evaluate() << "\n";  // 17

    ExpressionPtr ex2 = Product(Const(6), ex1);
    std::cout << ex2->ToString() << "\n";  // 6 * (3 * 4 + 5)
    std::cout << ex2->Evaluate() << "\n";  // 102
}