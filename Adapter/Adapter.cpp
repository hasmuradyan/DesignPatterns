#include <iostream>
using namespace std;

class Client
{
public:
    virtual void request() = 0;
};


class Service 
{
public:
    void specialRequest() 
    {
        cout << "Service: Special Request" << endl;;
    }
};

class Adapter : public Client 
{
private:
    Service* service;

public:
    Adapter(Service* s) : service(s) {}

    void request() override 
    {
        cout << "Adapter: Translating Client request to Service" << endl;
        service->specialRequest();
    }
};

int main() 
{

    Service service;

    Adapter adapter(&service);

    cout << "Client: Making a request to the Adapter" << endl;
    adapter.request();

    return 0;
}
