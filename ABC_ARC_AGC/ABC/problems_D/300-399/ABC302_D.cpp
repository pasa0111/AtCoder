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
g++ ABC/problems_D/301-400/ABC302_D.cpp -o a.out && ./a.out < ./input.txt
*/

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    ll n,m,d;
    cin >> n >> m >> d;
    vector<ll> A(n),B(m);
    vecin(A); vecin(B);
    SORT(A); SORT(B);
    ll ans = -1,a,l = 0, r = 0; //l:A[i]-d<=B[j]を満たす最小のj, r:B[j] <= A[i]+dを満たす最大のj
    rep(i,n){
        a = A[i];
        while(l < m && B[l] < a-d)l++;
        while(r < m && B[r] <= a+d)r++;
        if(0 < r && r <= m) r--;
        //pair<ll,ll> test = MP(l,r);
        //cout << test << endl;
        if(l <= r && a-d <= B[l] && B[r] <= a+d) ans = a+B[r];
    }
    cout << ans << endl;
}