#include <iostream>
#include <vector>
#include <stack>
#include <chrono>
#include <algorithm>

using namespace std;

// Recursive Quick Sort
void quick_sort_recursive(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    
    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;
    
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        
        while (arr[j] > pivot) {
            j--;
        }
        
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    
    quick_sort_recursive(arr, left, j);
    quick_sort_recursive(arr, i, right);
}

// Non-Recursive Quick Sort
void quick_sort_non_recursive(vector<int>& arr, int left, int right) {
    stack<int> s;
    s.push(left);
    s.push(right);
    
    while (!s.empty()) {
        int r = s.top();
        s.pop();
        int l = s.top();
        s.pop();
        
        if (l >= r) {
            continue;
        }
        
        int pivot = arr[(l + r) / 2];
        int i = l;
        int j = r;
        
        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }
            
            while (arr[j] > pivot) {
                j--;
            }
            
            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
        
        s.push(l);
        s.push(j);
        s.push(i);
        s.push(r);
    }
}

int main() {
    vector<int> sizes = {50000, 100000, 150000, 200000, 250000};
    
    for (int size : sizes) {
        vector<int> arr(size);
        
        // Fill the array with random numbers
        for (int i = 0; i < size; i++) {
            arr[i] = rand();
        }
        
        // Sort the array using Recursive Quick Sort and measure execution time
        auto start_recursive = chrono::high_resolution_clock::now();
        quick_sort_recursive(arr, 0, size - 1);
        auto end_recursive = chrono::high_resolution_clock::now();
        auto duration_recursive = chrono::duration_cast<chrono::microseconds>(end_recursive - start_recursive);
        cout << "Recursive Quick Sort for array of size " << size << " took " << duration_recursive.count() << " microseconds." << endl;
        
        // Sort the array using Non-Recursive Quick Sort and measure execution time
        auto start_non_recursive = chrono::high_resolution_clock::now();
        quick_sort_non_recursive(arr, 0, size - 1);
        auto end_non_recursive = chrono::high_resolution_clock::now();
        auto duration_non_recursive = chrono::duration_cast<chrono::microseconds>(end_non_recursive - start_non_recursive);
        cout << "Non-Recursive Quick Sort for array of size " << size << " took " << duration_non_recursive.count() << " microseconds." << endl;
        
        cout << endl;
    }
    
    return 0;
}
