#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <string>
using namespace std;
using namespace std::chrono;
double arr[1000000];

void merge(double array[], int const l, int const m, int const r){
	auto const sArr1 = m - l + 1;
	auto const sArr2 = r - m;
	auto *lArr = new int[sArr1], *rArr = new int[sArr2];
	for (auto i = 0; i < sArr1; i++)
		lArr[i] = array[l + i];
	for (auto j = 0; j < sArr2; j++)
		rArr[j] = array[m + 1 + j];
    
	auto index_1 = 0, 
		 index_2 = 0;
	int index_m = l; 

	// Merge the temp arrays back into array[left..right]
	while (index_1 < sArr1 && index_2 < sArr2) {
		if (lArr[index_1] <= rArr[index_2]) {
			array[index_m] = lArr[index_1];
			index_1++;
		} else {
			array[index_m] = rArr[index_2];
			index_2++;
		}
		index_m++;
	}

	while (index_1 < sArr1) {
		array[index_m] = lArr[index_1];
		index_1++;
		index_m++;
	}

	while (index_2 < sArr2) {
		array[index_m] = rArr[index_2];
		index_2++;
		index_m++;
	}
	delete[] lArr;
	delete[] rArr;
}

void mergeSort(double array[], int const begin, int const end)
{
	if (begin >= end) return; 
	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

int main()
{   
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
		mergeSort(arr, 0, n - 1);
		auto end = high_resolution_clock::now();
		cout << "Time taken datasets " + to_string(a)  << ": " << duration_cast<milliseconds>(end - start).count() << "ms\n";
	}
	return 0;
}