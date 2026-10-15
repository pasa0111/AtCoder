#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1e9; [[maybe_unused]]constexpr ll INF = 4e18;
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

    ll n; cin >> n;
    string S; cin >> S;
    vector<ll> X(n,-1);

    rep(p,2)rep(q,2){
        X[0] = p, X[1] = q;
        for(ll i = 1; i < n-1; i++){
            if(S[i] == 'o'){
                if(X[i] == 0) X[i+1] = X[i-1];
                else X[i+1] = !X[i-1];
            }
            else {
                if(X[i] == 0) X[i+1] = !X[i-1];
                else X[i+1] = X[i-1];
            }
        }
        ll target = (S[0] == 'o' ? (X[0] == 0 ? X[1] : !X[1]) : (X[0] == 0 ? !X[1] : X[1]));
        if(target == X[n-1]){
            bool ok = false;
            if(S[n-1] == 'o'){
                if(X[n-1] == 0) ok = (X[n-2] == X[0]);
                else ok = (X[n-2] != X[0]);
            }
            else {
                if(X[n-1] == 0) ok = (X[n-2] != X[0]);
                else ok = (X[n-2] == X[0]);
            }
            if(ok){
                for(ll i = 0; i < n; i++) cout << (X[i] == 0 ? 'S' : 'W');
                cout << el;
                return 0;
            }
        }
    }
    cout << -1 << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}