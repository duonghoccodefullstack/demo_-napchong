#include <bits/stdc++.h>
using namespace std;

class phanso
{
private:
    int tu, mau;

public:
    phanso()
    {
        tu = mau = 0;
    }

    ~phanso()
    {
        tu = mau = 0;
    }

    void input()
    {
        cout << "Nhap tu so: ";
        cin >> this->tu;
        cout << "Nhap mau so: ";
        cin >> this->mau;
    }

    void output()
    {
        cout << this->tu << "/" << this->mau << endl;
    }

    friend phanso operator+(phanso a, phanso b)
    {
        phanso c;
        c.tu = a.tu * b.mau + a.mau * b.tu;
        c.mau = a.mau * b.mau;
        return c;
    }
};

int main()
{
    phanso a, b, c;

    a.input();
    b.input();

    c = a + b;
    c.output();
}

///

#include <iostream>
#include <string>
#include <cmath>

using namespace std;
class HinhChuNhat
{
private:
    float chieuDai, chieuRong;
    // float chieuDai2, chieuRong2;

public:
    HinhChuNhat()
    {
        chieuDai = 0;
        chieuRong = 0;
        // chieuDai2 = 0;
        // chieuRong2 = 0;
    }
    ~HinhChuNhat()
    {
        chieuDai = 0;
        chieuRong = 0;
        // chieuDai2 = 0;
        // chieuRong2 = 0;
    }

    void set()
    {
        HinhChuNhat() {}
        HinhChuNhat(int chieuDai, int chieuRong)
        {
            this->chieuDai = chieuDai;
            this->chieuRong = chieuRong;
        }
    }

    friend ostream &operator+(ostream &os, HinhChuNhat obj)
    {
        os << obj.chieuDai * obj.chieuRong + obj.chieuDai2 * obj.chieuRong2;

        return os;
    }

    class Hinh
    {
    public:
        void hinh()
        {
            cout << "Hình" << endl;
        }
    };

    int main()
    {
        int chon;
        cout << "Bài 1: Chương trình sử dụng lớp HinhChuNhat và kiểm tra việc nạp chồng toán tử +" << endl;
        cout << "Bài 2: Chương trình sử dụng lớp HinhTron và HinhVuong để kiểm tra tính chính xác của việc kế thừa và tính diện tích." << endl;
        cout << "Chọn bài: ";
        cin >> chon;

        switch (chon)
        {
        case 1:
            HinhChuNhat obj;
            obj.set();
            obj.get();
            obj.is;
            obj.os;
            break;
        case 2:
            Hinh obj1;
            obj1.hinh();
            break;
        }
    }


// project game #include <iostream>
#include <vector>
// #include <cstdlib>
// #include <ctime>

using namespace std;

class NhanVat
{
public:
    string ten;
    int mau;
    int satThuong;
    string monPhai ;
    string tuoi;
    NhanVat(const string &t, int m, int st, const string &mp, const string &ttmp) : ten(t), mau(m), satThuong(st), monPhai(mp), monPhai2(ttmp) {}

    void hienThiThongTin() const
    {
        cout << "Tên: " << ten << ", Máu: " << mau << ", Sát thương: " << satThuong << ", Môn phái: " << monPhai << endl;
        cout << "Kĩ năng môn phái: "  << monPhai2;
        cout << "Kĩ năng môn phái: " << monPhai2;
        }
};

class TroChoi
{
private:
    vector<NhanVat> nhanVats;

public:
    void themNhanVat()
    {
        string tenNhanVat, monPhai;
        int mauNhanVat, satThuongNhanVat, chon;

        cout << "Nhập tên nhân vật: ";
        cin >> tenNhanVat;

        cout << "Nhập máu nhân vật: ";
        cin >> mauNhanVat;

        cout << "Nhập sát thương nhân vật: ";
        cin >> satThuongNhanVat;

        // update code :
        cout << "Các môn phái  " << endl
             << "1.Thiếu Lâm " << endl
             << "2.Nga Mi" << endl
             << "3.Võ Dang " << endl
             << "4.Thiên Nhẫn " << endl;
        cout << "Nhập môn phái : ";

   

        
            cin >> chon;

            if (chon <= 0 && chon > 4)
            {
                cout << "Môn phái không hợp lệ. Vui lòng nhập lại!" << endl;
            }
            else 
            {
                switch (chon) {
                    case 1 :
                        monPhai = "Thiếu Lâm";
                        monPhai2 = "Sát  thương diện rộng ";
                        monPhai2 = "Đánh thắng hồi 50 máu ";
                        break;
                        
                    case  2 :
                        monPhai = "Nga Mi";
                        break;
                    case 3:
                        monPhai = "Võ Dang";
                        break;
                    case 4:
                        monPhai = "Thiên Nhẫn";
                        break;
                }
            }
           
        
            NhanVat nhanVatMoi(tenNhanVat, mauNhanVat, satThuongNhanVat, monPhai,monPhai2);
            nhanVats.push_back(nhanVatMoi);
            cout << "Đã thêm nhân vật thành công!" << endl;
        }

    void xoaNhanVat(const string &ten)
    {
        for (size_t i = 0; i < nhanVats.size(); ++i)
        {
            if (nhanVats[i].ten == ten)
            {
                nhanVats.erase(nhanVats.begin() + i);
                cout << "Đã xoá nhân vật '" << ten << "' thành công!" << endl;
                return;
            }
        }
        cout << "Không tìm thấy nhân vật có tên '" << ten << "'." << endl;
    }

    void hienThiDanhSachNhanVat() const
    {
        cout << "Danh sách nhân vật:" << endl;
        for (size_t i = 0; i < nhanVats.size(); ++i)
        {
            nhanVats[i].hienThiThongTin();
        }
    }

    void chienDau()
    {
        if (nhanVats.size() < 2)
        {
            cout << "Không đủ nhân vật để chiến đấu." << endl;
            return;
        }

        int index1 = rand() % nhanVats.size();
        int index2 = rand() % nhanVats.size();

        NhanVat &nhanVat1 = nhanVats[index1];
        NhanVat &nhanVat2 = nhanVats[index2];

        cout << "Trận đấu bắt đầu: " << nhanVat1.ten << " vs " << nhanVat2.ten << endl;

        while (nhanVat1.mau > 0 && nhanVat2.mau > 0)
        {
            nhanVat1.mau -= nhanVat2.satThuong;
            nhanVat2.mau -= nhanVat1.satThuong;
        }

        if (nhanVat1.mau <= 0)
        {
            cout << nhanVat2.ten << " chiến thắng!" << endl;
            xoaNhanVat(nhanVat1.ten);
        }
        else
        {
            cout << nhanVat1.ten << " chiến thắng!" << endl;
            xoaNhanVat(nhanVat2.ten);
        }
    }
};

int main()
{
    TroChoi troChoi;
    int luaChon;

    do
    {
        cout << "----- Menu -----" << endl;
        cout << "1. Thêm nhân vật" << endl;
        cout << "2. Hiển thị danh sách nhân vật" << endl;
        cout << "3. Chiến đấu" << endl;
        cout << "4. Thoát" << endl;

        cout << "Nhập lựa chọn: ";
        cin >> luaChon;

        switch (luaChon)
        {
        case 1:
            troChoi.themNhanVat();
            break;
        case 2:
            troChoi.hienThiDanhSachNhanVat();
            break;
        case 3:
            troChoi.chienDau();
            break;
        case 4:
            cout << " Ban đã thoát chương trinh" << endl;
            break;
        default:
            cout << " Bạn nhập sai . Xin  vui lòng nhập lại  " << endl;
            continue;   
        }

    } while (luaChon != 0);
    return 0;
}
