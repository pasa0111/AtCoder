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

    ll h,w; cin >> h >> w;
    vector<string> S(h); vecin(S);
    ll x,y;
    rep(i,h)rep(j,w){
        if(S[i][j] == 'T'){
            x = i, y = j;
            i = h;
            break;
        }
    }
    unordered_map<string,ll> M;
    queue<string> Q;
    string T = "";
    rep(i,h) T += S[i];
    Q.push(T);
    M[T] = 0;
    while(!Q.empty()){
        T = Q.front(); Q.pop();
        //cout << "T = " << T << el;
        ll cnt = M[T];
        rep(i,h) S[i] = T.substr(w*i, w);
        bool check = true;
        rep(i,h)rep(j,w){
            if(S[i][j] == '#'){
                check = false;
                i = h;
                break;
            }
        }
        if(check){
            cout << cnt << el;
            return 0;
        }
        vector<string> U(h,string(w,'?'));

        // 右に移動
        bool ok = true;
        for(ll i = 0; i < h; i++){
            for(ll j = w-1; j > 0; j--){
                U[i][j] = S[i][j-1];
                if(i == x && j == y && S[i][j-1] == '#'){
                    ok = false;
                    i = h;
                    break;
                }
            }
            if(ok) U[i][0] = '.';
        }
        if(ok){
            string V = "";
            rep(i,h) V += U[i];
            if(!M.count(V)){
                M[V] = cnt+1;
                Q.push(V);
            }
        }

        // 左
        ok = true;
        for(ll i = 0; i < h; i++){
            for(ll j = 0; j < w-1; j++){
                U[i][j] = S[i][j+1];
                if(i == x && j == y && S[i][j+1] == '#'){
                    ok = false;
                    i = h;
                    break;
                }
            }
            if(ok) U[i][w-1] = '.';
        }
        if(ok){
            string V = "";
            rep(i,h) V += U[i];
            if(!M.count(V)){
                M[V] = cnt+1;
                Q.push(V);
            }
        }

        // 上
        ok = true;
        for(ll j = 0; j < w; j++){
            for(ll i = 0; i < h-1; i++){
                U[i][j] = S[i+1][j];
                if(i == x && j == y && S[i+1][j] == '#'){
                    ok = false;
                    j = w;
                    break;
                }
            }
            if(ok) U[h-1][j] = '.';
        }
        if(ok){
            string V = "";
            rep(i,h) V += U[i];
            if(!M.count(V)){
                M[V] = cnt+1;
                Q.push(V);
            }
        }


        // 下
        ok = true;
        for(ll j = 0; j < w; j++){
            for(ll i = h-1; i > 0; i--){
                U[i][j] = S[i-1][j];
                if(i == x && j == y && S[i-1][j] == '#'){
                    ok = false;
                    j = w;
                    break;
                }
            }
            if(ok) U[0][j] = '.';
        }
        if(ok){
            string V = "";
            rep(i,h) V += U[i];
            if(!M.count(V)){
                M[V] = cnt+1;
                Q.push(V);
            }
        }
    }
    cout << -1 << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}