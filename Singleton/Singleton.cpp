#include <iostream>

class Singleton {
public:
    
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void printMessage() 
    {
        std::cout << "test" << std::endl;
    }

private:
    
    Singleton() {}

    ~Singleton() {}
};

int main() {
    // Get the Singleton instance
    Singleton& singleton = Singleton::getInstance();

    // Call a member function
    singleton.printMessage();

    return 0;
}