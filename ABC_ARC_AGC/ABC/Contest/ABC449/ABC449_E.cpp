#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 2000000000; [[maybe_unused]]constexpr ll INF = 9000000000000000000;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U, typename V> bool range(T a, U x, V b) { return ((a) < (x) && (x) < (b)); } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) { return square(a.first) + square(a.second); } template <typename T> vector<T> &sumvec(vector<T> &a) { ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i - 1]; return a; } template <typename T> vector<T> &vecin(vector<T> &a) { ll b = a.size(); rep(i, b) cin >> a[i]; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) { SORT(a); REVERSE(a); return a; } template <typename T> ostream &operator<<(ostream &os, const vector<T> &a) { bool first = true; os << "{"; for (const T &x : a) { if (!first) os << ","; first = false; os << x; } os << "}"; return os; } template <typename T> ostream &operator<<(ostream &os, const set<T> &a) { bool first = true; os << "{"; for (const T &x : a) { if (!first) os << ","; first = false; os << x; } os << "}"; return os; } template <typename T> ostream &operator<<(ostream &os, const multiset<T> &a) { bool first = true; os << "{"; for (const T &x : a) { if (!first) os << ","; first = false; os << x; } os << "}"; return os; } template <typename T, typename U> T &IOTA(T &a, U b) { iota(a.begin(), a.end(), b); return a; }
void yesno(bool b){
    if(b) cout << "Yes" << el;
    if(!b) cout << "No" << el;
}

int main(){
    // #ifdef pas4 
    //     freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////" << el;
    // #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n,m; cin >> n >> m;
    vector<ll> A(n); vecin(A);
    vector<ll> C(m+1);
    rep(i,n) C[A[i]]++;
    vector<vector<ll>> D(n+1);
    vector<ll> Q;
    Q.reserve(m);
    ll mx = 0;
    for(ll i = 1; i <= m; i++){
        if(C[i] == 0) Q.push_back(i);
        else D[C[i]].push_back(i);
        mx = max(mx,C[i]);
    }
    ll q; cin >> q;
    vector<pair<ll,ll>> X(q);
    vector<ll> ans(q);
    rep(i,q){
        cin >> X[i].first;
        X[i].second = i;
        if(X[i].first <= n){
            ans[i] = A[X[i].first-1];
        }
    }
    SORT(X);
    ll len = n;
    ll s = Q.size();
    ll cnt = 0;
    for(auto [x,idx]:X){
        if(x <= n) continue;
        if(len + (ll)Q.size() >= x){
            ans[idx] = Q[x-1-len];
            continue;
        }
        else {
            while(cnt < mx && len + (ll)Q.size() < x){
                len += Q.size();
                cnt++;
                s = Q.size();
                for(ll v:D[cnt]) Q.push_back(v);
                inplace_merge(Q.begin(), Q.begin()+s, Q.end());
            }
            if(cnt == mx){
                ll k = (x-len+(ll)Q.size()-1)/(ll)Q.size();
                len += (k-1)*Q.size();
            }
            assert(len+(ll)Q.size() >= x);
            ans[idx] = Q[x-1-len];
        }
    }
    rep(i,q) cout << ans[i] << el;
    
    // #ifdef pas4
    //     auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms" << el; cout << "//////////////////////////////////////////////////////" << el;
    // #endif
}