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
