#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {SORT(a); REVERSE(a); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n,m; cin >> n >> m;
    vector<vector<ll>> G(n);
    rep(i,m){
        ll a,b; cin >> a >> b; a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    string S; cin >> S;
    vector<vector<pair<ll,ll>>> T(n,vector<pair<ll,ll>>(2,{INF,-1}));
    queue<tuple<ll,ll,ll>> Q; // 今,始点,時間
    for(ll i = 0; i < n; i++){
        if(S[i] == 'S'){
            Q.push({i,i,0});
            T[i][0] = {0,i};
        }
    }
    while(!Q.empty()){
        auto [now,s,d] = Q.front(); Q.pop();
        for(ll to:G[now]){
            if(T[to][1].first <= d+1) continue;
            if(T[to][0].first == INF){
                T[to][0] = {d+1,s};
                Q.push({to,s,d+1});
            }
            else if(T[to][1].first == INF && T[to][0].second != s){
                T[to][1] = {d+1,s};
                Q.push({to,s,d+1});
            }
        }
    }
    for(ll i = 0; i < n; i++){
        if(S[i] == 'D'){
            assert(T[i][0].first < INF && T[i][1].first < INF);
            cout << T[i][0].first + T[i][1].first << el;
        }
    }

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}