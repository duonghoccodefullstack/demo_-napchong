//// update game 

    #include <iostream>
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
        string monPhai;
        string kiNangNhanVat;
        NhanVat(const string &t, int m, int st, const string &mp, const string &k) : ten(t), mau(m), satThuong(st), monPhai(mp), kiNangNhanVat(k) {}

        void hienThiThongTin() const
        {
            cout << "Tên: " << ten << ", Máu: " << mau << ", Sát thương: " << satThuong << ", Môn phái: " << monPhai << endl;
            cout << "Kĩ năng: " << kiNangNhanVat << endl;
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
            string kiNangNhanVat;
            int mauNhanVat, satThuongNhanVat, chon;

            cout << "Nhập tên nhân vật: ";
            cin >> tenNhanVat;

            cout << "Nhập máu nhân vật: ";
            cin >> mauNhanVat;

           // cout << "Nhập sát thương nhân vật: ";
            //cin >> satThuongNhanVat;

            // update các môn phái  :
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
                return;
            }

            switch (chon)
            {
            case 1:
                monPhai = "Thiếu Lâm";
                kiNangNhanVat = "\n+ Sát thương diện rộng X2 sát thương \n+Đánh thắng hồi 50 máu";
                break;
            case 2:
                monPhai = "Nga Mi";
                kiNangNhanVat = "\n+ Hồi sinh sau khi chết cộng 50 máu  ";
                break;
            case 3:
                monPhai = "Võ Dang";
                kiNangNhanVat = "\n+ Tăng giáp ảo khi đánh trúng trừ 50 máu phần trăm giáp ";
                break;
            case 4:
                monPhai = "Thiên Nhẫn";
                kiNangNhanVat = "\n+ Hồi sinh thêm 1 mạng \nGiảm sát  thương một nửa ";
                break;
            }

            int sum,sum1;

            sum = rand() % 100 + 1 
            ; //random  1 đến  100
         
            satThuongNhanVat = sum;

            NhanVat nhanVatMoi(tenNhanVat, mauNhanVat, satThuongNhanVat, monPhai, kiNangNhanVat);
            nhanVats.push_back(nhanVatMoi);
            cout << "Đã thêm nhân vật thành công!\n" << endl;
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
            cout << "\n Danh sách nhân vật:" << endl;

            // update  danh sách nhân vật theo số
            int sum = 1;

            for (size_t i = 0; i < nhanVats.size(); ++i)
            {
                cout << "Nhân vật " << sum++ << ": " << endl;
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

            cout << "\n Trận đấu bắt đầu: " << nhanVat1.ten << " vs " << nhanVat2.ten << endl;

            while (nhanVat1.mau > 0 && nhanVat2.mau > 0)
            {

                if (nhanVat1.monPhai == "Võ Đang")

                if (nhanVat1.monPhai == "Thiếu Lâm")
                {
                    for (int i = 0; i < nhanVats.size(); i++)
                    {
                        if (nhanVats[i].ten != nhanVat1.ten && nhanVats[i].mau > 0)
                        {
                            nhanVats[i].mau -= nhanVat1.satThuong * 2;
                        }
                    }
                    
                }

               
                    nhanVat1.mau -= nhanVat2.satThuong;
                nhanVat2.mau -= nhanVat1.satThuong;
            }

            if (nhanVat1.mau <= 0 && nhanVat1.mau > -1 )
            {

                if (nhanVat1.monPhai == "Nga Mi" || nhanVat1.monPhai == "Thiên Nhẫn")
                {
                    nhanVat1.mau += rand();
                                }

                if (nhanVat2.monPhai == "Nga Mi" || nhanVat2.monPhai == "Thiên Nhẫn")
                {
                    nhanVat2.mau += rand();
                }
                else if (nhanVat2.mau == 0)
                {
                    nhanVat2.mau -= (int ) nhanVat1.satThuong;
                }
                else
                {
                    cout<< nhanVat2.ten << " chiến thắng!" << endl;
                    xoaNhanVat(nhanVat1.ten);
                }

                if (nhanVat2.monPhai == "Thiếu Lâm") {
                    nhanVat2.mau += (int )50;
                }

            }
            else
            {
                cout << nhanVat1.ten << " chiến thắng!" << endl;
                xoaNhanVat(nhanVat2.ten);
               
                if (nhanVat1.monPhai == "Thiếu Lâm")
                {
                    nhanVat1.mau += 50;
                }

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

            cout << "Nhập lựa chọn: " ;
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


// project game 
    #include <iostream>
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
        string monPhai;
        string kiNangNhanVat;
        NhanVat(const string &t, int m, int st, const string &mp, const string &k) : ten(t), mau(m), satThuong(st), monPhai(mp), kiNangNhanVat(k) {}

        void hienThiThongTin() const
        {
            cout << "Tên: " << ten << ", Máu: " << mau << ", Sát thương: " << satThuong << ", Môn phái: " << monPhai << endl;
            cout << "Kĩ năng: " << kiNangNhanVat << endl;
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
            string kiNangNhanVat;
            int mauNhanVat, satThuongNhanVat, chon;

            cout << "Nhập tên nhân vật: ";
            cin >> tenNhanVat;

            cout << "Nhập máu nhân vật: ";
            cin >> mauNhanVat;

           // cout << "Nhập sát thương nhân vật: ";
            //cin >> satThuongNhanVat;

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
                return;
            }

            switch (chon)
            {
            case 1:
                monPhai = "Thiếu Lâm";
                kiNangNhanVat = "\n+ Sát thương diện rộng X2 sát thương \n+Đánh thắng hồi 50 máu";
                break;
            case 2:
                monPhai = "Nga Mi";
                kiNangNhanVat = "\n+ Hồi sinh sau khi chết cộng 50 máu  ";
                break;
            case 3:
                monPhai = "Võ Dang";
                kiNangNhanVat = "\n+ Tăng giáp ảo khi đánh trúng trừ 50 máu phần trăm giáp ";
                break;
            case 4:
                monPhai = "Thiên Nhẫn";
                kiNangNhanVat = "\n+ Hồi sinh thêm 1 mạng \nGiảm sát  thương một nửa ";
                break;
            }

            int sum;

            sum = rand() % 100 + 1 ; //random  1 đến  100

            satThuongNhanVat = sum;

            NhanVat nhanVatMoi(tenNhanVat, mauNhanVat, satThuongNhanVat, monPhai, kiNangNhanVat);
            nhanVats.push_back(nhanVatMoi);
            cout << "Đã thêm nhân vật thành công!\n" << endl;
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
            cout << "\n Danh sách nhân vật:" << endl;
            for (size_t i = 0; i < nhanVats.size(); ++i)
            {
                for (int j = 0; j < nhanVats.size(); j++)
                {
                    cout << "Nhân vật " << ++j << " :" << endl;
                }
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

            cout << "\n Trận đấu bắt đầu: " << nhanVat1.ten << " vs " << nhanVat2.ten << endl;

            while (nhanVat1.mau > 0 && nhanVat2.mau > 0)
            {
                if (nhanVat1.monPhai == "Thiếu Lâm")
                {
                    for (int i = 0; i < nhanVats.size(); i++)
                    {
                        if (nhanVats[i].ten != nhanVat1.ten && nhanVats[i].mau > 0)
                        {
                            nhanVats[i].mau -= nhanVat1.satThuong * 2;
                        }
                    }
                    
                }

                nhanVat1.mau -= nhanVat2.satThuong;
                nhanVat2.mau -= nhanVat1.satThuong;
            }

            if (nhanVat1.mau <= 0 && nhanVat1.mau > -1 )
            {
                if (nhanVat2.monPhai == "Nga Mi" || ) {
                    nhanVat2.mau += 50;
                } else if (nhanVat2.mau == 0  ) {
                    nhanVat2.mau -= nhanVat1.satThuong;
                                } else {
                    cout<< nhanVat2.ten << " chiến thắng!" << endl;
                    xoaNhanVat(nhanVat1.ten);
                }


                
                if (nhanVat2.monPhai == "Thiếu Lâm") {
                    nhanVat2.mau += 50;
                }

            }
            else
            {
                cout << nhanVat1.ten << " chiến thắng!" << endl;
                xoaNhanVat(nhanVat2.ten);
               
                if (nhanVat1.monPhai == "Thiếu Lâm")
                {
                    nhanVat1.mau += 50;
                }

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

            cout << "Nhập lựa chọn: " ;
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
