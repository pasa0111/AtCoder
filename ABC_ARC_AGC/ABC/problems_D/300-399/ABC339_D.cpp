#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {SORT(a); REVERSE(a); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

int D[60][60][60][60];
bool vis[60][60];

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector<string> S(n); vecin(S);
    queue<tuple<int,int,int,int>> Q;
    queue<pair<int,int>> bfs;
    int a = -1,b,c,d;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(S[i][j] == 'P'){
                if(a == -1){
                    a = i, b = j;
                }
                else {
                    c = i, d = j;
                    Q.push(tuple(a,b,c,d));
                    D[a][b][c][d] = 1;
                    bfs.push(pair(c,d));
                    vis[c][d] = true;
                    i = n;
                    break;
                }
            }
        }
    }
    bool ok = false;
    while(!bfs.empty()){
        auto [x,y] = bfs.front(); bfs.pop();
        if(x == a && y == b){
            ok = true;
            break;
        }
        for(int i = 0; i < 4; i++){
            int dx = DX[i], dy = DY[i];
            if(!(0 <= x+dx && x+dx < n) || !(0 <= y+dy && y+dy < n) || vis[x+dx][y+dy] || S[x+dx][y+dy] == '#') continue;
            vis[x+dx][y+dy] = true;
            bfs.push(pair(x+dx,y+dy));
        }
    }
    if(!ok){
        cout << -1 << el;
        return 0;
    }

    int ans = -1;
    while(!Q.empty()){
        auto [x,y,z,w] = Q.front(); Q.pop();
        if(x == z && y == w){
            ans = D[x][y][z][w]-1;
            break;
        }
        for(ll i = 0; i < 4; i++){
            int di = DX[i], dj = DY[i];
            int nx = max(0,min(n-1,x+di)), ny = max(0,min(n-1,y+dj)), nz = max(0,min(n-1,z+di)), nw = max(0,min(n-1,w+dj));
            if(S[nx][ny] == '#'){
                nx = x, ny = y;
            }
            if(S[nz][nw] == '#'){
                nz = z, nw = w;
            }
            if(D[nx][ny][nz][nw] != 0) continue;
            D[nx][ny][nz][nw] = D[x][y][z][w]+1;
            Q.push(tuple(nx,ny,nz,nw));
        }
    }
    cout << ans << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}