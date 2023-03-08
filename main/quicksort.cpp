#include <bits/stdc++.h>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;
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

int main() {
    int t = 10;
	while (t--){
		//"../datasets/data10.txt"
		int a = 10 - t;
		string name_f = "../datasets/data" + to_string(a) + ".txt";
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
		auto start = high_resolution_clock::now();
		quicksort(arr, 0, n - 1);
		auto end = high_resolution_clock::now();
		cout << "Time taken datasets " + to_string(a)  << ": " << duration_cast<milliseconds>(end - start).count() << "ms\n";
		
		// for (int i = 0; i < 100; i++) cout << arr[i] << " ";
	}
	return 0;
}