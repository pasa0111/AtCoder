#include <bits/stdc++.h> /*  ^__________^  */
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,n) for(ll i = 0; i < (ll)(n); i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) {return a * a;} template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;} struct set_stage{set_stage(){ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(20);}}set_stage; template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> auto sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); } template <typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p) { is >> p.first >> p.second; return is;}
template <typename T> T &SORT(T &a) {sort(a.begin(), a.end()); return a;} template <typename T> T& REVERSE(T &a) {reverse(a.begin(), a.end()); return a;} template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) {os << "{"; bool f = 1; for (const auto &x : a) {if (!f) os << ","; f = 0; os << x;} return os << "}";} template <typename T> vector<vector<T>>& sumvec2d(vector<vector<T>>& A){ll h = A.size(); if(h == 0) return A; ll w = A[0].size(); for(ll i = 0; i < h; i++)for(ll j = 1; j < w; j++) A[i][j] += A[i][j-1]; for(ll j = 0; j < w; j++)for(ll i = 1; i < h; i++) A[i][j] += A[i-1][j]; return A;} pair<ll,ll> dirvec(pair<ll,ll> a, pair<ll,ll> b){ll dx = a.first-b.first, dy = a.second-b.second; if(dx == 0 && dy == 0) return pair(0,0); else if(dx == 0) return pair(0,1); else if(dy == 0) return pair(1,0); if(dx < 0){dx = -dx; dy = -dy;} ll g = gcd(dx,abs(dy)); dx /= g, dy /= g; return pair(dx,dy);} template <typename T, typename U> vector<T>& operator*=(vector<T>& V,const U& k) {for(auto& x:V) x *= k; return V;}
template <typename T,typename U> vector<T> operator*(vector<T> V, const U& k) {return V *= k;} template <typename T,typename U> vector<T> operator*(const U& k,vector<T> V) {return V *= k;} template <typename T,typename U> pair<T,T>& operator*=(pair<T,T>& P,const U& k) {P.first *= k; P.second *= k; return P;} template <typename T,typename U> pair<T,T> operator*(pair<T,T> P,const U& k) {return P *= k;} template <typename T,typename U> pair<T,T> operator*(const U& k, pair<T,T> P) {return P *= k;} template <typename T> T dot(const vector<T>& A, const vector<T>& B){assert(A.size() == B.size()); ll s = A.size(); T res = 0; for(ll i = 0; i < s; i++) res += A[i]*B[i]; return res;} template <typename T> T dot(const pair<T,T>& A, const pair<T,T>& B){return A.first*B.first + A.second*B.second;} template <typename T> vector<T>& vecin(vector<T>& a) {for (auto &x:a) cin >> x; return a;} template <typename T> T &RSORT(T &a) {sort(a.rbegin(),a.rend()); return a;} template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;}
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

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

// fast_set S(n)  [0,n)のset
// contains(a)  aを含むか?
// next(a)  a 以上の最小の要素（存在しなければ N ）
// prev(a)  a 以下の最大の要素（存在しなければ -1 ）
// min()
// max()

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif

    ll h,w; cin >> h >> w;
    vector<string> S(h); vecin(S);
    vector<vector<pair<ll,ll>>> U(h,vector<pair<ll,ll>>(w,pair(-1,-1))), D(h,vector<pair<ll,ll>>(w,pair(-1,-1))), L(h,vector<pair<ll,ll>>(w,pair(-1,-1))), R(h,vector<pair<ll,ll>>(w,pair(-1,-1)));
    for(ll i = 1; i < h; i++)for(ll j = 0; j < w; j++) U[i][j] = pair(i-1,j);
    for(ll i = 0; i < h-1; i++)for(ll j = 0; j < w; j++) D[i][j] = pair(i+1,j);
    for(ll j = 1; j < w; j++)for(ll i = 0; i < h; i++) L[i][j] = pair(i,j-1);
    for(ll j = 0; j < w-1; j++)for(ll i = 0; i < h; i++) R[i][j] = pair(i,j+1);

    vector<bool> X(h,true), Y(w,true);
    ll a = 0, b = 0;
    auto erase_r = [&](ll r) -> bool {
        if(b == w || R[r][b].first == -1) return false;
        ll x = r, y = b;
        char c = S[x][y];
        while(x != -1){
            auto [nx,ny] = R[x][y];
            if(nx == -1) break;
            if(c != S[nx][ny]) return false;
            tie(x,y) = R[x][y];
        }
        x = r, y = b;
        while(x != -1){
            auto [ux,uy] = U[x][y];
            auto [dx,dy] = D[x][y];
            if(ux != -1) D[ux][uy] = D[x][y];
            if(dx != -1) U[dx][dy] = U[x][y];
            tie(x,y) = R[x][y];
        }
        X[r] = false;
        while(a < h && !X[a]) a++;
        return true;
    };

    auto erase_c = [&](ll c) -> bool {
        if(a == h || D[a][c].first == -1) return false;
        ll x = a, y = c;
        char z = S[x][y];
        while(x != -1){
            // cout << pair(x,y) << el;
            auto [nx,ny] = D[x][y];
            if(nx == -1) break;
            if(z != S[nx][ny]) return false;
            tie(x,y) = D[x][y];
        }
        x = a, y = c;
        while(x != -1){
            auto [lx,ly] = L[x][y];
            auto [rx,ry] = R[x][y];
            if(lx != -1) R[lx][ly] = R[x][y];
            if(rx != -1) L[rx][ry] = L[x][y];
            tie(x,y) = D[x][y];
        }
        Y[c] = false;
        while(b < w && !Y[b]) b++;
        return true;
    };

    fast_set I(h),J(w);
    for(ll i = 0; i < h; i++) I.insert(i);
    for(ll j = 0; j < w; j++) J.insert(j);

    while('_'){
        ll i = I.next(0);
        bool check = false;
        while(i < h){
            if(erase_r(i)){
                cout << "erase: i = " << i << el;
                check = true;
                I.erase(i);
            }
            i = I.next(i+1);
        }

        ll j = J.next(0);
        while(j < w){
            if(erase_c(j)){
                cout << "erase: j = " << j << el;
                check = true;
                J.erase(j);
            }
            j = J.next(j+1);
        }
        
        if(!check) break;
    }

    ll ans = 0;
    for(ll i = 0; i < h; i++)for(ll j = 0; j < w; j++) if(X[i] && Y[j]) ans++;
    cout << ans << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}