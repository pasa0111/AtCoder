#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
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

    string S; cin >> S;
    ll n = S.size();
    ll m = 0;
    for(ll i = 0; i < n; i++) m += (S[i] == 'M' ? 1 : 0);
    const ll lim = 100010;
    vector<ll> dp(lim), nextdp(lim);
    ll cnt = 0;
    for(ll i = 0; i < n; i++){
        if(S[i] == '+'){
            for(ll j = max(0LL,cnt-m/2-1); j <= min(m/2,cnt); j++){
                ll x = j-(cnt-j);
                //cout << pair(j,x) << el;
                nextdp[j] = dp[j] + x;
            }
        }
        else if(S[i] == '-'){
            for(ll j = max(0LL,cnt-m/2-1); 2*j <= m; j++){
                ll x = j-(cnt-j);
                nextdp[j] = dp[j] - x;
            }
        }
        else {
            for(ll j = max(0LL,cnt-m/2-1); 2*j <= m; j++){
                nextdp[j] = max(nextdp[j],dp[j]);
                if(j > 0) nextdp[j] = max(nextdp[j],dp[j-1]);
            }
            cnt++;
        }
        swap(dp,nextdp);
        //cout << "i = " << i << el << dp << el;
        nextdp.assign(lim,0);
    }
    cout << dp[m/2] << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}