#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 2e9; [[maybe_unused]]constexpr ll INF = 9e18;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U, typename V> bool range(T a, U x, V b) { return ((a) < (x) && (x) < (b)); } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) { return square(a.first) + square(a.second); } template <typename T> vector<T> &sumvec(vector<T> &a) { ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i - 1]; return a; } template <typename T> vector<T> &vecin(vector<T> &a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) { SORT(a); REVERSE(a); return a; } template <typename T, typename U> T &IOTA(T &a, U b) { iota(a.begin(), a.end(), b); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
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
    ll a,b;
    rep(i,m){
        cin >> a >> b; a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> C(n,1); //0:白確定, 1:黒でいい
    ll k; cin >> k;
    vector<ll> P(k), D(k);
    ll p,d;
    queue<pair<ll,ll>> Q; //(頂点,距離)
    vector<bool> visited(n,false);
    rep(query,k){
        cin >> p >> d; p--;
        P[query] = p, D[query] = d; 
        Q.push({p,0});
        visited[p] = true;
        while(!Q.empty()){
            auto [now,cnt] = Q.front(); Q.pop();
            if(cnt == d) continue;
            C[now] = 0;
            for(ll to:G[now]){
                if(visited[to]) continue;
                visited[to] = true;
                Q.push({to,cnt+1});
            }
        }
        visited.assign(n,false);
    }
    bool ok;
    rep(i,k){
        p = P[i], d = D[i];
        Q.push({p,0});
        visited[p] = true;
        ok = false;
        while(!Q.empty()){
            auto [now,cnt] = Q.front(); Q.pop();
            if(cnt == d){
                if(C[now] == 1) ok = true;
                continue;
            }
            C[now] = 0;
            for(ll to:G[now]){
                if(visited[to]) continue;
                visited[to] = true;
                Q.push({to,cnt+1});
            }
        }
        if(!ok){
            yesno(0);
            return 0;
        }
        visited.assign(n,false);
    }
    yesno(1);
    rep(i,n) cout << C[i];
    cout << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n" << "//////////////////////////////////////////////////////\n";
    #endif
}