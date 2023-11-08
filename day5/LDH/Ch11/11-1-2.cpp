#include <iostream>
#include <cString>
using namespace std;


class Book
{
private:
    char * title;
    char * isbn;
    int price;
public:
    Book(char * t, char * i, int p) : price(p)
    {
        title = new char[strlen(t)+1];
        isbn = new char[strlen(i)+1];
        strcpy(title,t);
        strcpy(isbn,i);
    }
    Book(const Book& book) : price(book.price)
    {
        title = new char[strlen(book.title)+1];
        isbn = new char[strlen(book.isbn)+1];
        strcpy(title, book.title);
        strcpy(isbn, book.isbn);
    }
    Book& operator=(const Book& book)
    {
        delete []title;
        delete []isbn;

        title = new char[strlen(book.title)+1];
        isbn = new char[strlen(book.isbn)+1];
        strcpy(title, book.title);
        strcpy(isbn, book.isbn);
        price=book.price;
        return *this;
    }
    void ShowBookInfo()
    {
        cout<<"제목: "<<title<<endl;
        cout<<"ISBN: "<<isbn<<endl;
        cout<<"가격: "<<price<<endl;
    }
    ~Book()
    {
        delete[] title;
        delete[] isbn;
    }
};

class EBook : public Book
{
private:
    char * DRMKey;
public:
    EBook(char *t, char*i, int p, char*d) : Book(t,i,p)
    {
        DRMKey = new char[strlen(d)+1];
        strcpy(DRMKey,d);
    }
    EBook(const EBook& ebook) : Book(ebook)
    {
        DRMKey = new char[strlen(ebook.DRMKey)+1];
        strcpy(DRMKey,ebook.DRMKey);
    }
    EBook& operator=(const EBook& ebook)
    {
        delete []DRMKey;
        
        DRMKey = new char[strlen(ebook.DRMKey)+1];
        strcpy(DRMKey,ebook.DRMKey);
        Book::operator=(ebook);
        return *this;       
    }
    ~EBook()
    {
        delete[] DRMKey;
    }
    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout<<"인증키: "<<DRMKey<<endl;
    }    
};

int main(void)
{
    Book book("좋은 C++", "555-12345-890-0",20000);
    Book newbook=book;
    newbook.ShowBookInfo();
    cout<<endl;
    EBook ebook("좋은 C++", "555-12345-890-0",20000,"fdx9w0i8kiw");
    EBook newebook=ebook;
    newbook.ShowBookInfo();
}