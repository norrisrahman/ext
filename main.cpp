#include <iostream>
#include <array>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

struct Toko {
	string produk;
	int harga;
    string stok;
};

void tulisData ( Toko tulisData) {
    fstream myFile;
    myFile.open("data.txt", ios::app);

    myFile << tulisData.produk << "             " << tulisData.harga << "               " << tulisData.stok <<  endl;

    myFile.close();
}

void tambahData() {
    string tanggal,bulan,tahun, tgl;

    Toko tambahData;

    cout << "Masukkan Nama produk \t\t\t: ";
    cin >> tambahData.produk;
    cout << "Masukkan Harga Produk \t\t\t: ";
    cin >> tambahData.harga;
    cout << "Masukkan Stok Persediaan Produk \t: ";
    cin >> tambahData.stok; 

    tulisData(tambahData);

    cout << endl;
}

void bacaData() {
    ifstream myFile;
    Toko dataToko;

    myFile.open("data.txt");

    myFile >> dataToko.produk;
    myFile >> dataToko.harga;
    myFile >> dataToko.stok;
    
    system ("cls");
    cout << "\nMenampilkan Semua Data :\n" << endl;
    cout << "Nama Produk\t\t" << "Harga\t\t\t" << "Stok Produk"<< endl;
    cout << "======================================================================" << endl;
    while (!myFile.eof()){
        cout << dataToko.produk << "\t\t\t"<< "Rp " << dataToko.harga << "\t\t\t"<< dataToko.stok <<  endl;

        myFile >> dataToko.produk;
        myFile >> dataToko.harga;
        myFile >> dataToko.stok;
    }
    cout << endl;
    
    myFile.close();
    
}

int ukuranData (fstream &myFile) {
    Toko ukuranData;
    int ukuran, hasilukuran;


    myFile.open("data.txt");
    while (getline(myFile, ukuranData.produk))
        ukuran++;

    myFile.close();

    hasilukuran = ukuran;
    return hasilukuran;
}

void prosesPengurutan(struct Toko arr[], int n){
    int i, j;
    struct Toko key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;        
        while (j >= 0 && arr[j].produk > key.produk) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
            arr[j + 1] = key;
    }
}

void pengurutanData () {
    fstream myFile;

    int size = ukuranData(myFile);

    myFile.open("data.txt");

    Toko* pengurutanData = new Toko[size];

    for(int i = 0; i<size; i++){

        myFile >> pengurutanData[i].produk;
        myFile >> pengurutanData[i].harga;
        myFile >> pengurutanData[i].stok;
    }

    myFile.close();

    prosesPengurutan(pengurutanData, size);
    
    system("cls");
    cout << "Hasil Pengurutan Data :\n" << endl;
    cout << "Nama Produk\t\t" << "Harga\t\t\t" << "Stok Produk"<< endl;
    cout << "======================================================================" << endl;
    for ( int i=0; i<size; i++) {
        cout << pengurutanData[i].produk << "\t\t\t"<< "Rp " << pengurutanData[i].harga << "\t\t\t"<< pengurutanData[i].stok <<  endl;
    }

    cout << endl;
}

void simpanData(struct Toko array[], int size) {

    fstream myFile;
    myFile.open("data2.txt", ios::trunc | ios::out);

    for (int i=0; i < size; i++){

        myFile << array[i].produk << "    " << array[i].harga << "   " << array[i].stok << endl;
    }

    myFile.close();
}

void pesanError () {
    system ("cls");
    cout << "\n\nKeyword Invalid / Data Tidak Ada\n\n"<< endl;
}

void hasilCari (Toko array) {
    system ("cls");
    cout << "\nHasil Pencarian Data :\n" << endl;
    cout << "Tanggal\t\t\t" << "ID Record\t" << "Jumlah Telur" << "\t" << "Harga /Kg" << endl;
    cout << "======================================================================" << endl;
    cout << array.produk << "\t\t" << array.harga << "\t" << array.stok << endl;
    cout << endl; 
}

void update() {
    string kataKunci;

    fstream myFile;

    int ukuran = ukuranData(myFile);

    myFile.open("data.txt");

    Toko* array = new Toko[ukuran];

    for(int i = 0; i<ukuran; i++){

        myFile >> array[i].produk;
        myFile >> array[i].harga;
        myFile >> array[i].stok;
    }

    myFile.close();

    cout<<"Masukkan Tanggal Record Untuk Update Data (dd/mm/yyyy) : ";
    cin >> kataKunci;

    for(int i=0;i< ukuran;i++) {
        if(array[i].produk==kataKunci) {
            cout << "\nTanggal\t\t\t" << "ID Record\t" << "Jumlah Telur" << "\t" << "Harga /Kg" << endl;
            cout << "======================================================================" << endl;
            cout << array[i].produk << "\t\t" << array[i].harga << "\t" << array[i].stok  << endl;

            cout << "\nMasukkan Data Baru : " << endl;
                cout << "Masukkan Tanggal \t: ";
                cin >> array[i].produk;
                cout << "Masukkan Bulan \t\t: ";
                cin >> array[i].harga;
                cout << "Masukkan Tahun \t\t: ";
                cin >> array[i].stok;

                simpanData(array, ukuran);

                cout << endl;
            return;
        }
    }
    pesanError();
}

int main() {
    int x;

    cout << "\t\t\t DATABASE BARANG MINIMARKET ABC \t\t\t" << endl;
    menu:
    cout << "Pilih Menu :" << endl;
    cout << "1. Tambahkan Produk" << endl;
    cout << "2. Tampilkan Seluruh Data Produk" << endl;
    cout << "3. Urutkan Produk Berdasarkan Abjad" << endl;
    cout << "4. Mencari Data" << endl;
    cout << "5. Perbarui Data" << endl;
    cout << "6. Hapus Data" << endl;
    cout << "7. Keluar";
    cout << endl;

    cout << "Pilih Menu [1-6]: ";
    cin >> x;

    switch (x) {
    case 1:
        system ("cls");
        tambahData();
        goto menu;
        break;
    case 2 :
        system("cls");
        bacaData();
        goto menu;
        break;
    case 3 :
        system ("cls");
        pengurutanData();
        goto menu;
        break;
    case 5:
        system ("cls");
        update();
        goto menu;
        break;
    default:
        break;
    }

    
	return 0;
}