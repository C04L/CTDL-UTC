#include <iostream>
#include "SoLon.cpp"

using namespace std;

SoLon fibonacci(SoLon n);
SoLon giaithua(SoLon n);

int main() {

    int n;
    cout << "Nhap gia tri cho n de tinh fibonacci: \n";
    cin >> n;
    fibonacci(SoLon(n)).printSolon();
    int c;
    cout << "Nhap gia tri cho c de tinh giai thua: \n";
    cin >> c;
    giaithua(SoLon(c)).printSolon();
    system("pause");
    return 0;
}
SoLon fibonacci(SoLon n){
    if (n == SoLon(0) || n == SoLon(1)) {
        return n;
    }
    SoLon a(0), b(1), c;
    for (SoLon i = 2; i <= n; i = i + SoLon(1)) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

SoLon giaithua(SoLon n) {
    if (n == SoLon(0) || n == SoLon(1)) {
        return SoLon(1);
    }
    SoLon result(1);
    for (SoLon i = 2; i <= n; i = i + SoLon(1)) {
        result = result * i;
    }
    return result;
}
