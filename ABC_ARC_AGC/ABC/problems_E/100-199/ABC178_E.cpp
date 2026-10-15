#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 2e9; [[maybe_unused]]constexpr ll INF = 9e18;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U, typename V> bool range(T a, U x, V b) { return ((a) < (x) && (x) < (b)); } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) { return square(a.first) + square(a.second); } template <typename T> vector<T> &sumvec(vector<T> &a) { ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i - 1]; return a; } template <typename T> vector<T> &vecin(vector<T> &a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) { SORT(a); REVERSE(a); return a; } template <typename T, typename U> T &IOTA(T &a, U b) { iota(a.begin(), a.end(), b); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

ll A[200010], B[200010];

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    pair<ll,ll> maxA1 = {-INF,-1},maxA2 = {-INF,-1},maxB1 = {-INF,-1},maxB2 = {-INF,-1},minA1 = {INF,-1},minA2 = {INF,-1},minB1 = {INF,-1},minB2 = {INF,-1};
    rep(i,n){
        ll x,y; cin >> x >> y;
        ll a = x+y, b = x-y;
        A[i] = a, B[i] = b;
        if(maxA1.first <= a){
            maxA2 = maxA1;
            maxA1 = {a,i};
        }
        else if(maxA2.first < a) maxA2 = {a,i};
        if(maxB1.first <= b){
            maxB2 = maxB1;
            maxB1 = {b,i};
        }
        else if(maxB2.first < b) maxB2 = {b,i};

        if(minA1.first >= a){
            minA2 = minA1;
            minA1 = {a,i};
        }
        else if(minA2.first > a) minA2 = {a,i};
        if(minB1.first >= b){
            minB2 = minB1;
            minB1 = {b,i};
        }
        else if(minB2.first > b) minB2 = {b,i};
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ll a = A[i], b = B[i];
        ll p = (maxA1.second != i ? maxA1.first : maxA2.first);
        ll q = (maxB1.second != i ? maxB1.first : maxB2.first);
        ll r = (minA1.second != i ? minA1.first : minA2.first);
        ll s = (minB1.second != i ? minB1.first : minB2.first);
        ans = max({ans,p-a,q-b,a-r,b-s});
    }
    cout << ans << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}