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
//#include <atcoder/all>
//using namespace atcoder;

using namespace std;
#define ll long long
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i);}
#define sumvecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i); if(i > 0) vec[i] += vec[i-1];}
#define REVERSE(vec) reverse(vecall(vec))
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec); REVERSE(vec)
#define MP make_pair
#define MT make_tuple

template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p){os << "(" << p.first << ", " << p.second << ")";return os;}
template <typename T, typename U> pair<T, U> operator+(const pair<T, U> & l, const pair<T, U> & r){return {l.first + r.first, l.second + r.second};}

constexpr char el = '\n';

/*
g++ template.cpp -o a.out && ./a.out < ./input.txt
g++acl template.cpp -o a.out && ./a.out < ./input.txt
*/



void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

const ll inf = 1000000000000000;
ll n,m,ans = inf;
vector<ll> C(10);
vector<vector<ll>> animal(10); //動物園iにいる動物の番号
vector<ll> see(100);

void solve(ll sum, ll now){
    if(now == n){
        bool check = true;
        for(int i = 0; i < m; i++){
            //cout << see[i] << " ";
            if(see[i] < 2)check = false;
        }
        //cout << el;
        if(check) ans = min(ans,sum);
        return;
    }

    solve(sum,now+1);
    for(int a:animal[now]) see[a]++;
    solve(sum+C[now],now+1);
    for(int a:animal[now]) see[a]++;
    solve(sum+C[now]+C[now],now+1);
    for(int a:animal[now]) see[a] -= 2;
    return;
}

int main(){
    cin >> n >> m;
    rep(i,n) cin >> C[i];
    int k;
    rep(i,m){
        cin >> k;
        int a;
        rep(j,k){
            cin >> a;
            animal[a-1].push_back(i);
        }
    }
    solve(0,0);
    cout << ans << el;
}