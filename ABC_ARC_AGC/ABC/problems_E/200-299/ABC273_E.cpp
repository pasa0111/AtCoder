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

    ll q; cin >> q;
    vector<ll> T(q+1), V(q+1);
    vector<ll> ID(q+1); // ID[i] = Aiのオリジナルの番号
    unordered_map<ll,ll> M; // ページ --> そこに書かれている数列のID
    vector<ll> D(q+1,1); // 保存しておくべき長さ
    ID[0] = 0;

    for(ll i = 1; i <= q; i++){
        ID[i] = i;
        string S; cin >> S;
        if(S[0] == 'D'){
            T[i] = 1;
        }
        else{
            if(S[0] == 'A') T[i] = 0;
            else if(S[0] == 'S') T[i] = 2;
            else T[i] = 3;
            cin >> V[i];

            if(T[i] == 2){
                ID[i] = ID[i-1];
                M[V[i]] = ID[i];
            }
            else if(T[i] == 3){
                ID[i] = M[V[i]];
            }
        }
    }
    
    for(ll i = q; i >= 1; i--){
        if(T[i] == 0){
            D[ID[i-1]] = max(D[ID[i-1]], D[ID[i]] - 1);
        }
        else if(T[i] == 1){
            D[ID[i-1]] = max(D[ID[i-1]], D[ID[i]] + 1);
        }
    }
    
    vector<ll> A;
    unordered_map<ll,vector<ll>> B; // ID --> 数列
    for(ll i = 1; i <= q; i++){
        ll t = T[i], v = V[i];
        if(t == 0) A.push_back(v);
        else if(t == 1){if(!A.empty()) A.pop_back();}
        else if(t == 2){
            vector<ll>& C = B[ID[i]];
            ll s = A.size();
            if(ID[i] > 0 && C.empty()) for(ll j = max(0LL, s-D[ID[i]]); j < s; j++) C.push_back(A[j]);
        }
        else if(t == 3) A = B[ID[i]];
        cout << (A.empty() ? -1 : *A.rbegin()) << (i == q ? el : ' ');
    }

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}