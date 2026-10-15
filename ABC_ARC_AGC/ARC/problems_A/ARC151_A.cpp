#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    int N, n = 0;
    string S, T, ans = "";
    cin >> N >> S >> T;
    for(int i = 0; i < N; i++){
        if(S.at(i) != T.at(i)){n++;}
    }
    if(n % 2 == 1){cout << -1 << endl;}
    if(n % 2 == 0){
        int s = 0, t = 0, m = n/2;
        for(int i = 0; i < N; i++){
            if(S.at(i) == T.at(i)){ans += "0";}
            if(S.at(i) != T.at(i)){
                if(s == m){
                    if(S.at(i) == '0'){ans += "0";}
                    if(S.at(i) == '1'){ans += "1";}
                }
                if(t == m){
                    if(T.at(i) == '0'){ans += "0";}
                    if(T.at(i) == '1'){ans += "1";}
                }
                if(s < m && t < m){
                    if(S.at(i) == '1'){s++;}
                    if(T.at(i) == '1'){t++;}
                    ans += "0";
                }
            }
        }
        cout << ans << endl;
    }
}