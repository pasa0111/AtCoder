#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

//n^mをlong long型で返す
long long pwr(long long n, int m){
    long long res = 1;
    for(int i = 0; i < m; i++){res *= n;}
    return res;
}

//整数(0か1)をstringに変換する
string inttostr(long long n){
    if(n == 0){return "0";}
    if(n == 1){return "1";}
    else {return "";}
}

//10進数のnを2進数に変換し、string型で返す(n < 2^60)
string tentotwo(long long n){
    long long x=pwr(2,59);
    string res = "";
    for(int i = 0; i < 60; i++){
        res += inttostr(n/x);
        n %= x;
        x /= 2;
    }
    return res;
}

//nは2進数表記
//答えとなるxを作る
void solve(string n, int a, long long x){
    long long y = x + pwr(2,59-a);

    if(a <= 59){
        solve(n,a+1,x);
        if(n.at(a) == '1'){solve(n,a+1,y);}
    }
    if(a == 60){
        cout << x << endl;
    }
}

int main(){
    long long N;
    cin >> N;
    string n = tentotwo(N);
    //cout << n << endl;
    solve(n,0,0);
}