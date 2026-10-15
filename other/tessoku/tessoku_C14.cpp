#include <bits/stdc++.h> /*  ^__________^  */
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

    ll n,m; cin >> n >> m;
    vector<vector<pair<ll,ll>>> G(n);
    rep(i,m){
        ll a,b,c; cin >> a >> b >> c; a--,b--;
        G[a].push_back(pair(b,c));
        G[b].push_back(pair(a,c));
    }
    PGqueue<tuple<ll,ll,ll>> Q; // 距離, 直前, 今
    Q.push({0,-1,0});
    vector<set<ll>> P(n);
    vector<ll> D(n,INF);
    D[0] = 0;
    while(!Q.empty()){
        auto [dist,pre,now] = Q.top(); Q.pop();
        if(dist > D[now]) continue;
        for(auto [to,cost]:G[now]){
            if(D[to] < D[now]+cost) continue;
            else if(D[to] == D[now]+cost) P[to].insert(now);
            else {
                P[to].clear();
                P[to].insert(now);
                D[to] = D[now]+cost;
                Q.push({D[to],now,to});
            }
        }
    }
    vector<bool> V(n,false);
    V[n-1] = true;
    queue<ll> K;
    K.push(n-1);
    while(!K.empty()){
        ll now = K.front(); K.pop();
        for(ll pre:P[now]){
            if(V[pre]) continue;
            V[pre] = true;
            K.push(pre);
        }
    }
    cout << count(V.begin(), V.end(), true) << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}