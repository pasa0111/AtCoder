#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {SORT(a); REVERSE(a); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

void solve(){
    ll n,a,b; cin >> n >> a >> b; a--,b--;
    if(n%2 == 1 || (a+b)%2 == 0){
        yesno(0);
        return;
    }
    yesno(1);
    bool f = false;
    if(a%2 == 0){
        swap(a,b);
        f = true;
    }
    ll A = a, B = b;
    //cout << pair(a,b) << el;
    string ans = "";
    for(ll j = 0; j < b; j++){
        if(j%2 == 0) rep(i,n-1) ans += 'D';
        else rep(i,n-1) ans += 'U';
        ans += 'R';
    }

    for(ll i = 0; i < a-1; i++){
        if(i%2 == 0) rep(j,n-b-1) ans += 'R';
        else rep(j,n-b-1) ans += 'L';
        ans += 'D';
    }


    while(a < n-1 && b < n-2){
        rep(i,n-b-1) ans += 'R';
        ans += 'D';
        rep(i,n-b-2) ans += 'L';
        ans += 'D';
        ans += 'L';
        rep(i,n-a-2) ans += 'D';
        ans += 'R';
        rep(i,n-a-3) ans += 'U';
        ans += 'R';
        ans += 'U';
        a+=2,b+=2;
    }
    if(a == n-1){
        ans += 'R';
        for(ll j = b+1; j < n-1; j++){
            if(j%2 == 1) ans += 'D';
            else ans += 'U';
            ans += 'R';
        }
        ans += 'D';
    }
    else if(b == n-2){
        ans += 'R';
        ans += 'D';
        ans += 'D';
        for(ll i = a+1; i < n-1; i++){
            if(i%2 == 0) ans += 'L';
            else ans += 'R';
            ans += 'D';
        }
        ans += 'R';
    }


    ll x = 0, y = 0;
    for(char c:ans){
        if(c == 'U') x--;
        else if(c == 'D') x++;
        else if(c == 'L') y--;
        else y++;
    }
    // assert(x == n-1 && y == n-1);

    if(x != n-1 || y != n-1){
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                if(i == A && j == B) cout << 'P';
                else cout << ((i+j)%2 == 0 ? '.' : '#');
            }
            cout << el;
        }
        cout << ans << el;
        x = 0, y = 0;
        cout << pair(0,0);
        for(char c:ans){
            if(c == 'U') x--;
            else if(c == 'D') x++;
            else if(c == 'L') y--;
            else y++;
            cout << " --> " << pair(x,y);
        }
        cout << el;
    }


    if(f){
        for(ll i = 0; i < n*n-2; i++){
            if(ans[i] == 'R') ans[i] = 'D';
            else if(ans[i] == 'U') ans[i] = 'L';
            else if(ans[i] == 'L') ans[i] = 'U';
            else ans[i] = 'R';
        }
    }
    
    x = 0, y = 0;
    for(char c:ans){
        if(c == 'U') x--;
        else if(c == 'D') x++;
        else if(c == 'L') y--;
        else y++;
    }
    assert(x == n-1 && y == n-1);

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