#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {SORT(a); REVERSE(a); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

int main(){
    ll n; cin >> n;
    vector<vector<ll>> dist(n,vector<ll>(n,INF));
    for(ll i = 0; i < n; i++) dist[i][i] = 0;
    rep(i,n-1){
        ll u,v; cin >> u >> v; u--,v--;
        dist[u][v] = 1;
        dist[v][u] = 1;
    }
    for(ll k = 0; k < n; k++){
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    ll cnt = 0, s, t;
    for(ll i = 0; i < n; i++)for(ll j = i+1; j < n; j++){
        if(dist[i][j]%2 == 1 && dist[i][j] > 1){
            cnt++;
            s = i;
            t = j;
        }
    }
    if(cnt%2 == 1){
        cout << "First" << el;
        cout << s+1 << " " << t+1 << el;
        dist[s][t] = 1;
        dist[t][s] = 1;
    }
    else cout << "Second" << el;

    while('_'){
        ll x,y; cin >> x >> y; x--,y--;
        if(x == -2) break;
        dist[x][y] = 1;
        dist[y][x] = 1;
        for(ll i = 0; i < n; i++){
            for(ll j = i+1; j < n; j++){
                if(dist[i][j] > 1 && dist[i][j]%2 == 1){
                    cout << i+1 << " " << j+1 << el;
                    dist[i][j] = 1;
                    dist[j][i] = 1;
                    i = n;
                    break;
                }
            }
        }
    }
}