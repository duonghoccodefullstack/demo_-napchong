#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

 




 
//class Sach
//{
//private:
//    string tieuDe ; string tacGia;
//    int namXuatBan , n  ;
//  
//public:
//    void set()
//    {
//        
//         cout << " -------------------- "<< endl;
//         cin.ignore();
//        cout << "Nhap tieu de sach:"; getline(cin, this->tieuDe);
//        
//        cout << "Nhap ten tac gia: ";getline(cin, this->tacGia);
//        cout << "Nhap nam xuat ban: "; cin >> this->namXuatBan;
//        cout << "Nhap id: ";
//    }
// 
//    void get()
//    {
//    	  cout << " -------------------- "<< endl;
//        	cout << "da them sach "<< endl;
////       cout << "tieu de sach: "<<this->tieuDe << endl;
////        cout << "ten tac gia: "<<this->tacGia << endl;
////        cout << "nam xuat ban :"<< this->namXuatBan<< endl; 
////        cout << " -------------------- "<< endl;
//    }
//   
//};

class Sach {
	protected:
        char MaSach[10];
        char TenSach[100];
        char TheLoai[100];
        char TacGia[100];
        int NamXuatBan;
    public:
        void setSach(char[], char[], char[], char[], int);
        void setMaSach(char[]);
        void setTenSach(char[]);
        void setTheLoai(char[]);
        void setTacGia(char[]);
        void setNamXuatBan(int);
        string getMaSach();
        string getTenSach();
        string getTheLoai();
        string getTacGia();
        int getNamXuatBan();
};


void Sach :: setSach(char Ma[], char Ten[], char Loai[], char TG[], int NXB) {
    strcpy(MaSach, Ma);
    strcpy(TenSach, Ten);
    strcpy(TheLoai, Loai);
    strcpy(TacGia, TG);
    NamXuatBan = NXB;
}

void Sach :: setMaSach(char Ma[]) {
    strcpy(MaSach, Ma);
}

void Sach :: setTenSach(char Ten[]) {
    strcpy(TenSach, Ten);
}

void Sach :: setTheLoai(char Loai[]) {
    strcpy(TheLoai, Loai);
}

void Sach :: setTacGia(char TG[]) {
    strcpy(TacGia, TG);
}

void Sach :: setNamXuatBan(int NXB) {
    this -> NamXuatBan = NXB;
}

string Sach :: getMaSach() {
    return MaSach;
}

string Sach :: getTenSach() {
    return TenSach;
}

string Sach :: getTheLoai() {
    return TheLoai;
}

string Sach :: getTacGia() {
    return TacGia;
}

int Sach :: getNamXuatBan() {
    return NamXuatBan;
}

void Menu() {
  
    cout << endl;
    cout << "------ Book management software-------" << endl;
    cout << "1. Nhap them mot cuon sach" << endl;
   
    cout << "2. Xoa mot cuon sach" << endl;
 	cout << "4.Thoat"<< endl;
   
 
    cout << "=> Moi chon chuc nang: ";
}
 
 void ThemSach() {
    cout << "\t\tNhap them mot cuon sach" << endl;
    cout << endl;
    char MS[10], Ten[100], Loai[100], TG[100];
    int NXB;;
    cin.ignore();
    cout << "- Nhap ma sach: ";
    cin.getline(MS, 10);
    cout << "- Nhap ten sach: ";
    cin.getline(Ten, 100);
    cout << "- Nhap the loai: ";
    cin.getline(Loai, 100);
    cout << "- Nhap tac gia: ";
    cin.getline(TG, 100);
    cout << "- Nhap nam xuat ban: ";
    cin >> NXB;
    Sach New;
    New.setSach(MS, Ten, Loai, TG, NXB);
    cout << endl;
    cout << "\t\tThem sach thanh cong ^^" << endl;
  
   
}
 
// void XoaSach() {
//    // Tìm và xoá theo mã sách, không xoá được nếu sinh viên đang mượn cuốn sách này
//    cout << "\t\tXoa mot cuon sach" << endl;
//    cout << endl;
//    string Find;
//    Sach Delete;
// 
//    cin.ignore();
//    cout << "- Nhap ma sach can xoa: ";
//    getline(cin, Find);
//  
//    if(!readMuon) {
//        cout << endl;
//        cout << "\t\tLoi doc du lieu !" << endl;
//    }
//    else {
//        bool check_1 = false;
//        while(!readMuon.eof()) {
//            readMuon.read((char *)(&Muon), sizeof(MuonTra));
//            if(Find == Muon.getMaSach()) {
//                check_1 = true;
//            }
//        }
//        if(check_1 == false) {
//            if(!readSach) {
//                cout << endl;
//                cout << "\t\tLoi doc du lieu !" << endl;
//            }
//            else {
//                bool check_2 = false;
//                while(!readSach.eof()) {
//                    readSach.read((char *)(&Delete), sizeof(Sach));
//                    if(Find == Delete.getMaSach()) {
//                        readSach.read((char *)(&Delete), sizeof(Sach));
//                        check_2 = true;
//                    }
//                    if(readSach.good()) {
//                        deleteSach.write((char *)(&Delete), sizeof(Sach));
//                    }
//                }
//                if(check_2 == false) {
//                    cout << endl;
//                    cout << "\t\tMa sach khong ton tai. Vui long thu lai!" << endl;
//                }
//                else {
//                    cout << endl;
//                    cout << "\t\tXoa thanh cong!" << endl;
//                }
//            }
//        }
//        else {
//            cout << endl;
//            cout << "\t\tSach nay dang duoc muon. Khong the xoa, vui long thu lai!" << endl;
//            return;
//        }
//    }
//    deleteSach.close();
//    readMuon.close();
//    readSach.close();
//    // Sao chép dữ liệu từ file deletesach.bin sang file sach.bin
//    ofstream save_readSach("sach.bin", ios :: binary);
//    ifstream read_deleteSach("deletesach.bin", ios :: binary);
//    while(!read_deleteSach.eof()) {
//        read_deleteSach.read((char *)(&Delete), sizeof(Sach));
//        if(read_deleteSach.good()) {
//            save_readSach.write((char *)(&Delete), sizeof(Sach));
//        }
//    }
//    read_deleteSach.close();
//    save_readSach.close();
//}


void Thoat() {
    cout << endl;
    cout << "\t\tXin chao va hen gap lai!" << endl;
    cout << endl;
}
 int main () {	
// 		cout << "------ Book management software-------" << endl;
//	 	int n ;
//	 	try_again:
//	 	cout << "1.Them  Sach" << endl << "2.Xoa Sach" << endl << "3.Tim Kiem Sach Theo TacGia" << endl << "4.Thoat" << endl;
//	 	cout << "Moi ban chon chuc nang :";
//	 	Sach obj;
//		 
//		 cin >> n;
	 int chon;
    do {
        Menu();
        cin >> chon;
        cout << "=========================" << endl;
        switch(chon) {
            case 1:
                ThemSach();
                break;
//            case 2:
//                 XoaSach();
//                break;
//            case 3:
//               	TimKiemSachTheoTacGia();
            case 4:
               Thoat();
                break;
           
        }
        if(chon != 4) {
            cout << endl;
            cout << "========================="<<endl;
            cout << "=> Nhan Enter de tro ve !";
            cin.ignore();
            cin.get();
            system("clear");
        }
    }
    while(chon != 4);
		
	return 0;
	
}