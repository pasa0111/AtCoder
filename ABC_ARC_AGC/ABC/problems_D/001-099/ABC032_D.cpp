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

    ll n,w; cin >> n >> w;
    ll mx_v = -1, mx_w = -1;
    vector<ll> V(n), W(n);
    rep(i,n){
        cin >> V[i] >> W[i];
        mx_v = max(mx_v,V[i]);
        mx_w = max(mx_w,W[i]);
    }
    if(mx_w <= 1000){
        const ll m = min(w,n*mx_w);
        vector<ll> dp(m+1,-INF), nextdp(m+1,-INF);
        dp[0] = 0;
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j <= m; j++){
                nextdp[j] = dp[j];
                if(j-W[i] >= 0) nextdp[j] = max(nextdp[j], dp[j-W[i]]+V[i]);
            }
            swap(dp,nextdp);
        }
        cout << *max_element(dp.begin(), dp.end()) << el;
    }
    else if(mx_v <= 1000){
        const ll m = n*mx_v;
        vector<ll> dp(m+1,INF), nextdp(m+1,INF);
        dp[0] = 0;
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j <= m; j++){
                nextdp[j] = dp[j];
                if(j-V[i] >= 0) nextdp[j] = min(dp[j-V[i]]+W[i], nextdp[j]);
            }
            swap(dp,nextdp);
        }
        for(ll j = m; j >= 0; j--){
            if(dp[j] <= w){
                cout << j << el;
                break;
            }
        }
    }
    else if(n <= 30){
        const ll a = n/2, b = n - n/2;
        map<ll,ll> A,B;
        rep(info,1<<a){
            ll weight = 0, value = 0;
            rep(i,a) if(((info>>i)&1) == 1){
                value += V[i];
                weight += W[i];
            }
            A[weight] = max(A[weight], value);
        }
        rep(info,1<<b){
            ll weight = 0, value = 0;
            rep(i,b) if(((info>>i)&1) == 1){
                value += V[a+i];
                weight += W[a+i];
            }
            B[weight] = max(B[weight], value);
        }
        ll mx = 0;
        for(auto& [weight,value]:B){
            mx = max(mx,value);
            value = mx;
        }

        ll ans = 0;
        for(auto [weight,value]:A){
            if(weight > w) break;
            auto it = B.upper_bound(w-weight);
            if(it == B.begin()) break;
            ans = max(ans, value + (*prev(it)).second);
        }
        cout << ans << el;
    }

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}