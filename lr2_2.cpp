// ЗАДАНИЕ 2

#include <iostream>
#include <string>
using namespace std;

class Publication
{
protected:
    string book_title;
    float book_price;

public:
    void virtual getdata() 
    {
        cout << "Введите название книги: ";
        getline(cin, book_title);

        cout << "Введите цену книги: ";
        cin >> book_price;
        cin.ignore();
    }

    void virtual putdata() const
    {
        cout << "Название книги: " << book_title << endl;
        cout << "Цена книги: " << book_price << endl;
    }
};

class sales
{
protected:
    float sales[3];

public:
    void getdata_sales()
    {
        for (int i = 0; i < 3; i += 1)
        {
            cout << "Введите общую стоимость проданных экземпляров книги за " << i + 1 << " месяц" << ": ";
            cin >> sales[i];
        }
        cin.ignore();
    }

    void putdata_sales() const
    {
        float summa_sales = 0;
        
        for (int i = 0; i < 3; ++i)
        {
            cout << "Стоимость продаж книги за месяц " << i + 1 << ": " << sales[i] << endl;
            summa_sales += sales[i];
        }
        cout << "\nОбщая стоимость равна: " << summa_sales;
    }
};

class book: public Publication, public sales
{
private:
    int book_pages;

public:
    void getdata() override
    {
        Publication::getdata(); 
        cout << "Введите количество страниц книги: ";
        cin >> book_pages;
        cin.ignore();

        getdata_sales();
    }

    void putdata() const override
    {
        Publication::putdata(); 
        cout << "Количество страниц книги: " << book_pages << endl;

        putdata_sales();
    }
};

class type: public Publication, public sales
{
private:
    float book_audio_duration_minutes;

public:
    void getdata() override
    {
        Publication::getdata(); 
        cout << "Введите время записи книги (в минутах): ";
        cin >> book_audio_duration_minutes;
        cin.ignore();

        getdata_sales();
    }

    void putdata() const override
    {
        Publication::putdata(); 
        cout << "Время записи книги: " << book_audio_duration_minutes << " минут" << endl;

        putdata_sales();
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    system("chcp 1251");

    book new_book;
    type new_type;

    cout << "\nВведите данные о книге." << endl;
    new_book.getdata();

    cout << "\nВведите данные об аудиозаписи книги." << endl;
    new_type.getdata();

    cout << "\nДанные о книге: " << endl;
    new_book.putdata();

    cout << "\nДанные об аудиозаписи: " << endl;
    new_type.putdata();
}
