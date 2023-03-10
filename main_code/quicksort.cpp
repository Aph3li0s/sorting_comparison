#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <string>
using namespace std;
double arr[1000000];

int partition(double arr[], int low, int high) {
    double pivot = arr[(low + high) / 2];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j) {
            return j;
        }

        swap(arr[i], arr[j]);
    }
}

void quicksort(double arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quicksort(arr, low, p);
        quicksort(arr, p + 1, high);
    }
}

signed main() {
	
    int t = 10;
	while (t--){
		int a = 10 - t;
		string name_f = "../datasets/data" + to_string(a) + ".txt";
		int n = sizeof(arr) / sizeof(arr[0]);
		ifstream file(name_f);
		if (file.is_open()) { 
			for (int i = 0; i < 1000000; i++){
				file >> arr[i];
			}
			file.close();
		} else cout << "Unable to open file" << endl;
		auto start = std::chrono::high_resolution_clock::now();
		quicksort(arr, 0, n - 1);
		auto end = std::chrono::high_resolution_clock::now();
		cout << "Time taken datasets " + to_string(a)  << ": " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";
		for (int i = 0; i < 10; i++) cout << arr[i] << " ";
        cout << endl;
	}
}