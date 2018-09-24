#include <iostream>
#include <cstring>

using namespace std;

//#define BASIC
#define RETURN

#ifdef BASIC
struct Books
{
    char title[50];
    char author[50];
    int book_id;
};

void printBook(struct Books book)
{
    cout << "Book title: " << book.title << endl;
    cout << "Book author: " << book.author << endl;
    cout << "Book ID: " << book.book_id << endl;
}
void printBookAdd(struct Books* book)
{
    cout << "Book title: " << book->title << endl;
    cout << "Book author: " << book->author << endl;
    cout << "Book ID: " << book->book_id << endl;
}
#endif
struct test {
    int i;
    char c;
    double d;
    float f;
};

struct test set(int a, float b, char c, double d)
{
    struct test t;
    t.i = a;
    t.f = b;
    t.c = c;
    t.d = d;
    return t;
}

void print(struct test t2)
{
    printf("int: %d\n", t2.i);
    printf("char: %c\n", t2.c);
    printf("float: %f\n", t2.f);
    printf("double: %f\n", t2.d);
}
#ifdef RETURN

#endif
int main()
{
#ifdef RETURN
    struct test info;
    info = set(2,3.22,'d',4.335);
    print(info);
#endif

#ifdef BASIC
    Books Book1;
    strcpy(Book1.title, "C++ programme");
    strcpy(Book1.author, "wenliang");
    Book1.book_id = 12345;

    cout << "Book title: " << Book1.title << endl;
    cout << "Book author: " << Book1.author << endl;
    cout << "Book ID: " << Book1.book_id << endl;

    cout << "######################" << endl;
    printBook(Book1);
    
    cout << "######################" << endl;
    printBookAdd(&Book1);
#endif

    return 0;
}
