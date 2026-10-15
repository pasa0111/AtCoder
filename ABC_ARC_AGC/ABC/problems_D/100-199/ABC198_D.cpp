#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 2e9; [[maybe_unused]]constexpr ll INF = 9e18;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U, typename V> bool range(T a, U x, V b) { return ((a) < (x) && (x) < (b)); } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) { return square(a.first) + square(a.second); } template <typename T> vector<T> &sumvec(vector<T> &a) { ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i - 1]; return a; } template <typename T> vector<T> &vecin(vector<T> &a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) { SORT(a); REVERSE(a); return a; } template <typename T, typename U> T &IOTA(T &a, U b) { iota(a.begin(), a.end(), b); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "UNSOLVABLE") << el;
}

vector<bool> used(10,false);
set<char> S;
ll x,y,z;
vector<char> V;
vector<ll> U(26);
string A,B,C;
bool ans = false;
void solve(ull cnt){
    if(ans) return;
    if(cnt == V.size()){
        x = 0, y = 0, z = 0;
        if(U[A[0]-'a'] == 0 || U[B[0]-'a'] == 0 || U[C[0]-'a'] == 0) return;
        for(char a:A) x = 10*x + U[a-'a'];
        for(char b:B) y = 10*y + U[b-'a'];
        for(char c:C) z = 10*z + U[c-'a'];
        if(x+y == z && x > 0 && y > 0) ans = true;
        return;
    }
    for(ll i = 0; i < 10; i++){
        if(!used[i]){
            U[V[cnt]-'a'] = i;
            used[i] = true;
            solve(cnt+1);
            U[V[cnt]-'a'] = -1;
            used[i] = false;
        }
    }
    return;
}


int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> A >> B >> C;
    for(char a:A) S.insert(a);
    for(char b:B) S.insert(b);
    for(char c:C) S.insert(c);
    if(S.size() > 10){
        yesno(0);
        return 0;
    }
    for(char s:S) V.push_back(s);
    solve(0);
    if(!ans) yesno(0);
    else cout << x << el << y << el << z << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n" << "//////////////////////////////////////////////////////\n";
    #endif
}