#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1e9; [[maybe_unused]]constexpr ll INF = 4e18;
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

    ll n; cin >> n;
    const ll mod = 1000000007;
    vector<vector<ll>> G(n);
    rep(i,n-1){
        ll a,b; cin >> a >> b; a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue<ll> Q;
    vector<vector<ll>> C(n);
    vector<ll> P(n,-1);
    vector<ll> D(n,-1);
    vector<vector<ll>> E(n);
    D[0] = 0;
    Q.push(0);
    while(!Q.empty()){
        ll now = Q.front(); Q.pop();
        for(ll to:G[now]){
            if(to == P[now]) continue;
            P[to] = now;
            C[now].push_back(to);
            D[to] = D[now]+1;
            E[D[to]].push_back(to);
            Q.push(to);
        }
    }
    vector<vector<ll>> dp(n,vector<ll>(2,1));
    for(ll d = n-1; d > 0; d--){
        for(ll now:E[d]){
            dp[P[now]][0] *= dp[now][0]+dp[now][1];
            dp[P[now]][1] *= dp[now][0];
            dp[P[now]][0] %= mod;
            dp[P[now]][1] %= mod;
        }
    }
    cout << (dp[0][0] + dp[0][1])%mod << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}