#include <iostream>
#include <string>
using namespace std;

class Product 
{
public:
    virtual string Operation() const = 0;
};

class ConcreteProductA : public Product 
{
public:
    string Operation() const override 
    {
        return "Concrete Product A";
    }
};

class ConcreteProductB : public Product 
{
public:
    string Operation() const override
    {
        return "Concrete Product B";
    }
};

class Creator
{
public:
    virtual Product* FactoryMethod() const = 0;
};

class ConcreteCreatorA : public Creator 
{
public:
    Product* FactoryMethod() const override
    {
        return new ConcreteProductA();
    }
};

class ConcreteCreatorB : public Creator 
{
public:
    Product* FactoryMethod() const override
    {
        return new ConcreteProductB();
    }
};

int main()
{
    Creator* creator = new ConcreteCreatorA();
    Product* product = creator->FactoryMethod();

    cout << product->Operation() << endl;

    delete product;
    delete creator;

    creator = new ConcreteCreatorB();
    product = creator->FactoryMethod();

    cout << product->Operation() << endl;

    delete product;
    delete creator;

    return 0;
}
