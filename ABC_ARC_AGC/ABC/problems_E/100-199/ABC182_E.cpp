#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1e9; [[maybe_unused]]constexpr ll INF = 4e18;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U, typename V> bool range(T a, U x, V b) { return ((a) < (x) && (x) < (b)); } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) { return square(a.first) + square(a.second); } template <typename T> vector<T> &sumvec(vector<T> &a) { ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i - 1]; return a; } template <typename T> vector<T> &vecin(vector<T> &a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) { SORT(a); REVERSE(a); return a; } template <typename T, typename U> T &IOTA(T &a, U b) { iota(a.begin(), a.end(), b); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

namespace atcoder {
struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}
    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }
    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }
    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }
    long long size(int a) {
        assert(0 <= a && a < _n);
        return (long long)(-parent_or_size[leader(a)]);
    }
    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }
  private:
    int _n;
    std::vector<int> parent_or_size;
};
}
using namespace atcoder;

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int h,w,n,m; cin >> h >> w >> n >> m;
    dsu R(h*w), C(h*w);
    vector<int> A(n), B(n);
    rep(i,n){
        cin >> A[i] >> B[i];
        A[i]--,B[i]--;
    }
    vector<string> S(h,string(w,'.'));
    rep(i,m){
        int c,d; cin >> c >> d; c--,d--;
        S[c][d] = '#';
    }
    for(int i = 0; i < h; i++){
        for(int j = 1; j < w; j++){
            if(S[i][j-1] == '.' && S[i][j] == '.'){
                R.merge(w*i+j-1,w*i+j);
            }
        }
    }
    for(int j = 0; j < w; j++){
        for(int i = 1; i < h; i++){
            if(S[i-1][j] == '.' && S[i][j] == '.'){
                C.merge((i-1)*w+j, i*w+j);
            }
        }
    }
    vector<bool> P(h*w,false),Q(h*w,false);
    for(int i = 0; i < n; i++){
        int a = A[i], b = B[i];
        int r = R.leader(a*w+b);
        int c = C.leader(a*w+b);
        P[r] = true;
        Q[c] = true;
    }
    // for(int i = 0; i < h; i++) cout << S[i] << el;
    // cout << el;
    // vector<vector<int>> X(h,vector<int>(w)), Y(h,vector<int>(w));
    // for(int i = 0; i < h; i++){
    //     for(int j = 0; j < w; j++){
    //         X[i][j] = R.size(i*w+j);
    //         Y[i][j] = C.size(i*w+j);
    //     }
    // }
    // for(int i = 0; i < h; i++){
    //     for(int j = 0; j < w; j++){
    //         cout << X[i][j] << " ";
    //     }
    //     cout << el;
    // }
    // cout << el;
    // for(int i = 0; i < h; i++){
    //     for(int j = 0; j < w; j++){
    //         cout << Y[i][j] << " ";
    //     }
    //     cout << el;
    // }
    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(S[i][j] == '#') continue;
            int r = R.leader(i*w+j);
            int c = C.leader(i*w+j);
            if(P[r] || Q[c]) ans++;
        }
    }
    cout << ans << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}