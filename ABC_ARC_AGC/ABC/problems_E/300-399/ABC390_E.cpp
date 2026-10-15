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

    ll n,x; cin >> n >> x;
    vector<vector<pair<ll,ll>>> S(3); //(ビタミン,カロリー)
    rep(i,n){
        ll v,a,c; cin >> v >> a >> c;
        S[v-1].push_back(pair(a,c));
    }
    vector<vector<ll>> V(3,vector<ll>(x+10));
    for(ll s = 0; s < 3; s++){
        vector<ll> dp(x+10,-INF), nextdp(x+10,-INF);
        dp[0] = 0;
        for(auto [a,c]:S[s]){
            for(ll i = 0; i <= x; i++){
                nextdp[i] = max(nextdp[i],dp[i]);
                if(i+c <= x) nextdp[i+c] = max(nextdp[i+c], dp[i]+a);
            }
            swap(dp,nextdp);
            nextdp.assign(x+10,-INF);
        }
        V[s][0] = dp[0];
        for(ll i = 1; i <= x; i++) V[s][i] = max(dp[i], V[s][i-1]);
    }
    ll ans = -INF;
    for(ll i = 0; i <= x; i++)for(ll j = 0; i+j <= x; j++){
        ll cnt = min({V[0][i], V[1][j], V[2][x-i-j]});
        ans = max(ans,cnt);
    }
    cout << ans << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}