#include <iostream>

using namespace std;

// fungsi void dengan parameter x by reference untuk melakukan perhitungan, y by value untuk batas akhir, z untuk melakukan perhitungan
void hitung(int *x, int y, int *z) {
	// perulangan dimulai dari 1 hingga lebih kecil sama dengan batas akhirnya (y) denga penjumlahan i setiap step sebesar +1
	for(int i = 1; i <= y; i++) {
		// melakukan perhitungan kuadrat i dan dijumlahkan ke x
		*x += i*i;
		// melakukan perhitungan 2i - 1 dan dikali dengan z
		*z *= (2*i - 1);
	}
}

int main(int argc, char const *argv[]) {
	// deklarasi awal dan inisialisasi untuk variabel x dan z
	int x = 0, y, z = 1;

	// meminta input batas akhir kepada user
	cin >> y;

	// memanggil fungsi untuk melakukan perhitungan
	hitung(&x, y, &z);

	// cetak hasil operasi perhitungan yang dilakukan
	cout << x << endl << z << endl;
	
	return 0;
}