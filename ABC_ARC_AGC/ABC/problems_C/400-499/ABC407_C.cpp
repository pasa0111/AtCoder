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
using mint = modint998244353;

using namespace std;
#define ll long long
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec[i];}
#define sumvecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec[i]; if(i > 0) vec[i] += vec[i-1];}
#define REVERSE(vec) reverse(vecall(vec))
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec); REVERSE(vec)
#define MP make_pair
#define MT make_tuple
#define el '\n'
#define inf 2147483647
#define INF 9223372036854775807
#define range(a,x,b) ((a) < (x) && (x) < (b))

template <typename T> using PLqueue = priority_queue<T>;
template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>;
template <typename T, typename U>   ostream&    operator<<(ostream& os, const pair<T, U>& p){os << "(" << p.first << ", " << p.second << ")";return os;}
template <typename T, typename U>   pair<T, U>  operator+(const pair<T, U>& l, const pair<T, U>& r){return {l.first + r.first, l.second + r.second};}
template <typename T, typename U>   pair<T, U>  operator-(const pair<T, U>& l, const pair<T, U>& r){return {l.first - r.first, l.second - r.second};}
template <typename T, typename U>   vector<T>&  operator<<(vector<T>& a, const U& b){a.push_back(b); return a;}
template <typename T>               void        operator--(vector<T>& a, int){if(!a.empty())a.pop_back();}
template <typename T>               ostream&    operator<<(ostream& os, const vector<T>& a){ll sizesizesize = a.size(); os << "{"; os << a[0]; for(ll i = 1; i < sizesizesize; i++) os << "," << a[i]; os << "}"; return os;}
template <typename T, typename U>   set<T>&     operator<<(set<T>& a, const U& b){a.insert(b); return a;}
template <typename T, typename U>   set<T>&     operator-=(set<T>& a, const U& b){a.erase(b); return a;}
template <typename T>               T           min(set<T>& a){return *a.begin();}
template <typename T>               T           max(set<T>& a){return *a.rbegin();}
template <typename T, typename U>   queue<T>&   operator<<(queue<T>& a, const U& b){a.push(b); return a;}
template <typename T>               void        operator--(queue<T>& a, int){if(!a.empty())a.pop();}
template <typename T, typename U>   PGqueue<T>& operator<<(PGqueue<T>& a, const U& b){a.push(b); return a;}
template <typename T>               void        operator--(PGqueue<T>& a, int){if(!a.empty())a.pop();}
template <typename T, typename U>   PLqueue<T>& operator<<(PLqueue<T>& a, const U& b){a.push(b); return a;}
template <typename T>               void        operator--(PLqueue<T>& a, int){if(!a.empty())a.pop();}
template <typename T, typename U>   stack<T>&   operator<<(stack<T>& a, const U& b){a.push(b); return a;}
template <typename T>               void        operator--(stack<T>& a, int){if(!a.empty())a.pop();}


/*
g++acl path -o a.out && ./a.out < ./input.txt
g++ path -o a.out && ./a.out < ./input.txt
*/


void yesno(bool b){
    if(b) cout << "Yes" << el;
    if(!b) cout << "No" << el;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    ll n = S.size(), ans = 0, cnt = 0;
    for(int i = n-1; i >= 0; i--){
        S[i] = ((10+(S[i]-'0') - cnt)%10) + '0';
        ans += S[i]-'0';
        cnt = (cnt+(S[i]-'0'))%10;
        ans++;
    }
    cout << ans << el;
}