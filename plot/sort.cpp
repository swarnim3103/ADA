#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <cstdlib>  // For rand()
using namespace std;
using namespace std::chrono;

// Function to generate random data
vector<int> generateData(int size) {
    vector<int> data(size);
    for (int &num : data)
        num = rand() % 10000;
    return data;
}
// **3. Merge Sort**
void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// **Benchmark function**
void benchmarkSorting(int size, void (*sortFunc)(vector<int>&), const string &sortName, ofstream &outfile) {
    vector<int> data = generateData(size);
    
    auto start = high_resolution_clock::now();
    sortFunc(data);
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(stop - start).count();
    
    outfile << sortName << "," << size << "," << duration << "\n";  
}

// Overloaded function for QuickSort and MergeSort (needs extra parameters)
void benchmarkSorting(int size, void (*sortFunc)(vector<int>&, int, int), const string &sortName, ofstream &outfile) {
    vector<int> data = generateData(size);
    
    auto start = high_resolution_clock::now();
    sortFunc(data, 0, data.size() - 1);
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(stop - start).count();
    
    outfile << sortName << "," << size << "," << duration << "\n";  
}

int main() {
    ofstream outfile("sorting_results.csv");
    outfile << "Algorithm,Size,Time\n";  // CSV Header
    
    vector<int> sizes = {1000, 2000, 3000, 4000, 5000}; // Test sizes
    
    for (int size : sizes) {
        benchmarkSorting(size, mergeSort, "MergeSort", outfile);
    }

    outfile.close();
    cout << "Benchmark complete. Data saved to sorting_results.csv\n";
    return 0;
}
