#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;


void solve(int n, long long k, vector<int> num, long long a, long long b, long long &ans){
    //cout << "n;" << n << ",k:" << k << ",a:" << a << ",b:" << b << endl;
    if(n == 0){ans = max(ans, a*b);}

    if(n >= 1){
        if(num.at(k) == 0){solve(n,k-1,num,a,b,ans);}
        if(num.at(k) >= 1){
            num.at(k)--;
            solve(n-1,k,num,a * 10 + k,b,ans);
            solve(n-1,k,num,a,b * 10 + k,ans);
        }
    }
    return;
}

int main(){
    long long N, ans=0;
    int n=0, t;
    vector<int> num(10,0);
    cin >> N;
    for(int i = 0; i < 10; i++){
        t = N % 10;
        N /= 10;
        n++;
        num.at(t)++;
        //cout << "add:" << t << endl;
        if(N == 0){break;}
    }
    solve(n,9,num,0,0,ans);
    cout << ans << endl;
}