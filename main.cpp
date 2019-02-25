#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

bool rool[8];
const int size=300;
bool a[size];

void set_rool(int x) {
    for (int i=0; i<8; i++) {
        rool[i] = x / (int) pow(2, 7-i);
        x = x % (int) pow(2, 7-i);
    }
    cout << endl;
}

void print(bool arr[], int length, string s=" ") {
    for (int i=0; i<length; i++) {
        cout << arr[i] << s;
    }
    cout << endl;
}

void draw_print(bool arr[], int length) {
    for (int i=0; i<length; i++) {
        if (arr[i]) cout << "▓▓";
        else cout << "  ";
    }
    cout << endl;
}

bool is_life(int n){
    bool left = a[n-1];
    bool mid = a[n];
    bool right = a[n+1];
    return rool[7-(left*4 + mid*2 + right)];
}

void step() {
    bool new_a[size];
    new_a[0] = 0;
    new_a[size-1] = 0;
    for (int i=1; i<size-1; i++) {
        new_a[i] = is_life(i);
    }
    for (int i=0; i<size; i++) {
        a[i] = new_a[i];
    }
}

int main() {
    int x;
    do {
        cout << "x >> ";
        cin >> x;
        cout << endl;
        set_rool(x);
        print(rool, 8);
        cout << endl;
        for (int i=0; i<size; i++) {
            a[i] = 0;
        }
        a[size/2] = 1;
        for (int i=0; i<size/2; i++) {
            draw_print(a, size);
            step();
        }
        cout << endl;
    } while (x > 0);
    return 0;
}
