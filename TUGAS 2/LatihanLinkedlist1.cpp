#include <iostream>

using namespace std;

typedef string infoname;
typedef int infoscore;
typedef struct TElmtList *address;

typedef struct TElmtList {
	infoname nama;
	infoscore nilai;
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

address Allocation(infoname name, infoscore score) {
	address NewElmnt = new ElmtList;
	NewElmnt->nama = name;
	NewElmnt->nilai = score;
	return NewElmnt;
}

void InsertFirst(List *L, infoname name, infoscore score) {
	address NewElmnt = Allocation(name, score);
	NewElmnt->next = L->first;
	L->first = NewElmnt;
}

void insertAfter(address PreElmnt, infoname name, infoscore score) {
	if(PreElmnt != NULL) {
		address NewElmnt = Allocation(name, score);
		NewElmnt->next = PreElmnt->next;
		PreElmnt->next = NewElmnt;
	}
}

void InsertLast(List *L, infoname name, infoscore score) {
	if(IsEmpty(*L)) {
		InsertFirst(L, name, score);
	} else {
		address temp = L->first;
		while(temp->next != NULL) {
		    temp = temp->next;
		}
		insertAfter(temp, name, score);
	}
}

void PrintList(List L) {
	address temp = L.first;
	while(temp != NULL) {
		cout << "Nama : " << temp->nama << "\t" << "Nilai : " << temp->nilai << endl;
		temp = temp->next;
	}
	cout << endl;
}

int main(int argc, char const *argv[]) {
	List mhs;

	cout << "Nilai Mahasiswa" << endl;
	cout << "[1] Masukkan data (nama, nilai)" << endl;
	cout << "[2] Mencetak semua data" << endl;

	unsigned int menu;

	do {
		cout << "Masukkan menu : ";
		cin  >> menu;

		if(menu == 1) {
			string nama;
			int nilai;

			cout << "nama : ";
			cin >> nama;
			cout << "nilai : ";
			cin >> nilai;

			InsertLast(&mhs, nama, nilai);
		} else if(menu == 2) {
			PrintList(mhs);
		}
	} while (menu > 0 && menu < 3);

	return 0;
}