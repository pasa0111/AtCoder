#include <bits/stdc++.h> /*  ^__________^  */
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1, 1, 0, 0, -1, -1, 1, 1}; [[maybe_unused]] constexpr ll DY[8] = {0, 0, -1, 1, -1, 1, -1, 1};
#define rep(i,n) for (ll i = 0; i < (ll)(n); i++)
template <typename T> using PLqueue=priority_queue<T>; template <typename T, typename U> istream &operator>>(istream &is, pair<T, U> &p){is >> p.first >> p.second; return is;} template <typename T> vector<T> rotate(vector<T> &S){assert(!S.empty()); int h = S.size(), w = S[0].size(); vector<T> res(w); for (int i = 0; i < w; i++) res[i].resize(h); for (int i = 0; i < w; i++) {for(int j = 0; j < h; j++) {res[i][j] = S[j][w - 1 - i];}} return res;} template <typename T> T &SORT(T &a){sort(a.begin(),a.end()); return a;} template <typename T> T &REVERSE(T &a){reverse(a.begin(), a.end()); return a;} template <ranges::range R> requires(!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) {if constexpr (is_same_v<ranges::range_value_t<R>, string>) {bool f = true; for (const auto &x : a) {if (!f) os << '\n'; f = false; os << x; } return os;} else{os << "{"; bool f = 1; for (const auto &x:a) {if (!f) os << ","; f = 0; os << x;} return os << "}";}}
template <typename T> using PGqueue=priority_queue<T,vector<T>,greater<T>>; template <typename T> vector<vector<T>> &sumvec2d(vector<vector<T>> &A) {ll h = A.size(); if(h == 0) return A; ll w = A[0].size(); for(ll i = 0; i < h; i++) for(ll j = 1; j < w; j++) A[i][j] += A[i][j-1]; for(ll j = 0; j < w; j++) for(ll i = 1; i < h; i++) A[i][j] += A[i - 1][j]; return A;} pair<ll, ll> dirvec(pair<ll, ll> a, pair<ll, ll> b) {ll dx = a.first-b.first, dy = a.second-b.second; if(dx == 0 && dy == 0) return pair(0,0); else if(dx == 0) return pair(0,1); else if(dy == 0) return pair(1, 0); if(dx < 0){dx = -dx; dy = -dy;} ll g = gcd(dx,abs(dy)); dx /= g, dy /= g; return pair(dx,dy);} template <typename T> vector<T> &vecin(vector<T> &a){for(auto &x:a) cin >> x; return a;} template <typename T> T &RSORT(T &a){sort(a.rbegin(), a.rend()); return a;} template <typename T> vector<T> &sumvec(vector<T> &a){ll b = a.size(); for(ll i = 1; i < b; i++) a[i] += a[i-1]; return a;}
template <typename T> T square(T a){return a*a;} template <typename T,typename U> ostream &operator<<(ostream &os,const pair<T,U> &p){os << "(" << p.first << ", " << p.second << ")"; return os;} struct set_stage{set_stage(){ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(20);}}set_stage; template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) {return {a.first+b.first, a.second+b.second};} template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b){return {a.first - b.first, a.second - b.second};} template <typename T,typename U> auto sqabs(const pair<T, U> &a){return square(a.first) + square(a.second);} template <typename T> auto intpow(T a, ll b){using Ret = std::conditional_t<std::is_integral_v<T> && (sizeof(T) < sizeof(ll)), ll, T>; assert(b >= 0); Ret res = 1; Ret base = a; while(b) {if(b & 1) res *= base; b >>= 1; if(!b)break; base *= base;} return res;}
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

int main(){
    ll n,q; cin >> n >> q;
    vector<ld> X(n+1),Y(n+1); rep(i,n) cin >> X[i] >> Y[i];
    X[n] = X[0], Y[n] = Y[0];
    auto tri = [](ld x){
        return x*x*x;
    };
    
    rep(query,q){
        ll u,v; cin >> u >> v; u--,v--;
        ld s = 0;
        ld x = 0, y = 0;
        if(u < v){
            for(ll i = u; i < v; i++){
                s += abs((X[i]-X[i+1])*(Y[i]+Y[i+1]));
                x += ((tri(X[i])-tri(X[i+1]))*(Y[i]-Y[i+1])/3.0 + (square(X[i])-square(X[i+1]))*(X[i]*Y[i+1]-X[i+1]*Y[i])/2.0)/(X[i]-X[i+1]);
                y += ((tri(Y[i])-tri(Y[i+1]))*(X[i]-X[i+1])/3.0 + (square(Y[i])-square(Y[i+1]))*(X[i+1]*Y[i]-X[i]*Y[i+1])/2.0)/(Y[i]-Y[i+1]);
            }
            s += abs((X[v]-X[u])*(Y[v]+Y[u]));
            s /= 2.0;
            x += ((tri(X[v])-tri(X[u]))*(Y[v]-Y[u])/3.0 + (square(X[v])-square(X[u]))*(X[v]*Y[u]-X[u]*Y[v])/2.0)/(X[v]-X[u]);
            y += ((tri(Y[v])-tri(Y[u]))*(X[v]-X[u])/3.0 + (square(Y[v])-square(Y[u]))*(X[u]*Y[v]-X[v]*Y[u])/2.0)/(Y[v]-Y[u]);
            cout << x/s << ' ' << y/s << el;
        }
        else {
            for(ll i = u; i < n; i++){
                s += abs((X[i]-X[i+1])*(Y[i]+Y[i+1]));
                x += ( (tri(X[i])-tri(X[i+1]))*(Y[i]-Y[i+1])/3.0 + (square(X[i])-square(X[i+1])) * (X[i]*Y[i+1]-X[i+1]*Y[i])/2.0 ) / (X[i]-X[i+1]);
                y += ( (tri(Y[i])-tri(Y[i+1]))*(X[i]-X[i+1])/3.0 + (square(Y[i])-square(Y[i+1])) * (X[i+1]*Y[i]-X[i]*Y[i+1])/2.0 ) / (Y[i]-Y[i+1]);
            }
            // s += abs((X[0]-X[n-1])*(Y[0]+Y[n-1]));
            // x += ((tri(X[0])-tri(X[n-1]))*(Y[0]-Y[n-1])/3.0 + (square(X[0])-square(X[n-1]))*(X[0]*Y[n-1]-X[n-1]*Y[0])/2.0)/(X[0]-X[n-1]);
            // y += ((tri(Y[0])-tri(Y[n-1]))*(X[0]-X[n-1])/3.0 + (square(Y[0])-square(Y[n-1]))*(X[n-1]*Y[0]-X[0]*Y[n-1])/2.0)/(Y[0]-Y[n-1]);
            for(ll i = 0; i < v; i++){
                s += abs((X[i]-X[i+1])*(Y[i]+Y[i+1]));
                x += ((tri(X[i])-tri(X[i+1]))*(Y[i]-Y[i+1])/3.0 + (square(X[i])-square(X[i+1]))*(X[i]*Y[i+1]-X[i+1]*Y[i])/2.0)/(X[i]-X[i+1]);
                y += ((tri(Y[i])-tri(Y[i+1]))*(X[i]-X[i+1])/3.0 + (square(Y[i])-square(Y[i+1]))*(X[i+1]*Y[i]-X[i]*Y[i+1])/2.0)/(Y[i]-Y[i+1]);
            }
            s += abs((X[v]-X[u])*(Y[v]+Y[u]));
            s /= 2.0;
            x += ((tri(X[v])-tri(X[u]))*(Y[v]-Y[u])/3.0 + (square(X[v])-square(X[u]))*(X[v]*Y[u]-X[u]*Y[v])/2.0)/(X[v]-X[u]);
            y += ((tri(Y[v])-tri(Y[u]))*(X[v]-X[u])/3.0 + (square(Y[v])-square(Y[u]))*(X[u]*Y[v]-X[v]*Y[u])/2.0)/(Y[v]-Y[u]);
            cout << x/s << ' ' << y/s << el;
        }
    }
}