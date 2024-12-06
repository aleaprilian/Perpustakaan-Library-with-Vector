#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include<vector>
using namespace std;

void tampilanawal(){
    cout<<" \t\t\t======================================================="<<endl;
    cout<<" \t\t\tSELAMAT DATANG DI PERPUSTAKAAN MAHASISWA PROVINSI RIAU "<<endl;
    cout<<" \t\t\t======================================================="<<endl;
}
void menuawal(){
    cout<<" \t\t\tSILAHKAN PILIH MENU \n"<<" 1.PEMINJAMAN BUKU \n"<<"\n"<<" 2.PENGEMBALIAN BUKU \n"<<"\n"<<" 3.HAPUS BUKU \n"<<"\n"<<" 4.TAMPILKAN LIST BUKU \n"<<endl;
}

int dendabook(int x, int y){                                    //fungsi dengan nilai balik dengan parameter untuk menghitung denda
if(x > y ){
    int denda = x*50000 - y*50000;
    return denda;
}else if ( x < y){
    int denda = 0;
    return denda;
}
}

void tampilanakhir(){
    cout<<" \t\t\t==================================== "<<endl;
    cout<<" \t\t\tPERPUSTAKAAN MAHASISWA PROVINSI RIAU "<<endl;
    cout<<" \t\t\t==================================== "<<endl;
}

void tampilanbaca(){
	cout<<" \t\t\t=============================="<<endl;
    cout<<" \t\t\tTERIMAKASIH ATAS KUNJUNGANNYA "<<endl;
    cout<<" \t\t\t=============================="<<endl;
}

void waktu (){                                              //fungsi tanpa nilai balik untuk menampilkan waktu       
     time_t waktu;   
    time(&waktu);   
    cout << " WAKTU KUNJUNGAN PERPUSTAKAAN : " << asctime(localtime(&waktu));
}



class PeminjamanBuku {
    public :                                                //atribut kelas
    int pilbook,menu,kembali;
    string nama;
    char ulang;
                                                
    
 std::vector<std::string> perpus;                           //untuk menyimpan list buku
 std::string namaBuku;                                     //pendeklarasian vektor

    void listbuku(){         
        cout<<" \t\t\t\t========================== "<<endl;                           //fungsi tanpa nilai balik untuk menampilkan list buku
        cout<<" \t\t\t\t   LIST PEMINJAMAN BUKU    "<<endl;
        cout<<" \t\t\t\t========================== "<<endl;
        cout<<"\n"<<endl;
        cout<<" NAMA PEMINJAM \t\t  : "<< nama << endl;
        cout<<"\n"<<endl;
        for (int i = 0; i < perpus.size(); i++) {
        cout << i + 1 << "." << perpus[i] <<endl;
}
}

    void akhir(){
    tampilanakhir();
        cout<<"\n"<<endl;
        cout<<" NAMA PEMINJAM \t\t  : "<< nama <<endl;
        cout<<"\n"<<endl;
    listbuku();
        cout<<"\n"<<endl;
    waktu();
    tampilanbaca();
}

    void tampil () {
        system("Color 98 ");
        tampilanawal();      
        cout<<" MASUKKAN NAMA MAHASISWA : ";
        getline(cin, nama);


        do { 
            system("cls");
            menuawal();
            cout<<" MASUKKAN PILIHAN : ";
            menu = getch(); 
            switch (menu){
                case '1' :   //menu untuk peminjaman buku 
                    do {    
                        system("cls");
                        cout <<" MASUKKAN NAMA BUKU : ";
                        getline(cin, namaBuku); // Menggunakan getline untuk membaca input string dengan spasi

                        perpus.push_back(namaBuku);  // Menambahkan elemen ke vector
                        cout<<" "<<endl;
                        cout<<" Apakah Anda Ingin Meminjam Lagi? ";
                        ulang = getch ();
                    } while (toupper(ulang) == 'Y');
            
                    system("cls");
                    tampilanakhir();
                    listbuku();
                    break;

                case '2' :  //menu untuk pengembalian buku
                    system("cls");
                if(perpus.size () != 0){
    
                do{
                    listbuku();
                    cout<<" MASUKKAN TOTAL BUKU YANG DIKEMBALIKAN : ";
                    cin>>kembali;
                    cin.ignore();
                if( kembali <= perpus.size() ){
                    int totdenda; 
                    totdenda = dendabook (perpus.size(), kembali); 
                    
                    if(kembali != perpus.size()){
                        cout<<" JUMLAH BUKU TIDAK SESUAI! "<<endl;
                        cout<<" TOTAL DENDA : "<< totdenda <<endl;     
                    } else {
                        tampilanbaca();
                    }
                }else{
                        cout<<" JUMLAH YANG DIMASUKKAN TIDAK VALID! SILAHKAN ULANGI KEMBALI "<<endl;
                }
                        cout<<" Apakah Anda Ingin Mengulang Menu Ini? <y/n>";
                        ulang = getch();
                }while(toupper(ulang) == 'Y');    
                }else {
                        cout<< " SILAHKAN PILIH BUKU TERLEBIH DAHULU "<<"\n"<<endl;
                     } 
                    perpus.clear();                                                     //membersihkan elemen pada vektor
                    break;

                case '3':  // Menu untuk menghapus buku
                    do{
                    system("cls");
                    listbuku();

                    int pilbook;
                    cout<<" MASUKKAN NOMOR BUKU YANG AKAN DIHAPUS : ";
                    cin>>pilbook;
                    cin.ignore();

                if(pilbook < perpus.size()){
                    perpus.erase(perpus.begin() + pilbook - 1);
                }else {
                    cout<<" KODE BUKU TIDAK VALID! "<<endl;
                }
                    cout << " Apakah Anda Ingin Menghapus Lagi ? <y/n> ";
                    ulang = getch ();
                    cout<<" \n "<<endl;
                    }while(toupper(ulang) == 'Y');    
                   
                    break;
                
                case '4' :   //menu untuk menampilkan list buku
                    system("cls");
                    listbuku();
                    cout<<"\n"<<endl;
                    break;  

                default :
                    cout<<" PILIHAN TIDAK ADA ! "<<endl;
            
        }
            cout<<" Apakah Anda Ingin Mengulang Kembali ? ";
            ulang = getch();
        } while (toupper(ulang) == 'Y');

        system("cls");
        akhir();
} 
};
 
int main (){
    PeminjamanBuku pinjam;
    pinjam.tampil();
    return 0;
}

