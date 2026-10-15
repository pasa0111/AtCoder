#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    long long n=0, t=9, u=1, N;
    cin >> N;
    vector<long long> num(10,0);
    for(int i = 0; i < 10; i++){
        long long k = N % 10;
        num.at(k)++;
        //cout << "add:" << k << endl;
        N/=10;
        n++;
        if(N == 0){break;}
    }
    long long a=0, b=0;
    while(t >= 0){
        //cout << "t:" << t << endl;
        if(num.at(t) > 0){
            if(n == 1){
                long long A = a, B = b;
                a = a * 10 + t;
                b = b * 10 + t;
                if(A * b >= a * B){a = A;}
                if(A * b < a * B){b = B;}
            }
            if(n >= 2){
                if(u % 2 == 1){a = a * 10 + t;}
                if(u % 2 == 0){b = b * 10 + t;}
            }
            u++;
            n--;
            num.at(t)--;
        }
        if(num.at(t) == 0){t--;}
    }
    //cout << "a:" << a << ", b:" << b << endl;
    cout << a * b << endl;
}