#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Bubble Sort
void bubble_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Merge Sort
void merge(vector<int>& arr, int left, int med, int right) {
    int n1 = med - left + 1;
    int n2 = right - med;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[med + 1 + i];

    int i = 0, j = 0, k = left;
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
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void display(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> deliveryTimes = {5, 100, 154, 205, 25, 75, 81, 90, 64, 21, 53, 48, 25, 467}; // can be changed into your preffered delivery time

    // Bubble Sort
    vector<int> bubbleSorted = deliveryTimes;
    auto start = high_resolution_clock::now();
    bubble_sort(bubbleSorted);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    cout << "Sorted values after using Bubble sort: ";
    display(bubbleSorted);
    cout << "Bubble Sort takes: " << duration.count() << " nanoseconds to finish" << endl;

    // Merge Sort
    vector<int> mergeSorted = deliveryTimes;
    start = high_resolution_clock::now();
    mergeSort(mergeSorted, 0, mergeSorted.size() - 1);
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    cout << "Sorted values after using Merge Sort: ";
    display(mergeSorted);
    cout << "Merge Sort takes: " << duration.count() << " nanoseconds to finish" << endl;

    return 0;
}

//This program implements The bubble sort and merge sort algorithms, we need to use sorting algorithms to solve unsorted datas.
//In the upper part of our code, we define function for each algorithm.
// We all know that bubble sort swaps adjacent elements if they are not sequenced correctly,
// while merge sort divides the array into smaller sub arrays and then sorts the values inside it and then merges them back after the sorting is done.
//And then we create a vector of delivery times containing the values that to be sorted in the program.
// Of course, each algorithm must use each of their own vector or else one wont work if they use the same vector, each algorithm should have copies of the unsorted values.
// You can also notice that we imported the chrono library, the use of this function is to measure the execution time of each sorting algorithm.
// At the end of our code, we can see that we displayed the sorted values of the two algorithms and its execution time.

//In conclusion, this program demonstrates the differences of each sorting algorithms. Merge sort performs better in handling the larger datasets than bubble sort.
//Time complexity analysis:
//BUBBLE SORT: O(n^2)
//MERGE SORT: O(n log n)