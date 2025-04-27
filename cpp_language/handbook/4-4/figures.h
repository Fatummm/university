
class Figure {
private:

public:
    virtual int Perimeter() const = 0;

    virtual ~Figure() {}
};

class Triangle: public Figure {
private:
    int a_side, b_side, c_side;
public:
    Triangle(int a, int b, int c): a_side(a), b_side(b), c_side(c) {};

    int Perimeter() const override {
        return a_side + b_side + c_side;
    }
};

class Rectangle: public Figure {
private:
    int a_side, b_side;
public:
    Rectangle(int a, int b): a_side(a), b_side(b){};

    int Perimeter() const override {
        return (a_side + b_side) * 2;
    }
};