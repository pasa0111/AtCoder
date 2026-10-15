#include <bits/stdc++.h> /*  ^__________^  */
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1, 1, 0, 0, -1, -1, 1, 1}; [[maybe_unused]] constexpr ll DY[8] = {0, 0, -1, 1, -1, 1, -1, 1};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } struct set_stage { set_stage() { ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(20); } } set_stage; template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> auto sqabs(const pair<T, U> &a) { return square(a.first) + square(a.second); }
template <typename T, typename U> istream &operator>>(istream &is, pair<T, U> &p) { is >> p.first >> p.second; return is; } template <typename T> vector<T> rotate(vector<T> &S) { assert(!S.empty()); int h = S.size(), w = S[0].size(); vector<T> res(w); for (int i = 0; i < w; i++) res[i].resize(h); for (int i = 0; i < w; i++) { for (int j = 0; j < h; j++) { res[i][j] = S[j][w - 1 - i]; } } return res; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <ranges::range R> requires(!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { if constexpr (is_same_v<ranges::range_value_t<R>, string>) { bool f = true; for (const auto &x : a) { if (!f) os << '\n'; f = false; os << x; } return os; } else { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; } }
template <typename T> vector<vector<T>> &sumvec2d(vector<vector<T>> &A) { ll h = A.size(); if (h == 0) return A; ll w = A[0].size(); for (ll i = 0; i < h; i++) for (ll j = 1; j < w; j++) A[i][j] += A[i][j - 1]; for (ll j = 0; j < w; j++) for (ll i = 1; i < h; i++) A[i][j] += A[i - 1][j]; return A; } pair<ll, ll> dirvec(pair<ll, ll> a, pair<ll, ll> b) { ll dx = a.first - b.first, dy = a.second - b.second; if (dx == 0 && dy == 0) return pair(0, 0); else if (dx == 0) return pair(0, 1); else if (dy == 0) return pair(1, 0); if (dx < 0) { dx = -dx; dy = -dy; } ll g = gcd(dx, abs(dy)); dx /= g, dy /= g; return pair(dx, dy); } template <typename T> vector<T> &vecin(vector<T> &a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &RSORT(T &a) { sort(a.rbegin(), a.rend()); return a; } template <typename T> vector<T> &sumvec(vector<T> &a) { ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i - 1]; return a; }
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
using dsu = atcoder::dsu;

// 11:55 ~ 12:08
int main(){
    ll n,m; cin >> n >> m;
    vector<ll> A(n), B(n); vecin(A), vecin(B);
    vector<ll> S = A, T = B;
    dsu uf(n);
    rep(i,m){
        ll a,b; cin >> a >> b; a--,b--;
        if(uf.same(a,b)) continue;
        a = uf.leader(a), b = uf.leader(b);
        ll p = S[a], q = S[b], r = T[a], s = T[b];
        S[uf.merge(a,b)] = p+q;
        T[uf.leader(a)] = r+s;
    }

    // 操作回数求めなくていいのありがたい
    for(ll i = 0; i < n; i++){
        if(uf.leader(i) == i && S[i] != T[i]){
            // cout << "i = " << i << "  " << pair(S[i],T[i]) << el;
            yesno(0);
            return 0;
        }
    }
    yesno(1);
}