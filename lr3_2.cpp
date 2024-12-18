// ЗАДАНИЕ 2

#include <iostream>
#include <vector>
#include <cstdlib>
#include <memory>
using namespace std;

class Base 
{
public:
    virtual void display() const 
    {
        cout << "Это объект базового класса." << endl;
    }
    virtual ~Base() = default; 
};

class Derived : public Base 
{
public:
    void display() const override 
    {
        cout << "Это объект производного класса." << endl;
    }
};

class Storage 
{
private:
    vector<shared_ptr<Base>> items; 

public:
    void add(shared_ptr<Base> item) 
    {
        items.push_back(item); 
    }

    void show() const 
    {
        for (const auto& item : items) 
        {
            item->display(); 
        }
    }
};

int main() 
{
    setlocale(LC_ALL, "rus");
    
    srand(static_cast<unsigned int>(time(nullptr))); 
    Storage storage;

    
    for (int i = 0; i < 10; ++i) 
    { 
        int randomNum = rand(); 
        if (randomNum % 2 == 0) 
        {
            storage.add(make_shared<Base>());
        }
        else 
        {
            storage.add(make_shared<Derived>());
        }
    }

    storage.show();

    return 0;
}
