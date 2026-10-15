#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1e9; [[maybe_unused]]constexpr ll INF = 4e18;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U, typename V> bool range(T a, U x, V b) { return ((a) < (x) && (x) < (b)); } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) { return square(a.first) + square(a.second); } template <typename T> vector<T> &sumvec(vector<T> &a) { ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i - 1]; return a; } template <typename T> vector<T> &vecin(vector<T> &a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) { SORT(a); REVERSE(a); return a; } template <typename T, typename U> T &IOTA(T &a, U b) { iota(a.begin(), a.end(), b); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

const ll lim = 1000010;
ll P[lim], Q[lim];

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int T; cin >> T;
    P[0] = 1, Q[0] = 1;
    for(int i = 1; i < lim; i++){
        P[i] = (P[i-1]*1017LL)%998244353;
        Q[i] = (Q[i-1]*1017LL)%1000000007;
    }
    rep(test,T){
        string A,B; cin >> A >> B;
        int n = A.size();
        A += A;
        ll h = 0,g = 0;
        for(int i = 0; i < n; i++){
            h = (h+(B[i]-'0')*P[n-1-i])%998244353;
            g = (g+(B[i]-'0')*Q[n-1-i])%1000000007;
        }
        vector<ll> H(n), G(n);
        for(int i = 0; i < n; i++){
            H[0] = (H[0]+(A[i]-'0')*P[n-1-i])%998244353;
            G[0] = (G[0]+(A[i]-'0')*Q[n-1-i])%1000000007;
        }
        if(H[0] == h && G[0] == g){
            cout << 0 << el;
            continue;
        }
        bool ok = false;
        for(int i = 1; i < n; i++){
            H[i] = (1017LL*H[i-1]+(A[i-1+n]-'0')-((A[i-1]-'0')*P[n]) + 9982443530000LL)%998244353;
            G[i] = (1017LL*G[i-1]+(A[i-1+n]-'0')-((A[i-1]-'0')*Q[n]) + 10000000070000LL)%1000000007;
            if(H[i] == h && G[i] == g){
                cout << i << el;
                ok = true;
                break;
            }
        }
        if(!ok) cout << -1 << el;
    }

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}