#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {SORT(a); REVERSE(a); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

namespace atcoder {
template <class T>
struct weighted_dsu {
  public:
    weighted_dsu() : _n(0) {}
    weighted_dsu(int n) : _n(n), parent_or_size(n, -1), diff_weight(n, 0) {}

    // a から見て b が重み w になるように結合する
    int merge(int a, int b, T w) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;

        // 根同士の相対的な重みを計算
        T w_x_to_y = w + weight(a) - weight(b);

        if (-parent_or_size[x] < -parent_or_size[y]) {
            std::swap(x, y);
            w_x_to_y = -w_x_to_y;
        }
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        diff_weight[y] = w_x_to_y;
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
        int r = leader(parent_or_size[a]);
        diff_weight[a] += diff_weight[parent_or_size[a]]; // 経路圧縮のついでに重みを累積
        return parent_or_size[a] = r;
    }

    // 根からの絶対的な重みを取得する関数
    T weight(int a) {
        assert(0 <= a && a < _n);
        leader(a); // 事前に経路圧縮
        return diff_weight[a];
    }

    // aとbが連結のとき aから見たbの相対的な距離を返す
    T diff(int a, int b) {
        assert(same(a, b));
        return weight(b) - weight(a);
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
    std::vector<T> diff_weight; // 親ノードとの相対的な重みを記録
};
}
template <class T> using wdsu = atcoder::weighted_dsu<T>;
// wdsu<ll> uf(n)  宣言
// diff(x,y)  xから見たyの位置
// weight(x)  根からxの距離
// merge(x,y,w)  xから見てyの位置がwになるように結合

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n,m; cin >> n >> m;
    wdsu<ll> uf(n);
    bool ans = true;
    rep(i,m){
        ll l,r,d; cin >> l >> r >> d; l--,r--;
        if(uf.same(l,r) && uf.diff(l,r) != d){
            ans = false;
            break;
        }
        else uf.merge(l,r,d);
    }
    yesno(ans);

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}