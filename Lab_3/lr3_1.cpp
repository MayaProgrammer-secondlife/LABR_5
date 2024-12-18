// ЗАДАНИЕ 1

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Part 
{
protected:
    string name;

    Part(const string& name) : name(name) {}

public:
    virtual ~Part() = default; 

    virtual void display() const 
    {
        cout << "Part: " << name << endl;
    }
};

class Assembly : public Part 
{
private:
    vector<shared_ptr<Part>> components; 

    Assembly(const string& name) : Part(name) {}

public:
    
    static shared_ptr<Assembly> create(const string& name) 
    {
        return shared_ptr<Assembly>(new Assembly(name));
    }

    void addComponent(shared_ptr<Part> component) 
    {
        components.push_back(component);
    }

    
    void display() const override 
    {
        cout << "Сборка: " << name << endl;
        for (const auto& component : components) 
        {
            component->display(); 
        }
    }
};

class ConcretePart : public Part 
{
public:
    
    ConcretePart(const string& name) : Part(name) {}

    void display() const override 
    {
        cout << "Деталь: " << name << endl;
    }
};

int main() 
{
    setlocale(LC_ALL, "rus");
    
    vector<shared_ptr<Part>> storage;

    auto part1 = make_shared<ConcretePart>("Деталь 1");
    auto part2 = make_shared<ConcretePart>("Деталь 2");
    auto part3 = make_shared<ConcretePart>("Деталь 3");

    auto assembly1 = Assembly::create("Сборка 1");
    assembly1->addComponent(part1);
    assembly1->addComponent(part2);

    storage.push_back(assembly1);

    auto assembly2 = Assembly::create("Сборка 2");
    assembly2->addComponent(part3);

    storage.push_back(assembly2);

    for (const auto& part : storage) 
    {
        part->display();
    }

    return 0;
}
