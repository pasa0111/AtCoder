#include <bits/stdc++.h> /*  ^__________^  */
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1, 1, 0, 0, -1, -1, 1, 1}; [[maybe_unused]] constexpr ll DY[8] = {0, 0, -1, 1, -1, 1, -1, 1};
#define rep(i,n) for (ll i = 0; i < (ll)(n); i++)
template <ranges::range R> requires(!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a); template <typename T> using PLqueue=priority_queue<T>; template <typename T,typename U> ostream &operator<<(ostream &os,const pair<T,U> &p){os << "(" << p.first << ", " << p.second << ")"; return os;} template <typename T, typename U> istream &operator>>(istream &is, pair<T, U> &p){is >> p.first >> p.second; return is;} template <typename T> vector<T> rotate(vector<T> &S){assert(!S.empty()); int h = S.size(), w = S[0].size(); vector<T> res(w); for (int i = 0; i < w; i++) res[i].resize(h); for (int i = 0; i < w; i++) {for(int j = 0; j < h; j++) {res[i][j] = S[j][w - 1 - i];}} return res;} template <typename T> T &SORT(T &a){sort(a.begin(),a.end()); return a;} template <typename T> T &REVERSE(T &a){reverse(a.begin(), a.end()); return a;} template <ranges::range R> requires(!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) {if constexpr (is_same_v<ranges::range_value_t<R>, string>) {bool f = true; for (const auto &x : a) {if (!f) os << '\n'; f = false; os << x; } return os;} else{os << "{"; bool f = 1; for (const auto &x:a) {if (!f) os << ","; f = 0; os << x;} return os << "}";}}
template <typename T> using PGqueue=priority_queue<T,vector<T>,greater<T>>; template <typename T> vector<vector<T>> &sumvec2d(vector<vector<T>> &A) {ll h = A.size(); if(h == 0) return A; ll w = A[0].size(); for(ll i = 0; i < h; i++) for(ll j = 1; j < w; j++) A[i][j] += A[i][j-1]; for(ll j = 0; j < w; j++) for(ll i = 1; i < h; i++) A[i][j] += A[i - 1][j]; return A;} pair<ll, ll> dirvec(pair<ll, ll> a, pair<ll, ll> b) {ll dx = a.first-b.first, dy = a.second-b.second; if(dx == 0 && dy == 0) return pair(0,0); else if(dx == 0) return pair(0,1); else if(dy == 0) return pair(1, 0); if(dx < 0){dx = -dx; dy = -dy;} ll g = gcd(dx,abs(dy)); dx /= g, dy /= g; return pair(dx,dy);} template <typename T> vector<T> &vecin(vector<T> &a){for(auto &x:a) cin >> x; return a;} template <typename T> T &RSORT(T &a){sort(a.rbegin(), a.rend()); return a;} template <typename T> vector<T> &sumvec(vector<T> &a){ll b = a.size(); for(ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T,typename U> bool chmax(T& a, U b){if(a < b){a = b; return true;} return false;}
template <typename T> T square(T a){return a*a;}  struct set_stage{set_stage(){ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(20);}}set_stage_0w0; template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) {return {a.first+b.first, a.second+b.second};} template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b){return {a.first - b.first, a.second - b.second};} template <typename T> auto intpow(T a, ll b){using Ret = std::conditional_t<std::is_integral_v<T> && (sizeof(T) < sizeof(ll)), ll, T>; assert(b >= 0); Ret res = 1; Ret base = a; while(b){if(b & 1) res *= base; b >>= 1; if(!b)break; base *= base;} return res;} ll intpow(ll a,ll b,ll c){assert(b >= 0 && c > 0); ll res = 1%c; ll base = a%c; while(b){if(b & 1) res = (res*base)%c; b >>= 1; if(!b) break; base = (base*base)%c;} return res;} template <typename T,typename U> bool chmin(T& a, U b){if(a > b){a = b; return true;} return false;}
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

/*

とりあえず文字を数字にしてみる
R=1, B=2, W=3
R @ B = W になるようなうまい演算子@があったら嬉しい --> x@y = 3-(x+y)%3

実験して頂点を求めてみる
最下段がx,yのとき
頂点 = 3-(x+y)%3

x,y,zのとき
頂点 = 3 - (x@y + y@z)%3
    = 3 - (3-(x+y)%3 + 3-(y+z)%3)%3 
    = 3 - (6 - (x+2y+z)%3)%3
    = 3 - (3 - (x+2y+z)%3)%3         // 3で割るので6を3に置き換えても良い

x,y,z,wのとき
頂点 = 3 - ({x,y,z} + {y,z,w})%3
    = 3 - (3 - (3 - (x+2y+z)%3)%3 + 3 - (3 - (y+2z+w)%3)%3)%3
    = 3 - (3 - (3 - (x+3y+3z+w)%3)%3)%3

実験結果:計算式の一番深いところ(x+3y+3z+w や x+2y+z)さえ計算できれば良い

xやyの係数は何? --> 頂点まで登るルートの数



*/

int main(){
    ll n; cin >> n;
    string S; cin >> S;
    vector<ll> A(n);
    for(ll i = 0; i < n; i++){
        if(S[i] == 'R') A[i] = 1;
        else if(S[i] == 'B') A[i] = 2;
        else A[i] = 3;
    }
    ll value = 0;
    ll p = 0, q = 1; // binom = (3^p)*q  (q%3 != 0)
    for(ll i = 0; i < n; i++){
        //binom = binom * (n-1-i)/(i+1); // オーバーフロー! --> binom  (mod 3) を持つ 
        if(p == 0) value += q*A[i];
        if(i == n-1) continue;
        ll tmp = n-1-i;
        while(tmp%3 == 0){
            p++;
            tmp /= 3;
        }
        q = q*tmp%3;
        tmp = i+1;
        while(tmp%3 == 0){
            p--;
            tmp /= 3;
        }
        tmp %= 3;
        if(tmp == 2) q = q*2%3;
    }
    rep(i,n-1) value = 3-value%3;
    if(value == 1) cout << 'R' << el;
    else if(value == 2) cout << 'B' << el;
    else cout << 'W' << el;
}