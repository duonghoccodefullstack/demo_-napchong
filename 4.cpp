
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Sach {
private:
    string tieuDe;
    string tacGia;
    int namXuatBan;

public:
    Sach(string tieuDe, string tacGia, int namXuatBan) {
        this->tieuDe = tieuDe;
        this->tacGia = tacGia;
        this->namXuatBan = namXuatBan;
    }

    void HienThiThongTin() {
        cout << "Tiêu đề: " << tieuDe << endl;
        cout << "Tác giả: " << tacGia << endl;
        cout << "Năm xuất bản: " << namXuatBan << endl;
    }

    string GetTacGia() {
        return tacGia;
    }
};

class ThuVien {
private:
    vector<sach> danhSachSach;

public:
    void ThemSach(Sach sach) {
        danhSachSach.push_back(sach);
    }

    void XoaSach(Sach sach) {
        for (int i = 0; i < danhSachSach.size(); i++) {
            if (danhSachSach[i].GetTacGia() == sach.GetTacGia()) {
                danhSachSach.erase(danhSachSach.begin() + i);
                break;
            }
        }
    }

    void TimKiemSachTheoTacGia(string tacGia) {
        cout << "Các sách của tác giả " << tacGia << ":" << endl;
        for (int i = 0; i < danhSachSach.size(); i++) {
            if (danhSachSach[i].GetTacGia() == tacGia) {
                danhSachSach[i].HienThiThongTin();
                cout << endl;
            }
        }
    }
};

int main() {
    ThuVien thuVien;

    Sach sach1("Sách 1", "Tác giả 1", 2000);
    Sach sach2("Sách 2", "Tác giả 2", 2005);
    Sach sach3("Sách 3", "Tác giả 1", 2010);

    thuVien.ThemSach(sach1);
    thuVien.ThemSach(sach2);
    thuVien.ThemSach(sach3);

    thuVien.TimKiemSachTheoTacGia("Tác giả 1");

    thuVien.XoaSach(sach2);

    thuVien.TimKiemSachTheoTacGia("Tác giả 2");

    return 0;
}

