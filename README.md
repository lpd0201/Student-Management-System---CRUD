# 🎓 Student Management System (Hệ thống Quản lý Sinh viên)

![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)

> Console viết bằng ngôn ngữ C để tự luyện tập về cấp phát bộ nhớ động, con trỏ, các thao tác với Struct và các thao tác với Github.

## ✨ Tính năng chính (Features)

Chương trình bao gồm các chức năng CRUD (Create, Read, Update, Delete) hoàn chỉnh:

- [x] **Thêm sinh viên mới:** Tự động mở rộng bộ nhớ (realloc) để chứa thêm dữ liệu.
- [x] **Hiển thị danh sách:** In ra dạng bảng ngay ngắn, căn lề đẹp mắt.
- [x] **Tìm kiếm:** Tìm sinh viên theo tên (gần đúng).
- [x] **Cập nhật thông tin:** Sửa điểm số và tên (có xử lý cấp phát lại bộ nhớ cho tên mới).
- [x] **Xóa sinh viên:** Xóa theo MSSV, tự động dồn mảng và giải phóng bộ nhớ thừa.
- [x] **Sắp xếp:** Sắp xếp danh sách theo Điểm Trung Bình (Selection Sort).
- [x] **Quản lý bộ nhớ:** Cam kết không Memory Leak 

## 🛠️ Kỹ thuật sử dụng (Tech Stack)

Bài tập này được dùng để rèn kỹ năng xử lý bộ nhớ động là chủ yếu

* **Pointers & Double Pointers:** Sử dụng `**sv` để thay đổi địa chỉ mảng trong hàm con.
* **Dynamic Memory Management:** Sử dụng `malloc`, `calloc`, `realloc` và `free`.
* **Struct & Data Structures:** Mảng cấu trúc động.
* **String Manipulation:** Xử lý chuỗi, chuẩn hóa tên (Normalize Name).
* **Defensive Programming:** Kiểm tra `NULL` sau khi cấp phát, xử lý trôi lệnh `stdin`.

## 🚀 Hướng dẫn cài đặt & Chạy (Installation)

1.  **Clone dự án:**
    ```bash
    git clone [https://github.com/TenCuaBan/Student-Management-System-C.git](https://github.com/TenCuaBan/Student-Management-System-C.git)
    ```
2.  **Di chuyển vào thư mục:**
    ```bash
    cd Student-Management-System-C
    ```
3.  **Biên dịch (Compile) bằng GCC:**
    ```bash
    gcc main.c -o student_manager
    ```
4.  **Chạy chương trình:**
    * Windows: `.\student_manager.exe`
    * Linux/Mac: `./student_manager`


## 📞 Liên hệ
📧 **Email:** [25139008@student.hcmute.edu.vn]
