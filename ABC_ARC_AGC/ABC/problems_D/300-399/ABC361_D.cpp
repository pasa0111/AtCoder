#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 2000000000; [[maybe_unused]]constexpr ll INF = 9000000000000000000;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U, typename V> bool range(T a, U x, V b) { return ((a) < (x) && (x) < (b)); } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) { return square(a.first) + square(a.second); } template <typename T> vector<T> &sumvec(vector<T> &a) { ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i - 1]; return a; } template <typename T> vector<T> &vecin(vector<T> &a) { for(auto& x:a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) { SORT(a); REVERSE(a); return a; } template <typename T> ostream &operator<<(ostream &os, const vector<T> &a) { bool first = true; os << "{"; for (const T &x : a) { if (!first) os << ","; first = false; os << x; } os << "}"; return os; } template <typename T> ostream &operator<<(ostream &os, const set<T> &a) { bool first = true; os << "{"; for (const T &x : a) { if (!first) os << ","; first = false; os << x; } os << "}"; return os; } template <typename T> ostream &operator<<(ostream &os, const multiset<T> &a) { bool first = true; os << "{"; for (const T &x : a) { if (!first) os << ","; first = false; os << x; } os << "}"; return os; } template <typename T, typename U> T &IOTA(T &a, U b) { iota(a.begin(), a.end(), b); return a; }
void yesno(bool b){
    if(b) cout << "Yes" << el;
    if(!b) cout << "No" << el;
}

ll n;
string S,T;
ll ans = INF, cnt = 0;
void solve(ll now){
    cout << "now = " << now << el;
    cout << "S = " << S << el;
    if(now == n-1){
        if(S[now] == T[now]){
            assert(S[n] == '?' && S[n+1] == '?');
            ans = min(ans,cnt);
        }
        return;
    }

    if(S[now] == T[now]) solve(now+1);
    else if(S[now] == '?'){
        assert(S[now+1] == '?');
        for(ll i = now+2; i < n+1; i++){
            if(S[i] == T[now]){
                S[now] = S[i], S[now+1] = S[i+1];
                S[i] = '?', S[i+1] = '?';
                cnt++;
                solve(now+1);
                cnt--;
                S[i] = S[now], S[i+1] = S[now+1];
                S[now] = '?', S[now+1] = '?';
            }
        }
    }
    else if(S[now+1] == '?'){
        assert(S[now+2] == '?');
        for(ll i = now+3; i < n+1; i++){
            S[now+1] = S[i], S[now+2] = S[i+1];
            S[i] = S[now], S[i+1] = S[now+1];
            S[now] = '?', S[now+1] = '?';
            cnt+=2;
            for(ll j = now+2; j < n+1; j++){
                if(S[j] == T[now]){
                    S[now] = S[j], S[now+1] = S[j+1];
                    S[j] = '?', S[j+1] = '?';
                    cnt++;
                    solve(now+1);
                    cnt--;
                    S[j] = S[now], S[j+1] = S[now+1];
                    S[now] = '?', S[now+1] = '?';
                }
            }
            S[now] = S[i], S[now+1] = S[i+1];
            S[i] = S[now+1], S[i+1] = S[now+2];
            S[now+1] = '?', S[now+2] = '?';
            cnt -= 2;
        }
    }
    else {
        ll memo_i = -1;
        for(ll i = now+2; i < n+1; i++){
            if(S[i] == '?'){
                assert(S[i+1] == '?');
                S[i] = S[now], S[i+1] = S[now+1];
                S[now] = '?', S[now+1] = '?';
                memo_i = i;
                cnt++;
                break;
            }
        }
        for(ll j = now+2; j < n+1; j++){
            if(S[j] == T[now]){
                S[now] = S[j], S[now+1] = S[j+1];
                S[j] = '?', S[j+1] = '?';
                cnt++;
                solve(now+1);
                cnt--;
                S[j] = S[now], S[j+1] = S[now+1];
                S[now] = '?', S[now+1] = '?';
            }
        }
        cnt--;
        S[now] = S[memo_i], S[now+1] = S[memo_i+1];
        S[memo_i] = '?', S[memo_i+1] = '?';
    }
}

int main(){
    #ifdef pas4 
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////" << el;
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> S >> T;
    S += "??";
    solve(0);
    cout << ans << el;
    
    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms" << el; cout << "//////////////////////////////////////////////////////" << el;
    #endif
}