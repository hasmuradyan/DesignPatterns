#include <iostream>
#include <string>
using namespace std;


class AbstractProductA 
{
public:
    virtual string OperationA() = 0;
};

// Concrete Products for Product A in two variants
class ConcreteProductA1 : public AbstractProductA 
{
public:
    string OperationA() override
    {
        return "Product A - Variant 1: Operation A";
    }
};

class ConcreteProductA2 : public AbstractProductA 
{
public:
    string OperationA() override 
    {
        return "Product A - Variant 2: Operation A";
    }
};

class AbstractProductB 
{
public:
    virtual string OperationB() = 0;
};


class ConcreteProductB1 : public AbstractProductB
{
public:
    string OperationB() override
    {
        return "Product B - Variant 1: Operation B";
    }
};

class ConcreteProductB2 : public AbstractProductB
{
public:
    string OperationB() override 
    {
        return "Product B - Variant 2: Operation B";
    }
};

class AbstractFactory {
public:
    virtual AbstractProductA* CreateProductA() = 0;
    virtual AbstractProductB* CreateProductB() = 0;
};

// Concrete Factories for two variants
class ConcreteFactory1 : public AbstractFactory 
{
public:
    AbstractProductA* CreateProductA() override 
    {
        return new ConcreteProductA1();
    }

    AbstractProductB* CreateProductB() override
    {
        return new ConcreteProductB1();
    }
};

class ConcreteFactory2 : public AbstractFactory 
{
public:
    AbstractProductA* CreateProductA() override 
    {
        return new ConcreteProductA2();
    }

    AbstractProductB* CreateProductB() override
    {
        return new ConcreteProductB2();
    }
};


void Client(AbstractFactory& factory) 
{
    AbstractProductA* productA = factory.CreateProductA();
    AbstractProductB* productB = factory.CreateProductB();

    productA->OperationA();
    productB->OperationB();

    delete productA;
    delete productB;
}

int main() {
    ConcreteFactory1 factory1;
    cout << "product 1" << endl;
    Client(factory1);

    ConcreteFactory2 factory2;
    cout << "product 2" << endl;
    Client(factory2);

    return 0;
}
