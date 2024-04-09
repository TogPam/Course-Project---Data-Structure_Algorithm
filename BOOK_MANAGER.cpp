#include <bits/stdc++.h>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

typedef struct Book
{
    int stt;
    string name_book;          // tên sách
    string author;             // tác giả
    string code;               // mã
    string type;               // thể loại
    int publishing_year;       // năm xuất bản
    string publishing_company; // công ty xuất bản

    void input_info_aBook()
    {
        fflush(stdin);
        cout << "Ten sach: ";
        getline(cin, name_book);
        cout << "Tac gia: ";
        getline(cin, author);
        cout << "Ma: ";
        getline(cin, code);
        cout << "The loai: ";
        getline(cin, type);
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
        cout << "\n\tTen sach: " << info.name_book << endl;
        cout << "\tTac gia: " << info.author << endl;
        cout << "\tMa: " << info.code << endl;
        cout << "\tNam xuat ban: " << info.publishing_year << endl;
        cout << "\tNha xuat ban: " << info.publishing_company << endl;
        cout << "\n";
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
        cout << "\n\t(!)The Book List is EMPTY\n\n";
        return;
    }
    aBook_node *p = ls.head_Book;
    int i = 0;
    cout << "                                                           DANH SACH BOOKS\n";
    cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|STT|\n";
    while (p != NULL)
    {
        cout << "|" << i << " | " << p->info.name_book << "___TAC GIA: " << p->info.author << " ___LOAI: " << p->info.type << " __NHA XB: " << p->info.publishing_company << "__NXB: " << p->info.publishing_year << endl;
        p->info.stt = i;
        i++;
        p = p->next;
    }
    cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;
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
    if (!isEmpty_List_Book(ls))
    {
        cout << "\n\t(!)Da co danh sach roi\n";
        return;
    }
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
            fileBook >> a.publishing_year;
            fileBook.ignore();
            getline(fileBook, a.publishing_company);
            add_BooksTail(ls, a);
        }
    }
    fileBook.close();
}

void add_abook_intoFile_List(List &ls, Book a)
{

    a.input_info_aBook();
    add_BooksTail(ls, a);
    ofstream fileBook;
    fileBook.open("Books.txt", fstream::app);
    if (fileBook.is_open())
    {
        fileBook << endl;
        fileBook << a.name_book << endl;
        fileBook << a.author << endl;
        fileBook << a.code << endl;
        fileBook << a.type << endl;
        fileBook << a.publishing_year << endl;
        fileBook << a.publishing_company;
    }
    fileBook.close();
}

aBook_node *node_at_pos(List st, int x)
{
    aBook_node *p = st.head_Book;
    if (p->info.stt == x)
    {
        return p;
    }
    if (st.tail_Book->info.stt == x)
    {
        return st.tail_Book;
    }
    while (x != 0)
    {
        p = p->next;
        x--;
    }
    return p;
    return NULL;
}

void display_aBook_node_inList(List ls, int x)
{
    aBook_node *p = node_at_pos(ls, x);
    if (!p)
    {
        cout << "\n\t(!)Khong co stt nay\n"
             << endl;
        return;
    }
    p->display_aBook_node();
}

void deleteHead(List &ls)
{
    if (isEmpty_List_Book(ls))
        return;
    aBook_node *temp = ls.head_Book;
    ls.head_Book = ls.head_Book->next;
    temp = NULL;
    delete temp;
    return;
}

void deleteTail(List &ls)
{
    if (isEmpty_List_Book(ls))
        return;
    if (ls.head_Book == ls.tail_Book)
    {
        ls.head_Book = ls.tail_Book = NULL;
        return;
    }
    aBook_node *p = ls.head_Book;
    while (p != ls.tail_Book)
    {
        p = p->next;
    }
    aBook_node *temp = ls.tail_Book;
    ls.tail_Book = p;
    ls.tail_Book->next = NULL;
    delete temp;
    return;
}

void deleteP(List &ls, int stt)
{
    aBook_node *p = ls.head_Book;
    while (p->next->info.stt != stt)
    {
        p = p->next;
    }
    aBook_node *temp = p->next;
    p->next = temp->next;
    temp->next = NULL;
    delete temp;
    return;
}

void listToFile(List &ls)
{
    if (isEmpty_List_Book(ls))
    {
        cout << "\n\t(!)The Book List is EMPTY\n\n";
        return;
    }
    aBook_node *a = ls.head_Book;
    fstream fileBook;
    fileBook.open("Books.txt", ios::out);
    while (a != NULL)
    {
        if (fileBook.is_open())
        {
            fileBook << a->info.name_book << endl;
            fileBook << a->info.author << endl;
            fileBook << a->info.code << endl;
            fileBook << a->info.type << endl;
            fileBook << a->info.publishing_year << endl;
            fileBook << a->info.publishing_company << endl;
        }
        a = a->next;
    }
    fileBook.close();
}

void delete_aBookNode(List &ls, int stt)
{
    if (isEmpty_List_Book(ls))
        return;
    if (stt == 0)
    {
        deleteHead(ls);
        return;
    }
    if (stt == count_Books_inList(ls))
    {
        deleteTail(ls);
        return;
    }
    else
    {

        deleteP(ls, stt);
        return;
    }
    listToFile(ls);
}

void displayBook_baseType(List ls, string type)
{
    aBook_node *p = ls.head_Book;
    cout << "                                                           DANH SACH BOOKS\n";
    cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|STT|\n";
    while (p != NULL)
    {
        if (p->info.type == type)
        {
            cout << "|" << p->info.stt << " | " << p->info.name_book << "___TAC GIA: " << p->info.author << " ___NAM XB: " << p->info.publishing_year << " __NXB: " << p->info.publishing_company << endl;
        }
        p = p->next;
    }
    cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;
}

void menu();
int main()
{
    List ls;
    initBook_List(ls);
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
            cout << "\n\tCo " << count_Books_inList(ls) << " cuon sach" << endl;
            system("pause");
            break;
        }
        case 2:
        {
            input_info_BookList_byFile(ls);
            cout << "\n\tDa them danh sach tu FILE\n";
            display_Book_list(ls);
            cout << "\n\tCo " << count_Books_inList(ls) << " cuon sach" << endl;
            system("pause");
            break;
        }
        case 3:
        {
            Book a;
            add_abook_intoFile_List(ls, a);
            system("pause");
            break;
        }
        case 4:
        {
            if (!isEmpty_List_Book(ls))
            {

                display_Book_list(ls);
                int stt;
                cout << "\n\tSTT SACH(?): ";
                cin >> stt;
                display_aBook_node_inList(ls, stt);
            }
            system("pause");
            break;
        }
        case 5:
        {
            if (!isEmpty_List_Book(ls))
            {
                cout << "\n\t1.Tieu Thuyet\n";
                cout << "\t2.Hoc Thuat\n";
                cout << "\t3.Self-help\n";
                cout << "\t4.Gia Tuong\n\n";
                int t;
                cout << "\t\t(?)Chon: ";
                cin >> t;
                switch (t)
                {
                case 1:
                {
                    displayBook_baseType(ls, "Tieu Thuyet");
                    break;
                }
                case 2:
                {
                    displayBook_baseType(ls, "Hoc Thuat");
                    break;
                }
                case 3:
                {
                    displayBook_baseType(ls, "Self-help");
                    break;
                }
                case 4:
                {
                    displayBook_baseType(ls, "Gia Tuong");
                    break;
                }
                }
            }
            system("pause");
            break;
        }
        case 7:
        {
            break;
        }
        case 6:
        {
            display_Book_list(ls);
            if (!isEmpty_List_Book(ls))
            {

                int stt;
                cout << "\n\t(*)LUU Y: VIEC XOA SACH SE ANH HUONG DEN FILE\n";
                cout << "\n\t(?)STT SACH MUON XOA: ";
                cin >> stt;
                delete_aBookNode(ls, stt);
            }
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
    cout << "\t+-------------------------+" << endl;
    cout << "\t|1. Xem danh sach         |" << endl;
    cout << "\t|2. Them sach tu FILE     |" << endl;
    cout << "\t|3. Them sach tu ban phim |" << endl;
    cout << "\t|4. Xem chi tiet sach     |" << endl;
    cout << "\t|5. Danh sach phan loai   |" << endl;
    cout << "\t|6. Xoa sach              |" << endl;
    cout << "\t|7. Xoa danh sach         |" << endl;
    cout << "\t|  0. THOAT               |" << endl;
    cout << "\t+-------------------------+" << endl;
}