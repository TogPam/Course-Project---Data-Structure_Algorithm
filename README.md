# Đồ án qua môn -- Thực hiện chương trình quản lí sách HUIT
![image](https://github.com/user-attachments/assets/7c370e41-5ec6-413a-a69d-998ebf442daa)
> Sử dụng C/C++
> Sử dụng cấu trúc dữ liệu Linked List!
# Kết quả đánh giá hoàn thiện : 8.5/10

## File dữ liệu sách có cấu trúc như thế này:
![image](https://github.com/user-attachments/assets/2a4b36eb-4fd9-445c-9ad2-4a660315d1a5)
- Tên sách
- Tác giả
- Mã sách
- Thể loại
- Năm XB
- Nhà XB
## Tổ chức một book và book_node:
```c++
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
       ...
    }

} aBook_node;
```
## Tổ chức danh sách liên kết đơn để lưu trữ:
![image](https://github.com/user-attachments/assets/c4562ca8-22b7-4292-8c53-439e74ff4b50)
