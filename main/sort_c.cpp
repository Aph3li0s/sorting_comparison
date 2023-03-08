#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <string>
using namespace std;
using namespace std::chrono;
double arr[1000000];

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
		sort(arr, arr + n);
		auto end = high_resolution_clock::now();
		cout << "Time taken datasets " + to_string(a)  << ": " << duration_cast<milliseconds>(end - start).count() << "ms\n";	
	}
	return 0;
}