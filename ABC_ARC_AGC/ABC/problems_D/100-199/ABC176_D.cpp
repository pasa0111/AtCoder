#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1e9; [[maybe_unused]]constexpr ll INF = 4e18;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U, typename V> bool range(T a, U x, V b) { return ((a) < (x) && (x) < (b)); } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) { return square(a.first) + square(a.second); } template <typename T> vector<T> &sumvec(vector<T> &a) { ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i - 1]; return a; } template <typename T> vector<T> &vecin(vector<T> &a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) { SORT(a); REVERSE(a); return a; } template <typename T, typename U> T &IOTA(T &a, U b) { iota(a.begin(), a.end(), b); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

string S[1010];
ll V[1010][1010];
int DX[] = {-1,1,0,0}, DY[] = {0,0,-1,1};

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int h,w; cin >> h >> w;
    int a,b,c,d; cin >> a >> b >> c >> d;
    a--,b--,c--,d--;
    
    for(int i = 0; i < h; i++){
        cin >> S[i];
        fill(begin(V[i]), end(V[i]), INF);
    }
    V[a][b] = 0;
    deque<tuple<int,int,int>> Q;
    Q.push_back({a,b,0});
    while(!Q.empty()){
        auto [x,y,z] = Q.front(); Q.pop_front();
        if(z > V[x][y]) continue;
        for(int i = 0; i < 4; i++){
            int dx = DX[i], dy = DY[i];
            if(!(0 <= x+dx && x+dx < h) || !(0 <= y+dy && y+dy < w) || S[x+dx][y+dy] == '#' || V[x+dx][y+dy] <= V[x][y]) continue;
            V[x+dx][y+dy] = V[x][y];
            Q.push_front({x+dx,y+dy,z});
        }
        for(int i = -2; i <= 2; i++){
            if(!(0 <= x+i && x+i < h)) continue;
            for(int j = -2; j <= 2; j++){
                if(abs(i)+abs(j) <= 1 || !(0 <= y+j && y+j < w) || S[x+i][y+j] == '#' || V[x+i][y+j] <= V[x][y]+1) continue;
                V[x+i][y+j] = V[x][y]+1;
                Q.push_back({x+i,y+j,z+1});
            }
        }
    }
    if(V[c][d] == INF) V[c][d] = -1;
    cout << V[c][d] << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}