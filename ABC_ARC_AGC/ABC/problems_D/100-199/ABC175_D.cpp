#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {sort(a.rbegin(),a.rend()); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n,k; cin >> n >> k;
    vector<vector<ll>> P(32,vector<ll>(n));
    vector<ll> I(n);
    rep(i,n){
        cin >> P[0][i];
        P[0][i]--;
        I[P[0][i]] = i;
    }
    vector<vector<ll>> C(32,vector<ll>(n));
    rep(i,n){
        ll c; cin >> c;
        C[0][I[i]] = c;
    }
    for(ll i = 1; i < 32; i++)for(ll j = 0; j < n; j++){
        P[i][j] = P[i-1][P[i-1][j]];
        C[i][j] = C[i-1][j] + C[i-1][P[i-1][j]];
    }
    ll ans = -INF;
    for(ll s = 0; s < n; s++){
        ll score = 0;
        ll cnt = max(0LL,k-n-1);
        ll now = s;
        ll res = -INF;
        if(C[31][s] >= 0){
            for(ll i = 0; i < 32; i++){
                if(((cnt>>i)&1) == 1){
                    score += C[i][now];
                    now = P[i][now];
                }
            }
            res = score;
            while(k > cnt){
                score += C[0][now];
                now = P[0][now];
                cnt++;
                res = max(res,score);
            }
        }
        else {
            score = C[0][s];
            res = max(res,score);
            now = P[0][s];
            cnt = 1;
            while(now != s && k > cnt){
                score += C[0][now];
                res = max(res,score);
                now = P[0][now];
                cnt++;
            }
        }
        ans = max(ans,res);
    }
    cout << ans << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}