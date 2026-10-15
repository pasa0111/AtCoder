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

    int n,k; cin >> n >> k;
    vector<vector<int>> A(n,vector<int>(n));
    rep(i,n) vecin(A[i]);
    multiset<int> X, Z;
    int Y;
    // for(ll i = 0; i < k; i++)for(ll j = 0; j < k; j++) Z.insert(A[i][j]);
    // Y = *Z.begin();
    // Z.erase(Z.begin());
    // const ull t = k*k/2;
    // while(Z.size() > t){
    //     X.insert(Y);
    //     Y = *Z.begin();
    //     Z.erase(Z.begin());
    // }
    //cout << pair(0,0) << " : " << X[0] << " " << Y[0] << " " << Z[0] << el;
    // for(ll i = 1; i+k-1 < n; i++){
    //     X[i] = X[i-1], Y[i] = Y[i-1], Z[i] = Z[i-1];
    //     X[i].insert(Y[i]);
    //     Y[i] = -1;
    //     for(ll j = 0; j < k; j++){
    //         // i-1行目の要素の削除
    //         ll a = A[i-1][j];
    //         if(X[i].count(a)) X[i].erase(X[i].find(a));
    //         else if(Z[i].count(a)) Z[i].erase(Z[i].find(a));

    //         // i+k-1行目の追加
    //         a = A[i+k-1][j];
    //         if(!X[i].empty() && a <= *X[i].rbegin()) X[i].insert(a);
    //         else Z[i].insert(a);
    //     }
    //     if(!X[i].empty()){
    //         Y[i] = *X[i].rbegin();
    //         X[i].erase(prev(X[i].end()));
    //     }
    //     else {
    //         Y[i] = *Z[i].begin();
    //         Z[i].erase(Z[i].begin());
    //     }
    //     assert(Y[i] != -1);
    //     while(Z[i].size() > t){
    //         X[i].insert(Y[i]);
    //         Y[i] = *Z[i].begin();
    //         Z[i].erase(Z[i].begin());
    //     }
    //     while(Z[i].size() < t){
    //         Z[i].insert(Y[i]);
    //         Y[i] = *X[i].rbegin();
    //         X[i].erase(prev(X[i].end()));
    //     }
    //     //cout << pair(i,0) << " : " << X[i] << " " << Y[i] << " " << Z[i] << el;
    //     ans = min(ans,Y[i]);
    // }
    int ans = inf;
    for(ll q = 0; q+k-1 < n; q++){
        X.clear(), Z.clear();
        for(ll i = 0; i < k; i++)for(ll j = 0; j < k; j++) Z.insert(A[q+i][j]);
        Y = *Z.begin();
        Z.erase(Z.begin());
        const ull t = k*k/2;
        while(Z.size() > t){
            X.insert(Y);
            Y = *Z.begin();
            Z.erase(Z.begin());
        }
        //cout << pair(q,0) << X << " " << Y << " " << Z << el;
        ans = min(ans,Y);
        for(ll j = 1; j+k-1 < n; j++){
            X.insert(Y);
            Y = -1;
            for(ll p = q; p < q+k; p++){
                ll a = A[p][j-1];
                if(X.count(a)) X.erase(X.find(a));
                else if(Z.count(a)) Z.erase(Z.find(a));

                a = A[p][j+k-1];
                if(!X.empty() && a <= *X.rbegin()) X.insert(a);
                else Z.insert(a);
            }
            if(!X.empty()){
                Y = *X.rbegin();
                X.erase(prev(X.end()));
            }
            else {
                Y = *Z.begin();
                Z.erase(Z.begin());
            }
            while(Z.size() < t){
                Z.insert(Y);
                Y = *X.rbegin();
                X.erase(prev(X.end()));
            }
            while(Z.size() > t){
                X.insert(Y);
                Y = *Z.begin();
                Z.erase(Z.begin());
            }
            //cout << pair(q,j) << X << " " << Y << " " << Z << el;
            ans = min(ans,Y);
        }
    }
    cout << ans << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}