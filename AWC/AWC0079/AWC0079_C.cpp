#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]]constexpr ll INF = 4000000000000000000;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {SORT(a); REVERSE(a); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n,q; cin >> n >> q;
    vector<ll> A(n), B(n);
    rep(i,n) cin >> A[i] >> B[i];
    rep(query,q){
        ll t; cin >> t;
        if(t == 1){
            ll i,a,b; cin >> i >> a >> b; i--;
            A[i] = a;
            B[i] = b;
        }
        else {
            ll d; cin >> d;
            ll x = INF;
            ll p = 0, q = d;
            ll time = 0;
            bool ok = false;
            for(ll i = 0; i < n; i++){
                p += B[i];
                q += A[i];
                if(q <= p){
                    ok = true;
                    cout << i+1 << el;
                    break;
                }
                if(q-p < x) time = i;
                x = min(x, q-p);
            }
            if(ok) continue;
            if(x <= 0){
                cout << time+1 << el;
                continue;
            }
            //cout << pair(p,q) << el;
            ll y = q-p;
            ll z = d-y;
            if(z <= 0){
                cout << -1 << el;
                continue;
            }
            ll k = (x+z-1)/z;
            p = 0, q = d - k*z;
            for(ll i = 0; i < n; i++){
                p += B[i];
                q += A[i];
                if(q <= p){
                    cout << n*k + i + 1 << el;
                    break;
                }
            }
        }
    }

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}