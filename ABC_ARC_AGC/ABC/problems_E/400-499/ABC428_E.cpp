#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {SORT(a); REVERSE(a); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

ll u = -1,v = -1;
vector<ll> R;
vector<vector<ll>> G;
vector<ll> ans;
vector<ll> D;

void dfs(ll id, ll now){
    //cout << "now = " << now << el;
    for(ll to:G[now]){
        if(D[to] <= D[now]) continue;
        ans[to] = id;
        dfs(id, to);
    }
    return;
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n; cin >> n;
    ans.assign(n,-1);
    G.resize(n);
    D.assign(n,INF);
    rep(i,n-1){
        ll a,b; cin >> a >> b; a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    D[0] = 0;
    queue<ll> Q;
    Q.push(0);
    ll mx = 0;
    while(!Q.empty()){
        ll now = Q.front(); Q.pop();
        for(ll to:G[now]){
            if(D[to] != INF) continue;
            D[to] = D[now]+1;
            if(mx == D[to]) u = max(u,to);
            else if(mx < D[to]){
                u = to;
                mx = D[to];
            }
            Q.push(to);
        }
    }
    D.assign(n,INF);
    D[u] = 0;
    Q.push(u);
    mx = 0;
    while(!Q.empty()){
        ll now = Q.front(); Q.pop();
        for(ll to:G[now]){
            if(D[to] != INF) continue;
            D[to] = D[now]+1;
            if(mx == D[to]) v = max(v,to);
            else if(mx < D[to]){
                v = to;
                mx = D[to];
            }
            Q.push(to);
        }
    }
    // v ~ u
    R = {v};
    ll now = v;
    while(now != u){
        for(ll to:G[now]){
            if(D[to] == D[now]-1){
                now = to;
                R.push_back(to);
                break;
            }
        }
    }
    //cout << R << el;
    ll r = R.size();
    for(ll i = 0; i < r; i++){
        ll id = (i >= r-1-i ? (i == r-1-i ? max(u,v) : v) : u);
        ll pre = (i > 0 ? R[i-1] : -1);
        ans[R[i]] = id;
        for(ll to:G[R[i]]){
            if(to == pre || D[to] <= D[R[i]]) continue;
            ans[to] = id;
            dfs(id,to);
        }
    }
    for(ll i = 0; i < n; i++){
        assert(ans[i] != -1);
        cout << ans[i]+1 << el;
    }

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}