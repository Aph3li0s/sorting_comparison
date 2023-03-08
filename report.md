# Báo cáo thực nghiệm
## I. Mở đầu
*Đánh giá thuật toán sắp xếp:* Khi so sánh giữa các thuật toán thường sẽ có các vấn đề sau đây:

* Thời gian chạy. Đối với các dữ liệu rất lớn, các thuật toán không hiệu quả sẽ chạy rất chậm và không thể ứng dụng trong thực tế.
* Bộ nhớ. Các thuật toán nhanh đòi hỏi đệ quy sẽ có thể phải tạo ra các bản copy của dữ liệu đang xử lí. Với những hệ thống mà bộ nhớ có giới hạn (ví dụ như hệ thống nhúng), một vài thuật toán sẽ không thể chạy được.
* Độ ổn định. Độ ổn định được định nghĩa dựa trên điều gì sẽ xảy ra với các phần tử có giá trị giống nhau.


Một thuật toán sắp xếp ổn định là khi các phần tử bằng với giá trị bằng nhau sẽ giữ nguyên thứ tự trong mảng trước khi sắp xếp. Ngược lại, các phần tử có giá trị bằng nhau sẽ có thể có thứ tự bất kỳ sẽ khiến thuật toán đó trở nên không ổn định.
## II. So sánh các thuật toán sắp xếp
### 1. Quicksort
**1.1 Mô tả**
* Đây là một thuật toán dạng "Chia để trị", hoạt động bằng cách chọn một phần tử trong mảng đầu làm chốt "pivot" trong mảng. Sau đó phân hoạch các phần tử khác thành 2 mảng con, một mảng con bao gồm các phần tử nhỏ hơn hoặc bằng pivot, và phần còn lại là các phần tử lớn hơn pivot. 
* Sau đó, thuật toán đệ quy được áp dụng trên hai mảng con này để sắp xếp chúng.

**1.2 Độ phức tạp**
* Tốt nhất: $nlogn$
* Trung bình: $nlogn$
* Xấu nhất: $n^2$
 
**1.3 Ưu và nhược điểm**
* Quicksort chạy rất nhanh và dễ cài đặt, nên thường được sử dụng trong các thư viện của Java, C++,... và được sử dụng rộng rãi trên toàn thế giới
* Trong trường hợp xấu nhất, độ phức tạp của Quicksort là $n^2$. Nếu pivot không tốt có thể dẫn đến lỗi. Ngoài ra, Quicksort tỏ ra không ổn định khi ta sử dụng trên những tập dữ liệu có cấu trúc phức tạp 

**1.4 Cài đặt**

*Lưu ý:* Chọn pivot là phần tử nằm giữa trong mảng
```c++
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
```
### 2. Mergesort
**1.1 Mô tả**
* Mergesort là một thuật toán sắp xếp đệ quy, chia một danh sách thành hai phần, sắp xếp các phần đó riêng biệt và sau đó trộn lại chúng để tạo ra một danh sách được sắp xếp hoàn chỉnh. 

**1.2 Độ phức tạp**
* Tốt nhất: $nlogn$
* Trung bình: $nlogn$
* Xấu nhất: $nlogn$
 
**1.3 Ưu và nhược điểm**
* Mergesort là một trong những thuật toán sắp xếp nhanh nhất và mang tính ổn định cao, thích hợp để sắp xếp các danh sách có kích thước lớn.
* Cài đặt phức tạp, thường chậm hơn các thuật toán khác khi sắp xếp các danh sách nhỏ vì phải tốn thời gian trộn các danh sách con lại với nhau. Ngoài ra, mergesort cần nhiều bộ nhớ để lưu trữ các mảng con

**1.4 Cài đặt**

```c++
void merge(double array[], int const l, int const m, int const r){
    // Tạo các mảng con left và right
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

	// Merge các temp arrays lại với nhau
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
```
### 3. Heapsort
**1.1 Mô tả**
**1.2 Độ phức tạp**
* Tốt nhất: $nlogn$
* Trung bình: $nlogn$
* Xấu nhất: $nlogn$
**1.3 Ưu và nhược điểm**
* Heapsort chạy nhanh, mang tính nhất quán dù gặp bất kì trường hợp nào. Ngoài ra, heapsort sử dụng ít bộ nhớ vì không yêu cầu thêm bộ nhớ khi sử dụng 
* Không ổn định và thiếu sự linh hoạt.

**1.4 Cài đặt**
```c++
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
```
### 4. C++ Sort
**1.1 Mô tả**
C++ Sort sử dụng thuật toán Introsort (sự kết hợp giữa Quicksort, Heapsort và Insertion Sort), nhờ đó tăng độ hiệu quả khi sắp xếp. 

**1.2 Độ phức tạp**
* Tốt nhất: $nlogn$
* Trung bình: $nlogn$
* Xấu nhất: $nlogn$

**1.3 Ưu và nhược điểm**
* std::sort() giải quyết được những nhược điểm của các thuật toán sort khác. Vì vậy, C++ Sort chạy rất nhanh chóng

**1.4 Cài đặt**
```c++
int arr[];
int n = sizeof(arr) / sizeof(arr[0]);
sort(arr, arr + n);
```
## III. Kết quả thực nghiệm

## IV. Tổng kết 
