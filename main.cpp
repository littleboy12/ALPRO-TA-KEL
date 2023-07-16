#include <iostream>
#include <string>
using namespace std;

struct db_nilai {
    // tb_nama
    string namaMahasiswa, nim;
    string saveNama, saveNim;
    int jmlMahasiwa = 0;

    // tb_nilai
    float nilaiPretes, nilaiPrak, nilaiPost;
    float savePre, savePrak, savePost;
    float setPertemuan1 = 0;
    float setPertemuan2 = 0;
    float setPertemuan3 = 0;
    float setPertemuan4 = 0;
    float setPertemuan5 = 0;
    float nilaiFinal = 0;
    int jmlNilai = 0;
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
    void setInp();
    void inpCount();
    void inpNilai(int);
};

/*INPUT DATA MAHASISWA*/
void Main :: setValue() {
    int jml;
    cout << "Masukan Jumlah Mahasiswa : "; cin >> jml;
    cin.ignore();
    for (int i = 0; i < jml; i++) {
        cout << "Data ke-" << i + 1 << endl;
        cout << "Nama   : "; getline(cin, arr[i].namaMahasiswa);
        cout << "NIM    : "; getline(cin, arr[i].nim);
        cout << endl;
        arr[data.jmlMahasiwa].saveNama = arr[i].namaMahasiswa; 
        arr[data.jmlMahasiwa].saveNim = arr[i].nim; 
        data.jmlMahasiwa++;
    }
    setSystem();
}

void Main :: getName (int jml) {
    if (data.jmlMahasiwa != 0) {
        cout << "========= Data Mahasiswa =========\n";
        for (int i = 0; i < jml; i++) {
            cout << i+1 << ". Nama Lengkap\t: " <<  arr[i].saveNama << "\n   NIM\t\t: " << arr[i].saveNim << "\n   Nilai\t: " << arr[i].nilaiFinal << endl << endl;
        }
        cout << "==================================\n";
    } else {
        cout << endl << "- Tidak Ada Data Mahasiswa -" << endl;;
    }
    setSystem();
} 
/*INPUT DATA MAHASISWA*/

/* INPUT NILAI */
void Main :: setInp() {
    cout << endl;
    int pil;
    cout << "Input Nilai Bedasarkan :\n1. Jumlah Praktikan \n2. Nama\nPilih : "; cin >> pil;
    if (pil == 1) {
        inpCount();
        system("cls");
    }
}

void Main :: inpCount() {
    int jml;
    cout << "Masukan Jumlah Praktikan : "; cin >> jml;
    if (jml > data.jmlMahasiwa) {
        cout << "JUMLAH YANG ANDA MASUKAN MELEBIHI JUMLAH PRAKTIKAN !! JUMLAH PRAKTIKAN ADALAH " << data.jmlMahasiwa << " ORANG" << endl;
    } else if (data.jmlNilai == data.jmlMahasiwa) {
        cout << "NILAI PRAKTIKAN SUDAH DI INPUTKAN SEMUA";
    } else {
        inpNilai(jml);
    }
    setSystem();
}

void Main :: inpNilai(int jml) {
    cout << endl << "Input Nilai " << endl;
    if (data.jmlNilai == 0) {
        for (int i = 0; i < jml; i++) {
            cout << "Nama   : " << arr[i].saveNama << endl;
            cout << "NIM    : " << arr[i].saveNim << endl;
            cout << "Pretest: "; cin >> arr[i].nilaiPretes;
            cout << "Praktek: "; cin >> arr[i].nilaiPrak;
            cout << "Postest: "; cin >> arr[i].nilaiPost;

            arr[data.jmlNilai].savePre = arr[i].nilaiPretes;
            arr[data.jmlNilai].savePrak = arr[i].nilaiPrak;
            arr[data.jmlNilai].savePost = arr[i].nilaiPost;

            arr[i].setPertemuan1 = (arr[i].savePre + arr[i].savePrak + arr[i].savePost) / 3;

            arr[i].nilaiFinal = (arr[i].setPertemuan1 + arr[i].setPertemuan2 + arr[i].setPertemuan4 + arr[i].setPertemuan5) / 5;

            data.jmlNilai++;
        }
    } else {
        for (int i = data.jmlNilai; i <= jml; i++) {
            if (jml > data.jmlNilai) {
                cout << "NILAI PRAKTIKAN YANG SUDAH DI NILAI ADALAH " << data.jmlNilai << ", Tersisa " << data.jmlMahasiwa - data.jmlNilai << " ORANG LAGI";
                setSystem();
            }
            
            cout << "Nama   : " << arr[i].saveNama << endl;
            cout << "NIM    : " << arr[i].saveNim << endl;
            cout << "Pretest: "; cin >> arr[i].nilaiPretes;
            cout << "Praktek: "; cin >> arr[i].nilaiPrak;
            cout << "Postest: "; cin >> arr[i].nilaiPost;

            arr[data.jmlNilai].savePre = arr[i].nilaiPretes;
            arr[data.jmlNilai].savePrak = arr[i].nilaiPrak;
            arr[data.jmlNilai].savePost = arr[i].nilaiPost;

            arr[i].setPertemuan1 = (arr[i].savePre + arr[i].savePrak + arr[i].savePost) / 3;

            arr[i].nilaiFinal = (arr[i].setPertemuan1 + arr[i].setPertemuan2 + arr[i].setPertemuan4 + arr[i].setPertemuan5) / 5;

            data.jmlNilai++;
        }
    }
    
}
/*end - INPUT NILAI*/

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
    } else if(pil == 3) {
        system("cls");
        setInp();
    }
}

int main () {
    Main view;
    view.setSystem();
}
