//
// Created by Coal on 11/9/2024.
//
#include <cmath>
#ifndef solon_cpp
#define solon_cpp
#include "MyVector.cpp"
#include <iostream>
class SoLon {
    MyVector<int> arr;
public:

    SoLon() {}
    SoLon(int number) {
        int temp = number;
        if (temp < 10) {
            arr.push_back(temp);
            return;
        }
        while (temp > 0) {
            arr.push_back(temp % 10);
            temp /= 10;
        }
    }
    void printSolon() {
        for (int i = arr.get_size() - 1; i >= 0; i--) {
            std::cout << arr[i] << "";
        }
        std::cout << std::endl;
    }
    //Cong 2 so lon
    SoLon operator+(SoLon other) {
        SoLon result;
        int carry = 0;
        int i = 0;
        while (i < arr.get_size() || i < other.arr.get_size() || carry != 0) {
            int sum = carry;
            if (i < arr.get_size()) {
                sum += arr[i];
            }
            if (i < other.arr.get_size()) {
                sum += other.arr[i];
            }
            carry = sum / 10;
            sum %= 10;
            result.arr.push_back(sum);
            i++;
        }
        return result;
    }
    //Nhan so nguyen
    SoLon operator*(int other) {
        SoLon result;
        int carry = 0;
        for (int i = 0; i < arr.get_size() || carry != 0; i++) {
            int sum = carry;
            if (i < arr.get_size()) {
                sum += arr[i] * other;
            }
            carry = sum / 10;
            sum %= 10;
            result.arr.push_back(sum);
        }
        // std::cout << result.arr.get_capacity();
        return result;
    }
    //Nhan 2 so lon
    SoLon operator*(SoLon other) {
        SoLon result(0);;
        SoLon temp = *this;
        for (int i = 0; i < other.arr.get_size(); i++) {
            result = result + (temp * other.arr[i] * pow(10, i));
        }
        return result;
    }
    //Tru 2 so lon
    SoLon operator-(SoLon other) {
        SoLon result;
        SoLon temp = *this;
        int carry = 0;
        for (int i = 0; i < arr.get_size(); i++) {
            int m;
            if (i > other.arr.get_size() - 1)  {
                other.arr.push_back(0);
            }
            if (temp.arr[i] < other.arr[i] + carry) {
                temp.arr[i] += 10;
                m = (temp.arr[i] - other.arr[i] - carry)%10;
                carry = 1;
            } else {
                m = temp.arr[i] - other.arr[i] - carry;
                carry = 0;
            }
            result.arr.push_back(m);
        }
        while (result.arr.back() == 0) {
            result.arr.pop_back();
        }
        return result;
    }

    bool operator==(const SoLon& other) const {
        SoLon temp = *this;
        SoLon temp2 = other;
        if (temp.arr.get_size() != temp2.arr.get_size()) {
            return false;
        }
        for (int i = 0; i < temp.arr.get_size(); i++) {
            if (temp.arr[i] != temp2.arr[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const SoLon& other) const {
        return !(*this == other);
    }

    bool operator<(const SoLon& other) const {
        SoLon temp = *this;
        SoLon temp2 = other;
        if (temp.arr.get_size() < temp2.arr.get_size()) {
            return true;
        }
        if (temp.arr.get_size() == temp2.arr.get_size()) {
            for (int i = temp.arr.get_size() - 1; i >= 0; i--) {
                if (temp.arr[i] < temp2.arr[i]) {
                    return true;
                }
            }
        }
        return false;
    }
    bool operator>(const SoLon& other) const {
        SoLon temp = *this;
        SoLon temp2 = other;
        if (temp.arr.get_size() > temp2.arr.get_size()) {
            return true;
        }
        if (temp.arr.get_size() == temp2.arr.get_size()) {
            for (int i = temp.arr.get_size() - 1; i >= 0; i--) {
                if (temp.arr[i] > temp2.arr[i]) {
                    return true;
                }
            }
        }
        return false;
    }
    bool operator<=(const SoLon& other) const {
        SoLon temp = *this;
        SoLon temp2 = other;
        if (temp == temp2) {
            return true;
        }
        return !(*this > other);
    }
    bool operator>=(const SoLon& other) const {
        SoLon temp = *this;
        SoLon temp2 = other;
        if (temp == temp2) {
            return true;
        }
        return !(*this < other);
    }
};
#endif