#include <bits/stdc++.h> /*  ^__________^  */
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> auto sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); } template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;}
template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {sort(a.rbegin(),a.rend()); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; } template <typename T> vector<vector<T>>& sumvec2d(vector<vector<T>>& A){ll h = A.size(); if(h == 0) return A; ll w = A[0].size(); for(ll i = 0; i < h; i++)for(ll j = 1; j < w; j++) A[i][j] += A[i][j-1]; for(ll j = 0; j < w; j++)for(ll i = 1; i < h; i++) A[i][j] += A[i-1][j]; return A;}
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

pair<ll,ll> dirvec(pair<ll,ll> a, pair<ll,ll> b){ ll dx = a.first-b.first, dy = a.second-b.second; if(dx == 0 && dy == 0) return pair(-1,0); else if(dx == 0) return pair(0,1); else if(dy == 0) return pair(1,0); if(dx < 0){ dx = -dx; dy = -dy; } ll g = gcd(dx,abs(dy)); dx /= g, dy /= g; return pair(dx,dy); }

pair<ll,ll> e(pair<ll,ll> a, pair<ll,ll> b){
    if(a == b) return pair(-1,0);
    auto [x,y] = a;
    auto [z,w] = b;
    if(x == z) return pair(0,1);
    else if(y == w) return pair(1,0);
    ll dx = x-z, dy = y-w;
    if(dx < 0){
        dx = -dx;
        dy = -dy;
    }
    ll g = gcd(dx,abs(dy));
    dx /= g;
    dy /= g;
    return pair(dx,dy);
}

void solve(){
    ll px,py,qx,qy,rx,ry,sx,sy; cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;
    pair<ll,ll> m = e(pair(px,py),pair(qx,qy)), l = e(pair(rx,ry), pair(sx,sy));
    // cout << m << " " << l << el;
    if(m != l){
        yesno(1);
        return;
    }
    else {
        ll x = px+qx, y = py+qy, z = rx+sx, w = ry+sy;
        // cout << pair(x,y) << " " << pair(z,w) << el;
        pair<ll,ll> k = e(pair(x,y),pair(z,w));
        // cout << k << el;
        auto [a,b] = k;
        auto [c,d] = m;
        yesno(k == pair(-1,0) || a*c + b*d == 0);
    }
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(15);

    ll t; cin >> t;
    for(ll i = 0; i < t; i++) solve();

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}