#include <iostream>
using namespace std;

void linearSearch(int arr[], int n, int target) {
    int indices[n];
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            indices[count++] = i;
        }
    }

    if (count > 0) {
        cout << "Element " << target << " found at indices: ";
        for (int i = 0; i < count; i++) {
            cout << indices[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Element " << target << " not found." << endl;
    }
}

int main() {
    int arr[] = {1, 2, 3, 2, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 2;
    linearSearch(arr, n, target);
    return 0;
}
