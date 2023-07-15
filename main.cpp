#include <iostream>
#include <string>
using namespace std;

struct db_nilai {
    string namaMahasiswa;
    string saveNama;
    int jmlMahasiwa = 0;
    db_nilai *berikut;
};

class Main {
private:
    db_nilai arr[50];
    db_nilai data;
public:
    void setSystem ();
    void setValue ();
    void getName (int);
};

void Main :: setValue() {
    int jml;
    cout << "Masukan Jumlah Mahasiswa : "; cin >> jml;
    cin.ignore();
    for (int i = 0; i < jml; i++) {
        cout << "Nama " << i+1 << " : "; getline(cin, arr[i].namaMahasiswa);
        arr[data.jmlMahasiwa].saveNama = arr[i].namaMahasiswa; 
        data.jmlMahasiwa++;
    }
    setSystem();
}

void Main :: getName (int jml) {
    if (data.jmlMahasiwa != 0) {
        for (int i = 0; i < jml; i++) {
            cout << i+1 << ". " <<  arr[i].saveNama << endl;
        }
    } else {
        cout << endl << "- Tidak Ada Data Mahasiswa -" << endl;;
    }
    setSystem();
}

void Main :: setSystem () {
    int pil;
    cout << endl << "===========================" << endl;
    cout << "1. Tambah Data Mahasiswa\n2. Lihat Data Mahasiwa\nPilihan : "; cin >> pil;
    if (pil == 1) {
        system("cls");
        setValue();
    } else if(pil == 2) {
        system("cls");
        getName(data.jmlMahasiwa);
    }
     
}

int main () {
    Main view;
    view.setSystem();
}
