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

int main(){
    int n;
    ll m;
    cin >> n >> m;
    vector<pair<ll,ll>> A(n);
    vector<vector<ll>> B(11,vector<ll>(n));
    rep(i,n){
        cin >> A[i].first;
        int p = 0, q = 1;
        while(q <= A[i].first){
            p++;
            q *= 10;
        }
        A[i].second = p;
        A[i].first %= m;
    }
    SORT(A);
    rep(i,11){
        ll c = 1;
        rep(j,i){c*=10;}
        rep(j,n){
            B[i][j] = (A[j].first*c)%m;
        }
        SORT(B[i]);
    }
    ll ans = 0;

    //rep(i,n){cout << B[0][i] << " ";}
    //cout << endl;

    rep(i,n){
        ll start = -1, end = n, t = -10, u, p = A[i].second, x = A[i].first;
        if(x != 0){
        while(start != end){
            u = t;
            t = (start+end)/2;
            if(u == t){break;}
            if(B[p][t] <= m-x){start = t;}
            if(B[p][t] > m-x){end = t;}
        }
        while(t >= 0 && B[p][t] > m-x){t--;}
        if(t == -1){t++;}
        while(t < n && B[p][t] <= m-x){t++;}
        t--;
        if(B[p][t] != m-x){continue;}
        ll start2 = -1, end2 = t+1, mid = -10;
        while(start2 != end2){
            u = mid;
            mid = (start2+end2)/2;
            if(u == mid){break;}
            if(B[p][mid] > m-x-1){end2 = mid;}
            if(B[p][mid] <= m-x-1){start2 = mid;}
        }
        while(mid >= 0 && B[p][mid] > m-x-1){mid--;}
        if(mid == -1){mid = 0;}
        while(mid < n && B[p][mid] <= m-x-1){mid++;}
        if(B[p][t] == m-x){ans += t-mid+1;}
        }
        if(x == 0){
        start = -1, end = n, t = -10;
        while(start != end){
            u = t;
            t = (start+end)/2;
            if(u == t){break;}
            if(B[p][t] > 0){end = t;}
            if(B[p][t] == 0){start = t;}
        }
        while(t >= 0 && B[p][t] > 0){t--;}
        while(t < n && B[p][t] <= 0){t++;}
        ans += t;
        }
    }
    cout << ans << endl;
}