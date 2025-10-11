#include <iostream>

using namespace std;

typedef int infotype;
typedef struct TElmtList *address;

typedef struct TElmtList {
	infotype value;
	address next;
} ElmtList;

typedef struct TList {
	address first;
} List;

void CreateEmpty(List *L) {
	L->first = NULL;
}

bool IsEmpty(List L) {
	return L.first == NULL;
}

address Allocation(infotype angka) {
	address NewElmnt = new ElmtList;
	NewElmnt->value = angka;
	return NewElmnt;
}

void InsertFirst(List *L, infotype angka) {
	address NewElmnt = Allocation(angka);
	NewElmnt->next = L->first;
	L->first = NewElmnt;
}

void insertAfter(address PreElmnt, infotype angka) {
	if(PreElmnt != NULL) {
		address NewElmnt = Allocation(angka);
		NewElmnt->next = PreElmnt->next;
		PreElmnt->next = NewElmnt;
	}
}

void insertSorted(List *L, infotype angka) {
	if(IsEmpty(*L) || (*L).first->value > angka) {
		InsertFirst(L, angka);
	} else {
		address temp = L->first;
		while(temp->next != NULL || temp->next->value < angka) {
		    temp = temp->next;
		}
		insertAfter(temp, angka);
	}
}

void PrintList(List L) {
	address temp = L.first;
	cout << "isi list : \n";
	while(temp != NULL) {
		cout << temp->value << endl;
		temp = temp->next;
	}
	cout << endl;
}

int main(int argc, char const *argv[]) {
	List bilangan;

	cout << "list bilangan" << endl;
	cout << "[1] Masukkan angka" << endl;
	cout << "[2] Mencetak semua angka" << endl;

	unsigned int menu;
	int angka;

	do {
		cout << "Masukkan menu : ";
		cin  >> menu;

		if(menu == 1) {
			cout << "masukkan angka : ";
			cin >> angka;

			insertSorted(&bilangan, angka);
		} else if(menu == 2) {
			PrintList(bilangan);
		}
	} while (menu > 0 && menu < 3);

	return 0;
}