//
// Created by Coal on 11/9/2024.
//

#ifndef thevector
#define thevector
template <class T>
class MyVector {
    int size;
    int cap;
    T* arr;
public:
    MyVector() {
        size = 0;
        cap = 1;
        arr = new T[cap];
    }
    void push_back(T val) {
        if (size == cap) {
            cap *= 2;
            T* temp = new T[cap];
            for (int i = 0; i < size; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }
        arr[size++] = val;
    }
    void pop_back() {
        if (size > 0) {
            size--;
        }
    }
    T& operator[](int index) {
        return arr[index];
    }
    int get_size() {
        return size;
    }
    int get_capacity() {
        return cap;
    }

    int back() {
        return arr[size - 1];
    }

};
#endif
