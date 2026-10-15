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

    ll n,x,y; cin >> n >> x >> y;
    const ll p = n/2, q = n/2 + n%2;
    vector<ll> X(p), Y(q);
    rep(i,n){
        if(i%2 == 0) cin >> Y[i/2];
        else cin >> X[i/2];
    }
    // xの前半列挙
    unordered_map<ll,string> M;
    ll h = p/2;
    rep(info,1<<h){
        ll z = 0;
        string S = "";
        rep(i,h){
            if(((info>>i)&1) == 0){
                z += X[i];
                S += '+';
            }
            else{
                z -= X[i];
                S += '-';
            }
        }
        M[z] = S;
    }
    ll g = p-h;
    bool ok = false;
    string SX = "";
    rep(info,1<<g){
        ll z = 0;
        string S = "";
        rep(i,g){
            if(((info>>i)&1) == 0){
                z += X[h+i];
                S += '+';
            }
            else{
                z -= X[h+i];
                S += '-';
            }
        }
        if(M.count(x-z)){
            SX = M[x-z] + S;
            ok = true;
            break;
        }
    }
    if(!ok){
        yesno(0);
        return 0;
    }

    // yの前半列挙
    M.clear();
    h = q/2;
    rep(info,1<<h){
        ll z = 0;
        string S = "";
        rep(i,h){
            if(((info>>i)&1) == 0){
                z += Y[i];
                S += '+';
            }
            else{
                z -= Y[i];
                S += '-';
            }
        }
        M[z] = S;
    }
    g = q-h;
    ok = false;
    string SY = "";
    rep(info,1<<g){
        ll z = 0;
        string S = "";
        rep(i,g){
            if(((info>>i)&1) == 0){
                z += Y[h+i];
                S += '+';
            }
            else{
                z -= Y[h+i];
                S += '-';
            }
        }
        if(M.count(y-z)){
            SY = M[y-z] + S;
            ok = true;
            break;
        }
    }
    if(!ok){
        yesno(0);
        return 0;
    }
    yesno(1);
    char now = 'R';
    for(ll i = 0; i < n; i++){
        if(i%2 == 0){
            if(SY[i/2] == '+'){
                if(now == 'R') cout << 'L';
                else cout << 'R';
                now = 'U';
            }
            else {
                if(now == 'R') cout << 'R';
                else cout << 'L';
                now = 'D';
            }
        }
        else {
            if(SX[i/2] == '+'){
                if(now == 'U') cout << 'R';
                else cout << 'L';
                now = 'R';
            }
            else {
                if(now == 'U') cout << 'L';
                else cout << 'R';
                now = 'L';
            }
        }
    }
    cout << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}