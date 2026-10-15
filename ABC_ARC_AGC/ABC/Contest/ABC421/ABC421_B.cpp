#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;

int64_t f(int64_t x){
    int64_t y = x, keta = 0;
    while(y != 0){
        y /= 10;
        keta++;
    }
    int64_t z = 0, a = 1, b, c = 1;
    for(int i = 0; i < keta-1; i++){c *= 10;}
    for(int i = 0; i < keta; i++){
        b = (x % (a * 10) - x % a) / a;
        z += b * c;
        a *= 10;
        c /= 10;
    }
    return z;
}

int main(){
    int64_t X, Y, Z;
    cin >> X >> Y;
    for(int i = 0; i < 8; i++){
    Z = f(X + Y);
    X = Y;
    Y = Z;
    }
    cout << Y << endl;
}