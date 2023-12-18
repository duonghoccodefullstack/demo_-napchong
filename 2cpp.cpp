
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

class Sach {
public:
  string tieuDe;
  string tacGia;
  int namXuatBan;

  Sach() {
    this->tieuDe = "";
    this->tacGia = "";
    this->namXuatBan = 0;
  }

  void setTieuDe(const string& tieuDe) {
    this->tieuDe = tieuDe;
  }

  string getTieuDe() const {
    return tieuDe;
  }

  // Tương tự với các thuộc tính và phương thức khác

};

void ThemSach() {
  Sach sach;
  cout << "Nhap tieu de sach: "; getline(cin, sach.tieuDe);
  cout << "Nhap tac gia sach: "; getline(cin, sach.tacGia);
  cout << "Nhap nam xuat ban sach: "; cin >> sach.namXuatBan;
  // Thêm sach vào danh sách sách
}


int  main () {
	ThemSach();
}
	
	
