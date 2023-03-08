#include <bits/stdc++.h>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;
double arr[1000000];

void merge(double arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temporary arrays
    double L[n1], R[n2];
 
    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temporary arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// Merge sort function
void mergeSort(double arr[], int l, int r) {
    if (l < r) {
        // Find the middle point
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

int main()
{   
    int t = 10;
	while (t--){
		//"../datasets/data10.txt"
		int a = 10 - t;
		string name_f = "./datasets/data" + to_string(a) + ".txt";
		long long i = 0;
		double num;
		int n = sizeof(arr) / sizeof(arr[0]);
		ifstream file(name_f);
		if (file.is_open()) { 
			while (file >> num) {
				arr[i] = num;
				i++;
			}
			file.close();
		} else cout << "Unable to open file" << endl;
		
		// for (int i = 0; i < 100; i++) cout << arr[i] << " ";
		auto start = high_resolution_clock::now();
		mergeSort(arr, 0, n - 1);
		auto end = high_resolution_clock::now();
		cout << "Time taken datasets " + to_string(a)  << ": " << duration_cast<milliseconds>(end - start).count() << "ms\n";
	}
	return 0;
}