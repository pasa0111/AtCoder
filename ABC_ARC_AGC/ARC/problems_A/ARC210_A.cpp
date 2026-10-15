#include <bits/stdc++.h> /*  ^__________^  */
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1, 1, 0, 0, -1, -1, 1, 1}; [[maybe_unused]] constexpr ll DY[8] = {0, 0, -1, 1, -1, 1, -1, 1};
#define rep(i,n) for (ll i = 0; i < (ll)(n); i++)
template <typename T> using PLqueue=priority_queue<T>; template <typename T, typename U> istream &operator>>(istream &is, pair<T, U> &p){is >> p.first >> p.second; return is;} template <typename T> vector<T> rotate(vector<T> &S){assert(!S.empty()); int h = S.size(), w = S[0].size(); vector<T> res(w); for (int i = 0; i < w; i++) res[i].resize(h); for (int i = 0; i < w; i++) {for(int j = 0; j < h; j++) {res[i][j] = S[j][w - 1 - i];}} return res;} template <typename T> T &SORT(T &a){sort(a.begin(),a.end()); return a;} template <typename T> T &REVERSE(T &a){reverse(a.begin(), a.end()); return a;} template <ranges::range R> requires(!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) {if constexpr (is_same_v<ranges::range_value_t<R>, string>) {bool f = true; for (const auto &x : a) {if (!f) os << '\n'; f = false; os << x; } return os;} else{os << "{"; bool f = 1; for (const auto &x:a) {if (!f) os << ","; f = 0; os << x;} return os << "}";}}
template <typename T> using PGqueue=priority_queue<T,vector<T>,greater<T>>; template <typename T> vector<vector<T>> &sumvec2d(vector<vector<T>> &A) {ll h = A.size(); if(h == 0) return A; ll w = A[0].size(); for(ll i = 0; i < h; i++) for(ll j = 1; j < w; j++) A[i][j] += A[i][j-1]; for(ll j = 0; j < w; j++) for(ll i = 1; i < h; i++) A[i][j] += A[i - 1][j]; return A;} pair<ll, ll> dirvec(pair<ll, ll> a, pair<ll, ll> b) {ll dx = a.first-b.first, dy = a.second-b.second; if(dx == 0 && dy == 0) return pair(0,0); else if(dx == 0) return pair(0,1); else if(dy == 0) return pair(1, 0); if(dx < 0){dx = -dx; dy = -dy;} ll g = gcd(dx,abs(dy)); dx /= g, dy /= g; return pair(dx,dy);} template <typename T> vector<T> &vecin(vector<T> &a){for(auto &x:a) cin >> x; return a;} template <typename T> T &RSORT(T &a){sort(a.rbegin(), a.rend()); return a;} template <typename T> vector<T> &sumvec(vector<T> &a){ll b = a.size(); for(ll i = 1; i < b; i++) a[i] += a[i-1]; return a;}
template <typename T> T square(T a){return a*a;} template <typename T,typename U> ostream &operator<<(ostream &os,const pair<T,U> &p){os << "(" << p.first << ", " << p.second << ")"; return os;} struct set_stage{set_stage(){ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(20);}}set_stage; template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) {return {a.first+b.first, a.second+b.second};} template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b){return {a.first - b.first, a.second - b.second};} template <typename T,typename U> auto sqabs(const pair<T, U> &a){return square(a.first) + square(a.second);} template <typename T> auto intpow(T a, ll b){using Ret = std::conditional_t<std::is_integral_v<T> && (sizeof(T) < sizeof(ll)), ll, T>; assert(b >= 0); Ret res = 1; Ret base = a; while(b) {if(b & 1) res *= base; b >>= 1; if(!b)break; base *= base;} return res;}
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

/*

A[i]の初期状態 = base[i] とする
クエリq(1 <= q <= Q)の処理後を考える
S[i] = 数列のi番目にクエリqまでに加算された合計 とする
クエリqを処理した後のA[i]は?
A[i] = base[i] + S[i]

0 < A1 < A2 < ... < An が成り立つ
--> 任意のクエリ処理時点で i = 1...n-1について A[i] < A[i+1]
--> base[i] + S[i] < base[i+1] + S[i+1]

0 < A1 だから base[1] = 1 で良い?
A1とA2について
base[1] + S[1] < base[2] + S[2] --> 1 + S[1]-S[2] < base[2]
が常に成り立つようなbase[2]を設定すれば良い
--> base[2] = 1 + max(S[1]-S[2]) + 1
--> 同じことを繰り返せば順番にbase[i]を決定できる

max(S[i-1]-S[i]) = D[i] (i = 2...n) とすれば i = 2...nについて
base[i] = base[i-1] + D[i] + 1
S[i-1] = S[i] = 0 も考えてDは0で初期化する

*/

int main(){
    ll n,q; cin >> n >> q;
    vector<ll> D(n), S(n);
    rep(query,q){
        ll i,x; cin >> i >> x; i--;
        S[i] += x;
        if(i > 0) D[i] = max(D[i], S[i-1]-S[i]);
        if(i < n-1) D[i+1] = max(D[i+1], S[i]-S[i+1]);
    }
    vector<ll> base(n);
    base[0] = 1;
    for(ll i = 1; i < n; i++) base[i] = base[i-1] + D[i] + 1;
    cout << reduce(base.begin(),base.end()) << el;
}