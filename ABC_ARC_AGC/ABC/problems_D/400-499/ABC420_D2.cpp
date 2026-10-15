#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {SORT(a); REVERSE(a); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int h,w; cin >> h >> w;
    vector<string> S(h); vecin(S);
    vector<vector<vector<int>>> D(h,vector<vector<int>>(w,vector<int>(2,inf)));
    queue<tuple<int,int,bool>> Q; //(x,y,s)
    for(int i = 0; i < h; i++)for(int j = 0; j < w; j++){
        if(S[i][j] == 'S'){
            Q.push(tuple(i,j,false));
            D[i][j][0] = 0;
            i = h;
            break;
        }
    }
    int ans = -1;
    while(!Q.empty()){
        auto [x,y,s] = Q.front(); Q.pop();
        if(S[x][y] == 'G'){
            ans = D[x][y][s];
            break;
        }
        for(int i = 0; i < 4; i++){
            int dx = DX[i], dy = DY[i];
            if(!(0 <= x+dx && x+dx < h) || !(0 <= y+dy && y+dy < w) || S[x+dx][y+dy] == '#') continue;
            bool ns = (S[x][y] == '?' ? !s : s);
            if((ns && S[x+dx][y+dy] == 'o') || (!ns && S[x+dx][y+dy] == 'x')) continue;
            if(D[x+dx][y+dy][ns] <= D[x][y][s]+1) continue;
            D[x+dx][y+dy][ns] = D[x][y][s]+1;
            Q.push(tuple(x+dx,y+dy,ns));
        }
    }
    cout << ans << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}