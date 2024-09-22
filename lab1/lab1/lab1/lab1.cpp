#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book
{

public:
    string title;
    string author;
    string ISBN;

    Book(string m, string n, string c)
    {
        title = m;
        author = n;
        ISBN = c;
    }

    ~Book()
    {
        cout << "Cartea " << title << " a fost distrusa" << endl;
    }
};

class Library
{

private:
    int entryprice;

public:
    vector<Book> Carti;

    void seteprice(int p)
    {
        entryprice = p;
    }

    int geteprice()
    {
        return entryprice;
    }

    void addBook(Book& b)
    {
        Carti.push_back(b);
    }

    void removeBook(int a)
    {
        a--;
        if (a >= 0 && a < Carti.size())
        {
            Carti.erase(Carti.begin() + a);
            cout << "Cartea " << a + 1 << " a fost eliminata." << endl << endl;
        }
        else cout << "Cartea nu exista." << endl;
    }

    void showBooks()
    {
        if (Carti.empty())
        {
            cout << "Nu sunt carti in biblioteca" << endl << endl;
        }
        else {
            cout << "Cartile din biblioteca (" << Carti.size() << ")" << endl << endl;
            for (Book& i : Carti)
            {
                cout << "Titlu: " << i.title << endl;
                cout << "Autor: " << i.author << endl;
                cout << "ISBN: " << i.ISBN << endl << endl;
            }
        }
    }
};

int main()
{
    Library library1;
    library1.seteprice(50);
    cout << "Pretul de intrare in biblioteca: " << library1.geteprice() << endl;

    Book book1("Harap Alb", "Mihai Eminescu", "9678491345234");
    library1.addBook(book1);

    Book book2("Ursul pacalit de vulpe", "Ion Creanga", "9678653949234");
    library1.addBook(book2);

    Book book3("Teme p/u acasa", "William Shakespeare", "9781856466936");
    library1.addBook(book3);

    library1.showBooks();

    library1.removeBook(3);

    library1.showBooks();

    return 0;
}
