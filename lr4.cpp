#include <iostream>
#include <vector>
#include <stdexcept> 
using namespace std;

const char* memory_Error() 
{
    return "Ошибка доступа к памяти";
}

const char* math_Error() 
{
    return "Математическая ошибка";
}

const char* zero_Error() 
{
    return "Деление на ноль ошибка";
}

const char* over_Error() 
{
    return "Переполнение ошибка";
}

class RuntimeError : public runtime_error 
{
public:
    RuntimeError(const string& message): runtime_error(message) {}
};

template <typename T>
class PointerArray
{
private:
    vector<T> arr;

public:
    void add(T obj) 
    {
        arr.push_back(obj);
    }

    T operator[](size_t index) const
    {
        if (index >= arr.size())
        {
            throw RuntimeError("Индекс вышел за пределы"); 
        }
        return arr[index];
    }

    
    size_t size() const 
    {
        return arr.size();
    }
};

int main()
{
    setlocale(LC_ALL, "rus");

    try
    {
        PointerArray<const char*> errorArray;
        errorArray.add(memory_Error());
        errorArray.add(math_Error());
        errorArray.add(zero_Error());
        errorArray.add(over_Error());

        for (size_t i = 0; i < errorArray.size(); ++i)
        {
            cout << errorArray[i] << endl;
        }

    }
    catch (const RuntimeError& e)
    {
        cerr << "runtime_Error: " << e.what() << endl;
    }
    catch (const exception& e)
    {
        cerr << "Исключение: " << e.what() << endl;
    }

    return 0;
}





