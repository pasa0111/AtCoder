#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {sort(a.rbegin(),a.rend()); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n,m,y; cin >> n >> m >> y;
    vector<vector<pair<ll,ll>>> G(n);
    rep(i,m){
        ll a,b,t; cin >> a >> b >> t;
        a--,b--;
        G[a].push_back(pair(b,t));
        G[b].push_back(pair(a,t));
    }
    vector<ll> X(n); vecin(X);
    vector<ll> T(n,INF); T[0] = 0;
    PGqueue<pair<ll,ll>> Q; //時間,今
    ll dx = INF;
    Q.push(pair(0,0));
    while(!Q.empty()){
        auto [dist,now] = Q.top(); Q.pop();
        //cout << pair(dist,now) << el;
        if(T[now] < dist) continue;
        dist = min(dist, dx + X[now] + y);
        T[now] = min(T[now], dist);
        if(dist + X[now] < dx){
            dx = dist+X[now];
        }
        for(auto [to,cost]:G[now]){
            if(T[to] <= T[now]+cost) continue;
            T[to] = T[now]+cost;
            Q.push(pair(T[to],to));
        }
    }
    for(ll i = 0; i < n; i++){
        if(T[i] == INF){
            T[i] = dx + X[i] + y;
            Q.push(pair(dx+X[i]+y,i));
        }
    }
    while(!Q.empty()){
        auto [dist,now] = Q.top(); Q.pop();
        //cout << pair(dist,now) << el;
        if(T[now] < dist) continue;
        dist = min(dist, dx + X[now] + y);
        T[now] = min(T[now], dist);
        if(dist + X[now] < dx){
            dx = dist+X[now];
        }
        for(auto [to,cost]:G[now]){
            if(T[to] <= T[now]+cost) continue;
            T[to] = T[now]+cost;
            Q.push(pair(T[to],to));
        }
    }
    for(ll k = 1; k < n; k++) cout << T[k] << " ";
    cout << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}