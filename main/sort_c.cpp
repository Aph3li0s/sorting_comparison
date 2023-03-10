#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <string>
using namespace std;
using namespace std::chrono;
double arr[1000000];

int main(){
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int t = 1; t <= 10; t++){
		string name_f = "../datasets/data" + to_string(t) + ".txt";
		ifstream file(name_f);
		if (file.is_open()) { 
			for (int i = 0; i < 1000000; i++){
				file >> arr[i];
			}
			file.close();
		} else cout << "Unable to open file" << endl;
		auto start = std::chrono::high_resolution_clock::now();
		sort(arr, arr + n);
		auto end = std::chrono::high_resolution_clock::now();
		cout << "Time taken datasets " + to_string(t)  << ": " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";	
	}
	return 0;
}