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

    int h,w,y; cin >> h >> w >> y;
    PGqueue<tuple<int,int,int>> Q;
    vector<vector<int>> A(h,vector<int>(w));
    rep(i,h) vecin(A[i]);
    for(int j = 1; j < w-1; j++) Q.push(tuple(A[0][j],0,j));
    for(int i = 0; i < h; i++){
        Q.push(tuple(A[i][0],i,0));
        if(w > 1) Q.push(tuple(A[i][w-1],i,w-1));
    }
    if(h > 1) for(ll j = 1; j < w-1; j++) Q.push(tuple(A[h-1][j],h-1,j));
    int ans = h*w;
    vector<vector<bool>> B(h,vector<bool>(w,true));
    for(int i = 1; i <= y; i++){
        while(!Q.empty() && get<0>(Q.top()) <= i){
            auto [a,x,y] = Q.top(); Q.pop();
            if(!B[x][y]) continue;
            B[x][y] = false;
            ans--;
            for(int j = 0; j < 4; j++){
                int dx = DX[j], dy = DY[j];
                if(!(0 <= x+dx && x+dx < h) || !(0 <= y+dy && y+dy < w) || !B[x+dx][y+dy]) continue;
                Q.push(tuple(A[x+dx][y+dy],x+dx,y+dy));
            }
        }
        cout << ans << el;
    }

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}