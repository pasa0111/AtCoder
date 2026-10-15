#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

void solve(int n, int x, int y, long long &ans, map<int,long long> &r, map<int,long long> &b){
    if(n == 1){ans = max(ans,b.at(1));}

    if(n >= 2){
        r[n-1] = r.at(n);
        b.at(n) += r.at(n) * x;

        r.at(n-1) += b.at(n);
        b[n-1] = b.at(n) * y;

        solve(n-1,x,y,ans,r,b);
    }

    return;
}

int main(){
    long long N, X, Y, ans = 0;
    cin >> N >> X >> Y;
    map<int,long long> r,b; //レベル[i]の宝石の数を保存
    r[N] = 1;
    b[N] = 0;
    solve(N,X,Y,ans,r,b);
    cout << ans << endl;
}