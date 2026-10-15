#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1e9; [[maybe_unused]]constexpr ll INF = 4e18;
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

    ll n,m; cin >> n >> m;
    vector<vector<ll>> S(n+1), T(n+1);
    vector<ll> L(n+10,INF);
    rep(i,m){
        ll l,r; cin >> l >> r;
        S[l].push_back(r);
        T[r].push_back(l);
        L[l] = min(L[l], r);
    }
    for(ll i = n; i >= 0; i--) L[i] = min(L[i], L[i+1]);
    rep(i,n){
        if(S[i+1].size() > 1) SORT(S[i+1]);
        if(T[i+1].size() > 1) SORT(T[i+1]);
    }
    ll q; cin >> q;
    rep(query,q){
        ll s,t; cin >> s >> t;
        if(S[s].empty() || T[t].empty()){
            yesno(0);
            continue;
        }
        if(t < S[s][0] || T[t][T[t].size()-1] < s){
            yesno(0);
            continue;
        }
        auto x = prev(upper_bound(S[s].begin(), S[s].end(), t));
        auto y = lower_bound(T[t].begin(), T[t].end(), s);
        if(*x == t){
            if(x != S[s].begin()) yesno(1);
            else if(next(y) != T[t].end()) yesno(1);
            else yesno(L[s+1] <= t);
        }
        else yesno(*y <= *x+1);
    }
    
    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}