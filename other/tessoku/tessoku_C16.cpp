#include <bits/stdc++.h> /*  ^__________^  */
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {sort(a.rbegin(),a.rend()); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

ll n,m,k;
vector<map<ll,ll>> M;
vector<vector<tuple<ll,ll,ll,ll>>> V;
vector<ll> IDX;
vector<bool> S;
vector<ll> MX;
ll f(ll hazama, ll pos){
    if(hazama < 0) return -INF;
    if(!S[pos]) sort(V[pos].begin(), V[pos].end(), [](tuple<ll,ll,ll,ll> x, tuple<ll,ll,ll,ll> y){return get<3>(x) < get<3>(y);});
    S[pos] = true;
    ll mx = MX[pos];
    M[pos][0] = 0;
    for(ll i = IDX[pos]; i < (ll)V[pos].size(); i++){
        auto [a,s,b,t] = V[pos][i];
        if(hazama < t) break;
        assert(b == pos);
        M[pos][t] = max(mx, f(s-k,a)+1);
        mx = max(mx, M[pos][t]);
        IDX[pos] = i+1;
        MX[pos] = mx;
    }
    return prev(M[pos].upper_bound(hazama))->second;
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m >> k;
    M.resize(n);
    V.resize(n);
    IDX.assign(n,0);
    S.assign(n,false);
    MX.assign(n,0);

    rep(i,m){
        ll a,s,b,t; cin >> a >> s >> b >> t; a--,b--;
        V[b].push_back({a,s,b,t});
    }
    ll ans = 0;
    rep(i,n) ans = max(ans, f(INF,i));
    cout << ans << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}