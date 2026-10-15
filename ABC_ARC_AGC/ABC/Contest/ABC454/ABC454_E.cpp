#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1e9; [[maybe_unused]]constexpr ll INF = 4e18;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U, typename V> bool range(T a, U x, V b) { return ((a) < (x) && (x) < (b)); } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) { return square(a.first) + square(a.second); } template <typename T> vector<T> &sumvec(vector<T> &a) { ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i - 1]; return a; } template <typename T> vector<T> &vecin(vector<T> &a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) { SORT(a); REVERSE(a); return a; } template <typename T, typename U> T &IOTA(T &a, U b) { iota(a.begin(), a.end(), b); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

int n,a,b;
vector<vector<bool>> visited;
vector<int> DX = {-1,1,0,0}, DY = {0,0,-1,1};
string ans = "";
string num = "UDLR";
bool ok = false;
void dfs(int x, int y){
    if(x == n-1 && y == n-1){
        if((int)ans.size() == n*n-2){
            ok = true;
        }
        return;
    }

    int tox = -1, toy = -1, f = -1;
    bool flag = false;
    rep(i,4){
        int dx = DX[i], dy = DY[i];
        if(!range(-1,x+dx,n) || !range(-1,y+dy,n) || visited[x+dx][y+dy]) continue;
        if((int)ans.size() < n*n-3 && x+dx == n-1 && y+dy == n-1) continue;
        int cnt = 0;
        rep(j,4){
            int ds = DX[j], dt = DY[j];
            if(!range(-1,x+dx+ds,n) || !range(-1,y+dy+dt,n) || visited[x+dx+ds][y+dy+dt]) cnt++; 
        }
        if(cnt == 3){
            if(flag) return;
            flag = true;
            tox = x+dx;
            toy = y+dy;
            f = i;
        }
    }
    if(!flag)rep(i,4){
        int dx = DX[i], dy = DY[i];
        if(!range(-1,x+dx,n) || !range(-1,y+dy,n) || visited[x+dx][y+dy]) continue;
        ans += num[i];
        visited[x+dx][y+dy] = true;
        dfs(x+dx,y+dy);
        if(ok) return;
        visited[x+dx][y+dy] = false;
        ans.pop_back();
    }
    if(flag){
        ans += num[f];
        visited[tox][toy] = true;
        dfs(tox,toy);
        if(ok) return;
        visited[tox][toy] = false;
        ans.pop_back();
    }
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int T; cin >> T;
    rep(test,T){
        cin >> n >> a >> b; a--,b--;
        visited.assign(n,vector<bool>(n,false));
        visited[0][0] = true;
        visited[a][b] = true;
        ok = false;
        ans = "";
        dfs(0,0);
        yesno(ok);
        if(ok) cout << ans << el;
    }

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}