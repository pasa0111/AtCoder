#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 2e9; [[maybe_unused]]constexpr ll INF = 9e18;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U, typename V> bool range(T a, U x, V b) { return ((a) < (x) && (x) < (b)); } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) { return square(a.first) + square(a.second); } template <typename T> vector<T> &sumvec(vector<T> &a) { ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i - 1]; return a; } template <typename T> vector<T> &vecin(vector<T> &a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) { SORT(a); REVERSE(a); return a; } template <typename T, typename U> T &IOTA(T &a, U b) { iota(a.begin(), a.end(), b); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll h,w; cin >> h >> w;
    vector<string> S(h); vecin(S);
    queue<pair<ll,ll>> Q;
    vector<ll> DX = {-1,1,0,0}, DY = {0,0,-1,1};
    for(ll j = 0; j < w; j++){
        if(S[0][j] == '.'){
            Q.push({0,j});
            S[0][j] = 'x';
        }
        if(S[h-1][j] == '.'){
            Q.push({h-1,j});
            S[h-1][j] = 'x';
        }
        while(!Q.empty()){
            auto [x,y] = Q.front(); Q.pop();
            rep(i,4){
                ll dx = DX[i], dy = DY[i];
                if(!range(-1,x+dx,h) || !range(-1,y+dy,w) || S[x+dx][y+dy] != '.') continue;
                S[x+dx][y+dy] = 'x';
                Q.push({x+dx,y+dy});
            }
        }
    }
    for(ll i = 1; i < h-1; i++){
        if(S[i][0] == '.'){
            S[i][0] = 'x';
            Q.push({i,0});
        }
        if(S[i][w-1] == '.'){
            S[i][w-1] = 'x';
            Q.push({i,w-1});
        }
        while(!Q.empty()){
            auto [x,y] = Q.front(); Q.pop();
            rep(i,4){
                ll dx = DX[i], dy = DY[i];
                if(!range(-1,x+dx,h) || !range(-1,y+dy,w) || S[x+dx][y+dy] != '.') continue;
                S[x+dx][y+dy] = 'x';
                Q.push({x+dx,y+dy});
            }
        }
    }
    ll ans = 0;
    rep(i,h)rep(j,w){
        if(S[i][j] != '.') continue;
        Q.push({i,j});
        S[i][j] = 'o';
        ans++;
        while(!Q.empty()){
            auto [x,y] = Q.front(); Q.pop();
            rep(i,4){
                ll dx = DX[i], dy = DY[i];
                if(!range(-1,x+dx,h) || !range(-1,y+dy,w) || S[x+dx][y+dy] != '.') continue;
                S[x+dx][y+dy] = 'o';
                Q.push({x+dx,y+dy});
            }
        }
    }
    cout << ans << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}