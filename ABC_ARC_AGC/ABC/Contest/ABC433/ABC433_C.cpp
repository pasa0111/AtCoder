#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>


using namespace std;
#define ll long long
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(unsigned ll i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

//サイズが1のchar型xをintにして返す
int char_int(char x){
    int res = 0;
    if(x == '0'){res = 0;}
    if(x == '1'){res = 1;}
    if(x == '2'){res = 2;}
    if(x == '3'){res = 3;}
    if(x == '4'){res = 4;}
    if(x == '5'){res = 5;}
    if(x == '6'){res = 6;}
    if(x == '7'){res = 7;}
    if(x == '8'){res = 8;}
    if(x == '9'){res = 9;}
    return res;
}


int main(){
    string S;
    cin >> S;
    int x = 0,y = 0, start = 0, end = 0, n = S.size(), ans = 0;
    while(end < n){
        while(S[start] == S[end]){
            x++;
            end++;
        }
        int save = end;
        while(char_int(S[start])+1 == char_int(S[end])){
            y++;
            end++;
        }
        ans += min(x,y);
        start = save;
        x = y;
        y = 0;
    }
    cout << ans << endl;
}