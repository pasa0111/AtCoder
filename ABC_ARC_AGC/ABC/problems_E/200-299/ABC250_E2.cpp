#include <bits/stdc++.h> /*  ^__________^  */
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {sort(a.rbegin(),a.rend()); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n; cin >> n;
    vector<ll> A(n), B(n); vecin(A), vecin(B);
    vector<pair<ll,ll>> ok(n,{-1,-1});
    unordered_set<ll> X,Y, S,T; // S:Aから探す要素, T:Bから探す要素
    ll i = 0;
    while(i < n){
        if(X.count(A[i])){
            assert(i > 0);
            ok[i] = ok[i-1];
            i++;
            continue;
        }

        ll j = (i > 0 ? ok[i-1].second+1 : 0);
        if(j == n) break;
        X.insert(A[i]);
        S.clear(), T.clear();
        T.insert(A[i]);
        i++;
        while(!S.empty() || !T.empty()){
            bool check = true;
            for(ll t:T){
                while(j < n && !Y.count(t)){
                    if(!X.count(B[j])) S.insert(B[j]);
                    Y.insert(B[j]);
                    j++;
                }
                if(!Y.count(t)){
                    check = false;
                    break;
                }
            }
            T.clear();
            if(!check){
                i = inf;
                break;
            }

            for(ll s:S){
                while(i < n && !X.count(s)){
                    if(!Y.count(A[i])) T.insert(A[i]);
                    X.insert(A[i]);
                    i++;
                }
                if(!X.count(s)){
                    check = false;
                    break;
                }
            }
            S.clear();
            if(!check){
                i = inf;
                break;
            }
        }
        if(i <= n) ok[i-1] = pair(j-1,j-1);
        while(j < n && X.count(B[j])){
            ok[i-1].second = j;
            j++;
        }
    }

    ll q; cin >> q;
    rep(query,q){
        ll a,b; cin >> a >> b; a--,b--;
        yesno(ok[a].first <= b && b <= ok[a].second);
    }

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}