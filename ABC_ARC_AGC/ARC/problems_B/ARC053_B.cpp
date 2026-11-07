// my library: https://github.com/pasa0111/AtCoder/blob/main/.vscode/cpp.code-snippets
#include <bits/stdc++.h> /*  ^__________^  */
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,n) for (ll i = 0; i < (ll)(n); i++)
template <typename T> vector<T> make_vector(size_t a, T b) {return vector<T>(a, b); } template <typename... Ts> auto make_vector(size_t a, Ts... ts) {return vector(a,make_vector(ts...));} template <ranges::range R> requires(!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a); template <typename T,typename U> ostream &operator<<(ostream &os,const pair<T,U> &p){os << "(" << p.first << ", " << p.second << ")"; return os;} template <typename T, typename U> istream &operator>>(istream &is, pair<T, U> &p){is >> p.first >> p.second; return is;} template <typename T> vector<T> rotate(const vector<T> &S){assert(!S.empty()); int h = S.size(), w = S[0].size(); vector<T> res(w); for (int i = 0; i < w; i++) res[i].resize(h); for (int i = 0; i < w; i++) {for(int j = 0; j < h; j++) {res[i][j] = S[j][w - 1 - i];}} return res;} template <typename T> T &SORT(T &a){sort(a.begin(),a.end()); return a;} template <typename T> T &REVERSE(T &a){reverse(a.begin(), a.end()); return a;} template <ranges::range R> requires(!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) {if constexpr (is_same_v<ranges::range_value_t<R>, string>) {bool f = true; for (const auto &x : a) {if (!f) os << '\n'; f = false; os << x; } return os;} else{os << "{"; bool f = 1; for (const auto &x:a) {if (!f) os << ","; f = 0; os << x;} return os << "}";}}
template <typename T> using PLqueue=priority_queue<T>; template <typename T> using PGqueue=priority_queue<T,vector<T>,greater<T>>; template <typename T> vector<vector<T>> &sumvec2d(vector<vector<T>> &A) {ll h = A.size(); if(h == 0) return A; ll w = A[0].size(); for(ll i = 0; i < h; i++) for(ll j = 1; j < w; j++) A[i][j] += A[i][j-1]; for(ll j = 0; j < w; j++) for(ll i = 1; i < h; i++) A[i][j] += A[i - 1][j]; return A;} pair<ll, ll> dirvec(pair<ll, ll> a, pair<ll, ll> b) {ll dx = a.first-b.first, dy = a.second-b.second; if(dx == 0 && dy == 0) return pair(0,0); else if(dx == 0) return pair(0,1); else if(dy == 0) return pair(1, 0); if(dx < 0){dx = -dx; dy = -dy;} ll g = gcd(dx,abs(dy)); dx /= g, dy /= g; return pair(dx,dy);} template <typename T> T& vecin(T& a){for(auto& x:a) cin >> x; return a;} template <typename T> T &RSORT(T &a){sort(a.rbegin(), a.rend()); return a;} template <typename T> T &sumvec(T &a){for(size_t i = 1; i < a.size(); i++) a[i] += a[i-1]; return a;} template <typename T,typename U> bool chmax(T& a, U b){if(a < b){a = b; return true;} return false;}
template <typename T> auto square(T a){using Ret = conditional_t<is_integral_v<T> && (sizeof(T) < sizeof(ll)), ll, T>; return Ret(a)*Ret(a);}  struct set_stage{set_stage(){ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(20);}}set_stage_0w0; template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) {return {a.first+b.first, a.second+b.second};} template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b){return {a.first - b.first, a.second - b.second};} template <typename T> auto intpow(T a, ll b){using Ret = std::conditional_t<std::is_integral_v<T> && (sizeof(T) < sizeof(ll)), ll, T>; assert(b >= 0); Ret res = 1; Ret base = a; while(b){if(b & 1) res *= base; b >>= 1; if(!b)break; base *= base;} return res;} ll intpow(ll a,ll b,ll c){assert(b >= 0 && c > 0); ll res = 1%c, base = (a%c+c)%c; while(b){if(b & 1) res = (res*base)%c; b >>= 1; if(!b) break; base = (base*base)%c;} return res;} template <typename T,typename U> bool chmin(T& a, U b){if(a > b){a = b; return true;} return false;} template <typename T, typename U> auto sqabs(const pair<T,U>& a){return square(a.first) + square(a.second);}
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

/*

x = n を達成できる?
ダメなら x = n/2 を達成できる?
さらにダメなら x = n/3 を達成できる?
...

'a'がcnt['a']個Sに含まれているとする
この'a'の使い道は
- 回文中に "..a...a.." と対になるように2つ置く
- 奇数長の回文の中央に1つ置く
の2通り
cnt['a']が奇数の場合,2番目の使い方を奇数回行う必要
-> 奇数長の回文がその分だけ必要

cnt['a']からcnt['z']の偶奇を調べて,奇数長の回文が少なくともいくつ必要か調べる

例えば cnt['a'],cnt['b'],cnt['c'] が奇数でその他が偶数だったとする
とりあえず'a','b','c'を1つずつ使う
今 "a", "b", "c" の3つがあり,ここから残りの文字を追加して左右に伸ばす
一番短い文字列の左右に残っている文字を2つずつ追加する
もっとうまいやり方ありそうだけどPGqueueで愚直にシミュレーション

*/

int main(){
    string S; cin >> S;
    array<ll,26> cnt = {};
    for(char s:S) cnt[s-'a']++;
    PGqueue<ll> Q;
    for(ll i = 0; i < 26; i++){
        if(cnt[i]%2 == 1){
            Q.push(1);
            cnt[i]--;
        }
    }
    if(Q.empty()){
        cout << S.size() << el;
        return 0;
    }
    ll idx = 0;
    while(idx < 26){
        while(cnt[idx] > 0){
            ll len = Q.top(); Q.pop();
            Q.push(len+2);
            cnt[idx] -= 2;
        }
        idx++;
    }
    cout << Q.top() << el;
}