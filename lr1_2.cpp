// ЗАДАНИЕ 2

#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<fstream>
#include<cstdlib>
#include<algorithm>
using namespace std;

class Book
{
public:
    string author_name;
    string book_name;
    string type_of_book;
};

class MyBooks
{
public:
    vector <Book> books;

    void addBook()
    {
        Book my_book;

        cout << "\n" << "Введите полное название книги: ";
        cin.clear();
        cin.ignore();
        getline(cin, my_book.book_name);

        cout << "Введите полное ФИО автора книги: ";
        cin.clear();
        getline(cin, my_book.author_name);

        cout << "Введите тип книги (художественная или техническая): ";
        cin.clear();
        getline(cin, my_book.type_of_book);

        //командой добавляем книгу
        books.push_back(my_book);
    }

    void spisokBooks()
    {
        if (books.empty())
        {
            cout << "\n" << "В библиотеке нет книг. Добавьте книгу для совершения действия." << endl;
        }

        else
        {
            cout << "\n" << "Список книг библиотеки: " << "\n" << endl;

            for (int i = 0; i < books.size(); i++)
            {
                cout << "\n" << "Тип книги: " << books[i].type_of_book << "\n" << "ФИО автора: " << books[i].author_name << "\n" << "Название книги: " << books[i].book_name << "\n" << "\n";
            }
        }
    }

    void researchBook_type()
    {
        //переменная для хранения нашедшейся книги
        bool book_found = false;
        //переменная для хранения нашедшейся книги по типу
        bool book_type_found = false;

        if (books.empty())
        {
            cout << "\n" << "В библиотеке нет книг. Добавьте книгу для совершения действия." << endl;
        }

        else
        {
            string TYPE;
            cout << "\nВведите тип книги (художественная или техническая): ";
            cin.clear();
            cin.ignore();
            getline(cin, TYPE);

            //проверка на пустой ввод
            if (TYPE.empty())
            {
                cout << "Поиск книги не может быть осуществлён, так как тип книги не введён." << endl;
                return;
            }

            else
            {
                string TYPE;
                cout << "\n Повторно введите тип книги.";
                cout << "\n" << "Введите тип книги (художественная или техническая): ";
                cin >> TYPE;

                for (int i = 0; i < books.size(); i++)
                {
                    if ((books[i].type_of_book) == (TYPE))
                    {
                        cout << "\n" << "\nНайдены следующие книги: \n\n";
                        cout << "Тип книги: " << books[i].type_of_book << "\n" << "ФИО автора: " << books[i].author_name << "\n" << "Название книги: " << books[i].book_name << endl;
                    }
                }
            }
        }
    }

    void researchBook_author()
    {
        if (books.empty())
        {
            cout << "\n" << "В библиотеке нет книг. Добавьте книгу для совершения действия." << endl;
        }

        else
        {
            string AUTHOR;
            cout << "\nВведите ФИО автора: ";
            cin.clear();
            cin.ignore();
            getline(cin, AUTHOR);
            
            if (AUTHOR.empty())
            {
                cout << "Поиск книги не может быть осуществлён, так как ФИО автора книги не введёно." << endl;
                return;
            }

            else
            {
                string Avtor;
                cout << "\n Повторно введите ФИО автора книги.";
                cout << "\n" << "Введите ФИО автора: ";
                cin.clear();
                cin.ignore();
                getline(cin, Avtor);

                for (int i = 0; i < books.size(); i++)
                {
                    if ((books[i].author_name) == (Avtor))
                    {
                        cout << "\n" << "\nНайдены следующие книги: \n\n";
                        cout << "Тип книги: " << books[i].type_of_book << "\n" << "ФИО автора: " << books[i].author_name << "\n" << "Название книги: " << books[i].book_name << endl;
                    }
                }
            }
        }
    }

    void researchBook_name()
    {
        if (books.empty())
        {
            cout << "\n" << "В библиотеке нет книг. Добавьте книгу для совершения действия." << endl;
        }

        else
        {
            string NAME;
            cout << "\nВведите название книги: ";
            cin.clear();
            cin.ignore();
            getline(cin, NAME);

            if (NAME.empty())
            {
                cout << "Поиск книги не может быть осуществлён, так как название книги не введёно." << endl;
                return;
            }

            else
            {
                string NameB;
                cout << "\n Повторно введите название книги.";
                cout << "\n" << "Введите название книги: ";
                cin.clear();
                cin.ignore();
                getline(cin, NameB);

                for (int i = 0; i < books.size(); i++)
                {
                    if (string(books[i].book_name) == NameB)
                    {
                        cout << "\n" << " \nНайдены следующие книги: \n\n";
                        cout << "Тип книги: " << books[i].type_of_book << "\n" << "ФИО автора: " << books[i].author_name << "\n" << "Название книги: " << books[i].book_name << endl;
                    }
                }
                }
        }
    }

    void deleteBook()
    {
        if (books.empty())
        {
            cout << "\n" << "В библиотеке нет книг. Добавьте книгу для совершения действия." << endl;
        }

        else
        {
            int Choice;
            cout << "\n" << "По какому признаку Вы хотите удалить книгу? Вам доступны следующие варианты: \n";
            cout << "1. По типу книги" << endl;
            cout << "2. По автору книги" << endl;
            cout << "3. По названию книги" << endl;
            cout << "Ваша введённая цифра: ";
            cin >> Choice;

            string number;
            string stroka_1;
            string stroka_2;

            switch (Choice)
            {
            case 1:
                cout << "\n" << "Тип книги: ";
                cin >> number;

                for (int i = 0; i < books.size(); i++)
                {
                    if ((books[i].type_of_book) == (number))
                    {
                        books.erase(books.begin() + i);
                    }
                }
                break;

            case 2:
                cout << "\n" << "Введите автора книги: ";
                cin.clear();
                cin.ignore();
                getline(cin, stroka_1);

                for (int i = 0; i < books.size(); i++)
                {
                    if ((books[i].author_name) == (stroka_1))
                    {
                        books.erase(books.begin() + i);
                    }
                }
                break;

            case 3:
                cout << "\n" << "Введите название книги: ";
                cin.clear();
                cin.ignore();
                getline(cin, stroka_2);

                for (int i = 0; i < books.size(); i++)
                {
                    if ((books[i].book_name) == (stroka_2))
                    {
                        books.erase(books.begin() + i);
                    }
                }
                break;
            }
        }
    }

    void number_of_types_Books()
    {
        Book new_book;
        
        int t_type_book = 0;
        int h_type_book = 0;

        for (const auto& book : books)
        {
            if (book.type_of_book == "художественная")
            {
                h_type_book += 1;
            }

            else if (book.type_of_book == "техническая")
            {
                t_type_book += 1;
            }
        }

        cout << "\nКоличество художественных книг в Вашей библиотеке составляет: " << h_type_book << endl;
        cout << "Количество технических книг в Вашей библиотеке составляет: " << t_type_book << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");

    system("chcp 1251");

    MyBooks prostor;

    int choice;
    while (true)
    {
        int choice = 0;

        cout << "\n" << "Выберите дальнейшую команду. " << endl;
        cout << "1. Добавить в библиотеку книгу " << endl;
        cout << "2. Вывести список книг " << endl;
        cout << "3. Искать книгу по типу книги (доступны опции: художественная книга, техническая книга)  " << endl;
        cout << "4. Искать книгу по автору " << endl;
        cout << "5. Искать книгу по названию " << endl;
        cout << "6. Удалить книгу " << endl;
        cout << "7. Выход из библиотеки " << endl;
        cout << "8. Вывести количество книг по типам (художественная, техническая литература)" << endl;
        cout << "\nВаша введённая цифра: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            prostor.addBook();
            break;

        case 2:
            prostor.spisokBooks();
            break;

        case 3:
            prostor.researchBook_type();
            break;

        case 4:
            prostor.researchBook_author();
            break;

        case 5:
            prostor.researchBook_name();
            break;

        case 6:
            prostor.deleteBook();
            break;

        case 7:
            cout << "\n" << "Вы вышли из библиотеки. Для входа повторно запустите программу." << endl;
            return 0;
            break;

        case 8:
            prostor.number_of_types_Books();
            break;
        }
    }
}