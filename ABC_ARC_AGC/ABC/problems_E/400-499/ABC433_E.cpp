#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {SORT(a); REVERSE(a); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

void solve(){
    ll n,m; cin >> n >> m;
    vector<ll> I(n), J(m);
    vector<ll> X(n*m+1,-1), Y(n*m+1,-1);
    bool check = true;
    rep(i,n){
        ll a; cin >> a;
        if(X[a] != -1){
            check = false;
        }
        X[a] = i;
        I[i] = a;
    }
    rep(j,m){
        ll a; cin >> a;
        if(Y[a] != -1){
            check = false;
        }
        Y[a] = j;
        J[j] = a;
    }
    if(!check){
        yesno(0);
        return;
    }
    if(X[n*m] == -1 || Y[n*m] == -1){
        yesno(0);
        return;
    }
    vector<vector<ll>> M(n,vector<ll>(m,-1));
    vector<vector<ll>> V(n,vector<ll>(m));
    vector<ll> A;
    for(ll a = n*m; a >= 1; a--){
        if(X[a] != -1){
            for(ll j = 0; j < m; j++) V[X[a]][j]++;
            if(Y[a] != -1){
                for(ll i = 0; i < n; i++) V[i][Y[a]]++;
                M[X[a]][Y[a]] = a;
                continue;
            }
            ll lim = INF, idx = -1;
            for(ll j = 0; j < m; j++){
                if(V[X[a]][j] == 2 && M[X[a]][j] == -1 && J[j] > a && lim > J[j]){
                    lim = J[j];
                    idx = j;
                }
            }
            if(idx == -1){
                yesno(0);
                return;
            }
            M[X[a]][idx] = a;
        }
        else {
            if(Y[a] != -1){
                for(ll i = 0; i < n; i++) V[i][Y[a]]++;
                ll lim = INF, idx = -1;
                for(ll i = 0; i < n; i++){
                    if(V[i][Y[a]] == 2 && M[i][Y[a]] == -1 && I[i] > a && lim > I[i]){
                        lim = I[i];
                        idx = i;
                    }
                }
                if(idx == -1){
                    yesno(0);
                    return;
                }
                M[idx][Y[a]] = a;
            }
            else {
                A.push_back(a);
            }
        }
    }

    vector<tuple<ll,ll,ll>> P;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            //cout << M[i][j] << ' ';
            if(M[i][j] == -1){
                P.push_back({min(I[i],J[j]), i, j});
            }
        }
        //cout << el;
    }
    SORT(P);
    SORT(A);
    ll idx = 0;
    assert(P.size() == A.size());
    bool ans = true;
    for(auto [lim,i,j]:P){
        if(A[idx] < lim){
            M[i][j] = A[idx];
            idx++;
        }
        else ans = false;
    }

    yesno(ans);
    if(!ans) return;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cout << M[i][j] << ' ';
            assert(M[i][j] <= min(I[i],J[j]));
        }
        cout << el;
    }
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