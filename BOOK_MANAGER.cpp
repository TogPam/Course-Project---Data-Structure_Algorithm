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

bool isEmpty_List_Book(List ls)
{
    return ls.head_Book == NULL ? true : false;
}

void duyetList(List ls)
{
    if (isEmpty_List_Book(ls))
    {
        cout << "\n\t(!)DANH SACH RONG\n\n";
        return;
    }
    aBook_node *p = ls.head_Book;
    int i = 1;
    cout << "                                                                             DANH SACH BOOKS\n";
    cout << "+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|STT|                                                                                                                                                                    |\n";
    while (p != NULL)
    {
        cout << "|" << setw(3) << right << i << "| " << setw(40) << left << p->info.name_book
             << "| MA: " << setw(7) << left << p->info.code
             << "| TAC GIA: " << setw(22) << left << p->info.author
             << "| LOAI: " << setw(15) << left << p->info.type
             << "| NHA XB: " << setw(27) << left << p->info.publishing_company
             << "| NXB: " << setw(10) << left << p->info.publishing_year << "|" << endl;
        i++;
        p = p->next;
    }
    cout << "+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
}

int demSachTrongList(List ls)
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

void add_BooksHead(List &ls, Book a)
{
    aBook_node *p = getBook(a);
    if (isEmpty_List_Book(ls))
    {
        ls.head_Book = ls.tail_Book = p;
        return;
    }
    p->next = ls.head_Book;
    ls.head_Book = p;
    return;
}

void add_BooksAtK(List &ls, int stt, Book b)
{
    aBook_node *q = getBook(b);
    aBook_node *p = ls.head_Book;
    while (stt != 2)
    {
        p = p->next;
        stt--;
    }
    q->next = p->next;
    p->next = q;
    return;
}

void inputBookByFile(List &ls)
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

void themBookNodeVaoFileList(List &ls, Book a)
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
    while (p->next != ls.tail_Book)
    {
        p = p->next;
    }
    aBook_node *temp = p->next;
    temp = NULL;
    ls.tail_Book = p;
    p->next = NULL;
    delete temp;
    return;
}

void deleteP(List &ls, int stt)
{
    if (stt == 0)
    {
        deleteHead(ls);
        return;
    }
    if (stt == demSachTrongList(ls))
    {
        deleteTail(ls);
        return;
    }
    aBook_node *p = ls.head_Book;
    while (stt != 2)
    {
        p = p->next;
        stt--;
    }
    aBook_node *temp = p->next;
    p->next = temp->next;
    temp->next = NULL;
    delete temp;
    return;
}

void xoaBookNodeTrongList(List &ls, aBook_node *p)
{
    aBook_node *a = ls.head_Book;
    while (a->next != p)
    {
        a = a->next;
    }
    a->next = p->next;
    p->next = NULL;
    delete p;
}

void swap(Book &a, Book &b)
{
    Book temp = a;
    a = b;
    b = temp;
}

void sapXepTuyenTinh(List &ls)
{
    aBook_node *p = ls.head_Book;
    for (p; p != NULL; p = p->next)
    {
        for (aBook_node *pp = p->next; pp != NULL; pp = pp->next)
        {
            if (p->info.code > pp->info.code)
                swap(p->info, pp->info);
        }
    }
}

void sapXepTheoLoaiVaMa(List &ls)
{
    sapXepTuyenTinh(ls);
    List a;
    initBook_List(a);
    unordered_map<string, int> typeCount;

    aBook_node *pp = ls.head_Book;
    while (pp != NULL)
    {
        typeCount[pp->info.type]++;
        pp = pp->next;
    }

    for (auto it : typeCount)
    {
        // cout << it->first << ": " << it->second << endl;
        aBook_node *p = ls.head_Book;
        while (p != NULL)
        {
            if (p->info.type == it.first)
            {
                add_BooksTail(a, p->info);
            }
            p = p->next;
        }
    }
    ls = a;
}

void NXBCoItSachNhat(List ls)
{
    aBook_node *p = ls.head_Book;
    unordered_map<string, int> count;
    while (p != NULL)
    {
        count[p->info.publishing_company]++;
        p = p->next;
    }
    int min = count.begin()->second;
    for (auto it : count)
    {
        if (it.second <= min)
        {
            min = it.second;
        }
    }
    for (auto it : count)
    {
        if (it.second == min)
        {
            cout << it.first << "co: " << it.second << " quyen sach " << endl;
        }
    }
}

void thongKeSachTheoNXBCuaTacGia(List ls)
{
    unordered_map<string, unordered_map<string, int>> count;
    aBook_node *p = ls.head_Book;
    while (p != NULL)
    {
        count[p->info.author][p->info.publishing_company]++;
        p = p->next;
    }

    for (auto it : count)
    {
        cout << "Tac gia: " << it.first;
        for (auto itt : it.second)
        {
            cout << " co " << itt.second << " cuon sach o NXB " << itt.first << endl;
        }
    }
}

void thongKeSachTheoTungNamCuaTungNXB(List ls)
{
    unordered_map<int, unordered_map<string, int>> thongke;
    aBook_node *p = ls.head_Book;

    while (p != NULL)
    {
        thongke[p->info.publishing_year][p->info.publishing_company]++;
        p = p->next;
    }
    for (auto it : thongke)
    {
        cout << it.first << ": " << endl;
        for (auto itt : it.second)
        {
            cout << itt.first << " co: " << itt.second << " cuon sach " << endl;
        }
    }
}

void soLuongSachTheoTheLoai(List ls)
{
    unordered_map<string, int> count;
    aBook_node *p = ls.head_Book;
    while (p != NULL)
    {
        count[p->info.type]++;
        p = p->next;
    }
    for (auto it : count)
    {
        cout << it.first << " co " << it.second << " cuon sach!" << endl;
    }
}

void sachCoChuoiLapTrinh(List ls)
{
    aBook_node *p = ls.head_Book;
    while (p != NULL)
    {
        const char *name = p->info.name_book.c_str();
        string a = "lap trinh";
        char *tim = strstr(name, a.c_str());
        if (tim != NULL)
        {
            if (strcmp(p->info.publishing_company.c_str(), "DHQG") == 0 || strcmp(p->info.publishing_company.c_str(), "KHKT") == 0)
            {
                p->display_aBook_node();
            }
        }
        p = p->next;
    }
    cout << "\nNULL\n";
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
            duyetList(ls);
            cout << "\n\tCo " << demSachTrongList(ls) << " cuon sach" << endl;
            system("pause");
            break;
        }
        case 2:
        {
            int c;
            cout << "\n\n\t1. FILE\n";
            cout << "\t2. Ban Phim\n";
            cout << "\n\tChon: ";
            cin >> c;
            switch (c)
            {
            case 1:
            {
                inputBookByFile(ls);
                cout << "\n\tDa them danh sach tu FILE\n";
                duyetList(ls);
                cout << "\n\tCo " << demSachTrongList(ls) << " cuon sach" << endl;
                break;
            }
            case 2:
            {
                Book a;
                themBookNodeVaoFileList(ls, a);
                break;
            }
            }
            system("pause");
            break;
        }
        case 3:
        {
            duyetList(ls);
            int chon;
            cout << "\n\t1.Them\n";
            cout << "\t2.Xoa\n";
            cout << "\n\t(?)Chon: ";
            cin >> chon;
            cout << "\n\tVi tri:\n";
            cout << "\t1.Dau\n";
            cout << "\t2.Cuoi\n";
            cout << "\t3.Giua\n";
            cout << "\n\t(?)Chon: ";
            int vt;
            cin >> vt;
            switch (chon)
            {
            case 1:
            {
                switch (vt)
                {
                case 1:
                {
                    Book a;
                    a.input_info_aBook();
                    add_BooksHead(ls, a);
                    break;
                }
                case 2:
                {
                    Book a;
                    a.input_info_aBook();
                    add_BooksTail(ls, a);
                    break;
                }
                case 3:
                {
                    int stt;
                    cout << "\n\t(?)STT: ";
                    cin >> stt;
                    Book a;
                    a.input_info_aBook();
                    add_BooksAtK(ls, stt, a);
                    break;
                }
                }
                break;
            }
            case 2:
            {
                switch (vt)
                {
                case 1:
                {
                    deleteHead(ls);
                    break;
                }
                case 2:
                {
                    deleteTail(ls);
                    break;
                }
                case 3:
                {
                    int stt;
                    cout << "\n\t(?)STT: ";
                    cin >> stt;
                    deleteP(ls, stt);
                    break;
                }
                }

                break;
            }
            }
            system("pause");
            break;
        }
        case 4:
        {
            if (!isEmpty_List_Book(ls))
            {
                sapXepTheoLoaiVaMa(ls);
                duyetList(ls);
            }
            system("pause");
            break;
        }
        case 5:
        {
            Book a;
            a.input_info_aBook();
            add_BooksTail(ls, a);
            sapXepTheoLoaiVaMa(ls);
            break;
        }
        case 6:
        {
            thongKeSachTheoNXBCuaTacGia(ls);
            system("pause");
            break;
        }
        case 7:
        {
            NXBCoItSachNhat(ls);
            system("pause");
            break;
        }
        case 8:
        {
            thongKeSachTheoTungNamCuaTungNXB(ls);
            system("pause");
            break;
        }
        case 9:
        {
            soLuongSachTheoTheLoai(ls);
            system("pause");
            break;
        }
        case 10:
        {
            sachCoChuoiLapTrinh(ls);
            system("pause");
            break;
        }
        default:
            break;
        }
        system("cls");
    } while (c != 0);
    return 0;
}

void menu()
{
    cout << "\n\t\t\t\t                 BOOK MANAGER" << endl;
    cout << "\t+-------------------------------------------------------------------------------------------+" << endl;
    cout << "\t|1. Xem danh SACH                                                                           |" << endl;
    cout << "\t|2. Them SACH (File, ban phim)                                                              |" << endl;
    cout << "\t|3. Them/Xoa SACH tai vi tri                                                                |" << endl;
    cout << "\t|4. Sap xep theo loai va ma                                                                 |" << endl;
    cout << "\t|5. Them sach x vao danh sach da sap xep                                                    |" << endl;
    cout << "\t|6. Thong ke sach trong NXB cua tac gia                                                     |" << endl;
    cout << "\t|7. NXB co it sach nhat                                                                     |" << endl;
    cout << "\t|8. Thong ke sach theo tung nam cua tung NXB                                                |" << endl;
    cout << "\t|9. Dem so luong sach theo the loai                                                         |" << endl;
    cout << "\t|10.Co bao nhieu sach co chua chuoi `lap trinh` do NXB DHQG va NXB KHKT xuat ban, in sach ra|" << endl;
    cout << "\t|  0. THOAT                                                                                 |" << endl;
    cout << "\t+-------------------------------------------------------------------------------------------+" << endl;
}