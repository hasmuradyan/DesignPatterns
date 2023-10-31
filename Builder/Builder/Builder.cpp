#include <iostream>
#include <string>
using namespace std;

class ProductA1 {
public:
    void OperationA() {
        cout << "OperationA of ProductA1" << endl;
    }
};

class ProductB1 {
public:
    void OperationB() {
        cout << "OperationB of ProductB1" << endl;
    }
};

class Builder {
public:
    virtual void BuildStepA() = 0;
    virtual void BuildStepB() = 0;
};


class ConcreteBuilder : public Builder {
private:
    ProductA1 productA;
    ProductB1 productB;

public:
    void BuildStepA() override {
        cout << "Building ProductA1" << endl;
        productA.OperationA();
    }

    void BuildStepB() override {
        cout << "Building ProductB1" << endl;
        productB.OperationB();
    }
};

// Director
class Director {
public:
    void Construct(Builder& builder) {
        builder.BuildStepA();
        builder.BuildStepB();
    }
};

int main() {
    Director director;
    ConcreteBuilder builder1;

    cout << "Product" << endl;
    director.Construct(builder1);

    return 0;
}
