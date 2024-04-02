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
    string type;               // thể loại
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
         string _type,
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
        type = _type;
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
        cout << "The loai: ";
        getline(cin, type);
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
        cout << "The loai: " << info.type << endl;
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

void display_Book_list(List ls)
{
    if (isEmpty_List_Book(ls))
    {
        cout << "The Book List is EMPTY!" << endl;
        return;
    }
    aBook_node *p = ls.head_Book;
    int i = 0;
    cout << "                                          DANH SACH BOOKS\n";
    cout << "+-----------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|STT|\n";
    while (p != NULL)
    {
        cout << "|  " << i << "| " << p->info.name_book << "___CODE: " << p->info.code << "___TYPE: " << p->info.type << endl;
        i++;
        p = p->next;
    }
    cout << "+-----------------------------------------------------------------------------------------------------------+" << endl;
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

void input_info_BookList_byFile(List &ls)
{
    ifstream fileBook;
    fileBook.open("Books.txt");
    Book a;
    string line;
    if (fileBook.is_open())
    {
        while (getline(fileBook, line))
        {
            a.name_book = line;
            getline(fileBook, a.author);
            getline(fileBook, a.code);
            getline(fileBook, a.type);
            getline(fileBook, a.describe);
            getline(fileBook, a.status);
            getline(fileBook, a.borrower);
            fileBook >> a.quantity;
            fileBook >> a.publishing_year;
            fileBook.ignore();
            getline(fileBook, a.publishing_company);
            add_BooksTail(ls, a);
        }
    }
    fileBook.close();
}

aBook_node *node_at_pos(List st, int x)
{
}

void display_aBook_node_inList(List ls, int x)
{
}
void menu();
int main()
{
    List ls;
    initBook_List(ls);
    input_info_BookList_byFile(ls);
    int c;
    do
    {
        menu();
        cout << "\n\tChon(?): ";
        cin >> c;
        switch (c)
        {
        case 1:
        {
            display_Book_list(ls);
            cout << "Co " << count_Books_inList(ls) << " cuon sach" << endl;
            system("pause");
            break;
        }
        case 3:
        {
            display_Book_list(ls);
            int stt;
            cout << "\n\tSTT(?): ";
            cin >> stt;
            display_aBook_node_inList(ls, stt);
            system("pause");
            break;
        }
        }
        system("cls");
    } while (c != 0);
    return 0;
}

void menu()
{
    cout << "\n\t      BOOK MANAGER" << endl;
    cout << "\t+----------------------+" << endl;
    cout << "\t|1. Xem danh sach      |" << endl;
    cout << "\t|2. Them sach          |" << endl;
    cout << "\t|3. Xem chi tiet sach  |" << endl;
    cout << "\t|4. Chinh sua sach     |" << endl;
    cout << "\t|5. Xoa sach           |" << endl;
    cout << "\t|6. Xoa danh sach      |" << endl;
    cout << "\t+----------------------+" << endl;
}