#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {SORT(a); REVERSE(a); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}
ll D[400][400];

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n,m; cin >> n >> m;
    vector<vector<pair<ll,ll>>> G(n);
    vector<tuple<ll,ll,ll>> E(m);
    rep(i,m){
        ll a,b,c; cin >> a >> b >> c; a--,b--;
        G[a].push_back(pair(b,c));
        G[b].push_back(pair(a,c));
        E[i] = tuple(a,b,c);
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < 400; j++) D[i][j] = INF;
        D[i][i] = 0;
        PGqueue<pair<ll,ll>> Q;
        Q.push(pair(0,i));
        while(!Q.empty()){
            auto [t,now] = Q.top(); Q.pop();
            if(t > D[i][now]) continue;
            for(auto [to,c]:G[now]){
                if(D[i][to] <= t+c) continue;
                D[i][to] = t+c;
                Q.push(pair(t+c,to));
            }
        }
    }
    ll q; cin >> q;
    vector<ll> B;
    rep(query,q){
        ll k; cin >> k;
        B.resize(k); vecin(B); rep(i,k) B[i]--;
        ll ans = INF;
        do{
            ll dp1 = 0, dp2 = 0;
            ll x = 0, y = 0;
            for(ll i = 0; i < k; i++){
                ll nextdp1, nextdp2;
                auto [a,b,c] = E[B[i]];
                nextdp1 = min(dp1 + D[x][b] + c, dp2 + D[y][b] + c);
                nextdp2 = min(dp1 + D[x][a] + c, dp2 + D[y][a] + c);
                dp1 = nextdp1;
                dp2 = nextdp2;
                x = a;
                y = b;
            }
            dp1 += D[x][n-1];
            dp2 += D[y][n-1];
            ans = min({ans, dp1, dp2});
        }while(next_permutation(B.begin(), B.end()));
        cout << ans << el;
    }

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}