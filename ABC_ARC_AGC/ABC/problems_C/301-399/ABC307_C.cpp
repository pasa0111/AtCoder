#include <bits/stdc++.h> /*  ^__________^  */
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,n) for (ll i = 0; i < (ll)(n); i++)
template <typename T> vector<T> make_vector(size_t a, T b) {return vector<T>(a, b); } template <typename... Ts> auto make_vector(size_t a, Ts... ts) {return vector<decltype(make_vector(ts...))>(a,make_vector(ts...));} template <ranges::range R> requires(!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a); template <typename T,typename U> ostream &operator<<(ostream &os,const pair<T,U> &p){os << "(" << p.first << ", " << p.second << ")"; return os;} template <typename T, typename U> istream &operator>>(istream &is, pair<T, U> &p){is >> p.first >> p.second; return is;} template <typename T> vector<T> rotate(vector<T> &S){assert(!S.empty()); int h = S.size(), w = S[0].size(); vector<T> res(w); for (int i = 0; i < w; i++) res[i].resize(h); for (int i = 0; i < w; i++) {for(int j = 0; j < h; j++) {res[i][j] = S[j][w - 1 - i];}} return res;} template <typename T> T &SORT(T &a){sort(a.begin(),a.end()); return a;} template <typename T> T &REVERSE(T &a){reverse(a.begin(), a.end()); return a;} template <ranges::range R> requires(!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) {if constexpr (is_same_v<ranges::range_value_t<R>, string>) {bool f = true; for (const auto &x : a) {if (!f) os << '\n'; f = false; os << x; } return os;} else{os << "{"; bool f = 1; for (const auto &x:a) {if (!f) os << ","; f = 0; os << x;} return os << "}";}}
template <typename T> using PLqueue=priority_queue<T>; template <typename T> using PGqueue=priority_queue<T,vector<T>,greater<T>>; template <typename T> vector<vector<T>> &sumvec2d(vector<vector<T>> &A) {ll h = A.size(); if(h == 0) return A; ll w = A[0].size(); for(ll i = 0; i < h; i++) for(ll j = 1; j < w; j++) A[i][j] += A[i][j-1]; for(ll j = 0; j < w; j++) for(ll i = 1; i < h; i++) A[i][j] += A[i - 1][j]; return A;} pair<ll, ll> dirvec(pair<ll, ll> a, pair<ll, ll> b) {ll dx = a.first-b.first, dy = a.second-b.second; if(dx == 0 && dy == 0) return pair(0,0); else if(dx == 0) return pair(0,1); else if(dy == 0) return pair(1, 0); if(dx < 0){dx = -dx; dy = -dy;} ll g = gcd(dx,abs(dy)); dx /= g, dy /= g; return pair(dx,dy);} template <typename T> vector<T> &vecin(vector<T> &a){for(auto &x:a) cin >> x; return a;} template <typename T> T &RSORT(T &a){sort(a.rbegin(), a.rend()); return a;} template <typename T> vector<T> &sumvec(vector<T> &a){ll b = a.size(); for(ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T,typename U> bool chmax(T& a, U b){if(a < b){a = b; return true;} return false;}
template <typename T> T square(T a){return a*a;}  struct set_stage{set_stage(){ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(20);}}set_stage_0w0; template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) {return {a.first+b.first, a.second+b.second};} template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b){return {a.first - b.first, a.second - b.second};} template <typename T> auto intpow(T a, ll b){using Ret = std::conditional_t<std::is_integral_v<T> && (sizeof(T) < sizeof(ll)), ll, T>; assert(b >= 0); Ret res = 1; Ret base = a; while(b){if(b & 1) res *= base; b >>= 1; if(!b)break; base *= base;} return res;} ll intpow(ll a,ll b,ll c){assert(b >= 0 && c > 0); ll res = 1%c; ll base = a%c; while(b){if(b & 1) res = (res*base)%c; b >>= 1; if(!b) break; base = (base*base)%c;} return res;} template <typename T,typename U> bool chmin(T& a, U b){if(a > b){a = b; return true;} return false;} template <typename T, typename U> auto sqabs(pair<T,U> a){return a.first*a.first + a.second*a.second;}
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

int main(){
    ll ha,wa; cin >> ha >> wa;
    vector<string> A(ha),B,X; vecin(A);
    ll hb,wb; cin >> hb >> wb;
    B.resize(hb); vecin(B);
    ll hx,wx; cin >> hx >> wx;
    X.resize(hx); vecin(X);

    auto erase_right = [](vector<string>& S, ll& h, ll& w){
        for(ll i = 0; i < h; i++) if(S[i][w-1] == '#') return false;
        for(ll i = 0; i < h; i++) S[i].pop_back();
        w--;
        return true;
    };

    auto erase_under = [](vector<string>& S, ll& h, ll& w){
        for(ll j = 0; j < w; j++) if(S[h-1][j] == '#') return false;
        S.pop_back();
        h--;
        return true;
    };

    auto left = [&](vector<string>& S, ll& h, ll& w){
        for(ll i = 0; i < h; i++) if(S[i][0] == '#') return false;
        for(ll i = 0; i < h; i++){
            for(ll j = 0; j < w-1; j++) S[i][j] = S[i][j+1];
            S[i][w-1] = '.';
        }
        erase_right(S,h,w);
        return true;
    };

    auto up = [&](vector<string>& S, ll& h, ll& w){
        for(ll j = 0; j < w; j++) if(S[0][j] == '#') return false;
        for(ll j = 0; j < w; j++){
            for(ll i = 0; i < h-1; i++) S[i][j] = S[i+1][j];
            S[h-1][j] = '.';
        }
        erase_under(S,h,w);
        return true;
    };


    while(left(A,ha,wa));
    while(up(A,ha,wa));
    while(erase_right(A,ha,wa));
    while(erase_under(A,ha,wa));
    while(left(B,hb,wb));
    while(up(B,hb,wb));
    while(erase_right(B,hb,wb));
    while(erase_under(B,hb,wb));
    while(left(X,hx,wx));
    while(up(X,hx,wx));
    while(erase_right(X,hx,wx));
    while(erase_under(X,hx,wx));

    bool ans = false;
    for(ll ia = 0; ia+ha-1 < hx && !ans; ia++)for(ll ja = 0; ja+wa-1 < wx && !ans; ja++){
        for(ll ib = 0; ib+hb-1 < hx && !ans; ib++)for(ll jb = 0; jb+wb-1 < wx && !ans; jb++){
            vector<string> Y(hx,string(wx,'.'));
            for(ll i = 0; i < ha; i++)for(ll j = 0; j < wa; j++) Y[ia+i][ja+j] = A[i][j];
            for(ll i = 0; i < hb; i++)for(ll j = 0; j < wb; j++) if(B[i][j] == '#') Y[ib+i][jb+j] = B[i][j];
            if(X == Y) ans = true;
        }
    }
    yesno(ans);
}