#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1e9; [[maybe_unused]]constexpr ll INF = 4e18;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
namespace pasa{
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U, typename V> bool range(T a, U x, V b) { return ((a) < (x) && (x) < (b)); } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) { return square(a.first) + square(a.second); } template <typename T> vector<T> &sumvec(vector<T> &a) { ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i - 1]; return a; } template <typename T> vector<T> &vecin(vector<T> &a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) { SORT(a); REVERSE(a); return a; } template <typename T, typename U> T &IOTA(T &a, U b) { iota(a.begin(), a.end(), b); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}}
using namespace pasa;


// n以下の正整数が素数であるかをbool配列P(n+1)に保存
const int lim = 1000010; const ll LIM = 1e12 + 100;
vector<bool> P;
void sieve(){
    P.assign(lim,true);
    P[0] = false; P[1] = false;
    ll n = P.size()-1;
    for(ll i = 2; i*i <= n; i++){
        if(P[i]) for(ll j = i*i; j <= n; j += i) P[j] = false;
    }
    return;
}

vector<ll> Q,R;

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int q; cin >> q;
    sieve();
    Q.reserve(1000000);
    R.reserve(1000000);
    for(ll p = 2; p < lim; p++) if(P[p]) Q.push_back(p*p);
    for(int i = 0; i < (int)Q.size()-1; i++){
        if(Q[i] > LIM/Q[i]) break;
        for(int j = i+1; j < (int)Q.size(); j++){
            if(Q[i] > LIM/Q[j]) break;
            ll x = Q[i], y = Q[j];
            while(x <= LIM/Q[j]){
                y = Q[j];
                while(y <= LIM/x){
                    if(x*y < 0){
                        cout << pair(Q[i],Q[j]) << el;
                        assert(false);
                    }
                    R.push_back(x*y);
                    if(y > LIM/Q[j]) break;
                    y *= Q[j];
                }
                if(x > LIM/Q[i]) break;
                x *= Q[i];
            }
        }
    }
    SORT(R);
    rep(i,q){
        ll a; cin >> a;
        cout << *prev(upper_bound(R.begin(), R.end(), a)) << el;
    }

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}