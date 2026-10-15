#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {sort(a.rbegin(),a.rend()); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

const ll F[] = {0,2,5,5,4,5,6,3,7,6};

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n,m; cin >> n >> m;
    vector<ll> A(m); vecin(A);
    for(ll i = 0; i < m-1; i++){
        for(ll j = i+1; j < m; j++){
            if(F[A[i]] == F[A[j]]){
                A[i] = max(A[i],A[j]);
                A[j] = A[i];
            }
        }
    }
    SORT(A);
    A.erase(unique(A.begin(), A.end()),A.end());
    m = A.size();
    vector<ll> S(n+1);
    vector<vector<ll>> dp(n+1,vector<ll>(10));
    for(ll i = 1; i <= n; i++) dp[i][0] = -1;
    dp[0][0] = 0;
    for(ll i = 2; i <= n; i++){
        for(ll j = 0; j < m; j++){
            ll a = A[j];
            if(i-F[a] >= 0 && dp[i-F[a]][0] != -1){
                if(S[i] < S[i-F[a]]+1){
                    dp[i] = dp[i-F[a]];
                    dp[i][a]++;
                    S[i] = S[i-F[a]]+1;
                }
                else if(S[i] == S[i-F[a]]+1){
                    for(ll k = 9; k > 0; k--){
                        if(dp[i][k] > dp[i-F[a]][k]+(k == a)) break;
                        if(dp[i][k] < dp[i-F[a]][k]+(k == a)){
                            dp[i] = dp[i-F[a]];
                            dp[i][a]++;
                            break;
                        }
                    }
                }
            }
        }
    }
    for(ll i = 9; i > 0; i--) cout << string(dp[n][i],'0'+i);
    cout << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}