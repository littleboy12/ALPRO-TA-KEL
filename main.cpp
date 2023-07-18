#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct db_nilai {
    // tb_nama
    string namaMahasiswa, nim;
    string saveNama, saveNim;
    int jmlMahasiwa = 0;

    // tb_nilai
    float nilaiPretes, nilaiPrak, nilaiPost;
    float savePre, savePrak, savePost;
    float savePre2 = 0, savePrak2 = 0, savePost2 = 0;
    float savePre3 = 0, savePrak3 = 0, savePost3 = 0;
    float savePre4 = 0, savePrak4 = 0, savePost4 = 0;
    float savePre5 = 0, savePrak5 = 0, savePost5 = 0;
    float setPertemuan1 = 0;
    float setPertemuan2 = 0;
    float setPertemuan3 = 0;
    float setPertemuan4 = 0;
    float setPertemuan5 = 0;
    float nilaiFinal = 0;
    int jmlNilai  = 0;
    int jmlNilai2 = 0;
    int jmlNilai3 = 0;
    int jmlNilai4 = 0;
    int jmlNilai5 = 0;

    string view;
};

class Main {
private:
    db_nilai arr[50];
    db_nilai data;
    db_nilai arr2[50][50];
public:
    void setSystem ();
    void setDisplay();
    // Data Nama
    void setValue ();
    void getName (int);

    // Data Nilai
    void setInp(int);
    void inpCount(int);
    void inpNilai(int, int);
    void setPer();

    // Data Tampil
    void viewData(int);
    void view2D(int);

    // Data Sort
    void bubbleSortAscending(int jmlMahasiswa);
    void bubbleSortDescending(int jmlMahasiswa);
    void viewSortedDataAscending(int jmlMahasiswa);
    void viewSortedDataDescending(int jmlMahasiswa);
    
    void searchByNIM(const string& searchNIM);
};

//INPUT DATA MAHASISWA//
void Main :: setValue() {
    int jml;
    cout << "Masukan Jumlah Mahasiswa : "; cin >> jml;
    cin.ignore();
    for (int i = 0; i < jml; i++) {
        cout << "\nData ke-" << i + 1 << endl;
        cout << "Nama   : "; getline(cin, arr[i].namaMahasiswa);
        cout << "NIM    : "; getline(cin, arr[i].nim);
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
//INPUT DATA MAHASISWA//

/* INPUT NILAI */
void Main :: setPer() {
    int pil;
    cout << "Masukan Pertemuan (1-3) : "; cin >> pil;
    inpCount(pil);
}

// void Main :: setInp(int per) {
//     cout << endl;
//     int pil;
//     cout << "Input Nilai Bedasarkan :\n1. Jumlah Praktikan \n2. Nama\nPilih : "; cin >> pil;
//     if (pil == 1) {
//         inpCount();
//         system("cls");
//     }
// }

void Main :: inpCount(int per) {
    int jml;
    cout << "Jumlah Praktikan Yang Belum Di Input : " << data.jmlMahasiwa << endl << endl;
    if (per == 1) {
        cout << "Masukan Jumlah data mahasiswa atau satu per satu : "; cin >> jml;
        if (jml > data.jmlMahasiwa) {
            cout << "\nJUMLAH YANG ANDA MASUKAN MELEBIHI JUMLAH PRAKTIKAN !!\nJUMLAH PRAKTIKAN ADALAH " << data.jmlMahasiwa << " ORANG" << endl;
        } else if (data.jmlNilai == data.jmlMahasiwa) {
            cout << "NILAI PRAKTIKAN SUDAH DI INPUTKAN SEMUA" << endl;
        } else {
            inpNilai(jml, per);
        }
    } else if (per == 2) {
        cout << "Masukan Jumlah data mahasiswa atau satu per satu : "; cin >> jml;
        if (jml > data.jmlMahasiwa) {
            cout << "\nJUMLAH YANG ANDA MASUKAN MELEBIHI JUMLAH PRAKTIKAN !!\nJUMLAH PRAKTIKAN ADALAH " << data.jmlMahasiwa << " ORANG" << endl;
        } else if (data.jmlNilai2 == data.jmlMahasiwa) {
            cout << "NILAI PRAKTIKAN SUDAH DI INPUTKAN SEMUA" << endl;;
        } else {
            inpNilai(jml, per);
        }
    } else if (per == 3) {
        cout << "Masukan Jumlah data mahasiswa atau satu per satu : "; cin >> jml;
        if (jml > data.jmlMahasiwa) {
            cout << "\nJUMLAH YANG ANDA MASUKAN MELEBIHI JUMLAH PRAKTIKAN !!\nJUMLAH PRAKTIKAN ADALAH " << data.jmlMahasiwa << " ORANG" << endl;
        } else if (data.jmlNilai3 == data.jmlMahasiwa) {
            cout << "NILAI PRAKTIKAN SUDAH DI INPUTKAN SEMUA" << endl;;
        } else {
            inpNilai(jml, per);
        }
    } else if (per == 4) {
        cout << "Masukan Jumlah data mahasiswa atau satu per satu : "; cin >> jml;
        if (jml > data.jmlMahasiwa) {
            cout << "\nJUMLAH YANG ANDA MASUKAN MELEBIHI JUMLAH PRAKTIKAN !!\nJUMLAH PRAKTIKAN ADALAH " << data.jmlMahasiwa << " ORANG" << endl;
        } else if (data.jmlNilai4 == data.jmlMahasiwa) {
            cout << "NILAI PRAKTIKAN SUDAH DI INPUTKAN SEMUA" << endl;;
        } else {
            inpNilai(jml, per);
        }
    } else if (per == 5) {
        cout << "Masukan Jumlah data mahasiswa atau satu per satu : "; cin >> jml;
        if (jml > data.jmlMahasiwa) {
            cout << "\nJUMLAH YANG ANDA MASUKAN MELEBIHI JUMLAH PRAKTIKAN !!\nUMLAH PRAKTIKAN ADALAH " << data.jmlMahasiwa << " ORANG" << endl;
        } else if (data.jmlNilai5 == data.jmlMahasiwa) {
            cout << "NILAI PRAKTIKAN SUDAH DI INPUTKAN SEMUA" << endl;
        } else {
            inpNilai(jml, per);
        }
    }
    
    setSystem();
}

void Main :: inpNilai(int jml, int per) {
    if (per == 1) {
        cout << endl << "> Input Nilai Pertemuan " << per << endl << endl;
        if (data.jmlNilai == 0) {
            for (int i = 0; i < jml; i++) {
                cout << i+1 << ". Nama   : " << arr[i].saveNama << endl;
                cout << "   NIM    : " << arr[i].saveNim << endl;
                cout << "   Pretest: "; cin >> arr[i].nilaiPretes;
                cout << "   Praktek: "; cin >> arr[i].nilaiPrak;
                cout << "   Postest: "; cin >> arr[i].nilaiPost;
                cout << endl;

                arr[data.jmlNilai].savePre = arr[i].nilaiPretes;
                arr[data.jmlNilai].savePrak = arr[i].nilaiPrak;
                arr[data.jmlNilai].savePost = arr[i].nilaiPost;

                arr[i].setPertemuan1 = (arr[i].savePre + arr[i].savePrak + arr[i].savePost) / 3;

                arr[i].nilaiFinal = (arr[i].setPertemuan1 + arr[i].setPertemuan2 + arr[i].setPertemuan3) / 3;

                data.jmlNilai++;
            }
        } else if (data.jmlNilai >= 2){
            int setJml = data.jmlNilai + jml;
            for (int i = data.jmlNilai; i < setJml; i++) {
                if (jml > data.jmlNilai) {
                    cout << "NILAI PRAKTIKAN YANG SUDAH DI NILAI ADALAH " << data.jmlNilai << ", Tersisa " << data.jmlMahasiwa - data.jmlNilai << " ORANG LAGI" << endl;
                    system("pause");
                    system("cls");
                    setSystem();
                }
                
                cout << i+1 << ". Nama   : " << arr[i].saveNama << endl;
                cout << "   NIM    : " << arr[i].saveNim << endl;
                cout << "   Pretest: "; cin >> arr[i].nilaiPretes;
                cout << "   Praktek: "; cin >> arr[i].nilaiPrak;
                cout << "   Postest: "; cin >> arr[i].nilaiPost;
                cout << endl;

                arr[data.jmlNilai].savePre = arr[i].nilaiPretes;
                arr[data.jmlNilai].savePrak = arr[i].nilaiPrak;
                arr[data.jmlNilai].savePost = arr[i].nilaiPost;

                arr[i].setPertemuan1 = (arr[i].savePre + arr[i].savePrak + arr[i].savePost) / 3;

                arr[i].nilaiFinal = (arr[i].setPertemuan1 + arr[i].setPertemuan2 + arr[i].setPertemuan3) / 3;

                data.jmlNilai++;
            }
        } else {
            for (int i = data.jmlNilai; i <= jml; i++) {
                if (jml > data.jmlNilai) {
                    cout << "NILAI PRAKTIKAN YANG SUDAH DI NILAI ADALAH " << data.jmlNilai << ", Tersisa " << data.jmlMahasiwa - data.jmlNilai << " ORANG LAGI" << endl;
                    system("pause");
                    system("cls");
                    setSystem();
                }
                
                cout << i+1 << ". Nama   : " << arr[i].saveNama << endl;
                cout << "   NIM    : " << arr[i].saveNim << endl;
                cout << "   Pretest: "; cin >> arr[i].nilaiPretes;
                cout << "   Praktek: "; cin >> arr[i].nilaiPrak;
                cout << "   Postest: "; cin >> arr[i].nilaiPost;
                cout << endl;

                arr[data.jmlNilai].savePre = arr[i].nilaiPretes;
                arr[data.jmlNilai].savePrak = arr[i].nilaiPrak;
                arr[data.jmlNilai].savePost = arr[i].nilaiPost;

                arr[i].setPertemuan1 = (arr[i].savePre + arr[i].savePrak + arr[i].savePost) / 3;

                arr[i].nilaiFinal = (arr[i].setPertemuan1 + arr[i].setPertemuan2 + arr[i].setPertemuan3) / 3;

                data.jmlNilai++;
            }
        }
    } else if (per == 2) {
        cout << endl << "Input Nilai Pertemuan " << per << endl;
        if (data.jmlNilai2 == 0) {
            for (int i = 0; i < jml; i++) {
                cout << i+1 << ". Nama   : " << arr[i].saveNama << endl;
                cout << "   NIM    : " << arr[i].saveNim << endl;
                cout << "   Pretest: "; cin >> arr[i].nilaiPretes;
                cout << "   Praktek: "; cin >> arr[i].nilaiPrak;
                cout << "   Postest: "; cin >> arr[i].nilaiPost;
                cout << endl;

                arr[data.jmlNilai2].savePre2 = arr[i].nilaiPretes;
                arr[data.jmlNilai2].savePrak2 = arr[i].nilaiPrak;
                arr[data.jmlNilai2].savePost2 = arr[i].nilaiPost;

                arr[i].setPertemuan2 = (arr[i].savePre2 + arr[i].savePrak2 + arr[i].savePost2) / 3;

                arr[i].nilaiFinal = (arr[i].setPertemuan1 + arr[i].setPertemuan2 + arr[i].setPertemuan3) / 3;

                data.jmlNilai2++;
            }
        } else if (data.jmlNilai2 >= 2) {
            int setJml = data.jmlNilai2 + jml;
            for (int i = 0; i < setJml; i++) {
                if (jml > data.jmlNilai2) {
                    cout << "NILAI PRAKTIKAN YANG SUDAH DI NILAI ADALAH " << data.jmlNilai2 << ", Tersisa " << data.jmlMahasiwa - data.jmlNilai2 << " ORANG LAGI" << endl;
                    system("pause");
                    system("cls");
                    setSystem();
                }
                cout << i+1 << ". Nama   : " << arr[i].saveNama << endl;
                cout << "   NIM    : " << arr[i].saveNim << endl;
                cout << "   Pretest: "; cin >> arr[i].nilaiPretes;
                cout << "   Praktek: "; cin >> arr[i].nilaiPrak;
                cout << "   Postest: "; cin >> arr[i].nilaiPost;
                cout << endl;

                arr[data.jmlNilai2].savePre2 = arr[i].nilaiPretes;
                arr[data.jmlNilai2].savePrak2 = arr[i].nilaiPrak;
                arr[data.jmlNilai2].savePost2 = arr[i].nilaiPost;

                arr[i].setPertemuan2 = (arr[i].savePre2 + arr[i].savePrak2 + arr[i].savePost2) / 3;

                arr[i].nilaiFinal = (arr[i].setPertemuan1 + arr[i].setPertemuan2 + arr[i].setPertemuan3) / 3;

                data.jmlNilai2++;
            }
        } else {
            for (int i = data.jmlNilai2; i <= jml; i++) {
                if (jml > data.jmlNilai2) {
                    cout << "NILAI PRAKTIKAN YANG SUDAH DI NILAI ADALAH " << data.jmlNilai2 << ", Tersisa " << data.jmlMahasiwa - data.jmlNilai2 << " ORANG LAGI" << endl;
                    system("pause");
                    system("cls");
                    setSystem();
                }
                
                cout << i+1 << ". Nama   : " << arr[i].saveNama << endl;
                cout << "   NIM    : " << arr[i].saveNim << endl;
                cout << "   Pretest: "; cin >> arr[i].nilaiPretes;
                cout << "   Praktek: "; cin >> arr[i].nilaiPrak;
                cout << "   Postest: "; cin >> arr[i].nilaiPost;
                cout << endl;

                arr[data.jmlNilai2].savePre2 = arr[i].nilaiPretes;
                arr[data.jmlNilai2].savePrak2 = arr[i].nilaiPrak;
                arr[data.jmlNilai2].savePost2 = arr[i].nilaiPost;

                arr[i].setPertemuan2 = (arr[i].savePre2 + arr[i].savePrak2 + arr[i].savePost2) / 3;

                arr[i].nilaiFinal = (arr[i].setPertemuan1 + arr[i].setPertemuan2 + arr[i].setPertemuan3) / 3;
                data.jmlNilai2++;
            }
        }
    } else if (per == 3) {
        cout << endl << "Input Nilai Pertemuan " << per << endl;
        if (data.jmlNilai3 == 0) {
            for (int i = 0; i < jml; i++) {
                cout << i+1 << ". Nama   : " << arr[i].saveNama << endl;
                cout << "   NIM    : " << arr[i].saveNim << endl;
                cout << "   Pretest: "; cin >> arr[i].nilaiPretes;
                cout << "   Praktek: "; cin >> arr[i].nilaiPrak;
                cout << "   Postest: "; cin >> arr[i].nilaiPost;
                cout << endl;

                arr[data.jmlNilai3].savePre3 = arr[i].nilaiPretes;
                arr[data.jmlNilai3].savePrak3 = arr[i].nilaiPrak;
                arr[data.jmlNilai3].savePost3 = arr[i].nilaiPost;

                arr[i].setPertemuan3 = (arr[i].savePre3 + arr[i].savePrak3 + arr[i].savePost3) / 3;

                arr[i].nilaiFinal = (arr[i].setPertemuan1 + arr[i].setPertemuan2 + arr[i].setPertemuan3) / 3;

                data.jmlNilai3++;
            }
        } else if (data.jmlNilai3 >= 2) {
            int setJml = data.jmlNilai2 + jml;
            for (int i = data.jmlNilai3; i < setJml; i++) {
                if (jml > data.jmlNilai3) {
                    cout << "NILAI PRAKTIKAN YANG SUDAH DI NILAI ADALAH " << data.jmlNilai3 << ", Tersisa " << data.jmlMahasiwa - data.jmlNilai3 << " ORANG LAGI"<< endl;
                    system("pause");
                    system("cls");
                    setSystem();
                }
                
                cout << i+1 << ". Nama   : " << arr[i].saveNama << endl;
                cout << "   NIM    : " << arr[i].saveNim << endl;
                cout << "   Pretest: "; cin >> arr[i].nilaiPretes;
                cout << "   Praktek: "; cin >> arr[i].nilaiPrak;
                cout << "   Postest: "; cin >> arr[i].nilaiPost;
                cout << endl;

                arr[data.jmlNilai3].savePre3 = arr[i].nilaiPretes;
                arr[data.jmlNilai3].savePrak3 = arr[i].nilaiPrak;
                arr[data.jmlNilai3].savePost3 = arr[i].nilaiPost;

                arr[i].setPertemuan3 = (arr[i].savePre3 + arr[i].savePrak3 + arr[i].savePost3) / 3;

                arr[i].nilaiFinal = (arr[i].setPertemuan1 + arr[i].setPertemuan2 + arr[i].setPertemuan3) / 3;
                data.jmlNilai3++;
            }
        } else {
            for (int i = data.jmlNilai3; i <= jml; i++) {
                if (jml > data.jmlNilai) {
                    cout << "NILAI PRAKTIKAN YANG SUDAH DI NILAI ADALAH " << data.jmlNilai << ", Tersisa " << data.jmlMahasiwa - data.jmlNilai << " ORANG LAGI" << endl;
                    system("pause");
                    system("cls");
                    setSystem();
                }
                
                cout << i+1 << ". Nama   : " << arr[i].saveNama << endl;
                cout << "   NIM    : " << arr[i].saveNim << endl;
                cout << "   Pretest: "; cin >> arr[i].nilaiPretes;
                cout << "   Praktek: "; cin >> arr[i].nilaiPrak;
                cout << "   Postest: "; cin >> arr[i].nilaiPost;
                cout << endl;

                arr[data.jmlNilai3].savePre3 = arr[i].nilaiPretes;
                arr[data.jmlNilai3].savePrak3 = arr[i].nilaiPrak;
                arr[data.jmlNilai3].savePost3 = arr[i].nilaiPost;

                arr[i].setPertemuan3 = (arr[i].savePre3 + arr[i].savePrak3 + arr[i].savePost3) / 3;

                arr[i].nilaiFinal = (arr[i].setPertemuan1 + arr[i].setPertemuan2 + arr[i].setPertemuan3) / 3;
                data.jmlNilai3++;
            }
        }
    }   
}
//end - INPUT NILAI//

/* TAMPIL */
void Main :: viewData(int jmlMahasiswa) {
    for (int i = 0; i < jmlMahasiswa; i++) {
        for (int j = 0; j < 15; j++) {
            arr2[i][0].view = arr[i].saveNim;
            arr2[i][1].view = arr[i].saveNama;
            stringstream pre;
            pre << arr[i].savePre;
            arr2[i][2].view = pre.str();
            stringstream prak;
            prak << arr[i].savePrak;
            arr2[i][3].view = prak.str();
            stringstream post;
            post << arr[i].savePost;
            arr2[i][4].view = post.str();
            stringstream per1;
            per1 << arr[i].setPertemuan1;
            arr2[i][5].view = per1.str();
            stringstream pre2;
            pre2 << arr[i].savePre2;
            arr2[i][6].view = pre2.str();
            stringstream prak2;
            prak2 << arr[i].savePrak2;
            arr2[i][7].view = prak2.str();
            stringstream post2;
            post2 << arr[i].savePost2;
            arr2[i][8].view = post2.str();
            stringstream per2;
            per2 << arr[i].setPertemuan2;
            arr2[i][9].view = per2.str();
            
            stringstream pre3;
            pre3 << arr[i].savePre3;
            arr2[i][10].view = pre2.str();
            stringstream prak3;
            prak3 << arr[i].savePrak3;
            arr2[i][11].view = prak3.str();
            stringstream post3;
            post3 << arr[i].savePost3;
            arr2[i][12].view = post3.str();
            stringstream per3;
            per3 << arr[i].setPertemuan3;
            arr2[i][13].view = per3.str();
            
            stringstream final;
            final << arr[i].nilaiFinal;
            arr2[i][14].view = final.str();
        }
    }
    view2D(jmlMahasiswa);
}

void Main::view2D(int jmlMahasiswa) {
    const int dalam = 15;
    string sub[dalam] = {
        "NIM\t", "Nama\t", "PRE", "PRAK", "POST",
        "Pert1", "PRE", "PRAK", "POST", "Pert2",
        "PRE", "PRAK", "POST", "Pert3", "Total Nilai\t"
    };

    // Cetak judul kolom
    for (int j = 0; j < dalam; j++) {
            cout << "| " << sub[j] << "\t";
        }
        cout << "|" << endl;

    // Cetak data mahasiswa
    for (int i = 0; i < jmlMahasiswa; i++) {
        for (int j = 0; j < dalam; j++) {
            cout << "| " << arr2[i][j].view << "\t";
        }
        cout << "|" << endl;
    }
    
    setSystem();
}
/* end-TAMPIL */

/*SHOORTING*/
void Main::bubbleSortAscending(int jmlMahasiswa) {
    for (int i = 0; i < jmlMahasiswa - 1; i++) {
        for (int j = 0; j < jmlMahasiswa - i - 1; j++) {
            if (arr[j].nilaiFinal > arr[j + 1].nilaiFinal) {
                db_nilai temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Main::bubbleSortDescending(int jmlMahasiswa) {
    for (int i = 0; i < jmlMahasiswa - 1; i++) {
        for (int j = 0; j < jmlMahasiswa - i - 1; j++) {
            if (arr[j].nilaiFinal < arr[j + 1].nilaiFinal) {
                db_nilai temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Main::viewSortedDataAscending(int jmlMahasiswa) {
    bubbleSortAscending(jmlMahasiswa);
    viewData(jmlMahasiswa);
}

void Main::viewSortedDataDescending(int jmlMahasiswa) {
    bubbleSortDescending(jmlMahasiswa);
    viewData(jmlMahasiswa);
}
/*end-SHOORTING*/

/* SHEARCING */
void Main::searchByNIM(const string& searchNIM) {
    int foundIndex = -1;
    for (int i = 0; i < data.jmlMahasiwa; i++) {
        if (arr[i].saveNim == searchNIM) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        cout << "Data ditemukan:\n";
        cout << "Nama Lengkap: " << arr[foundIndex].saveNama << "\n";
        cout << "NIM         : " << arr[foundIndex].saveNim << "\n";
        cout << "Nilai Akhir : " << arr[foundIndex].nilaiFinal << "\n";
    } else {
        cout << "Data dengan NIM " << searchNIM << " tidak ditemukan.\n";
    }
    
    setSystem();
}
/* end-SHEARCING */

void Main :: setDisplay() {
    system("cls");
    cout << "===== PROGRAM SYSTEM REKAP NILAI =====" << endl;
    cout << "======== PRAKTIKUM MAHASISWA =========" << endl << endl;
    cout << " > Masuk Ke Dalam Aplikasi ->";
    system("pause");
    setSystem();
}

void Main :: setSystem () {
    int pil;
    cout << endl;
    cout << "======================================" << endl;
    cout << "Menu Aplikasi :" <<  endl;
    cout << "1. Tambah Data Mahasiswa\n2. Lihat Data Mahasiwa\n3. Input Nilai\n4. Tampil\n5. Urutkan dan Tampilkan Data\n6. Cari Data Berdasarkan NIM\n7. Keluar...\n\nMasukkan Pilihan : "; cin >> pil;
    if (pil == 1) {
        system("cls");
        setValue();
    } else if(pil == 2) {
        system("cls");
        getName(data.jmlMahasiwa);
    } else if(pil == 3) {
        system("cls");
        setPer();
    } else if(pil == 4) {
        system("cls");
        viewData(data.jmlMahasiwa);
    } else if (pil == 5) {
        system("cls");
        cout << "Pilih urutan data:\n";
        cout << "1. Urutkan dari terkecil ke terbesar\n";
        cout << "2. Urutkan dari terbesar ke terkecil\n";
        cout << "Pilih: ";
        int urutan;
        cin >> urutan;
        if (urutan == 1) {
            viewSortedDataAscending(data.jmlMahasiwa);
        } else if (urutan == 2) {
            viewSortedDataDescending(data.jmlMahasiwa);
        } else {
            cout << "Pilihan tidak valid.\n";
        }
    } else if (pil == 6) {
        system("cls");
        string searchNIM;
        cout << "Masukkan NIM yang ingin dicari: ";
        cin.ignore();
        getline(cin, searchNIM);
        searchByNIM(searchNIM);
    } else {
        system("cls");
        setDisplay();
    }
}


int main () {
    Main view;
    view.setDisplay();
}
