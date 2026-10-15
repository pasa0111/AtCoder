#include <bits/stdc++.h> /*  ^__________^  */
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1, 1, 0, 0, -1, -1, 1, 1}; [[maybe_unused]] constexpr ll DY[8] = {0, 0, -1, 1, -1, 1, -1, 1};
#define rep(i,n) for (ll i = 0; i < (ll)(n); i++)
template <typename T> using PLqueue=priority_queue<T>; template <typename T, typename U> istream &operator>>(istream &is, pair<T, U> &p){is >> p.first >> p.second; return is;} template <typename T> vector<T> rotate(vector<T> &S){assert(!S.empty()); int h = S.size(), w = S[0].size(); vector<T> res(w); for (int i = 0; i < w; i++) res[i].resize(h); for (int i = 0; i < w; i++) {for(int j = 0; j < h; j++) {res[i][j] = S[j][w - 1 - i];}} return res;} template <typename T> T &SORT(T &a){sort(a.begin(),a.end()); return a;} template <typename T> T &REVERSE(T &a){reverse(a.begin(), a.end()); return a;} template <ranges::range R> requires(!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) {if constexpr (is_same_v<ranges::range_value_t<R>, string>) {bool f = true; for (const auto &x : a) {if (!f) os << '\n'; f = false; os << x; } return os;} else{os << "{"; bool f = 1; for (const auto &x:a) {if (!f) os << ","; f = 0; os << x;} return os << "}";}}
template <typename T> using PGqueue=priority_queue<T,vector<T>,greater<T>>; template <typename T> vector<vector<T>> &sumvec2d(vector<vector<T>> &A) {ll h = A.size(); if(h == 0) return A; ll w = A[0].size(); for(ll i = 0; i < h; i++) for(ll j = 1; j < w; j++) A[i][j] += A[i][j-1]; for(ll j = 0; j < w; j++) for(ll i = 1; i < h; i++) A[i][j] += A[i - 1][j]; return A;} pair<ll, ll> dirvec(pair<ll, ll> a, pair<ll, ll> b) {ll dx = a.first-b.first, dy = a.second-b.second; if(dx == 0 && dy == 0) return pair(0,0); else if(dx == 0) return pair(0,1); else if(dy == 0) return pair(1, 0); if(dx < 0){dx = -dx; dy = -dy;} ll g = gcd(dx,abs(dy)); dx /= g, dy /= g; return pair(dx,dy);} template <typename T> vector<T> &vecin(vector<T> &a){for(auto &x:a) cin >> x; return a;} template <typename T> T &RSORT(T &a){sort(a.rbegin(), a.rend()); return a;} template <typename T> vector<T> &sumvec(vector<T> &a){ll b = a.size(); for(ll i = 1; i < b; i++) a[i] += a[i-1]; return a;}
template <typename T> T square(T a){return a*a;} template <typename T,typename U> ostream &operator<<(ostream &os,const pair<T,U> &p){os << "(" << p.first << ", " << p.second << ")"; return os;} struct set_stage{set_stage(){ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(20);}}set_stage; template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) {return {a.first+b.first, a.second+b.second};} template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b){return {a.first - b.first, a.second - b.second};} template <typename T,typename U> auto sqabs(const pair<T, U> &a){return square(a.first) + square(a.second);} template <typename T> auto intpow(T a, ll b){using Ret = std::conditional_t<std::is_integral_v<T> && (sizeof(T) < sizeof(ll)), ll, T>; assert(b >= 0); Ret res = 1; Ret base = a; while(b) {if(b & 1) res *= base; b >>= 1; if(!b)break; base *= base;} return res;}
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

void solve(){
    int n,m; cin >> n >> m;
    vector<pair<int,int>> E(m);
    vector<vector<pair<int,int>>> G(n);
    rep(i,m){
        int a,b; cin >> a >> b; a--,b--;
        if(a > b) swap(a,b);
        E[i] = {a,b};
        G[a].push_back({b,i});
        G[b].push_back({a,i});
    }

    queue<int> Q;
    vector<int> D(n,-1), P(n);
    D[0] = 0;
    Q.push(0);
    while(!Q.empty()){
        int now = Q.front(); Q.pop();
        for(auto [to,id]:G[now]){
            if(D[to] != -1) continue;
            E[id] = {-1,-1};
            D[to] = D[now]+1;
            P[to] = now;
            Q.push(to);
        }
    }

    vector<int> L,R;
    bool ans = false;
    for(auto [a,b]:E){
        if(a == -1) continue;
        if(D[a] == D[b]){
            ans = true;
            L.push_back(a);
            R.push_back(b);
            while(P[a] != P[b]){
                L.push_back(P[a]);
                R.push_back(P[b]);
                a = P[a];
                b = P[b];
            }
            L.push_back(P[a]);
            REVERSE(R);
            break;
        }
    }
    if(!ans) cout << -1 << el;
    else {
        cout << L.size()+R.size() << el;
        for(int a:L) cout << a+1 << ' ';
        for(int b:R) cout << b+1 << ' ';
        cout << el;
    }
}

int main(){
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}