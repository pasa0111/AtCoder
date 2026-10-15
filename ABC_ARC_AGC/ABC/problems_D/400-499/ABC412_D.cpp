#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {sort(a.rbegin(),a.rend()); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

ll n,m;
ll G[8][8]; // -2:初期状態で繋がっていない -1:初期状態で繋がっている 0:繋がっていない 1:繋がっている
ll I[8];
ll ans = INF;

void solve(ll now, ll cnt){
    if(cnt >= ans) return;
    //cout << pair(now,cnt) << el;
    if(now == n){
        // cout << pair(now,cnt) << el;
        // for(ll i = 0; i < 8; i++){
        //     for(ll j = 0; j < 8; j++){
        //         cout << G[i][j] << string(3-to_string(G[i][j]).size(),' ');
        //     }
        //     cout << el;
        // }
        ans = cnt;
        return;
    }
    vector<ll> S(8); rep(i,8) S[i] = G[now][i];
    if(I[now] == 2){
        ll dcnt = 0;
        for(ll j = now+1; j < n; j++){
            if(G[now][j] >= 0) continue;
            dcnt += (G[now][j] == -1 ? 1 : 0);
            G[now][j] = 0;
            G[j][now] = 0;
        }
        solve(now+1,cnt+dcnt);
        rep(j,8){
            G[now][j] = S[j];
            G[j][now] = S[j];
        }
    }
    else if(I[now] == 1){
        // iを新しく繋ぐ
        for(ll i = now+1; i < n; i++){
            if(G[now][i] == 1 || G[now][i] == 0 || I[i] == 2) continue;
            ll dcnt = (G[now][i] == -1 ? 0 : 1);
            G[now][i] = 1;
            G[i][now] = 1;
            I[now]++;
            I[i]++;
            for(ll j = now+1; j < n; j++){
                if(j == i) continue;
                dcnt += (G[now][j] == -1 ? 1 : 0);
                G[now][j] = 0;
                G[j][now] = 0;
            }
            solve(now+1,cnt+dcnt);
            I[now]--;
            I[i]--;
            for(ll j = 0; j < n; j++){
                G[now][j] = S[j];
                G[j][now] = S[j];
            }
        }
    }
    else if(I[now] == 0){
        // iとjを新しく繋ぐ
        for(ll i = now+1; i < n-1; i++){
            if(I[i] == 2) continue;
            ll a = (G[now][i] == -1 ? 0 : 1);
            I[now]++;
            I[i]++;
            for(ll j = i+1; j < n; j++){
                if(I[j] == 2) continue;
                G[now][i] = 1;
                G[i][now] = 1;
                ll b = (G[now][j] == -1 ? 0 : 1);
                G[now][j] = 1;
                G[j][now] = 1;
                I[now]++;
                I[j]++;
                for(ll k = now+1; k < n; k++){
                    if(k == i || k == j) continue;
                    if(G[now][k] == -1) b++;
                    G[now][k] = 0;
                    G[k][now] = 0;
                }
                solve(now+1,cnt+a+b);
                I[now]--;
                I[j]--;
                rep(j,n){
                    G[now][j] = S[j];
                    G[j][now] = S[j];
                }
            }
            I[now]--;
            I[i]--;
        }
    }
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    rep(i,8)rep(j,8) G[i][j] = -2;
    rep(i,m){
        ll a,b; cin >> a >> b; a--,b--;
        G[a][b] = -1;
        G[b][a] = -1;
    }
    solve(0,0);
    cout << ans << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}