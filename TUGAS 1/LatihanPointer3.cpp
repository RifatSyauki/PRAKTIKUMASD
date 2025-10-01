#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;

	cin >> n;

	int arr[n];

	cout << "Masukkan elemen: ";
	for(int i = 0; i < n; i++) cin >> arr[i];

	int *ptr = arr;

	for(int i = 0; i < n; i++) {
		int temp = *(ptr + i);
		*(ptr + i) = *(ptr + n - i -1);
		*(ptr + n - i - 1) = temp;
	}

	cout << "Array sesudah dibalik: ";
	for(int i = 0; i < n; i++) cout << arr[i] << ' ';
	cout << endl;
	
	return 0;
}