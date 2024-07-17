#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char hoTen[50];
    float diemTB;
    char xepLoai[20];
} SinhVien;

void nhapSinhVien(SinhVien *sv) {
    printf("Nhap ho ten: ");
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
    sv->hoTen[strcspn(sv->hoTen, "\n")] = '\0'; 
    printf("Nhap diem trung binh: ");
    scanf("%f", &sv->diemTB);
    getchar(); 

    // X?p lo?i
    if (sv->diemTB >= 8.0) strcpy(sv->xepLoai, "Gioi");
    else if (sv->diemTB >= 6.5) strcpy(sv->xepLoai, "Kha");
    else if (sv->diemTB >= 5.0) strcpy(sv->xepLoai, "Trung Binh");
    else strcpy(sv->xepLoai, "Yeu");
}

void xuatSinhVien(SinhVien sv) {
    printf("Ho ten: %s\n", sv.hoTen);
    printf("Diem trung binh: %.2f\n", sv.diemTB);
    printf("Xep loai: %s\n", sv.xepLoai);
}

void sapXepDiemTangDan(SinhVien a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].diemTB > a[j].diemTB) {
                SinhVien temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void sapXepDiemGiamDan(SinhVien a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].diemTB < a[j].diemTB) {
                SinhVien temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

SinhVien timDiemTBCaoNhat(SinhVien a[], int n) {
    SinhVien max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i].diemTB > max.diemTB) {
            max = a[i];
        }
    }
    return max;
}

SinhVien timDiemTBThapNhat(SinhVien a[], int n) {
    SinhVien min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i].diemTB < min.diemTB) {
            min = a[i];
        }
    }
    return min;
}

void inSinhVienGioiKha(SinhVien a[], int n) {
    printf("Danh sach sinh vien xep loai Gioi va Kha:\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].xepLoai, "Gioi") == 0 || strcmp(a[i].xepLoai, "Kha") == 0) {
            xuatSinhVien(a[i]);
        }
    }
}

int demSinhVienHoNguyen(SinhVien a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strncmp(a[i].hoTen, "Nguyen", 6) == 0) {
            count++;
        }
    }
    return count;
}

void menu() {
    printf("1. Nhap danh sach sinh vien\n");
    printf("2. Xuat danh sach sinh vien\n");
    printf("3. Sap xep danh sach sinh vien tang dan theo diem TB\n");
    printf("4. Sap xep danh sach sinh vien giam dan theo diem TB\n");
    printf("5. Tim sinh vien co diem TB cao nhat\n");
    printf("6. Tim sinh vien co diem TB thap nhat\n");
    printf("7. In danh sach sinh vien xep loai Gioi va Kha\n");
    printf("8. Dem so luong sinh vien ho Nguyen\n");
    printf("0. Thoat\n");
}

int main() {
    SinhVien danhSach[MAX];
    int n = 0;
    int luaChon;

    do {
        menu();
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);
        getchar(); 

        switch (luaChon) {
            case 1:
                printf("Nhap so luong sinh vien: ");
                scanf("%d", &n);
                getchar(); 
                for (int i = 0; i < n; i++) {
                    printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
                    nhapSinhVien(&danhSach[i]);
                }
                break;
            case 2:
                printf("Danh sach sinh vien:\n");
                for (int i = 0; i < n; i++) {
                    xuatSinhVien(danhSach[i]);
                }
                break;
            case 3:
                sapXepDiemTangDan(danhSach, n);
                printf("Danh sach sinh vien sau khi sap xep tang dan theo diem TB:\n");
                for (int i = 0; i < n; i++) {
                    xuatSinhVien(danhSach[i]);
                }
                break;
            case 4:
                sapXepDiemGiamDan(danhSach, n);
                printf("Danh sach sinh vien sau khi sap xep giam dan theo diem TB:\n");
                for (int i = 0; i < n; i++) {
                    xuatSinhVien(danhSach[i]);
                }
                break;
            case 5: {
                SinhVien max = timDiemTBCaoNhat(danhSach, n);
                printf("Sinh vien co diem TB cao nhat:\n");
                xuatSinhVien(max);
                break;
            }
            case 6: {
                SinhVien min = timDiemTBThapNhat(danhSach, n);
                printf("Sinh vien co diem TB thap nhat:\n");
                xuatSinhVien(min);
                break;
            }
            case 7:
                inSinhVienGioiKha(danhSach, n);
                break;
            case 8:
                printf("So luong sinh vien ho Nguyen: %d\n", demSinhVienHoNguyen(danhSach, n));
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (luaChon != 0);

    return 0;
}
