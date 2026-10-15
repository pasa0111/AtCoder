#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1e9; [[maybe_unused]]constexpr ll INF = 4e18;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {SORT(a); REVERSE(a); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

int n,m,x,y;
vector<vector<int>> G;
vector<bool> V,A;
vector<int> R;
queue<int> Q;

bool arrive(int s){
    if(s == y) return true;
    bool res = false;
    Q.push(s);
    A.assign(n,false);
    A[s] = true;
    while(!Q.empty()){
        int now = Q.front(); Q.pop();
        for(int to:G[now]){
            if(V[to] || A[to]) continue;
            A[to] = true;
            if(to == y){
                res = true;
                Q = {};
                break;
            }
            else Q.push(to);
        }
    }
    return res;
}

void solve(){
    cin >> n >> m >> x >> y; x--,y--;
    G.assign(n,{});
    V.assign(n,false);
    R.clear();
    rep(i,m){
        int u,v; cin >> u >> v; u--,v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    rep(i,n) SORT(G[i]);

    V[x] = true;
    R.push_back(x);
    int now = x;
    while(now != y){
        bool check = false;
        for(int to:G[now]){
            if(!V[to] && arrive(to)){
                now = to;
                R.push_back(to);
                V[to] = true;
                check = true;
                break;
            }
        }
        assert(check);
    }
    for(int r:R) cout << r+1 << " ";
    cout << el;
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