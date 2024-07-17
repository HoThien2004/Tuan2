#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int phanNguyen;
    int tuSo;
    int mauSo;
} HonSo;

// Hàm tạo hỗn số ngẫu nhiên
HonSo taoHonSoNgauNhien() {
    HonSo hs;
    hs.phanNguyen = rand() % 10; // Phần nguyên từ 0 đến 9
    hs.tuSo = rand() % 10;       // Tử số từ 0 đến 9
    hs.mauSo = rand() % 9 + 1;   // Mẫu số từ 1 đến 9 (không bằng 0)
    return hs;
}

// Hàm tạo mảng hỗn số ngẫu nhiên
void taoMangHonSo(HonSo b[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        b[i] = taoHonSoNgauNhien();
    }
}

// Hàm xuất danh sách hỗn số
void xuatDanhSachHonSo(HonSo b[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %d/%d\n", b[i].phanNguyen, b[i].tuSo, b[i].mauSo);
    }
}

// Hàm so sánh 2 hỗn số
int soSanhHonSo(HonSo a, HonSo b) {
    int giaTriA = a.phanNguyen * b.mauSo * a.mauSo + a.tuSo * b.mauSo;
    int giaTriB = b.phanNguyen * a.mauSo * b.mauSo + b.tuSo * a.mauSo;
    if (giaTriA < giaTriB) return -1;
    if (giaTriA > giaTriB) return 1;
    return 0;
}

// Hàm chuyển hỗn số thành phân số
void chuyenHonSoThanhPhanSo(HonSo hs, int *tuSo, int *mauSo) {
    *tuSo = hs.phanNguyen * hs.mauSo + hs.tuSo;
    *mauSo = hs.mauSo;
}

// Hàm chuyển phân số thành hỗn số
HonSo chuyenPhanSoThanhHonSo(int tuSo, int mauSo) {
    HonSo hs;
    hs.phanNguyen = tuSo / mauSo;
    hs.tuSo = tuSo % mauSo;
    hs.mauSo = mauSo;
    return hs;
}

// Hàm tính tổng 2 hỗn số
HonSo tongHonSo(HonSo a, HonSo b) {
    int tuSoA, mauSoA, tuSoB, mauSoB;
    chuyenHonSoThanhPhanSo(a, &tuSoA, &mauSoA);
    chuyenHonSoThanhPhanSo(b, &tuSoB, &mauSoB);
    int tuSoTong = tuSoA * mauSoB + tuSoB * mauSoA;
    int mauSoTong = mauSoA * mauSoB;
    return chuyenPhanSoThanhHonSo(tuSoTong, mauSoTong);
}

// Hàm tính hiệu 2 hỗn số
HonSo hieuHonSo(HonSo a, HonSo b) {
    int tuSoA, mauSoA, tuSoB, mauSoB;
    chuyenHonSoThanhPhanSo(a, &tuSoA, &mauSoA);
    chuyenHonSoThanhPhanSo(b, &tuSoB, &mauSoB);
    int tuSoHieu = tuSoA * mauSoB - tuSoB * mauSoA;
    int mauSoHieu = mauSoA * mauSoB;
    return chuyenPhanSoThanhHonSo(tuSoHieu, mauSoHieu);
}

// Hàm tính tích 2 hỗn số
HonSo tichHonSo(HonSo a, HonSo b) {
    int tuSoA, mauSoA, tuSoB, mauSoB;
    chuyenHonSoThanhPhanSo(a, &tuSoA, &mauSoA);
    chuyenHonSoThanhPhanSo(b, &tuSoB, &mauSoB);
    int tuSoTich = tuSoA * tuSoB;
    int mauSoTich = mauSoA * mauSoB;
    return chuyenPhanSoThanhHonSo(tuSoTich, mauSoTich);
}

// Hàm tính thương 2 hỗn số
HonSo thuongHonSo(HonSo a, HonSo b) {
    int tuSoA, mauSoA, tuSoB, mauSoB;
    chuyenHonSoThanhPhanSo(a, &tuSoA, &mauSoA);
    chuyenHonSoThanhPhanSo(b, &tuSoB, &mauSoB);
    int tuSoThuong = tuSoA * mauSoB;
    int mauSoThuong = mauSoA * tuSoB;
    return chuyenPhanSoThanhHonSo(tuSoThuong, mauSoThuong);
}

// Hàm sắp xếp mảng tăng dần (Bubble Sort)
void sapXepTangDan(HonSo b[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (soSanhHonSo(b[j], b[j + 1]) > 0) {
                HonSo temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
}

// Hàm sắp xếp mảng giảm dần (Bubble Sort)
void sapXepGiamDan(HonSo b[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (soSanhHonSo(b[j], b[j + 1]) < 0) {
                HonSo temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n = 5; // Số lượng phần tử trong mảng
    HonSo b[n];

    // Tạo mảng hỗn số ngẫu nhiên
    taoMangHonSo(b, n);

    // Xuất danh sách hỗn số
    printf("Danh sach hon so:\n");
    xuatDanhSachHonSo(b, n);

    // Sắp xếp tăng dần
    sapXepTangDan(b, n);
    printf("\nDanh sach hon so sau khi sap xep tang dan:\n");
    xuatDanhSachHonSo(b, n);

    // Sắp xếp giảm dần
    sapXepGiamDan(b, n);
    printf("\nDanh sach hon so sau khi sap xep giam dan:\n");
    xuatDanhSachHonSo(b, n);

    return 0;
}
