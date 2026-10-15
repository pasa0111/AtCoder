#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1e9; [[maybe_unused]]constexpr ll INF = 4e18;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U, typename V> bool range(T a, U x, V b) { return ((a) < (x) && (x) < (b)); } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) { return square(a.first) + square(a.second); } template <typename T> vector<T> &sumvec(vector<T> &a) { ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i - 1]; return a; } template <typename T> vector<T> &vecin(vector<T> &a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) { SORT(a); REVERSE(a); return a; } template <typename T, typename U> T &IOTA(T &a, U b) { iota(a.begin(), a.end(), b); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

int chebyshev(pair<int,int> x, pair<int,int> y){
    return max(abs(x.first-y.first), abs(x.second-y.second));
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector<tuple<int,int,int>> G(n);
    rep(i,n){
        int x,y; cin >> x >> y;
        G[i] = {x,y,i};
    }
    SORT(G);
    vector<tuple<int,int,int>> V;
    V.push_back(G[0]), V.push_back(G[1]), V.push_back(G[n-1]);
    if(n > 3) V.push_back(G[n-2]);
    for(int i = 0; i < n; i++){
        auto [x,y,idx] = G[i];
        G[i] = {y,x,idx};
    }
    SORT(G);
    for(int i = 0; i < n; i++){
        auto [y,x,idx] = G[i];
        G[i] = {x,y,idx};
    }
    V.push_back(G[0]), V.push_back(G[1]), V.push_back(G[n-1]);
    if(n > 3) V.push_back(G[n-2]);
    SORT(V);
    V.erase(unique(V.begin(), V.end()), V.end());
    int m = V.size();
    vector<int> D;
    for(int i = 0; i < m-1; i++){
        for(int j = i+1; j < m; j++){
            auto [a,b,idx] = V[i];
            auto [x,y,IDX] = V[j];
            D.push_back(chebyshev({a,b}, {x,y}));
        }
    }
    cout << RSORT(D)[1] << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}