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

template <typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p){os << "(" << p.first << ", " << p.second << ")";return os;}
template <typename T, typename U> pair<T, U> operator+(const pair<T, U> & l, const pair<T, U> & r){return {l.first + r.first, l.second + r.second};}

/*
g++ ABC/problems_D/301-400/ABC321_D.cpp -o a.out && ./a.out < ./input.txt
*/

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    ll n,m,p;
    cin >> n >> m >> p;
    vector<ll> A(n),B(m);
    vecin(A); vecin(B);
    SORT(A); RSORT(B);
    vector<ll> C(m);
    rep(i,m){
        C[i] = B[i];
        if(i > 0) C[i] += C[i-1];
    }
    int j = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        while(j < m && A[i]+B[j] >= p)j++;
        if(j > 0) ans += p*j + A[i]*(m-j) + C[m-1]-C[j-1];
        if(j == 0) ans += A[i]*m + C[m-1];
        //cout << ans << endl;
    }
    cout << ans << endl;
}