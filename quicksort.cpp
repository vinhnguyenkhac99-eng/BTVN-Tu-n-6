#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high, int step) {
    int pivot = arr[high];  
    int i = low - 1;

    cout << "\n--- Buoc " << step << " ---";
    cout << "\nPivot = " << pivot << endl;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
        
        cout << "arr[" << j << "] = " << arr[j] << ": ";
        for (int k = 0; k < arr.size(); k++)
            cout << arr[k] << " ";
        cout << endl;
    }

    swap(arr[i + 1], arr[high]);

    cout << "Sau khi dat pivot vao vi tri dung: ";
    for (int k = 0; k < arr.size(); k++)
        cout << arr[k] << " ";
    cout << endl;

    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high, int& step) {
    if (low < high) {
        step++;
        int pi = partition(arr, low, high, step);

        quickSort(arr, low, pi - 1, step);
        quickSort(arr, pi + 1, high, step);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    int step = 0;

    cout << "Mang ban dau: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    quickSort(arr, 0, n - 1, step);

    cout << "\nMang sau khi sap xep: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    cout << "\nTong so lan goi partition: " << step << endl;

    cout << "\n=== PHAN TICH DO PHUC TAP THUAT TOAN ===" << endl;
    cout << "\nDo phuc tap ly thuyet:" << endl;
    cout << "- Truong hop tot nhat (Best case): O(n log n)" << endl;
    cout << "- Truong hop trung binh (Average case): O(n log n)" << endl;
    cout << "- Truong hop xau nhat (Worst case): O(n^2)" << endl;
    cout << "- Do phuc tap khong gian (Space): O(log n) (do de quy)" << endl;

    return 0;
}

