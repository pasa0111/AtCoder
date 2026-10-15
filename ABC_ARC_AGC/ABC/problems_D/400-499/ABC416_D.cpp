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
#include <cctype>


using namespace std;
#define ll long long
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i);}
#define sumvecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i); if(i > 0) vec[i] += vec[i-1];}
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));
#define MP make_pair
#define MT make_tuple

/*
g++ ABC/problems_D/401-500/ABC416_D.cpp -o a.out && ./a.out < ./input.txt
*/

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int T;
    cin >> T;
    rep(test,T){
        int n,m;
        cin >> n >> m;
        vector<ll> A(n),B(n);
        vecin(A); vecin(B);
        SORT(A); RSORT(B);
        ll a = 0, b = 0, ans = 0;
        for(b = 0; b < n; b++){
            if(a == n){
                ans += B[b];
                //cout << ans << endl;
                continue;
            }
            while(a < n && A[a]+B[b] < m){
                ans += A[a];
                a++;
            }
            if(a == n) ans += B[b];
            if(a < n){
                ans += (A[a]+B[b])%m;
                a++;
            }
            //cout << ans << endl;
        }
        cout << ans << endl;
        //cout << endl;
    }
}