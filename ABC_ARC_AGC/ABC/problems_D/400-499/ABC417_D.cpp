#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1e9; [[maybe_unused]]constexpr ll INF = 4e18;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {SORT(a); REVERSE(a); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

vector<vector<int>> W; // クエリ番号 --> {そのクエリと同じ行き先になるクエリ番号}
vector<int> Q; // クエリiの答え

void rekkyo(int now, int ans){
    for(int k:W[now]){
        Q[k] = ans;
        rekkyo(k,ans);
    }
    return;
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector<int> P(n), A(n), B(n);
    rep(i,n) cin >> P[i] >> A[i] >> B[i];
    const int lim = 1010;
    vector<vector<int>> V(n+1,vector<int>(lim,-1)); // V[i][j] = i個目のプレゼントを受け取った後にテンションがjとなっているようなクエリ番号の一例
    vector<int> S = B;
    sumvec(S);
    int q; cin >> q;
    Q.assign(q,-1);
    W.resize(q);
    vector<int> X(q); vecin(X);
    for(int i = 0; i < q; i++){
        // x - (B[0]+...+B[p]) < lim
        // x-lim < S[p]

        if(X[i] < lim){
            if(V[0][X[i]] == -1) V[0][X[i]] = i;
            else W[V[0][X[i]]].push_back(i);
        }
        else if(X[i]-S[n-1] >= lim) Q[i] = X[i]-S[n-1];
        else {
            int p = upper_bound(S.begin(), S.end(), X[i]-lim) - S.begin();
            if(V[p+1][X[i]-S[p]] == -1) V[p+1][X[i]-S[p]] = i;
            else W[V[p+1][X[i]-S[p]]].push_back(i);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < lim; j++){
            if(V[i-1][j] == -1) continue;
            if(P[i-1] >= j){
                if(V[i][j+A[i-1]] == -1) V[i][j+A[i-1]] = V[i-1][j];
                else W[V[i][j+A[i-1]]].push_back(V[i-1][j]);
            }
            else {
                int to = max(0,j-B[i-1]);
                if(V[i][to] == -1) V[i][to] = V[i-1][j];
                else W[V[i][to]].push_back(V[i-1][j]);
            }
        }
    }
    for(int j = 0; j < lim; j++){
        int idx = V[n][j];
        if(idx == -1) continue;
        Q[idx] = j;
        rekkyo(idx,j);
    }
    for(int i = 0; i < q; i++){
        assert(Q[i] != -1);
        cout << Q[i] << el;
    }

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}