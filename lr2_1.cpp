// ЗАДАНИЕ 1

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

class book: public Publication
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
    }

    void putdata() const override
    {
        Publication::putdata(); 
        cout << "Количество страниц книги: " << book_pages << endl;
    }
};

class type: public Publication
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
    }

    void putdata() const override
    {
        Publication::putdata(); 
        cout << "Время записи книги: " << book_audio_duration_minutes << " минут" << endl;
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
