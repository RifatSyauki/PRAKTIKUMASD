#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	// deklarasi variabel untuk menentukan panjangnya array
	int n;

	// meminta input user panjangnya array
	cin >> n;

	// deklarasi array sepanang n
	int arr[n];

	// meminta input user untuk setiap elemen array
	cout << "Masukkan elemen: ";
	for(int i = 0; i < n; i++) cin >> arr[i];

	// membuat pointer untuk array arr
	int *ptr = arr;

	// perulangan untuk menukar setiap elemen array
	for(int i = 0; i < n/2; i++) {
		// simpan value pada terdepan ke-i
		int temp = *(ptr + i);
		// salin value pada terbelakang ke-i
		*(ptr + i) = *(ptr + n - i -1);
		// letakkan value awal terdepan ke-i pada terbelakang ke-i
		*(ptr + n - i - 1) = temp;
	}

	// cetak setiap elemennya
	cout << "Array sesudah dibalik: ";
	for(int i = 0; i < n; i++) cout << arr[i] << ' ';
	cout << endl;
	
	return 0;
}