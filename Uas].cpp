#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

void Menu(){
    cout<<"===================================================="<<endl;  
    cout<<"\tProgram Penjualan Pulsa Elektrik"<<endl;  
    cout<<"===================================================="<<endl;  
    cout<<endl;
    cout<<"Menu Pilihan Operator Pulsa Elektrik"<<endl;
    cout<<"----------------------------------------------------"<<endl;  
    cout<<"\t1. Telkomsel"<<endl; 
    cout<<"\t2. Indosat"<<endl; 
    cout<<"\t3. Xl"<<endl; 
    cout<<"\t4. Axis"<<endl; 
    cout<<"\t5. Esia"<<endl; 
    cout<<"\t6. Flexi"<<endl; 
    cout<<"----------------------------------------------------"<<endl;
}

class PengirimPesan{//base class
    protected://akses-specifier yang hanya boleh di akses oleh derived class
        string teks;//mendeklarasikan variabel
    public://akses-specifier yang di akses oleh siapa saja
        PengirimPesan(string teks){
            this->teks = teks;//untuk membedakan variabel dari teks
        }
    virtual char SetPengirimPesan() = 0;//virutal function
};

class KirimSMS : public PengirimPesan{//derived class
    private://akses-specifier yang hanya di akses di derived class
        string NoHP;//mendeklarasikan variabel
    public://akses-specifier yang di akses oleh siapa saja
        KirimSMS (string NoHP, string teks) :PengirimPesan(teks){//constraktor
            this->NoHP = NoHP; //untuk membedakan variabel dari NoHP
            this->teks = teks; //untuk membedakan variabel dari teks
        }
        char SetPengirimPesan(){//function SetPengirimPesan
            cout << "No. HP                : "<<NoHP<<endl;//sebagai outputan di layar dan memanggil variabel
            cout << "Pesan                 : "<<teks;//sebagai outputan di layar dan memanggil variabel
            return 0;
        }

};

int end(){
	system("exit");
}


int main()
{
    int oprtor,nominal;
    float bayar,harga;
    long uang,sisa;
    char lagi,psnLG, nomor[12];
    
    atas :
        Menu();
    do
    {
        cout<<"Input Operator [1-6]        : ";cin>>oprtor;

        if(oprtor>6)
            cout<<"Maaf Operator Tidak Tersedia"<<endl;
            cout<<"----------------------------------------------------"<<endl;
    }

    while(oprtor>6);
        cout<<"Masukan Nomor Handphone        : ";cin>>nomor;
        cout<<"----------------------------------------------------"<<endl;
        cout<<"Pilih Nominal Pulsa yang dibeli"<<endl;
        cout<<"----------------------------------------------------"<<endl;
        cout<<"\t1. 5.000"<<endl; 
        cout<<"\t2. 10.000"<<endl; 
        cout<<"\t3. 25.000"<<endl; 
        cout<<"\t4. 50.000"<<endl; 
        cout<<"\t5. 100.000"<<endl; 
        cout<<"----------------------------------------------------"<<endl;
        
    do
    {
        cout<<"Pilih Nominal Pulsa [1-5]  : ";cin>>nominal;

        if(nominal>5)
            cout<<"Maaf Nominal Terlalu Banyak!!\n";
    }

    while(nominal>5);
        cout<<"----------------------------------------------------"<<endl;
    {
        switch(oprtor)
        {
            case 1:
            cout<<"Operator Pilihan adalah      : Telkomsel\n";break;
            case 2:
            cout<<"Operator Pilihan adalah      : Indosat\n";break;
            case 3:
            cout<<"Operator Pilihan adalah      : Xl\n";break;
            case 4:
            cout<<"Operator Pilihan adalah      : Axis\n";break;
            case 5:
            cout<<"Operator Pilihan adalah      : Esia\n";break;
            case 6:
            cout<<"Operator Pilihan adalah      : Flexi\n";break;
        }
    }
        cout<<"Nomor Handphone Anda         : "<<nomor<<endl;
    {

    switch(nominal)
    {
        case 1:
        harga=5000;
        cout<<"Nominal Pulsa Pilihan        : 5.000\n";break;
        case 2:
        harga=10000;
        cout<<"Nominal Pulsa Pilihan        : 10.000\n";break;
        case 3:
        harga=25000;
        cout<<"Nominal Pulsa Pilihan        : 25.000\n";break;
        case 4:
        harga=50000;
        cout<<"Nominal Pulsa Pilihan        : 50.000\n";break;
        case 5:
        harga=100000;
        cout<<"Nominal Pulsa Pilihan        : 100.000\n\n";
        }
    }
        cout<<"Apakah Anda Membeli Pulsa[Y/T]    : ";cin>>lagi;
      
    if(lagi=='T'||lagi=='t'){
    	end();
	}
	else if(lagi=='y' || lagi=='Y')

        cout<<"----------------------------------------------------"<<endl;
        bayar=harga+2000;
        cout<<"Harga Pulsa           : Rp. "<<ceil(harga)<<endl;
        cout<<"Harga Jual            : Rp. "<<ceil(bayar)<<endl;
        cout<<"----------------------------------------------------"<<endl;

    do
    {
        cout<<"Total Bayar           : Rp. ";cin>>uang;
        if(uang<bayar)
            cout<<"Maaf uang anda kurang!!\n";
    }

    while(uang<bayar);
        sisa=uang-bayar;
        cout<<"kembalian             : Rp. "<<sisa<<"\n";
        PengirimPesan *pesan = new KirimSMS(nomor,"Terima kasih telah melakukan isi ulang senilai");
        cout<<pesan->SetPengirimPesan()<<ceil(harga)<<endl;//sebagai outputan di layar dan memanggil variabel
        //isi function KirimSMS memberikan ke pointer pesan

        cout<<"===================================================="<<endl;  
        cout<<"Transaksi lagi?[Y/T]        : ";cin>>psnLG;
         
        if(psnLG=='y'||psnLG=='Y'){
        	goto atas;
		}
		else if(psnLG=='t' || psnLG=='T'){
			goto bawah;
		}else{
			cout<<"Salah!!"<<endl;
		}
		bawah:
    
        getch();
        return 0;
		}
	
