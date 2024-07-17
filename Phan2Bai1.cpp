#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hàm tạo mảng ngẫu nhiên với n phần tử lớn hơn hoặc bằng 15
void taoMangNgauNhien(int a[], int n) {
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        a[i] = rand() % 100; // Số ngẫu nhiên từ 0 đến 99
    }
}

// Hàm tạo mảng chứa toàn số chẵn
void taoMangSoChan(int a[], int n, int b[], int *m) {
    *m = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] % 2 == 0) {
            b[*m] = a[i];
            (*m)++;
        }
    }
}

// Hàm tìm kiếm tuyến tính
int timKiemTuyenTinh(int a[], int n, int x) {
    for(int i = 0; i < n; i++) {
        if(a[i] == x) {
            return i; // Trả về vị trí của x
        }
    }
    return -1; // Không tìm thấy x
}

// Hàm sắp xếp Interchange Sort
void sapXepInterchangeSort(int a[], int n, int tangDan) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if((tangDan && a[i] > a[j]) || (!tangDan && a[i] < a[j])) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

// Hàm tìm kiếm nhị phân
int timKiemNhiPhan(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(a[mid] == x) {
            return mid; // Trả về vị trí của x
        }
        if(a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Không tìm thấy x
}

// Hàm sắp xếp Selection Sort
void sapXepSelectionSort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[minIdx]) {
                minIdx = j;
            }
        }
        int temp = a[minIdx];
        a[minIdx] = a[i];
        a[i] = temp;
    }
}

// Hàm sắp xếp Quick Sort
void sapXepQuickSort(int a[], int left, int right) {
    if(left >= right) return;
    int i = left, j = right, pivot = a[(left + right) / 2];
    while(i <= j) {
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;
        if(i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    sapXepQuickSort(a, left, j);
    sapXepQuickSort(a, i, right);
}

// Hàm in mảng
void inMang(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n = 15;
    int a[n];
    taoMangNgauNhien(a, n);

    printf("Mang ngau nhien: ");
    inMang(a, n);

    int b[n], m;
    taoMangSoChan(a, n, b, &m);

    printf("Mang so chan: ");
    inMang(b, m);

    int x = 50;
    int pos = timKiemTuyenTinh(a, n, x);
    if(pos != -1) {
        printf("Tim thay %d tai vi tri %d\n", x, pos);
    } else {
        printf("Khong tim thay %d\n", x);
    }

    sapXepInterchangeSort(a, n, 1);
    printf("Mang sap xep tang dan (Interchange Sort): ");
    inMang(a, n);

    pos = timKiemNhiPhan(a, n, x);
    if(pos != -1) {
        printf("Tim thay %d tai vi tri %d (Binary Search)\n", x, pos);
    } else {
        printf("Khong tim thay %d (Binary Search)\n", x);
    }

    sapXepSelectionSort(a, n);
    printf("Mang sap xep tang dan (Selection Sort): ");
    inMang(a, n);

    sapXepQuickSort(a, 0, n - 1);
    printf("Mang sap xep tang dan (Quick Sort): ");
    inMang(a, n);

    return 0;
}
