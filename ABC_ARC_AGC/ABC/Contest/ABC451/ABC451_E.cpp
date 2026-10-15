#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 2e9; [[maybe_unused]]constexpr ll INF = 9e18;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U, typename V> bool range(T a, U x, V b) { return ((a) < (x) && (x) < (b)); } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) { return square(a.first) + square(a.second); } template <typename T> vector<T> &sumvec(vector<T> &a) { ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i - 1]; return a; } template <typename T> vector<T> &vecin(vector<T> &a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) { SORT(a); REVERSE(a); return a; } template <typename T, typename U> T &IOTA(T &a, U b) { iota(a.begin(), a.end(), b); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

vector<vector<ll>> G;
vector<bool> visited;
ll start;
bool ans = true;
vector<vector<ll>> A;
void dfs(ll now){
    for(ll to:G[now]){
        if(visited[to]) continue;
        if(A[start][now]+A[now][to] != A[start][to]){
            ans = false;
            return;
        }
        else{
            visited[to] = true;
            dfs(to);
            visited[to] = false;
        }
    }
    return;
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n; cin >> n;
    G.resize(n), visited.assign(n,false), A.assign(n,vector<ll>(n));
    rep(i,n-1){
        for(ll j = i+1; j < n; j++){
            cin >> A[i][j];
            A[j][i] = A[i][j];
        }
    }
    ll mn,par;
    for(ll i = 1; i < n; i++){
        mn = INF, par = -1;
        for(ll j = 0; j < n; j++){
            if(j == i) continue;
            if(A[0][j] + A[j][i] == A[0][i]){
                if(A[i][j] < mn){
                    mn = A[i][j];
                    par = j;
                }
                else if(A[i][j] == mn) par = -1;
            }
        }
        if(par == -1){
            ans = false;
            break;
        }
        else{
            G[i].push_back(par);
            G[par].push_back(i);
        }
    }
    if(!ans){
        yesno(0);
        return 0;
    }
    rep(i,n){
        visited[i] = true;
        start = i;
        dfs(i);
        visited[i] = false;
        if(!ans) break;
    }
    yesno(ans);

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n" << "//////////////////////////////////////////////////////\n";
    #endif
}