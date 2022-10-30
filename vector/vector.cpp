#include <bits/stdc++.h>

using namespace std;

class Vector {
private:
    int *arr = NULL;
    int size = 0;
    int capacity;

    void expandCapacity() {
        capacity *= 2;
        cout << "Expand capacity to " << capacity << '\n';
        int *arr2 = new int[capacity];
        for (int i = 0; i < size; i++) {
            arr2[i] = arr[i];
        }
        swap(arr, arr2);
        delete[] arr2;
    }

public:
    Vector(int size) {
        if (size < 0) size = 1;
        capacity = size + 10;
        this->size = size;
        arr = new int[capacity];
    }

    int get(int index) {
        assert(index >= 0 && index < size);
        return arr[index];
    }

    int operator [](int index) {
        return arr[index];
    }

    int getFront() {
        return arr[0];
    }

    int getBack() {
        return arr[size - 1];
    }

    void set(int index, int value) {
        assert(index >= 0 && index < size);
        arr[index] = value;
    }

    void pushBack(int value) {
        if (size == capacity) {
            expandCapacity();
        }
        arr[size++] = value;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }

    int findIndex(int value) {
        int ans = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                ans = i;
                break;
            }
        }
        return ans;
    }

    void insert(int index, int value) {
        assert(index >= 0 && index < size);
        if (size == capacity) {
            expandCapacity();
        }
        for (int i = size - 1; i >= index; i--) {
            arr[i + 1] = arr[i];
        }
        arr[index] = value;
        size++;
    }

    void rightRotate() {
        int lastElement = arr[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            arr[i + 1] = arr[i];
        }
        arr[0] = lastElement;
    }

    void rightRotate(int times) {
        times %= size;
        while (times--) {
            rightRotate();
        }
    }

    void leftRotate() {
        int firstElement = arr[0];
        for (int i = 1; i < size; i++) {
            arr[i - 1] = arr[i];
        }
        arr[size - 1] = firstElement;
    }

    int pop(int index) {
        assert(index >= 0 && index < size);
        int deletedElement = arr[index];
        for (int i = index + 1; i < size; i++) {
            arr[i - 1] = arr[i];
        }
        size--;
        return deletedElement;
    }
    
    ~Vector() {
        delete[] arr;
        arr = NULL;
    }
};

/*

ADT: it's concerns about what not how
something like interface
concerec about attributes and function singatures not the implementation

*/

int main() {
    Vector v(10);
    for (int i = 0; i < 10; i++) {
        v.set(i, i);
    }
    v.print();
    cout << v.findIndex(5) << endl;
    cout << v.findIndex(15) << endl;
    cout << v.get(2) << endl;
    cout << v[2] << endl;
    v.pushBack(100);
    v.pushBack(101);
    v.pushBack(102);
    v.print();
    v.insert(3, 404);
    v.print();
    return 0;
}