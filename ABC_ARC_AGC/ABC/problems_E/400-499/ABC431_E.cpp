#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {SORT(a); REVERSE(a); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

void solve(){
    ll h,w; cin >> h >> w;
    vector<string> S(h); vecin(S);
    vector<vector<vector<ll>>> D(h,vector<vector<ll>>(w,vector<ll>(4,INF))); // dp[i][j][k] = マス(i,j)に方向kで入ってくるために必要な操作回数
    D[0][0][3] = 0;
    deque<tuple<ll,ll,ll>> Q; // マス,方向
    Q.push_back({0,0,3});
    ll ans = INF;
    while(!Q.empty()){
        auto [x,y,id] = Q.front(); Q.pop_front();
        //cout << x << " " << y << " " << id << el;
        if(S[x][y] == 'A'){
            ll dx = DX[id], dy = DY[id];
            if(x+dx == h-1 && y+dy == w){
                ans = min(ans,D[x][y][id]);
            }
            else if(0 <= x+dx && x+dx < h && 0 <= y+dy && y+dy < w && D[x+dx][y+dy][id] > D[x][y][id]){
                D[x+dx][y+dy][id] = D[x][y][id];
                Q.push_front({x+dx,y+dy,id});
            }

            ll next_id = (id+2)%4;
            dx = DX[next_id], dy = DY[next_id];
            if(x+dx == h-1 && y+dy == w){
                ans = min(ans,D[x][y][id]+1);
            }
            else if(0 <= x+dx && x+dx < h && 0 <= y+dy && y+dy < w && D[x+dx][y+dy][next_id] > D[x][y][id]+1){
                D[x+dx][y+dy][next_id] = D[x][y][id]+1;
                Q.push_back({x+dx,y+dy,next_id});
            }
            next_id = 3-id;
            dx = DX[next_id], dy = DY[next_id];
            if(x+dx == h-1 && y+dy == w){
                ans = min(ans,D[x][y][id]+1);
            }
            else if(0 <= x+dx && x+dx < h && 0 <= y+dy && y+dy < w && D[x+dx][y+dy][next_id] > D[x][y][id]+1){
                D[x+dx][y+dy][next_id] = D[x][y][id]+1;
                Q.push_back({x+dx,y+dy,next_id});
            }
        }
        else if(S[x][y] == 'B'){
            ll next_id = id;
            ll dx = DX[next_id], dy = DY[next_id];
            if(x+dx == h-1 && y+dy == w){
                ans = min(ans,D[x][y][id]+1);
            }
            else if(0 <= x+dx && x+dx < h && 0 <= y+dy && y+dy < w && D[x+dx][y+dy][next_id] > D[x][y][id]+1){
                D[x+dx][y+dy][id] = D[x][y][id]+1;
                Q.push_back({x+dx,y+dy,id});
            }

            next_id = (id+2)%4;
            dx = DX[next_id], dy = DY[next_id];
            if(x+dx == h-1 && y+dy == w){
                ans = min(ans,D[x][y][id]);
            }
            else if(0 <= x+dx && x+dx < h && 0 <= y+dy && y+dy < w && D[x+dx][y+dy][next_id] > D[x][y][id]){
                D[x+dx][y+dy][next_id] = D[x][y][id];
                Q.push_front({x+dx,y+dy,next_id});
            }
            next_id = 3-id;
            dx = DX[next_id], dy = DY[next_id];
            if(x+dx == h-1 && y+dy == w){
                ans = min(ans,D[x][y][id]+1);
            }
            else if(0 <= x+dx && x+dx < h && 0 <= y+dy && y+dy < w && D[x+dx][y+dy][next_id] > D[x][y][id]+1){
                D[x+dx][y+dy][next_id] = D[x][y][id]+1;
                Q.push_back({x+dx,y+dy,next_id});
            }
        }
        else if(S[x][y] == 'C'){
            ll next_id = id;
            ll dx = DX[next_id], dy = DY[next_id];
            if(x+dx == h-1 && y+dy == w){
                ans = min(ans,D[x][y][id]+1);
            }
            else if(0 <= x+dx && x+dx < h && 0 <= y+dy && y+dy < w && D[x+dx][y+dy][next_id] > D[x][y][id]+1){
                D[x+dx][y+dy][id] = D[x][y][id]+1;
                Q.push_back({x+dx,y+dy,id});
            }

            next_id = 3-id;
            dx = DX[next_id], dy = DY[next_id];            
            if(x+dx == h-1 && y+dy == w){
                ans = min(ans,D[x][y][id]);
            }
            else if(0 <= x+dx && x+dx < h && 0 <= y+dy && y+dy < w && D[x+dx][y+dy][next_id] > D[x][y][id]){
                D[x+dx][y+dy][next_id] = D[x][y][id];
                Q.push_front({x+dx,y+dy,next_id});
            }
            next_id = (id+2)%4;
            dx = DX[next_id], dy = DY[next_id];
            if(x+dx == h-1 && y+dy == w){
                ans = min(ans,D[x][y][id]+1);
            }
            else if(0 <= x+dx && x+dx < h && 0 <= y+dy && y+dy < w && D[x+dx][y+dy][next_id] > D[x][y][id]+1){
                D[x+dx][y+dy][next_id] = D[x][y][id]+1;
                Q.push_back({x+dx,y+dy,next_id});
            }
        }
    }
    cout << ans << el;
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll t; cin >> t;
    rep(test,t) solve();

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}