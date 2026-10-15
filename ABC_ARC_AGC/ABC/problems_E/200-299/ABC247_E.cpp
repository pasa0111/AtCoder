#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1e9; [[maybe_unused]]constexpr ll INF = 4e18;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
namespace pasa{
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U, typename V> bool range(T a, U x, V b) { return ((a) < (x) && (x) < (b)); } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) { return square(a.first) + square(a.second); } template <typename T> vector<T> &sumvec(vector<T> &a) { ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i - 1]; return a; } template <typename T> vector<T> &vecin(vector<T> &a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) { SORT(a); REVERSE(a); return a; } template <typename T, typename U> T &IOTA(T &a, U b) { iota(a.begin(), a.end(), b); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}}
using namespace pasa;

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n,x,y; cin >> n >> x >> y;
    vector<int> A(n); vecin(A);
    vector<int> large(n+10), small(n+10);
    vector<int> pos_X, pos_Y;
    for(int i = 0; i < n; i++){
        if(A[i] == x) pos_X.push_back(i+1);
        if(A[i] == y) pos_Y.push_back(i+1);
        if(A[i] > x) large[i+1]++;
        if(A[i] < y) small[i+1]++;
    }
    sumvec(large), sumvec(small);
    int id_x = 0, id_y = 0;
    ll ans = 0;
    for(int l = 1; l <= n; l++){
        int s = l,t = n+1, r = (l+n+1)/2;
        while(id_x < (int)pos_X.size() && pos_X[id_x] < l) id_x++;
        while(id_y < (int)pos_Y.size() && pos_Y[id_y] < l) id_y++;
        if(id_x == (int)pos_X.size() || id_y == (int)pos_Y.size()) break;
        int left = max(pos_X[id_x], pos_Y[id_y]);
        if(large[left]-large[l-1] > 0 || small[left]-small[l-1] > 0) continue;
        while(t-s > 1){
            if(large[r]-large[l-1] > 0 || small[r]-small[l-1] > 0) t = r;
            else s = r;
            r = (s+t)/2;
        }
        assert(large[r]-large[l-1] == 0 && small[r]-small[l-1] == 0);
        ans += r-left+1;
    }
    cout << ans << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}