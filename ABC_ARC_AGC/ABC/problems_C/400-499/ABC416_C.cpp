#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <deque>
#include <map>
using namespace std;


void solve(int n, int k, int x, vector<string> s, string &ans){
    //cout << "n:" << n << ",k:" << k << ",x:" << x << endl;
    if(x == 0){
        for(int i = 0; i < k; i++){
            ans += s.at(n-1);
        }
    }
    if(x == 1){
        //cout << "B" << endl;
        for(int i = 0; i < k; i++){
            ans += s.at(0);
        }
    }

    if(x >= 2){
        //cout << "C" << endl;
        int t = 1, u = 0; //t = n^u
        while(t+1 > x || x > t * n){
            t = t * n;
            u++;
        }
        //cout << "t:" << t << endl;
        for(int i = 0; i < k-u-1; i++){
            ans += s.at(0);
        }
        int y = x / t;
        int z = x % t;
        //cout << "y:" << y << ",z:" << z << endl;
        if(y == n){
            for(int i = 0; i < k; i++){
                ans += s.at(n-1);
            }
            return;
        }
        ans += s.at(y);
        solve(n,u,z,s,ans);
    }
    return;
}

int main(){
    int N, K, X;
    cin >> N >> K >> X;
    string ans = "", s = "";
    set<string> a;
    vector<string> S(N);
    for(int i = 0; i < N; i++){cin >> S.at(i);}
    sort(S.begin(), S.end());
    solve(N, K, X, S, ans);
    cout << ans << endl;
}