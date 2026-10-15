#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {SORT(a); REVERSE(a); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

struct scc_graph {
    int _n;
    struct edge { int to; };
    std::vector<std::pair<int, edge>> edges;

    scc_graph(int n) : _n(n) {}

    void add_edge(int from, int to) {
        edges.push_back({from, {to}});
    }

    std::vector<std::vector<int>> scc() {
        std::vector<int> start(_n + 1);
        for (auto e : edges) start[e.first + 1]++;
        for (int i = 1; i <= _n; i++) start[i] += start[i - 1];
        std::vector<int> elist(edges.size());
        for (auto e : edges) elist[start[e.first]++] = e.second.to;
        for (int i = _n; i > 0; i--) start[i] = start[i - 1];
        start[0] = 0;

        int now_ord = 0, group_num = 0;
        std::vector<int> visited(_n);
        std::vector<int> low(_n), ord(_n, -1), ids(_n);
        std::vector<int> node_stack;
        node_stack.reserve(_n);

        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            node_stack.push_back(v);
            for (int i = start[v]; i < start[v + 1]; i++) {
                int to = elist[i];
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = node_stack.back();
                    node_stack.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };

        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }

        for (auto& x : ids) x = group_num - 1 - x;
        std::vector<int> counts(group_num);
        for (auto x : ids) counts[x]++;
        std::vector<std::vector<int>> groups(group_num);
        for (int i = 0; i < group_num; i++) groups[i].reserve(counts[i]);
        for (int i = 0; i < _n; i++) groups[ids[i]].push_back(i);
        
        return groups;
    }
};

// add_edge(u, v) 有向辺の追加
// scc() dag化 グループごとの頂点をまとめたvector<vector<int>>が返ってくる

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n,m; cin >> n >> m;
    scc_graph G(n);
    rep(i,m){
        ll a,b; cin >> a >> b; a--,b--;
        G.add_edge(a,b);
    }
    vector<vector<int>> V = G.scc();
    ll ans = 0;
    for(ll i = 0; i < (ll)V.size(); i++) ans += V[i].size()*(V[i].size()-1)/2;
    cout << ans << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}