// my library: https://github.com/pasa0111/AtCoder/blob/main/.vscode/cpp.code-snippets
#include <bits/stdc++.h> /*  ^__________^  */
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,n) for (ll i = 0; i < (ll)(n); i++)
template <typename T> vector<T> make_vector(size_t a, T b) {return vector<T>(a, b); } template <typename... Ts> auto make_vector(size_t a, Ts... ts) {return vector<decltype(make_vector(ts...))>(a,make_vector(ts...));} template <ranges::range R> requires(!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a); template <typename T,typename U> ostream &operator<<(ostream &os,const pair<T,U> &p){os << "(" << p.first << ", " << p.second << ")"; return os;} template <typename T, typename U> istream &operator>>(istream &is, pair<T, U> &p){is >> p.first >> p.second; return is;} template <typename T> vector<T> rotate(vector<T> &S){assert(!S.empty()); int h = S.size(), w = S[0].size(); vector<T> res(w); for (int i = 0; i < w; i++) res[i].resize(h); for (int i = 0; i < w; i++) {for(int j = 0; j < h; j++) {res[i][j] = S[j][w - 1 - i];}} return res;} template <typename T> T &SORT(T &a){sort(a.begin(),a.end()); return a;} template <typename T> T &REVERSE(T &a){reverse(a.begin(), a.end()); return a;} template <ranges::range R> requires(!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) {if constexpr (is_same_v<ranges::range_value_t<R>, string>) {bool f = true; for (const auto &x : a) {if (!f) os << '\n'; f = false; os << x; } return os;} else{os << "{"; bool f = 1; for (const auto &x:a) {if (!f) os << ","; f = 0; os << x;} return os << "}";}}
template <typename T> using PLqueue=priority_queue<T>; template <typename T> using PGqueue=priority_queue<T,vector<T>,greater<T>>; template <typename T> vector<vector<T>> &sumvec2d(vector<vector<T>> &A) {ll h = A.size(); if(h == 0) return A; ll w = A[0].size(); for(ll i = 0; i < h; i++) for(ll j = 1; j < w; j++) A[i][j] += A[i][j-1]; for(ll j = 0; j < w; j++) for(ll i = 1; i < h; i++) A[i][j] += A[i - 1][j]; return A;} pair<ll, ll> dirvec(pair<ll, ll> a, pair<ll, ll> b) {ll dx = a.first-b.first, dy = a.second-b.second; if(dx == 0 && dy == 0) return pair(0,0); else if(dx == 0) return pair(0,1); else if(dy == 0) return pair(1, 0); if(dx < 0){dx = -dx; dy = -dy;} ll g = gcd(dx,abs(dy)); dx /= g, dy /= g; return pair(dx,dy);} template <typename T> T& vecin(T& a){for(auto& x:a) cin >> x; return a;} template <typename T> T &RSORT(T &a){sort(a.rbegin(), a.rend()); return a;} template <typename T> vector<T> &sumvec(vector<T> &a){ll b = a.size(); for(ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T,typename U> bool chmax(T& a, U b){if(a < b){a = b; return true;} return false;}
template <typename T> T square(T a){return a*a;}  struct set_stage{set_stage(){ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(20);}}set_stage_0w0; template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) {return {a.first+b.first, a.second+b.second};} template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b){return {a.first - b.first, a.second - b.second};} template <typename T> auto intpow(T a, ll b){using Ret = std::conditional_t<std::is_integral_v<T> && (sizeof(T) < sizeof(ll)), ll, T>; assert(b >= 0); Ret res = 1; Ret base = a; while(b){if(b & 1) res *= base; b >>= 1; if(!b)break; base *= base;} return res;} ll intpow(ll a,ll b,ll c){assert(b >= 0 && c > 0); ll res = 1%c; ll base = a%c; while(b){if(b & 1) res = (res*base)%c; b >>= 1; if(!b) break; base = (base*base)%c;} return res;} template <typename T,typename U> bool chmin(T& a, U b){if(a > b){a = b; return true;} return false;} template <typename T, typename U> auto sqabs(pair<T,U> a){return a.first*a.first + a.second*a.second;}
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

// from: https://github.com/hitonanode/cplib-cpp/blob/master/data_structure/fast_set.hpp
class fast_set {
    static constexpr int B = 64;

    int n;
    int cnt;
    std::vector<std::vector<uint64_t>> _d;

    static int bsf(uint64_t x) { return __builtin_ctzll(x); }
    static int bsr(uint64_t x) { return 63 - __builtin_clzll(x); }

public:
    fast_set(int n_) : n(n_), cnt(0) {
        do { n_ = (n_ + B - 1) / B, _d.push_back(std::vector<uint64_t>(n_)); } while (n_ > 1);
    }

    bool contains(int i) const {
        assert(0 <= i and i < n);
        return (_d.front().at(i / B) >> (i % B)) & 1;
    }

    void insert(int i) {
        assert(0 <= i and i < n);
        if (contains(i)) return;
        ++cnt;
        for (auto &vec : _d) {
            bool f = vec.at(i / B);
            vec.at(i / B) |= 1ULL << (i % B), i /= B;
            if (f) break;
        }
    }

    void erase(int i) {
        assert(0 <= i and i < n);
        if (!contains(i)) return;
        --cnt;
        for (auto &vec : _d) {
            vec.at(i / B) &= ~(1ULL << (i % B)), i /= B;
            if (vec.at(i)) break;
        }
    }

    int next(int i, const int default_val) const {
        assert(0 <= i and i <= n);

        for (auto itr = _d.cbegin(); itr != _d.cend(); ++itr, i = i / B + 1) {
            if (i / B >= int(itr->size())) break;

            if (auto d = itr->at(i / B) >> (i % B); d) {
                i += bsf(d);
                while (itr != _d.cbegin()) i = i * B + bsf((--itr)->at(i));
                return i;
            }
        }

        return default_val;
    }
    int next(const int i) const { return next(i, n); }

    int prev(int i, int default_val = -1) const {
        assert(-1 <= i and i < n);

        for (auto itr = _d.cbegin(); itr != _d.cend() and i >= 0; ++itr, i = i / B - 1) {
            if (auto d = itr->at(i / B) << (B - 1 - i % B); d) {
                i += bsr(d) - (B - 1);
                while (itr != _d.cbegin()) i = i * B + bsr((--itr)->at(i));
                return i;
            }
        }

        return default_val;
    }

    int min() const { return next(0); }
    int max() const { return prev(n - 1); }
    int size() const { return cnt; }
    bool empty() const { return cnt == 0; }

    void clear() {
        if (!cnt) return;
        cnt = 0;
        auto rec = [&](auto &&self, int d, int x) -> void {
            if (d) {
                for (auto m = _d.at(d).at(x); m;) {
                    int i = bsf(m);
                    m -= 1ULL << i, self(self, d - 1, x * B + i);
                }
            }
            _d.at(d).at(x) = 0;
        };
        rec(rec, _d.size() - 1, 0);
    }
};

// fast_set S(n)  [0,n)のset<int>
// contains(a)  aを含むか?
// next(a)  a 以上の最小の要素（存在しなければ N ）
// prev(a)  a 以下の最大の要素（存在しなければ -1 ）
// min()
// max()

int main(){
    ll n; cin >> n;
    vector<ll> A(n); vecin(A);
    vector<ll> I = A; SORT(I);
    I.erase(unique(I.begin(), I.end()), I.end());
    fast_set S(n+10);
    rep(i,n){
        ll id = lower_bound(I.begin(), I.end(), A[i]) - I.begin();
        if(S.contains(id)) S.erase(id);
        else S.insert(id);
    }
    cout << S.size() << el;
}