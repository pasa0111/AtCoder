#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 2000000000; [[maybe_unused]]constexpr ll INF = 9000000000000000000;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U, typename V> bool range(T a, U x, V b) { return ((a) < (x) && (x) < (b)); } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) { return square(a.first) + square(a.second); } template <typename T> vector<T> &sumvec(vector<T> &a) { ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i - 1]; return a; } template <typename T> vector<T> &vecin(vector<T> &a) { for(auto& x:a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) { SORT(a); REVERSE(a); return a; } template <typename T> ostream &operator<<(ostream &os, const vector<T> &a) { bool first = true; os << "{"; for (const T &x : a) { if (!first) os << ","; first = false; os << x; } os << "}"; return os; } template <typename T> ostream &operator<<(ostream &os, const set<T> &a) { bool first = true; os << "{"; for (const T &x : a) { if (!first) os << ","; first = false; os << x; } os << "}"; return os; } template <typename T> ostream &operator<<(ostream &os, const multiset<T> &a) { bool first = true; os << "{"; for (const T &x : a) { if (!first) os << ","; first = false; os << x; } os << "}"; return os; } template <typename T, typename U> T &IOTA(T &a, U b) { iota(a.begin(), a.end(), b); return a; }
void yesno(bool b){
    if(b) cout << "Yes" << el;
    if(!b) cout << "No" << el;
}

int main(){
    #ifdef pas4 
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////" << el;
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll h,w; cin >> h >> w;
    vector<vector<ll>> A(h,vector<ll>(w));
    rep(i,h) vecin(A[i]);
    vector<ll> P(h+w-1); vecin(P);
    queue<tuple<ll,ll,ll,ll>> Q; //(x,y,day,coin)
    vector<vector<ll>> D(h,vector<ll>(w,-INF)); //所持コイン-消費コインの最大値
    Q.push({0,0,0,A[0][0]-P[0]});
    D[0][0] = A[0][0]-P[0];
    vector<ll> DX = {1,0}, DY = {0,1};
    ll dx,dy;
    while(!Q.empty()){
        auto [x,y,day,coin] = Q.front();
        Q.pop();
        if(D[x][y] > coin) continue;
        rep(i,2){
            dx = DX[i], dy = DY[i];
            if(!range(-1,x+dx,h) || !range(-1,y+dy,w)) continue;
            if(D[x+dx][y+dy] < coin+A[x+dx][y+dy]-P[day+1]){
                D[x+dx][y+dy] = coin+A[x+dx][y+dy]-P[day+1];
                Q.push({x+dx,y+dy,day+1,coin+A[x+dx][y+dy]-P[day+1]});
            }
        }
    }
    vector<vector<ll>> E(h,vector<ll>(w));
    E[0][0] = D[0][0];
    for(ll i = 0; i < h; i++)for(ll j = 0; j < w; j++){
        if(range(-1,i-1,h) && range(-1,j-1,w)) E[i][j] = min(E[i-1][j], E[i][j-1]);
        else if(range(-1,i-1,h)) E[i][j] = E[i-1][j];
        else if(range(-1,j-1,w)) E[i][j] = E[i][j-1];
    }
    rep(i,h) cout << D[i] << el;
    cout << el;
    rep(i,h) cout << E[i] << el;

    cout << max(-E[h-1][w-1],0LL) << el;
    
    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms" << el; cout << "//////////////////////////////////////////////////////" << el;
    #endif
}