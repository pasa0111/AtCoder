#include <bits/stdc++.h> /*  ^__________^  */
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,n) for (ll i = 0; i < (ll)(n); i++)
template <typename T> vector<T> make_vector(size_t a, T b) {return vector<T>(a, b); } template <typename... Ts> auto make_vector(size_t a, Ts... ts) {return vector<decltype(make_vector(ts...))>(a,make_vector(ts...));} template <ranges::range R> requires(!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a); template <typename T,typename U> ostream &operator<<(ostream &os,const pair<T,U> &p){os << "(" << p.first << ", " << p.second << ")"; return os;} template <typename T, typename U> istream &operator>>(istream &is, pair<T, U> &p){is >> p.first >> p.second; return is;} template <typename T> vector<T> rotate(vector<T> &S){assert(!S.empty()); int h = S.size(), w = S[0].size(); vector<T> res(w); for (int i = 0; i < w; i++) res[i].resize(h); for (int i = 0; i < w; i++) {for(int j = 0; j < h; j++) {res[i][j] = S[j][w - 1 - i];}} return res;} template <typename T> T &SORT(T &a){sort(a.begin(),a.end()); return a;} template <typename T> T &REVERSE(T &a){reverse(a.begin(), a.end()); return a;} template <ranges::range R> requires(!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) {if constexpr (is_same_v<ranges::range_value_t<R>, string>) {bool f = true; for (const auto &x : a) {if (!f) os << '\n'; f = false; os << x; } return os;} else{os << "{"; bool f = 1; for (const auto &x:a) {if (!f) os << ","; f = 0; os << x;} return os << "}";}}
template <typename T> using PLqueue=priority_queue<T>; template <typename T> using PGqueue=priority_queue<T,vector<T>,greater<T>>; template <typename T> vector<vector<T>> &sumvec2d(vector<vector<T>> &A) {ll h = A.size(); if(h == 0) return A; ll w = A[0].size(); for(ll i = 0; i < h; i++) for(ll j = 1; j < w; j++) A[i][j] += A[i][j-1]; for(ll j = 0; j < w; j++) for(ll i = 1; i < h; i++) A[i][j] += A[i - 1][j]; return A;} pair<ll, ll> dirvec(pair<ll, ll> a, pair<ll, ll> b) {ll dx = a.first-b.first, dy = a.second-b.second; if(dx == 0 && dy == 0) return pair(0,0); else if(dx == 0) return pair(0,1); else if(dy == 0) return pair(1, 0); if(dx < 0){dx = -dx; dy = -dy;} ll g = gcd(dx,abs(dy)); dx /= g, dy /= g; return pair(dx,dy);} template <typename T> vector<T> &vecin(vector<T> &a){for(auto &x:a) cin >> x; return a;} template <typename T> T &RSORT(T &a){sort(a.rbegin(), a.rend()); return a;} template <typename T> vector<T> &sumvec(vector<T> &a){ll b = a.size(); for(ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T,typename U> bool chmax(T& a, U b){if(a < b){a = b; return true;} return false;}
template <typename T> T square(T a){return a*a;}  struct set_stage{set_stage(){ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(20);}}set_stage_0w0; template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) {return {a.first+b.first, a.second+b.second};} template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b){return {a.first - b.first, a.second - b.second};} template <typename T> auto intpow(T a, ll b){using Ret = std::conditional_t<std::is_integral_v<T> && (sizeof(T) < sizeof(ll)), ll, T>; assert(b >= 0); Ret res = 1; Ret base = a; while(b){if(b & 1) res *= base; b >>= 1; if(!b)break; base *= base;} return res;} ll intpow(ll a,ll b,ll c){assert(b >= 0 && c > 0); ll res = 1%c; ll base = a%c; while(b){if(b & 1) res = (res*base)%c; b >>= 1; if(!b) break; base = (base*base)%c;} return res;} template <typename T,typename U> bool chmin(T& a, U b){if(a > b){a = b; return true;} return false;} template <typename T, typename U> auto sqabs(pair<T,U> a){return a.first*a.first + a.second*a.second;}
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

/*

最長共通部分列を取れば y = 0 が達成可能
--> yを1増やす代わりにxを2以上減らせたりできないか
サンプル1
1 2 1 3
1 3 1
最長共通部分列をとる
1 * 1 *
1 * 1
--> 1の間にある要素を復活させることでxが2減り,yが1増える

o:共通部分列, x:Ai != Bi だが消さない要素, *:消した要素
A: o x x x * * * o     o x * o x x x 
B: o x x x       o * * o x   o x x x *


*/

int main(){
    ll n,m; cin >> n >> m;
    vector<ll> A(n), B(m); vecin(A), vecin(B);
    auto dp = make_vector(n+1,m+1,0LL);
    auto back = make_vector(n+1,m+1,pair(-1LL,-1LL));
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            back[i][j] = {i-1,j-1};
            chmax(dp[i][j], dp[i-1][j-1] + (A[i-1] == B[j-1]));
            if(chmax(dp[i][j], dp[i-1][j])){
                back[i][j] = {i-1,j};
            }
            if(chmax(dp[i][j], dp[i][j-1])){
                back[i][j] = {i,j-1};
            }
        }
    }
    ll x = 0, y = 0;
    ll ra = n, rb = m, la = n, lb = m;
    while(la > 0 && lb > 0 && A[la-1] != B[lb-1]) tie(la,lb) = back[la][lb];
    y += min(ra-la, rb-lb);
    x += max(ra-la, rb-lb) - min(ra-la, rb-lb);
    tie(ra,rb) = {la,lb};
    while(ra > 0 && rb > 0){
        tie(la,lb) = back[la][lb];
        while(la > 0 && lb > 0 && A[la-1] != B[lb-1]) tie(la,lb) = back[la][lb];
        if(la == 0 || lb == 0) la = 0, lb = 0;
        y += min(ra-la-1, rb-lb-1);
        x += max(ra-la-1, rb-lb-1) - min(ra-la-1, rb-lb-1);
        tie(ra,rb) = {la,lb};
    }
    cout << x+y << el;
}