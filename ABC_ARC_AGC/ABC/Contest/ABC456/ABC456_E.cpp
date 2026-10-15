#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1e9; [[maybe_unused]]constexpr ll INF = 4e18;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T> &sumvec(vector<T> &a) { ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i - 1]; return a; } template <typename T> vector<T> &vecin(vector<T> &a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {SORT(a); REVERSE(a); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

vector<vector<int>> G;
vector<string> S;
int w;
vector<vector<int>> V;
bool ans = false;
void dfs(int pos, int t){
    //cout << pair(pos,t) << el;
    int next_t = (t+1)%w;
    for(int to:G[pos]){
        if(S[to][next_t] == 'x') continue;
        if(V[to][next_t] == 1){
            ans = true;
            return;
        }
        if(V[to][next_t] == 0) continue;
        V[to][next_t] = 1;
        dfs(to,next_t);
        if(!ans) V[to][next_t] = 0;
    }
    return;
}

void solve(){
    int n,m; cin >> n >> m;
    G.assign(n,{});
    S.assign(n,"");
    rep(i,m){
        int u,v; cin >> u >> v; u--,v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    rep(i,n) G[i].push_back(i);
    cin >> w;
    V.assign(n,vector<int>(w,-1));
    vecin(S);
    ans = false;
    rep(i,n){
        if(S[i][0] == 'x' || V[i][0] != -1) continue;
        V[i][0] = 1;
        dfs(i,0);
        if(!ans) V[i][0] = 0;
        if(ans) break;
    }
    yesno(ans);
    return;
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    rep(test,t) solve();
    
    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}