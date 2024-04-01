#include <bits/stdc++.h>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

typedef struct Book
{
    string name_book;          // tên sách
    string author;             // tác giả
    string code;               // mã
    string language;           // ngôn ngữ
    string describe;           // mô tả
    string status;             // trạng thái
    string borrower;           // người mượn
    int quantity;              // số lượng
    int publishing_year;       // năm xuất bản
    string publishing_company; // công ty xuất bản

    Book() {}

    Book(string name,
         string au,
         string _code,
         string lang,
         string des,
         string _status,
         string borrow,
         int _quantity,
         int year,
         string company)
    {
        name_book = name;
        author = au;
        code = _code;
        language = lang;
        describe = des;
        borrower = borrow;
        quantity = _quantity;
        publishing_year = year;
        publishing_company = company;
    }

    void input_info_aBook()
    {
        fflush(stdin);
        cout << "Ten sach: ";
        getline(cin, name_book);
        cout << "Tac gia: ";
        getline(cin, author);
        cout << "Ma: ";
        getline(cin, code);
        cout << "Mo ta: ";
        getline(cin, describe);
        cout << "Ngon ngu: ";
        getline(cin, language);
        cout << "Trang thai: ";
        getline(cin, status);
        cout << "Nguoi muon: ";
        getline(cin, borrower);
        cout << "So luong: ";
        cin >> quantity;
        cout << "Nam xuat ban: ";
        cin >> (publishing_year);
        fflush(stdin);
        cout << "Nha xuat ban: ";
        getline(cin, publishing_company);
    }

} Book;

typedef struct aBook_node
{
    Book info;
    struct aBook_node *next;

    void display_aBook_node()
    {
        cout << "Ten sach: " << info.name_book << endl;
        cout << "Tac gia: " << info.author << endl;
        cout << "Ma: " << info.code << endl;
        cout << "Ngon ngu: " << info.language << endl;
        cout << "Mo ta: " << info.describe << endl;
        cout << "Trang thai: " << info.status << endl;
        cout << "Nguoi muon: " << info.borrower << endl;
        cout << "So luong: " << info.quantity << endl;
        cout << "Nam xuat ban: " << info.publishing_year << endl;
        cout << "Nha xuat ban: " << info.publishing_company << endl;
    }

} aBook_node;

aBook_node *getBook(Book x)
{
    aBook_node *cre = new aBook_node;
    if (!cre)
    {
        cout << "Cannot create a Book!" << endl;
        return NULL;
    }

    cre->info = x;
    cre->next = NULL;
    return cre;
}

typedef struct Book_List
{
    aBook_node *head_Book, *tail_Book;
} List;

void initBook_List(List &ls)
{
    ls.head_Book = ls.tail_Book = NULL;
}

int isEmpty_List_Book(List ls)
{
    return ls.head_Book == NULL ? 1 : 0;
}

void display_Book_list(Book_List ls)
{
    if (isEmpty_List_Book(ls))
    {
        cout << "The Book List is EMPTY!" << endl;
        return;
    }
    aBook_node *p = ls.head_Book;
    int i = 0;
    while (p != NULL)
    {
        cout << i << ". " << p->info.name_book << " CODE: " << p->info.code << endl;
        i++;
        p = p->next;
    }
}

int count_Books_inList(List ls)
{
    int c = 0;
    aBook_node *p = ls.head_Book;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

void add_BooksTail(List &ls, Book a)
{
    aBook_node *p = getBook(a);
    if (isEmpty_List_Book(ls))
    {
        ls.head_Book = ls.tail_Book = p;
        return;
    }
    ls.tail_Book->next = p;
    ls.tail_Book = p;
    return;
}

void input_info_BookList_byFile(Book &a)
{
    fstream fileBook;
    fileBook.open("Books.txt");
    if (fileBook.is_open())
    {
        getline(fileBook, a.name_book);
        getline(fileBook, a.author);
        getline(fileBook, a.code);
        getline(fileBook, a.language);
        getline(fileBook, a.describe);
        getline(fileBook, a.status);
        getline(fileBook, a.borrower);
        fileBook >> a.quantity;
        fileBook >> a.publishing_year;
        fileBook.ignore();
        getline(fileBook, a.publishing_company);
    }
    fileBook.close();
}
void menu();
int main()
{
    Book p;
    input_info_BookList_byFile(p);
    aBook_node *b = getBook(p);
    b->display_aBook_node();
    delete b;
    return 0;
}

void menu()
{
    cout << "1. Xem danh sach" << endl;
    cout << "2. Them sach" << endl;
    cout << "3. Xem chi tiet sach" << endl;
    cout << "4. Chinh sua sach" << endl;
    cout << "5. Xoa sach" << endl;
    cout << "6. Xoa danh sach" << endl;
}