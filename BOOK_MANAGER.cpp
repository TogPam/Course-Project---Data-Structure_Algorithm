#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

typedef struct Book
{
    char name_book[30];          // tên sách
    char author[20];             // tác giả
    int publishing_year;         // năm xuất bản
    char publishing_company[20]; // công ty xuất bản
    int quatity;                 // số lượng
    char status[15];             // trạng thái
    char describe[150];          // mô tả
    char code[15];               // mã
    char language[10];           // ngôn ngữ
    char borrower[20];           // người mượn
} Book;

typedef struct aBook_node
{
    Book info;
    struct aBook_node *next;
} aBook_node;

aBook_node *getBook(Book x)
{
    aBook_node *cre = (aBook_node *)malloc(sizeof(aBook_node));
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

void display_aBook_node(aBook_node *a)
{
    cout << "Ten sach: " << a->info.name_book << endl;
    cout << "Tac gia :" << a->info.author << endl;
    cout << "Ma: " << a->info.code << endl;
    cout << "Mo ta: " << a->info.describe << endl;
    cout << "Ngon ngu: " << a->info.language << endl;
    cout << "Trang thai: " << a->info.status << endl;
    cout << "Nguoi muon: " << a->info.borrower << endl;
    cout << "So luong: " << a->info.quatity << endl;
    cout << "Nam xuat ban: " << a->info.publishing_year << endl;
    cout << "Nha xuat ban: " << a->info.publishing_company << endl;
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

void input_info_aBook(Book &a)
{
    // fflush(std);
    cout << "Ten sach: ";
    gets(a.name_book);
    cout << "Tac gia :";
    gets(a.author);
    cout << "Ma: ";
    gets(a.code);
    cout << "Mo ta: ";
    gets(a.describe);
    cout << "Ngon ngu: ";
    gets(a.language);
    cout << "Trang thai: ";
    gets(a.status);
    cout << "Nguoi muon: ";
    gets(a.borrower);
    cout << "So luong: ";
    cin >> a.quatity;
    cout << "Nam xuat ban: ";
    cin >> (a.publishing_year);
    fflush(stdin);
    cout << "Nha xuat ban: ";
    gets(a.publishing_company);
    // return a;
}

int main()
{
    Book temp;
    input_info_aBook(temp);
    aBook_node *a = getBook(temp);
    cout << endl;
    display_aBook_node(a);
    delete a;
    return 0;
}