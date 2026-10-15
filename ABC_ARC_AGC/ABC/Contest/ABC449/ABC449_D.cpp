#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 2000000000; [[maybe_unused]]constexpr ll INF = 9000000000000000000;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U, typename V> bool range(T a, U x, V b) { return ((a) < (x) && (x) < (b)); } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) { return square(a.first) + square(a.second); } template <typename T> vector<T> &sumvec(vector<T> &a) { ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i - 1]; return a; } template <typename T> vector<T> &vecin(vector<T> &a) { ll b = a.size(); rep(i, b) cin >> a[i]; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) { SORT(a); REVERSE(a); return a; } template <typename T> ostream &operator<<(ostream &os, const vector<T> &a) { bool first = true; os << "{"; for (const T &x : a) { if (!first) os << ","; first = false; os << x; } os << "}"; return os; } template <typename T> ostream &operator<<(ostream &os, const set<T> &a) { bool first = true; os << "{"; for (const T &x : a) { if (!first) os << ","; first = false; os << x; } os << "}"; return os; } template <typename T> ostream &operator<<(ostream &os, const multiset<T> &a) { bool first = true; os << "{"; for (const T &x : a) { if (!first) os << ","; first = false; os << x; } os << "}"; return os; } template <typename T, typename U> T &IOTA(T &a, U b) { iota(a.begin(), a.end(), b); return a; }
void yesno(bool b){
    if(b) cout << "Yes" << el;
    if(!b) cout << "No" << el;
}

int main(){
    #ifdef pas4 
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////" << el;
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll l,r,d,u; cin >> l >> r >> d >> u;
    ll ans = 0;
    for(ll x = max(2LL,l); x <= r; x+=2){
        if((x&1) == 1){
            x--;
            continue;
        }
        assert(x%2 == 0);
        ans += max(0LL,min(u,x)-max(-x+1,d)+1);
    }
    for(ll x = min(-2LL,r); x >= l; x-=2){
        if((abs(x)&1) == 1){
            x++;
            continue;
        }
        assert(x%2 == 0);
        ans += max(0LL,min(u,-x-1)-max(d,x)+1);
    }
    for(ll y = max(2LL,d); y <= u; y+=2){
        if((y&1) == 1){
            y--;
            continue;
        }
        assert(y%2 == 0);
        ans += max(0LL, min(y-1,r)-max(-y,l)+1);
    }
    for(ll y = min(-2LL,u); y >= d; y-=2){
        if((abs(y)&1) == 1){
            y++;
            continue;
        }
        assert(y%2 == 0);
        ans += max(0LL, min(-y,r)-max(y+1,l)+1);
    }
    if(range(l-1,0,r+1) && range(d-1,0,u+1)) ans++;
    cout << ans << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms" << el; cout << "//////////////////////////////////////////////////////" << el;
    #endif
}