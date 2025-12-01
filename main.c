#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdint.h>
#include <ctype.h>

typedef struct {
    char mssv[10];
    char *hoTen;
    float diemToan, diemLy, diemHoa, diemTrungBinh;
} SinhVien;

// Con trỏ cấp 2 lưu địa chỉ con trỏ cấp 1

void normalizeName(char *str){
    if (str == NULL) return;

    char *temp = (char*)malloc(strlen(str) + 1);

    if (temp == NULL){
        printf("Loi cap phat bo nho!\n");
        return;
    }
    int i = 0, j = 0, firstChar = 1;
    // dem khoang trang dau dong
    while(str[i] == ' ') i++;
    while(str[i] != '\0'){
        if (str[i] != ' '){
            if (firstChar == 1){
                temp[j++] = toupper(str[i]);
                firstChar = 0;
            }
            else temp[j++] = tolower(str[i]);
            i++;
        }
        else{
            if (!firstChar){
                temp[j++] = ' ';
                firstChar = 1;
            }
            i++;
        }
    }

    // xóa khoảng trắng ở cuối, chẳng hạn Lý(space), j đứng sau space
    if (j > 0 && temp[j - 1] == ' ') j--;
    temp[j] = '\0';

    strcpy(str, temp); // dùng mảng (char p[] = "abc") mới có thể dùng strcpy
    free(temp);    
}

void createStudent(SinhVien **sv, int *p){
    int new_n = *p + 1;
    SinhVien *temp = (SinhVien*)realloc(*sv, new_n * sizeof(SinhVien));

    if (temp == NULL){
        printf("Loi cap phat RAM!\n");
        return;
    }

    *sv = temp;
    SinhVien *svMoi = &(*sv)[*p]; // lay dia chi phan tu thu p trong mang danhsach
    printf("\n---Nhap thong tin sinh vien thu %d ---\n", new_n);
    printf("Nhap MSSV: "); scanf("%s", svMoi -> mssv); // tuong duong danhSach[n].mssv

    while(getchar() != '\n');

    char buffer[100];
    printf("Nhap ho ten: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL){
        buffer[strcspn(buffer, "\n")] = '\0'; // xoa ki tu xuong dong
        svMoi -> hoTen = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        if (svMoi -> hoTen == NULL){
            printf("Lỗi cấp phát bộ nhớ !\n");
            return;
        }
        strcpy(svMoi -> hoTen, buffer);
        normalizeName(buffer);
    }

    printf("Nhap diem Toan, Ly, Hoa: ");
    scanf("%f %f %f", &svMoi -> diemToan, &svMoi -> diemLy, &svMoi -> diemHoa);

    svMoi -> diemTrungBinh = (svMoi -> diemToan + svMoi -> diemLy + svMoi -> diemHoa) / 3.0;
    (*p)++;
    printf("-> Them thanh cong! (Ten : %s, Bo nho ten: %zu bytes)\n", svMoi -> hoTen, strlen(svMoi -> hoTen) + 1);
    
}

void readList(SinhVien **sv, int *n){
    printf("%-10s | %-20s | %-6s | %-6s | %-6s | %-6s\n", 
           "MSSV", "Ho Ten", "Toan", "Ly", "Hoa", "DTB");
    puts("");
    printf("---------------------------------------------------------------");
    puts("");
    SinhVien *svPtr = *sv;
    for (int i = 0; i < *n; ++i){
        printf("%-10s | %-20s | %-6.1f | %-6.1f | %-6.1f | %-6.2f\n", svPtr -> mssv, svPtr -> hoTen, svPtr -> diemToan, 
            svPtr -> diemLy, svPtr -> diemHoa, svPtr -> diemTrungBinh);
    }
    
}

void readAndSearch(SinhVien **sv, int n){
    // Hàm tìm kiếm theo tên
    char c[30];
    printf("Nhap ten muon tim kiem: ");
    if (fgets(c, sizeof(c), stdin) != NULL){
        c[strcspn(c, "\n")] = '\0';
    }
    int found = 0;
    for (int i = 0; i < n; ++i){
        char *p = strstr((*sv)[i].hoTen, c);
        if (p != NULL){
            found = 1;
            printf("Tim thay sinh vien tuong tu: %s %s", (*sv)[i].mssv, (*sv)[i].hoTen);
        }
    }
    if (found == 0){
        printf("Khong tim thay sinh vien tuong tu!");
    }
}

void updateList(SinhVien **sv, int n){
    SinhVien *svPtr = *sv;
    printf("Nhap MSSV can chinh sua: ");
    char c[20]; scanf("%s", c);

    while(getchar() != '\n');

    // Duyệt tìm xem có xuất hiện MSSV này không
    int found = 0;
    SinhVien *indexFound = NULL; // con trỏ này lưu địa chỉ của MSSV được tìm thấy trong struct
    for (int i = 0; i < n; ++i){
        if (strcmp((*sv)[i].mssv, c) == 0){
            found = 1;
            indexFound = &(*sv)[i]; // indexFound là con trỏ lưu địa chỉ của sv[i];
            break;
        }
    }
    if (found == 1){
        printf("-> Tim thay MSSV : %s!\n", indexFound -> hoTen);
        printf("Nhap lai diem cac mon Toan, Ly, Hoa: ");
        scanf("%f %f %f", &indexFound -> diemToan, &indexFound -> diemLy, &indexFound -> diemHoa);
        indexFound -> diemTrungBinh = (indexFound -> diemToan + indexFound -> diemLy + indexFound -> diemHoa) / 3.0;
        
        printf("Diem cac mon Toan, Ly, Hoa la: "); 
        printf("%.f %.f %.f\n", indexFound -> diemToan, indexFound -> diemLy, indexFound -> diemHoa);
        printf("Diem trung binh sau khi cap nhat: "); printf("%.f\n", indexFound -> diemTrungBinh);
        while(getchar() != '\n'); // sau khi nhap so thi xoa bo dem
        printf("Sua ten (1 : Co, 2 : Khong) ?\n");
        int request; scanf("%d", &request);
        while(getchar() != '\n');
        if (request == 1){
            char buffer[100];
            printf("Nhap lai ho va ten: ");
            if (fgets(buffer, sizeof(buffer), stdin) != NULL){
                buffer[strcspn(buffer, "\n")] = '\0';
                free(indexFound -> hoTen);
                indexFound -> hoTen = (char *)malloc(strlen(buffer) + 1 * sizeof(char));
                if (indexFound -> hoTen == NULL){
                    printf("Loi cap phat bo nho!\n");
                    return;
                }
                strcpy(indexFound -> hoTen, buffer);
                normalizeName(buffer);
                printf("Cap nhat thanh cong! Ho va ten moi la : %s\n", indexFound -> hoTen);
            }
        }
        printf("Cap nhat thong tin hoan tat!!!\n");
    }
    else printf("Khong tim thay MSSV nay! \n");
}

void deleteList(SinhVien **sv, int *n){
    char c[30];
    printf("Nhap MSSV can xoa: ");
    scanf("%s", c);
    while(getchar() != '\n');
    int k = -1;
    for (int i = 0; i < *n; ++i){
        if (strcmp((*sv)[i].mssv, c) == 0){
            k = i;
            break;
        }
    }
    if (k != -1){
        printf("Tim thay MSSV can xoa %s, dang tien hanh xoa...\n", (*sv)[k].mssv);
        free((*sv)[k].hoTen);
        for (int i = k; i < *n - 1; ++i){
            (*sv)[i] = (*sv)[i + 1];

        }
        int new_n = *n - 1;
        if (new_n > 0){
            SinhVien *Ptr = (SinhVien*)realloc(*sv, new_n * sizeof(SinhVien));

            if (Ptr != NULL) *sv = Ptr;
            else printf("Loi cap phat bo nho realloc.\n");

        }
        else{
            free(*sv);
            *sv = NULL;
        }
        (*n)--;
        printf("Xoa thanh cong!\n");
    }
    else printf("Khong tim thay MSSV %s!\n", c);
}

void swap(SinhVien *sv1, SinhVien *sv2){
    SinhVien Ptr = *sv1;
    *sv1 = *sv2; *sv2 = Ptr;
}

void sortList(SinhVien **sv, int n){
    for (int i = 0; i < n - 1; ++i){
        for (int j = i + 1; j < n; ++j){
            if ((*sv)[i].diemTrungBinh < (*sv)[j].diemTrungBinh){
                swap(&(*sv)[i], &(*sv)[j]);
            }
        }
    }
    printf("Da sap xep danh sach theo thu tu giam dan diem trung binh!\n");
}

void cleanUpList(SinhVien **sv, int n){
    for (int i = 0; i < n; ++i){
        if ((*sv)[i].hoTen != NULL)
            free((*sv)[i].hoTen);
    }
    if (*sv != NULL){
        free(*sv);
        *sv = NULL;
    }
    
    printf("Da clean up bo nho thanh cong!!\n");
}

int main(void){

    //srand(time(NULL));
    SinhVien *danhSach = NULL;
    int n = 0;

    printf("------He thong quan ly sinh vien------\n");
    printf("========================================\n");
    int flag = 1;
    while(flag == 1){
        printf("\n--- MENU ---\n");
        printf("1. Them sinh vien\n");
        printf("2. Xem danh sach\n");
        printf("3. Tim kiem\n");
        printf("4. Cap nhat\n");
        printf("5. Xoa\n");
        printf("6. Sap xep\n");
        printf("7. Thoat (Clean Up)\n");
        printf("Lua chon cua ban: ");
        int request; scanf("%d", &request);
        switch(request){
            case 1: createStudent(&danhSach, &n); break;
            case 2: readList(&danhSach, &n); break;
            case 3: readAndSearch(&danhSach, n); break;
            case 4: updateList(&danhSach, n); break;
            case 5: deleteList(&danhSach, &n); break;
            case 6: sortList(&danhSach, n); break;
            case 7:
                cleanUpList(&danhSach, n);
                flag = 0;
                break;
            default: 
                printf("Lua chon khong hop le, chuong trinh se don dep bo nho va thoat..\n");
                cleanUpList(&danhSach, n);
                flag = 0;
                break;
        }
    }
    // danhSach la con tro cap 1, muon luu dia chi cua no dung con tro cap 2 (**sv)
    //readList(&danhSach, &n);
    
    return 0;
}