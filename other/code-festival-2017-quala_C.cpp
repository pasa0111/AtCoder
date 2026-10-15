#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {sort(a.rbegin(),a.rend()); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

ll h,w;
const ll lim = 105;
char G[lim][lim];
vector<ll> C(26);
bool ans = false;

void solve(ll x,ll y){
    if(ans) return;
    if(x == h){
        bool ok = true;
        for(ll i = 0; i < h; i++){
            for(ll j = 0; j < w; j++){
                ok &= G[i][j] != '?';
            }
        }
        ans |= ok;
        return;
    }
    if(y == w){
        solve(x+1,0);
        return;
    }
    if(G[x][y] != '?'){
        solve(x,y+1);
        return;
    }

    vector<pair<ll,ll>> D(26);
    rep(i,26) D[i] = pair(C[i],i);
    SORT(D);
    if(x == h-1-x){
        if(y == w-1-y){
            ll i = lower_bound(D.begin(), D.end(), pair(1,-1)) - D.begin();
            if(i == 26) return;
            i = D[i].second;
            G[x][y] = char('a'+i);
            C[i]--;
            solve(x,y+1);
            C[i]++;
            G[x][y] = '?';
        }
        else {
            ll i = lower_bound(D.begin(), D.end(), pair(2,-1)) - D.begin();
            if(i == 26) return;
            i = D[i].second;
            G[x][y] = char('a'+i);
            G[x][w-1-y] = char('a'+i);
            C[i] -= 2;
            solve(x,y+1);
            C[i] += 2;
            G[x][y] = '?';
            G[x][w-1-y] = '?';
        }
    }
    else {
        if(y == w-1-y){
            ll i = lower_bound(D.begin(), D.end(), pair(2,-1)) - D.begin();
            if(i == 26) return;
            i = D[i].second;
            G[x][y] = char('a'+i);
            G[h-1-x][y] = char('a'+i);
            C[i] -= 2;
            solve(x,y+1);
            C[i] += 2;
            G[x][y] = '?';
            G[h-1-x][y] = '?';
        }
        else {
            ll i = lower_bound(D.begin(), D.end(), pair(4,-1)) - D.begin();
            if(i == 26) return;
            i = D[i].second;
            G[x][y] = char('a'+i);
            G[x][w-1-y] = char('a'+i);
            G[h-1-x][y] = char('a'+i);
            G[h-1-x][w-1-y] = char('a'+i);
            C[i] -= 4;
            solve(x,y+1);
            C[i] += 4;
            G[x][y] = '?';
            G[x][w-1-y] = '?';
            G[h-1-x][y] = '?';
            G[h-1-x][w-1-y] = '?';
        }
    }
}


int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> h >> w;
    rep(i,lim)rep(j,lim) G[i][j] = '?';
    rep(i,h)rep(j,w){
        char a; cin >> a;
        C[a-'a']++;
    }
    solve(0,0);
    yesno(ans);

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}