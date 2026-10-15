#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1e9; [[maybe_unused]]constexpr ll INF = 4e18;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {SORT(a); REVERSE(a); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

ll n,m;
vector<vector<ll>> G;
vector<ll> R; // 経路
vector<ll> V; // -1:未探索 0:探索中 1:閉路 2:木
ll cnt = 0;
bool ok = true;
bool found = false;

void dfs(ll pre, ll now, bool tree){
    // cout << "dfs(" << pre << "," << now << "," << tree << ")" << el;
    // cout << "R = " << R << el;
    // cout << "V = " << V << el << el;


    // 閉路から派生した部分が木か?
    if(tree){
        for(ll to:G[now]){
            if(to == pre) continue;
            if(V[to] != -1 && V[to] != 0){
                ok = false;
                return;
            }
            V[to] = 2;
            dfs(now,to,true);
        }
        return;
    }


    for(ll to:G[now]){
        if(to == pre) continue;
        // 閉路発見
        if(V[to] == 0){
            found = true;
            cnt++;
            ll i = 0;
            while(R[i] != to) i++;
            for(ll j = i; j < (ll)R.size(); j++) V[R[j]] = 1;
            for(ll j = i; j < (ll)R.size(); j++){
                for(ll r:G[R[j]]){
                    if(V[r] == 1) continue;
                    V[r] = 2;
                    dfs(R[j],r,true);
                }
            }
            return;
        }
        if(found) break;

        // 探索
        V[to] = 0;
        R.push_back(to);
        dfs(now,to,false);
        R.pop_back();
    }

    return;
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    G.resize(n);
    V.assign(n,-1);
    rep(i,m){
        ll u,v; cin >> u >> v; u--,v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(ll s = 0; s < n; s++){
        if(V[s] != -1) continue;
        found = false;
        R = {s};
        V[s] = 0;
        dfs(-1,s,false);
        R.clear();
        if(!found){
            ok = false;
            break;
        }
    }
    if(!ok){
        cout << 0 << el;
        return 0;
    }
    ll ans = 1;
    rep(i,cnt) ans = (ans*2)%998244353;
    cout << ans << el;
    
    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}