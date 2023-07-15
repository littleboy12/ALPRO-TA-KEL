#include <iostream>
#include <string>
using namespace std;

struct db_nilai {
    // tb_nama
    string namaMahasiswa, nim;
    string saveNama, saveNim;
    int jmlMahasiwa = 0;

    // tb_nilai
    long nilaiPretes, nilaiPrak, nilaiPost;
};

class Main {
private:
    db_nilai arr[50];
    db_nilai data;
public:
    // Data Nama
    void setSystem ();
    void setValue ();
    void getName (int);

    // Data Nilai
    void inpNilai();
};

/*INPUT DATA MAHASISWA*/
void Main :: setValue() {
    int jml;
    cout << "Masukan Jumlah Mahasiswa : "; cin >> jml;
    cin.ignore();
    for (int i = 0; i < jml; i++) {
        cout << "Data ke-" << i + 1 << endl;
        cout << "Nama " << " : "; getline(cin, arr[i].namaMahasiswa);
        cout << "NIM " << "  : "; getline(cin, arr[i].nim);
        cout << endl;
        arr[data.jmlMahasiwa].saveNama = arr[i].namaMahasiswa; 
        arr[data.jmlMahasiwa].saveNim = arr[i].nim; 
        data.jmlMahasiwa++;
    }
    setSystem();
}

void Main :: getName (int jml) {
    if (data.jmlMahasiwa != 0) {
        for (int i = 0; i < jml; i++) {
            cout << i+1 << ". " <<  arr[i].saveNama << "/" << arr[i].saveNim << endl;
        }
    } else {
        cout << endl << "- Tidak Ada Data Mahasiswa -" << endl;;
    }
    setSystem();
}
/*END--INPUT DATA MAHASISWA*/

void Main :: setSystem () {
    int pil;
    cout << endl << "===========================" << endl;
    cout << "1. Tambah Data Mahasiswa\n2. Lihat Data Mahasiwa\n3. Input Nilai\nPilihan : "; cin >> pil;
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
