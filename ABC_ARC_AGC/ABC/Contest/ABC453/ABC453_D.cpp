#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 2e9; [[maybe_unused]]constexpr ll INF = 9e18;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U, typename V> bool range(T a, U x, V b) { return ((a) < (x) && (x) < (b)); } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) { return square(a.first) + square(a.second); } template <typename T> vector<T> &sumvec(vector<T> &a) { ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i - 1]; return a; } template <typename T> vector<T> &vecin(vector<T> &a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) { SORT(a); REVERSE(a); return a; } template <typename T, typename U> T &IOTA(T &a, U b) { iota(a.begin(), a.end(), b); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

vector<ll> DX = {-1,1,0,0}, DY = {0,0,-1,1};

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll h,w; cin >> h >> w;
    vector<string> S(h); vecin(S);
    vector<char> num = {'U','D','L','R'};
    vector<vector<vector<ll>>> C(4,vector<vector<ll>>(h,vector<ll>(w,inf)));
    ll a,b,c = -1,d = -1;
    rep(i,h)rep(j,w){
        if(S[i][j] == 'S'){
            a = i, b = j;
        }
    }
    queue<tuple<ll,ll,ll>> Q;
    rep(i,4){
        ll dx = DX[i], dy = DY[i];
        C[i][a][b] = 0;
        if(!range(-1,a+dx,h) || !range(-1,b+dy,w) || S[a+dx][b+dy] == '#') continue;
        Q.push({i,a+dx,b+dy});
        C[i][a+dx][b+dy] = 1;
    }
    ll f;
    while(!Q.empty()){
        auto [id,x,y] = Q.front(); Q.pop();
        if(S[x][y] == 'G'){
            c = x, d = y;
            f = id;
            break;
        }
        else if(S[x][y] == '.'){
            rep(i,4){
                ll dx = DX[i], dy = DY[i];
                if(!range(-1,x+dx,h) || !range(-1,y+dy,w) || S[x+dx][y+dy] == '#' || C[i][x+dx][y+dy] <= C[id][x][y]+1) continue;
                C[i][x+dx][y+dy] = C[id][x][y]+1;
                Q.push({i,x+dx,y+dy});
            }
        }
        else if(S[x][y] == 'o'){
            ll dx = DX[id], dy = DY[id];
            if(!range(-1,x+dx,h) || !range(-1,y+dy,w) || S[x+dx][y+dy] == '#' || C[id][x+dx][y+dy] <= C[id][x][y]+1) continue;
            C[id][x+dx][y+dy] = C[id][x][y]+1;
            Q.push({id,x+dx,y+dy});
        }
        else if(S[x][y] == 'x'){
            rep(i,4){
                if(i == id) continue;
                ll dx = DX[i], dy = DY[i];
                if(!range(-1,x+dx,h) || !range(-1,y+dy,w) || S[x+dx][y+dy] == '#' || C[i][x+dx][y+dy] <= C[id][x][y]+1) continue;
                C[i][x+dx][y+dy] = C[id][x][y]+1;
                Q.push({i,x+dx,y+dy});
            }
        }
    }
    if(c == -1) yesno(0);
    else {
        string ans;
        while(S[c][d] != 'S'){
            ll dx = DX[f], dy = DY[f];
            if(!range(-1,c-dx,h) || !range(-1,d-dy,w)) continue;
            rep(i,4){
                if(C[i][c-dx][d-dy] == C[f][c][d]-1){
                    if(S[c-dx][d-dy] == 'o' && f != i) continue;
                    if(S[c-dx][d-dy] == 'x' && f == i) continue;
                    ans += num[f];
                    f = i;
                    c -= dx;
                    d -= dy;
                    break;
                }
            }
        }
        REVERSE(ans);
        yesno(1);
        cout << ans << el;
    }



    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}