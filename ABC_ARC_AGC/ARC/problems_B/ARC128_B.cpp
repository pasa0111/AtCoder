// my library: https://github.com/pasa0111/AtCoder/blob/main/.vscode/cpp.code-snippets
#include <bits/stdc++.h> /*  ^__________^  */
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,n) for (ll i = 0; i < (ll)(n); i++)
template <typename T> vector<T> make_vector(size_t a, T b) {return vector<T>(a, b); } template <typename... Ts> auto make_vector(size_t a, Ts... ts) {return vector(a,make_vector(ts...));} template <ranges::range R> requires(!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a); template <typename T,typename U> ostream &operator<<(ostream &os,const pair<T,U> &p){os << "(" << p.first << ", " << p.second << ")"; return os;} template <typename T, typename U> istream &operator>>(istream &is, pair<T, U> &p){is >> p.first >> p.second; return is;} template <typename T> vector<T> rotate(const vector<T> &S){assert(!S.empty()); int h = S.size(), w = S[0].size(); vector<T> res(w); for (int i = 0; i < w; i++) res[i].resize(h); for (int i = 0; i < w; i++) {for(int j = 0; j < h; j++) {res[i][j] = S[j][w - 1 - i];}} return res;} template <typename T> T &SORT(T &a){sort(a.begin(),a.end()); return a;} template <typename T> T &REVERSE(T &a){reverse(a.begin(), a.end()); return a;} template <ranges::range R> requires(!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) {if constexpr (is_same_v<ranges::range_value_t<R>, string>) {bool f = true; for (const auto &x : a) {if (!f) os << '\n'; f = false; os << x; } return os;} else{os << "{"; bool f = 1; for (const auto &x:a) {if (!f) os << ","; f = 0; os << x;} return os << "}";}}
template <typename T> using PLqueue=priority_queue<T>; template <typename T> using PGqueue=priority_queue<T,vector<T>,greater<T>>; template <typename T> vector<vector<T>> &sumvec2d(vector<vector<T>> &A) {ll h = A.size(); if(h == 0) return A; ll w = A[0].size(); for(ll i = 0; i < h; i++) for(ll j = 1; j < w; j++) A[i][j] += A[i][j-1]; for(ll j = 0; j < w; j++) for(ll i = 1; i < h; i++) A[i][j] += A[i - 1][j]; return A;} pair<ll, ll> dirvec(pair<ll, ll> a, pair<ll, ll> b) {ll dx = a.first-b.first, dy = a.second-b.second; if(dx == 0 && dy == 0) return pair(0,0); else if(dx == 0) return pair(0,1); else if(dy == 0) return pair(1, 0); if(dx < 0){dx = -dx; dy = -dy;} ll g = gcd(dx,abs(dy)); dx /= g, dy /= g; return pair(dx,dy);} template <typename T> T& vecin(T& a){for(auto& x:a) cin >> x; return a;} template <typename T> T &RSORT(T &a){sort(a.rbegin(), a.rend()); return a;} template <typename T> T &sumvec(T &a){for(size_t i = 1; i < a.size(); i++) a[i] += a[i-1]; return a;} template <typename T,typename U> bool chmax(T& a, U b){if(a < b){a = b; return true;} return false;}
template <typename T> auto square(T a){using Ret = conditional_t<is_integral_v<T> && (sizeof(T) < sizeof(ll)), ll, T>; return Ret(a)*Ret(a);}  struct set_stage{set_stage(){ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(20);}}set_stage_0w0; template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) {return {a.first+b.first, a.second+b.second};} template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b){return {a.first - b.first, a.second - b.second};} template <typename T> auto intpow(T a, ll b){using Ret = std::conditional_t<std::is_integral_v<T> && (sizeof(T) < sizeof(ll)), ll, T>; assert(b >= 0); Ret res = 1; Ret base = a; while(b){if(b & 1) res *= base; b >>= 1; if(!b)break; base *= base;} return res;} ll intpow(ll a,ll b,ll c){assert(b >= 0 && c > 0); ll res = 1%c, base = (a%c+c)%c; while(b){if(b & 1) res = (res*base)%c; b >>= 1; if(!b) break; base = (base*base)%c;} return res;} template <typename T,typename U> bool chmin(T& a, U b){if(a > b){a = b; return true;} return false;} template <typename T, typename U> auto sqabs(const pair<T,U>& a){return square(a.first) + square(a.second);}
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

/*

目標: 0 0 x
その1手前 1 1 x-2

1 2 4 -> 3 1 3 -> 2 3 2 -> 1 5 1 -> 0 7 0
どれか2つの球の個数を等しくすればok

ランダムテスト
- max(a,b,c)が答えになる場合が多い

どれか2つの球の個数を等しくする とは
一方が+2,一方が-1で差が3ずつ変化する
-> A[i]とA[j]のmod3が等しければ合わせられる
-> 初期状態ではmod3が等しくない要素を合わせられるか?
-1,+2 -> 差が3ずつ変化
-1,-1 -> 差の変化なし
-> 合わせられなさそう



*/

// void solve(){
//     array<ll,3> A; vecin(A);
//     SORT(A);
//     if(false){
//         map<array<ll,3>,ll> M;
//         M[A] = 0;
//         queue<array<ll,3>> Q;
//         Q.push(A);
//         bool ok = false;
//         while(!Q.empty()){
//             auto B = Q.front(); Q.pop();
//             ll dist = M[B];
//             if(B[1] == 0){
//                 ok = true;
//                 break;
//             }
//             if(B[0] == 0){
//                 B[0] += 2;
//                 B[1]--;
//                 B[2]--;
//                 SORT(B);
//                 if(!M.count(B)){
//                     M[B] = dist+1;
//                     Q.push(B);
//                 }
//             }
//             else {
//                 for(ll i = 0; i < 3; i++){
//                     auto C = B;
//                     C[i] += 2;
//                     for(ll j = 0; j < 3; j++){
//                         if(i == j) continue;
//                         C[j]--;
//                     }
//                     SORT(C);
//                     if(!M.count(C)){
//                         M[C] = dist+1;
//                         Q.push(C);
//                     }
//                 }
//             }
//         }
//         cout << M << el;
//         yesno(ok);
//     }

//     ll ans = INF;
//     for(ll i = 0; i < 2; i++){
//         for(ll j = i+1; j < 3; j++){
//             if(A[i]%3 != A[j]%3) continue;
//             array<ll,3> B = A;
//             // ll cnt = 0;
//             ll k = 0;
//             while(i == k || j == k) k++;

//             // B[i] + 2p == B[j] - p
//             // p == (B[j]-B[i])/3
//             // B[k]+2q >= p
//             // q >= (p-B[k])/2;
//             ll p = (A[j]-A[i])/3, q = max(0LL, (p-A[k] + 2 - 1)/2);
//             B[i] += -q + 2*p;
//             B[j] += -q - p;
//             B[k] += 2*q - p;
//             // while(B[i] != B[j]){
//             //     cnt++;
//             //     if(B[k] == 0){
//             //         B[k] += 2;
//             //         B[i]--;
//             //         B[j]--;
//             //         // q++;
//             //     }
//             //     else {
//             //         B[k]--;
//             //         B[j]--;
//             //         B[i] += 2;
//             //         // p++;
//             //     }
//             //     cout << B << el;
//             // }
//             // cnt += B[i];
//             // cout << cnt << el;
//             // cout << pair(p,q) << el;
//             chmin(ans,p+q+B[i]);
//         }
//     }
//     if(ans == INF) cout << -1 << el;
//     else cout << ans << el;
// }

void solve(){
    array<ll,3> A; vecin(A); SORT(A);

    ll ans = INF;
    for(ll i = 0; i < 2; i++){
        for(ll j = i+1; j < 3; j++){
            if(A[i]%3 != A[j]%3) continue;
            ll k = 0;
            while(i == k || j == k) k++;
            array<ll,3> B = A;

            // B[i] + 2p == B[j] - p
            // p == (B[j]-B[i])/3
            // B[k]+2q >= p
            // q >= (p-B[k])/2;
            ll p = (A[j]-A[i])/3, q = max(0LL, (p-A[k] + 2 - 1)/2);
            B[i] += -q + 2*p;
            B[j] += -q - p;
            B[k] += 2*q - p;
            chmin(ans,p+q+B[i]);
        }
    }
    if(ans == INF) cout << -1 << el;
    else cout << ans << el;
}

int main(){
    ll t; cin >> t;
    for(ll i = 0; i < t; i++) solve();
}