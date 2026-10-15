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

    ll a,b; cin >> a >> b; a--;
    string A = to_string(a), B = to_string(b);
    ll sa = A.size(), sb = B.size();

    vector<vector<vector<ll>>> dp(sb+1,vector<vector<ll>>(2,vector<ll>(2)));
    dp[0][0][0] = 1;
    for(ll i = 1; i <= sb; i++){
        //cout << "i = " << i << el;
        if(B[i-1] != '4' && B[i-1] != '9') dp[i][0][0] = dp[i-1][0][0];
        else dp[i][0][1] = dp[i-1][0][0];
        dp[i][0][1] += dp[i-1][0][1];
        dp[i][1][0] = dp[i-1][1][0]*8;
        for(ll j = 0; j < (B[i-1]-'0'); j++){
            if(j == 4 || j == 9) continue;
            dp[i][1][0] += dp[i-1][0][0];
        }
        dp[i][1][1] = dp[i-1][1][1]*10;
        dp[i][1][1] += (B[i-1]-'0')*dp[i-1][0][1];
        dp[i][1][1] += dp[i-1][1][0]*2;
        if(B[i-1] > '4') dp[i][1][1] += dp[i-1][0][0];
    }
    ll p = dp[sb][0][1] + dp[sb][1][1];

    dp.assign(sa+1, vector<vector<ll>>(2,vector<ll>(2)));
    dp[0][0][0] = 1;
    for(ll i = 1; i <= sa; i++){
        //cout << "i = " << i << el;
        if(A[i-1] != '4' && A[i-1] != '9') dp[i][0][0] = dp[i-1][0][0];
        else dp[i][0][1] = dp[i-1][0][0];
        dp[i][0][1] += dp[i-1][0][1];
        dp[i][1][0] = dp[i-1][1][0]*8;
        for(ll j = 0; j < (A[i-1]-'0'); j++){
            if(j == 4 || j == 9) continue;
            dp[i][1][0] += dp[i-1][0][0];
        }
        dp[i][1][1] = dp[i-1][1][1]*10;
        dp[i][1][1] += (A[i-1]-'0')*dp[i-1][0][1];
        dp[i][1][1] += dp[i-1][1][0]*2;
        if(A[i-1] > '4') dp[i][1][1] += dp[i-1][0][0];
    }
    ll q = dp[sa][0][1] + dp[sa][1][1];

    cout << p-q << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}