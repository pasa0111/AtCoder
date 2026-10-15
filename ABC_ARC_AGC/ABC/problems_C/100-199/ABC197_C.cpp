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
/*
#include <atcoder/all>
using namespace atcoder;
*/
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
#define el '\n'
#define inf 2147483647
#define INF 9223372036854775807
#define range(a,x,b) ((a) < (x) && (x) < (b))

template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p){os << "(" << p.first << ", " << p.second << ")";return os;}
template <typename T, typename U> pair<T, U> operator+(const pair<T, U>& l, const pair<T, U>& r){return {l.first + r.first, l.second + r.second};}
template <typename T, typename U> vector<T>& operator<<(vector<T>& a, const U& b){a.push_back(b); return a;}
template <typename T> void operator--(vector<T>& a, int){if (!a.empty()) a.pop_back();}
template <typename T, typename U> set<T>& operator<<(set<T>& a, const U& b){a.insert(b); return a;}
template <typename T, typename U> set<T>& operator-=(set<T>& a, const U& b){a.erase(b); return a;}
template <typename T, typename U> queue<T>& operator<<(queue<T>& a, const U& b){a.push(b); return a;}
template <typename T> queue<T>& operator--(queue<T>& a){a.pop(); return a;}
template <typename T, typename U> priority_queue<T, vector<T>, greater<T>>& operator<<(priority_queue<T, vector<T>, greater<T>>& a, const U& b){a.push(b); return a;}
template <typename T> priority_queue<T, vector<T>, greater<T>>& operator--(priority_queue<T, vector<T>, greater<T>>& a){a.pop(); return a;}
template <typename T, typename U> stack<T>& operator<<(stack<T>& a, const U& b){a.push(b); return a;}
template <typename T> stack<T>& operator--(stack<T>& a){a.pop(); return a;}


/*
g++acl path -o a.out && ./a.out < ./input.txt
g++ path -o a.out && ./a.out < ./input.txt
*/


void yesno(bool b){
    if(b) cout << "Yes" << el;
    if(!b) cout << "No" << el;
}

vector<bitset<32>> A;
ll n,a;
unsigned ll ans = INF;

void solve(ll k,vector<bitset<32>> memo){

    if(k == n){
        bitset<32> q = 0;
        for(auto i:memo){
            //cout << i << el;
            q = q^i;
        }
        ans = min(ans,q.to_ullong());
        return;
    }
    
    bitset<32> p = A[k];
    memo << p;
    solve(k+1,memo);
    memo--;
    for(int i = k+1; i < n; i++){
        p = p | A[i];
        memo << p;
        solve(i+1,memo);
        memo--;
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    rep(i,n){
        cin >> a;
        bitset<32> b = a;
        A << b;
    }
    solve(0,{});
    cout << ans << el;
}