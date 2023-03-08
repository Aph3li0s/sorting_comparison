#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <string>
using namespace std;
using namespace std::chrono;
double arr[1000000];

void heapify(double arr[], int N, int i){
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < N && arr[l] > arr[largest])
		largest = l;
	if (r < N && arr[r] > arr[largest])
		largest = r;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, N, largest);
	}
}
void heapSort(double arr[], int N)
{
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);
	for (int i = N - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

int main(){
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
		// for (int i = 0; i < 100; i++) cout << arr[i] << " ";
		auto start = high_resolution_clock::now();
		heapSort(arr, n);
		auto end = high_resolution_clock::now();
		cout << "Time taken datasets " + to_string(a)  << ": " << duration_cast<milliseconds>(end - start).count() << "ms\n";	
	}
	return 0;
}
