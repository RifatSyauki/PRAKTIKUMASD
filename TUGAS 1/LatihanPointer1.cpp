#include <iostream>

using namespace std;

// fungsi void dengan parameter x by reference untuk menyimpan nilai dan y by value untuk batas akhir
void jumlah_bil_ganjil(int *x, int y) {
	// perulangan dimulai dari 1 hingga lebih kecil sama dengan batas akhirnya (y) denga penjumlahan i setiap step sebesar +2
	for(int i = 1; i <= y; i+=2) {
		// jumlahkan setiap nilai ganjil ke dalam variabel x
		// dimana x merupakan parameter by reference maka harus ditambah * untuk bisa mengakses valuenya
		*x += i;
	}
}

int main(int argc, char const *argv[]) {
	// deklarasi awal untuk variabel x dan y
	int x = 0, y; // atur x menjadi 0 agar variabel x tidak error ketika dijumlahkan (garbage value)

	// meminta input dari user untuk batas akhirnya
	cin >> y;

	// panggil fungsi untuk menghitung jumlah bilangan ganjil
	jumlah_bil_ganjil(&x, y);

	// cetak hasilnya
	cout << x << endl;

	return 0;
}