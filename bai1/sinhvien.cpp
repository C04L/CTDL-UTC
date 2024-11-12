//
// Created by Coal on 10/23/2024.
//
#ifndef SinhVien_cpp
#define SinhVien_cpp
#include <iostream>
using namespace std;
class SinhVien {
private:
    string hovaten;
    int masv;
    float diem1;
    float diem2;
    float diem3;
    float diemthi;
    float diemtongket;
    friend istream& operator>> (istream& is, SinhVien& sv){
        cout << "Nhap ma sinh vien...\n";
        is >> sv.masv;
        is.ignore();
        cout << "Nhap ho ten...\n";
        getline(is, sv.hovaten);
        cout << "Nhap diem thuong xuyen 1...\n";
        is >> sv.diem1;
        cout << "Nhap diem thuong xuyen 2...\n";
        is >> sv.diem2;
        cout << "Nhap diem thuong xuyen 3...\n";
        is >> sv.diem3;
        cout << "Nhap diem thi...\n";
        is >> sv.diemthi;
        sv.diemtongket = (sv.diemthi +(sv.diem1 + sv.diem2 + sv.diem3)/3)/2;
        return is;
    }
    friend ostream& operator<< (ostream& os,const SinhVien& sv){
        os << sv.hovaten << "\n";
        os << sv.masv<<"\n";
        os << sv.diem1<<"\n";
        os << sv.diem2 <<"\n";
        os << sv.diem3<<"\n";
        os << sv.diemthi<<"\n";
        os << sv.diemtongket << "\n";
        return os;
    }
public:
    SinhVien(const string &lop, const int &masv, const string &hovaten, float diem1, float diem2, float diem3,
        float diemthi)
        : masv(masv),
          hovaten(hovaten),
          diem1(diem1),
          diem2(diem2),
          diem3(diem3),
          diemthi(diemthi) {
        this->diemtongket = (this->diemthi +(this->diem1 + this->diem2 + this->diem3)/3)/2;
    }
    SinhVien() {}
    int getMasv() {
        return masv;
    }
    bool operator<(SinhVien& sv2) const {
        return diemtongket < sv2.diemtongket;
    }
    bool operator>(SinhVien& sv2) const {
        return diemtongket > sv2.diemtongket;
    }
};

#endif
