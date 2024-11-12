#include <fstream>
#include <iostream>
#include "sinhvien.cpp"
#include <vector>

#ifndef APPCONFIG_CPP
#define APPCONFIG_CPP
class AppConfig {
private:
    vector<SinhVien> dsSinhVien;
public:
    void run() {
        int choice;
        do {
            choice = menu();
            switch (choice) {
                case 1:
                    xemDs();
                break;
                case 2:
                    xemdiem();
                break;
                case 3:
                    themSinhVien();
                break;
                case 4:
                    xoaSinhVien();
                break;
                case 5:
                    timMax();
                break;
                case 6:
                    timMin();
                break;
                case 7:
                    nhapFile();
                break;
                case 8:
                    xuatFile();
                break;
                case 9:
                    sort();
                break;
            }

        } while (choice > 9 || choice < 1);
    }


    int menu() {
        system("cls");
        cout << "Luong sinh vien hien tai: " << dsSinhVien.size() << endl;
        cout << "==============================\n";
        cout << "1. Xem toan bo danh sach sinh vien\n";
        cout << "2. Tim kiem sinh vien dua tren msv\n";
        cout << "3. Them sinh vien\n";
        cout << "4. Xoa sinh vien\n";
        cout << "5. Tim sinh vien co diem cao nhat\n";
        cout << "6. Tim sinh vien co diem thap nhat\n";
        cout << "7. Nhap danh sach tu file txt\n";
        cout << "8. Xuat danh sach ra output.txt\n";
        cout << "9. Sap xep sinh vien theo thu tu diem thap -> cao\n";
        cout << "==============================\n";
        int n;
        cin >> n;
        return n;
    }

    void xemDs() {
        system("cls");
        if (dsSinhVien.empty()) {
            cout << "Khong co sinh vien nao\n";
        }
        for (int i = 0; i < dsSinhVien.size(); i++) {
            cout << "Sinh vien index: " << i << endl;
            cout << dsSinhVien[i] << endl;
        }
        cout << "==============================\n";
        system("pause");
        run();
    }
    void xemdiem() {
        system("cls");
        int msv;
        cout << "Nhap ma sinh vien muon tim: ";
        cin >> msv;
        int k = 0;
        bool found = false;
        while (k < dsSinhVien.size() && found == false) {
            if (dsSinhVien[k].getMasv() == msv) {
                found = true;
            } else {
                k++;
            }
        }
        if (found) {
            cout << dsSinhVien[k];
        } else {
            cout << "Khong tim thay sinh vien co ma so " << msv << endl;
        }
        system("pause");
        run();
    }

    void themSinhVien() {
        system("cls");
        SinhVien sv;
        cin >> sv;
        dsSinhVien.push_back(sv);
        run();
    }
    void xoaSinhVien() {
        int msv;
        cout << "Nhap ma sinh vien muon xoa: ";
        cin >> msv;
        int k = 0;
        bool found = false;
        while (k < dsSinhVien.size() && found == false) {
            if (dsSinhVien[k].getMasv() == msv) {
                found = true;
                dsSinhVien.erase(dsSinhVien.begin() + k);
                cout << "Da xoa sinh vien co ma sv: " << msv << " tai vi tri: " << k << endl;
            } else {
                k++;
            }
        }
        if (!found) {
            cout << "Khong tim thay sinh vien co ma so " << msv << endl;
        }
        system("pause");
        run();
    }
    void timMax() {
        system("cls");
        SinhVien max = dsSinhVien[0];
        for (int i = 1; i < dsSinhVien.size(); i++) {
            if (dsSinhVien[i] > max) {
                max = dsSinhVien[i];
            }
        }
        cout << "Sinh vien co diem cao nhat la: \n" << max;
        system("pause");
        run();
    }
    void timMin() {
        system("cls");
        SinhVien min = dsSinhVien[0];
        for (int i = 1; i < dsSinhVien.size(); i++) {
            if (dsSinhVien[i] < min) {
                min = dsSinhVien[i];
            }
        }
        cout << "Sinh vien co diem thap nhat la: \n" << min;
        system("pause");
        run();
    }
    void nhapFile() {
        system("cls");
        cout << "================LUU Y!!!!======================\n";
        cout << "File txt nhap vao phai co dinh dang sau: \n";
        cout << "Masinhvien \nTensinhvien\ndiem1 diem2 diem3 diemthi\n";
        cout << "===============================================\n";
        system("pause");
        system("cls");
        string filename;
        cout << "Nhap ten file: ";
        cin >> filename;
        ifstream file;
        file.open(filename);
        if (!file.is_open()) {
            cout << "Khong the mo file\n";
            system("pause");
            run();
        }

        SinhVien sv;
        while (file >> sv) {
            dsSinhVien.push_back(sv);
        }
        cout << "Da nhap file thanh cong\n";
        file.close();
        system("pause");
        run();
    }
    void xuatFile() {
        ofstream file;
        file.open("output.txt", ios::out);
        if (!file.is_open()) {
            cout << "Co loi khi tao file\n";
            system("pause");
            run();
        }
        for (int i = 0; i < dsSinhVien.size(); i++) {
            file << dsSinhVien[i];
            cout << dsSinhVien[i];
        }
        cout << "Da xuat file thanh cong\n";
        file.close();
        system("pause");
        run();
    }

    void sort() {
        char choice;
        system("cls");
        cout << "Sap xep se lam thay doi thu tu sinh vien, ban co chac khong? (y/n): ";
        cin >> choice;
        if (choice == 'y') {
            quicksort(dsSinhVien, 0, dsSinhVien.size() - 1);
            cout << "Da sap xep xong\n";
            xemDs();
            system("pause");
            run();
        } else {
            system("cls");
            run();
        }
    }
    void quicksort(vector<SinhVien>& arr, int s, int e) {

        if (e - s + 1 <= 1) {
            return;
        }
        int left = s;
        int ptr = 0;
        SinhVien pivot = arr[e];
        while (ptr < e) {
            if (arr[ptr] < pivot) {
                SinhVien temp = arr[ptr];
                arr[ptr] = arr[left];
                arr[left] = temp;
                left++;
            }
            ptr++;
        }
        arr[e] = arr[left];
        arr[left] = pivot;
        quicksort(arr, s, left - 1);
        quicksort(arr, left + 1, e);
    }

};

#endif




