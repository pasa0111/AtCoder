#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 2e9; [[maybe_unused]]constexpr ll INF = 9e18;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U, typename V> bool range(T a, U x, V b) { return ((a) < (x) && (x) < (b)); } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) { return square(a.first) + square(a.second); } template <typename T> vector<T> &sumvec(vector<T> &a) { ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i - 1]; return a; } template <typename T> vector<T> &vecin(vector<T> &a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) { SORT(a); REVERSE(a); return a; } template <typename T, typename U> T &IOTA(T &a, U b) { iota(a.begin(), a.end(), b); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

int DX[] = {-1,1,0,0}, DY[] = {0,0,-1,1};

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int h,w; cin >> h >> w;
    vector<string> S(h); vecin(S);
    vector<vector<int>> V(h);
    int s,t;
    rep(i,h)rep(j,w){
        if(S[i][j] == 'S'){
            s = i, t = j;
            break;
        }
    }
    bool ans = false;
    rep(i,4){
        int ds = DX[i], dt = DY[i];
        if(!range(-1,s+ds,h) || !range(-1,t+dt,w) || S[s+ds][t+dt] == '#') continue;
        queue<pair<int,int>> Q;
        rep(j,h) V[j].assign(w,inf);
        V[s+ds][t+dt] = 0;
        rep(j,4){
            int dx = DX[j], dy = DY[j];
            if(!range(-1,s+ds+dx,h) || !range(-1,t+dt+dy,w) || S[s+ds+dx][t+dt+dy] == 'S' || S[s+ds+dx][t+dt+dy] == '#') continue;
            Q.push({s+ds+dx,t+dt+dy});
            V[s+ds+dx][t+dt+dy] = 1;
        }
        while(!Q.empty()){
            auto [x,y] = Q.front(); Q.pop();
            if(S[x][y] == 'S'){
                ans = true;
                break;
            }
            rep(j,4){
                int dx = DX[j], dy = DY[j];
                if(!range(-1,x+dx,h) || !range(-1,y+dy,w) || S[x+dx][y+dy] == '#' || V[x+dx][y+dy] <= V[x][y]+1) continue;
                Q.push({x+dx,y+dy});
                V[x+dx][y+dy] = V[x][y]+1;
            }
        }
        if(ans) break;
    }
    yesno(ans);

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}