// my library: https://github.com/pasa0111/AtCoder/blob/main/.vscode/cpp.code-snippets
#include <bits/stdc++.h> /*  ^__________^  */
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,n) for (ll i = 0; i < (ll)(n); i++)
template <typename T> vector<T> make_vector(size_t a, T b) {return vector<T>(a, b); } template <typename... Ts> auto make_vector(size_t a, Ts... ts) {return vector<decltype(make_vector(ts...))>(a,make_vector(ts...));} template <ranges::range R> requires(!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a); template <typename T,typename U> ostream &operator<<(ostream &os,const pair<T,U> &p){os << "(" << p.first << ", " << p.second << ")"; return os;} template <typename T, typename U> istream &operator>>(istream &is, pair<T, U> &p){is >> p.first >> p.second; return is;} template <typename T> vector<T> rotate(vector<T> &S){assert(!S.empty()); int h = S.size(), w = S[0].size(); vector<T> res(w); for (int i = 0; i < w; i++) res[i].resize(h); for (int i = 0; i < w; i++) {for(int j = 0; j < h; j++) {res[i][j] = S[j][w - 1 - i];}} return res;} template <typename T> T &SORT(T &a){sort(a.begin(),a.end()); return a;} template <typename T> T &REVERSE(T &a){reverse(a.begin(), a.end()); return a;} template <ranges::range R> requires(!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) {if constexpr (is_same_v<ranges::range_value_t<R>, string>) {bool f = true; for (const auto &x : a) {if (!f) os << '\n'; f = false; os << x; } return os;} else{os << "{"; bool f = 1; for (const auto &x:a) {if (!f) os << ","; f = 0; os << x;} return os << "}";}}
template <typename T> using PLqueue=priority_queue<T>; template <typename T> using PGqueue=priority_queue<T,vector<T>,greater<T>>; template <typename T> vector<vector<T>> &sumvec2d(vector<vector<T>> &A) {ll h = A.size(); if(h == 0) return A; ll w = A[0].size(); for(ll i = 0; i < h; i++) for(ll j = 1; j < w; j++) A[i][j] += A[i][j-1]; for(ll j = 0; j < w; j++) for(ll i = 1; i < h; i++) A[i][j] += A[i - 1][j]; return A;} pair<ll, ll> dirvec(pair<ll, ll> a, pair<ll, ll> b) {ll dx = a.first-b.first, dy = a.second-b.second; if(dx == 0 && dy == 0) return pair(0,0); else if(dx == 0) return pair(0,1); else if(dy == 0) return pair(1, 0); if(dx < 0){dx = -dx; dy = -dy;} ll g = gcd(dx,abs(dy)); dx /= g, dy /= g; return pair(dx,dy);} template <typename T> T& vecin(T& a){for(auto& x:a) cin >> x; return a;} template <typename T> T &RSORT(T &a){sort(a.rbegin(), a.rend()); return a;} template <typename T> vector<T> &sumvec(vector<T> &a){ll b = a.size(); for(ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T,typename U> bool chmax(T& a, U b){if(a < b){a = b; return true;} return false;}
template <typename T> T square(T a){return a*a;}  struct set_stage{set_stage(){ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(20);}}set_stage_0w0; template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) {return {a.first+b.first, a.second+b.second};} template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b){return {a.first - b.first, a.second - b.second};} template <typename T> auto intpow(T a, ll b){using Ret = std::conditional_t<std::is_integral_v<T> && (sizeof(T) < sizeof(ll)), ll, T>; assert(b >= 0); Ret res = 1; Ret base = a; while(b){if(b & 1) res *= base; b >>= 1; if(!b)break; base *= base;} return res;} ll intpow(ll a,ll b,ll c){assert(b >= 0 && c > 0); ll res = 1%c; ll base = a%c; while(b){if(b & 1) res = (res*base)%c; b >>= 1; if(!b) break; base = (base*base)%c;} return res;} template <typename T,typename U> bool chmin(T& a, U b){if(a > b){a = b; return true;} return false;} template <typename T, typename U> auto sqabs(pair<T,U> a){return a.first*a.first + a.second*a.second;}
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

int main(){
    ll n,q; cin >> n >> q;
    vector<pair<ll,ll>> V(n);
    array<vector<pair<ll,ll>>,2> P;
    array<ll,2> cnt = {}; // x = 0 上の点
    rep(i,n){
        ll x,y; cin >> x >> y;
        V[i] = pair(x,y);
        if(x == 0) cnt[y < 0]++;
        else P[x < 0].push_back(pair(x,y));
    }
    // 傾きが大きい順にソート
    rep(i,2) sort(P[i].begin(), P[i].end(), [](const pair<ll,ll>& u, const pair<ll,ll>& v){
        auto [p,q] = u;
        auto [r,s] = v;
        // q/p > s/r
        return q*r > p*s;
    });
    auto upper = [](const pair<ll,ll>& a, const vector<pair<ll,ll>>& W){
        auto [p,q] = a;
        ll past = -1, future = W.size();
        while(future-past > 1){
            // cout << pair(past,future) << el;
            ll hazama = (past+future)/2;
            auto [r,s] = W[hazama];
            if(q*r > p*s) future = hazama;
            else past = hazama;
        }
        return future;
    };
    auto lower = [](const pair<ll,ll>& a, const vector<pair<ll,ll>>& W){
        auto [p,q] = a;
        ll past = -1, future = W.size();
        while(future-past > 1){
            // cout << pair(past,future) << el;
            ll hazama = (past+future)/2;
            auto [r,s] = W[hazama];
            if(q*r >= p*s) future = hazama;
            else past = hazama;
        }
        return future;
    };
    // cout << cnt << el;
    // cout << P[0] << el << P[1] << el;
    while(q--){
        ll a,b; cin >> a >> b; a--,b--;
        auto [ax,ay] = V[a];
        auto [bx,by] = V[b];
        // cout << V[a] << ' ' << V[b] << el;
        ll ans = 0;
        if(ax == 0){
            if(ay > 0){
                ans += cnt[0];
                if(bx < 0) ans += P[0].size() + cnt[1] + upper(V[b],P[1]);
                else if(bx == 0 && by < 0) ans += P[0].size() + cnt[1];
                else if(0 < bx) ans += upper(V[b],P[0]);
            }
            else {
                ans += cnt[1];
                if(bx < 0) ans += upper(V[b],P[1]);
                else if(bx == 0 && by > 0) ans += cnt[0] + P[1].size();
                else if(0 < bx) ans += P[1].size() + cnt[0] + upper(V[b],P[0]);
            }
        }
        else if(bx == 0){
            if(by > 0){
                ans += cnt[0];
                if(ax < 0) ans += P[1].size() - lower(V[a],P[1]);
                else if(0 < ax) ans += P[0].size() - lower(V[a],P[0]) + cnt[1] + P[1].size();
            }
            else {
                ans += cnt[1];
                if(ax < 0) ans += P[1].size() - lower(V[a],P[1]) + cnt[0] + P[0].size();
                else if(0 < ax) ans += P[0].size() - lower(V[a],P[0]);
            }
        }
        else if(ax < 0){
            if(bx < 0){
                if(lower(V[a],P[1]) <= lower(V[b],P[1])) ans = upper(V[b],P[1]) - lower(V[a],P[1]);
                else ans = P[1].size() - lower(V[a],P[1]) + cnt[0] + P[0].size() + cnt[1] + upper(V[b],P[1]);
            }
            else if(0 < bx) ans = P[1].size() - lower(V[a],P[1]) + cnt[0] + upper(V[b],P[0]);
        }
        else if(0 < ax){
            if(bx < 0) ans = P[0].size() - lower(V[a],P[0]) + cnt[1] + upper(V[b],P[1]);
            else if(0 < bx){
                if(lower(V[a],P[0]) <= lower(V[b],P[0])) ans = upper(V[b],P[0]) - lower(V[a],P[0]);
                else ans = P[0].size() - lower(V[a],P[0]) + cnt[1] + P[1].size() + cnt[0] + upper(V[b],P[0]);
            }
        }
        cout << ans << el;
    }
}