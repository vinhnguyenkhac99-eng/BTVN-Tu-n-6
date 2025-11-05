#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(vector<int>& arr, int left, int mid, int right, int level) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    cout << "Sau khi merge (" << left << "," << mid << "," << right << "): ";
    printArray(arr);
}

void mergeSort(vector<int>& arr, int left, int right, int level = 0) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, level + 1);
    mergeSort(arr, mid + 1, right, level + 1);
    merge(arr, left, mid, right, level);
}

int main() {
    vector<int> arr = {38, 27, 43, 10, 56, 78, 90};
    int n = arr.size();

    cout << "Mang ban dau: ";
    printArray(arr);

    mergeSort(arr, 0, n - 1);

    cout << "\nMang sau khi sap xep: ";
    printArray(arr);

    cout << "\n--- Phan tich do phuc tap ---\n";
    cout << "Thoi gian (Time Complexity): O(n log n)\n";
    cout << "Khong gian (Space Complexity): O(n)\n";
    cout << "-> Merge Sort chia de tri, do moi buoc chia mang lam doi, co log2(n) muc.\n";
    cout << "   Moi muc can duyet het n phan tu de tron lai.\n";

    return 0;
}
