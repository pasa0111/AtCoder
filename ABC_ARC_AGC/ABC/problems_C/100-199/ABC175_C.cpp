#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    long long X, K, D, ans;
    cin >> X >> K >> D;
    long long T = (abs(X)+D-1)/D; //高橋君が原点を通過するのに必要な移動回数の最小値

    if(T == 0){
        if(K % 2 == 0){ans = 0;}
        if(K % 2 == 1){ans = D;}
    }

    if(T <= K && T >= 1){
        if(X >= 0){
            long long Y = X - T * D; //T回原点に向かって移動した直後の座標
            long long Z = X - (T-1) * D; //T-1回原点に向かって移動した直後の座標
            if(abs(Y) <= abs(Z)){
                if((K-T)% 2 == 0){ans = abs(Y);}
                if((K-T)% 2 == 1){ans = abs(Z);}
            }
            if(abs(Y) > abs(Z)){
                if((K-T+1)%2 == 0){ans = abs(Z);}
                if((K-T+1)%2 == 1){ans = abs(Y);}
            }
        }

        if(X < 0){
            long long Y = X + T * D;
            long long Z = X + (T-1) * D;
            if(abs(Y) <= abs(Z)){
                if((K-T)% 2 == 0){ans = abs(Y);}
                if((K-T)% 2 == 1){ans = abs(Z);}
            }
            if(abs(Y) > abs(Z)){
                if((K-T+1)%2 == 0){ans = abs(Z);}
                if((K-T+1)%2 == 1){ans = abs(Y);}
            }
        }
    }

    if(T > K){
        if(X >= 0){ans = X - D*K;}
        if(X < 0){ans = abs(X + D*K);}
    }
    cout << ans << endl;
}