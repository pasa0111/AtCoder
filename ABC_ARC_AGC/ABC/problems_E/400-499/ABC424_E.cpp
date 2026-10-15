#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {SORT(a); REVERSE(a); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

void solve(){
    ll n,k,x; cin >> n >> k >> x;
    vector<ld> A(n); vecin(A);
    ld l = 0, r = inf, m = inf/2.0;
    ll cnt = 0, loop = 0, surf = INF;
    while('_'){
        cnt = 0;
        rep(i,n){
            ld len = A[i];
            ll num = 1;
            while(len > m){
                len /= 2.0;
                num *= 2;
            }
            cnt += num;
        }
        if(cnt > n+k) surf = min(surf,cnt);
        if(cnt > n+k) l = m;
        else r = m;
        m = (l+r)/2.0;
        loop++;
        if(loop == 200) break;
    }
    loop = 0;
    l = 0, m = r/2.0;
    while('_'){
        cnt = 0;
        rep(i,n){
            ld len = A[i];
            ll num = 1;
            while(len > m){
                len /= 2.0;
                num *= 2;
            }
            cnt += num;
        }
        if(surf >= cnt) r = m;
        else l = m;
        m = (l+r)/2.0;
        loop++;
        if(loop == 200) break;
    }
    assert(cnt == surf);
    map<ld,ll> Q; // 値,個数
    cnt = 0;
    rep(i,n){
        ld len = A[i];
        ll num = 1;
        while(len > m){
            len /= 2.0;
            num *= 2;
        }
        Q[len] += num;
        cnt += num;
    }
    for(auto q:Q) cout << q << " ";
    cout << el;
    for(auto& [len,num]:Q){
        //cout << pair(len,num) << el;
        if(x+1 >= cnt) break;
        if(num <= 1) continue;
        while(x+1 < cnt && num > 1){
            cnt--;
            num -= 2;
            Q[2*len]++;
        }
    }
    for(auto q:Q) cout << q << " ";
    cout << el;
    cout << fixed << setprecision(15) << (*Q.begin()).first << el;
    cout << el;
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