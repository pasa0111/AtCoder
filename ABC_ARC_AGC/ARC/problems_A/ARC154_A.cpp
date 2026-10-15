#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

long long c_i(char c){
    if(c == '0'){return 0;}
    if(c == '1'){return 1;}
    if(c == '2'){return 2;}
    if(c == '3'){return 3;}
    if(c == '4'){return 4;}
    if(c == '5'){return 5;}
    if(c == '6'){return 6;}
    if(c == '7'){return 7;}
    if(c == '8'){return 8;}
    if(c == '9'){return 9;}
    else{return 0;}
}

int main(){
    long long N, a=0, b=0;
    string A, B;
    cin >> N >> A >> B;
    for(unsigned int i = 0; i < N; i++){
        if(c_i(A.at(i)) < c_i(B.at(i))){
            char s = A.at(i);
            A.at(i) = B.at(i);
            B.at(i) = s;
        }
    }

    for(int i = 0; i < N; i++){
        a = 10*a + c_i(A.at(i));
        a %= 998244353;
    }

    for(int i = 0; i < N; i++){
        b = 10*b + c_i(B.at(i));
        b %= 998244353;
    }

    cout << a * b % 998244353 << endl;
}