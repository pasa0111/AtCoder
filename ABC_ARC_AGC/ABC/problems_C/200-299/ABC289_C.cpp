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
#include <atcoder/all>

using namespace atcoder;
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
g++acl template.cpp -o a.out && ./a.out < ./input.txt
*/


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

vector<vector<int>> S(10);
vector<int> have(11);
int n,m,ans = 0;

void solve(int k){
    if(k == m){
        bool hantei = true;
        for(int x = 1; x <= n; x++){
            if(have[x] == 0) hantei = false;
        }
        if(hantei) ans++;
        return;
    }

    for(int s:S[k]) have[s]++;
    solve(k+1);
    for(int s:S[k]) have[s]--;
    solve(k+1);
    return;
}

int main(){
    cin >> n >> m;
    int c,a;
    rep(i,m){
        cin >> c;
        rep(j,c){
            cin >> a;
            S[i].push_back(a);
        }
    }
    solve(0);
    cout << ans << el;
}