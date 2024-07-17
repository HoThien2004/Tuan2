#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void lietKeSoNguyenTo(int a[], int n) {
    bool coSoNguyenTo = false;
    for (int i = 2; i < n; i++) {
        if (laSoNguyenTo(i)) {
            printf("%d ", i);
            coSoNguyenTo = true;
        }
    }
    if (!coSoNguyenTo) {
        printf("Không tồn tại số nguyên tố nào nhỏ hơn %d\n", n);
    }
}

int chuSoDauLe(int n) {
    while (n >= 10) {
        n /= 10;
    }
    return n % 2 != 0;
}

int tongChuSoDauLe(int a[], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        if (chuSoDauLe(a[i])) {
            tong += a[i];
        }
    }
    return tong;
}

void demSoLanXuatHien(int a[], int n) {
    int dem[100] = {0};
    for (int i = 0; i < n; i++) {
        dem[a[i]]++;
    }
    for (int i = 0; i < 100; i++) {
        if (dem[i] > 0) {
            printf("%d xuat hien %d lan\n", i, dem[i]);
        }
    }
}

void sapXepChanLe(int a[], int n) {
    int chan[100], le[100];
    int soChan = 0, soLe = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            chan[soChan++] = a[i];
        } else {
            le[soLe++] = a[i];
        }
    }

    for (int i = 0; i < soChan - 1; i++) {
        for (int j = i + 1; j < soChan; j++) {
            if (chan[i] > chan[j]) {
                int temp = chan[i];
                chan[i] = chan[j];
                chan[j] = temp;
            }
        }
    }

    for (int i = 0; i < soLe - 1; i++) {
        for (int j = i + 1; j < soLe; j++) {
            if (le[i] < le[j]) {
                int temp = le[i];
                le[i] = le[j];
                le[j] = temp;
            }
        }
    }

    int index = 0;
    for (int i = 0; i < soChan; i++) {
        a[index++] = chan[i];
    }
    for (int i = 0; i < soLe; i++) {
        a[index++] = le[i];
    }
}

void dayConGiamDaiNhat(int a[], int n) {
    int maxLength = 1, length = 1;
    int start = 0, end = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            length++;
            if (length > maxLength) {
                maxLength = length;
                end = i;
                start = i - maxLength + 1;
            }
        } else {
            length = 1;
        }
    }
    printf("Day con giam dai nhat: ");
    for (int i = start; i <= end; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int timSoNhoThu2(int a[], int n) {
    int min = a[0], secondMin = __INT_MAX__;
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            secondMin = min;
            min = a[i];
        } else if (a[i] > min && a[i] < secondMin) {
            secondMin = a[i];
        }
    }
    return secondMin;
}

void timPhanTuChuaChuSoX(int a[], int n, int x) {
    int chuSo1 = x / 10;
    int chuSo2 = x % 10;
    printf("Cac phan tu chua chu so %d: ", x);
    for (int i = 0; i < n; i++) {
        int temp = a[i];
        bool found1 = false, found2 = false;
        while (temp > 0) {
            int chuSo = temp % 10;
            if (chuSo == chuSo1) found1 = true;
            if (chuSo == chuSo2) found2 = true;
            temp /= 10;
        }
        if (found1 && found2) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

void sapXepChanTangLeGiuNguyen(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] % 2 == 0 && a[j] % 2 == 0 && a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void sapXepLeDauChanCuoi(int a[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        while (a[left] % 2 != 0 && left < right) left++;
        while (a[right] % 2 == 0 && left < right) right--;
        if (left < right) {
            int temp = a[left];
            a[left] = a[right];
            a[right] = temp;
        }
    }
}

// Hàm chính để kiểm tra các chức năng
int main() {
    int a[] = {12, 3, 7, 45, 23, 56, 78, 15};
    int n = sizeof(a) / sizeof(a[0]);
    
    // 1. Liệt kê các số nguyên tố nhỏ hơn 50
    printf("Cac so nguyen to nho hon 50: ");
    lietKeSoNguyenTo(a, 50);
    printf("\n");

    // 2. Tính tổng các phần tử có chữ số đầu là chữ số lẻ
    printf("Tong cac phan tu co chu so dau la chu so le: %d\n", tongChuSoDauLe(a, n));

    // 3. Liệt kê số lần xuất hiện của các phần tử trong mảng
    printf("So lan xuat hien cua cac phan tu trong mang:\n");
    demSoLanXuatHien(a, n);

    // 4. Sắp xếp mảng có số chẵn tăng dần, số lẻ giảm dần
    printf("Sap xep mang co so chan tang dan, so le giam dan: ");
    sapXepChanLe(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // 5. Tìm dãy con giảm dài nhất
    dayConGiamDaiNhat(a, n);

    // 6. Tìm số nhỏ thứ 2 trong mảng
    printf("So nho thu 2 trong mang: %d\n", timSoNhoThu2(a, n));

    // 7. Tìm phần tử có chứa chữ số của x
    timPhanTuChuaChuSoX(a, n, 28);

    // 8. Sắp xếp mảng sao cho các phần tử chẵn tăng dần, các phần tử lẻ giữ nguyên vị trí
    printf("Sap xep mang chan tang dan, le giu nguyen: ");
    sapXepChanTangLeGiuNguyen(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // 9. Sắp xếp mảng: số lẻ ở đầu mảng, số chẵn ở cuối mảng
    printf("Sap xep mang: le o dau, chan o cuoi: ");
    sapXepLeDauChanCuoi(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
