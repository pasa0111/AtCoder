#pragma region my_template
#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <deque>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <cctype>
#include <chrono>
#include <cassert>
#include <numeric>
#include <random>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 2000000000; [[maybe_unused]]constexpr ll INF = 9000000000000000000;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
#define vecall(vec) vec.begin(),vec.end()
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a){return a*a;} template <typename T, typename U, typename V> bool range(T a,U x,V b){return ((a) < (x) && (x) < (b));} template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p){os << "(" << p.first << ", " << p.second << ")";return os;} template <typename T, typename U> pair<T, U> operator+(const pair<T, U>& a, const pair<T, U>& b){return {a.first + b.first, a.second + b.second};} template <typename T, typename U> pair<T, U> operator-(const pair<T, U>& a, const pair<T, U>& b){return {a.first - b.first, a.second - b.second};} template <typename T, typename U> ll sqabs(const pair<T, U>& a){return square(a.first)+square(a.second);} template <typename T> vector<T>& sumvec(vector<T>& a){ll b = a.size(); for(ll i = 1; i < b; i++)a[i] += a[i-1]; return a;}template <typename T> vector<T>& vecin(vector<T>& a){ll b = a.size(); rep(i,b)cin >> a[i]; return a;} template <typename T> vector<T>& SORT(vector<T>& a){sort(a.begin(), a.end()); return a;} template <typename T> T& REVERSE(T& a){reverse(a.begin(), a.end()); return a;} template <typename T> vector<T>& RSORT(vector<T>& a){SORT(a); REVERSE(a); return a;} template <typename T> ostream& operator<<(ostream& os, const vector<T>& a){bool first = true; os << "{"; for(const T& x:a){if(!first)os << ","; first = false; os << x;} os << "}"; return os;} template <typename T> ostream& operator<<(ostream& os, const set<T>& a){bool first = true; os << "{"; for(const T& x:a){if(!first)os << ","; first = false; os << x;} os << "}"; return os;} template <typename T> ostream& operator<<(ostream& os, const multiset<T>& a){bool first = true; os << "{"; for(const T& x:a){if(!first)os << ","; first = false; os << x;} os << "}"; return os;} template <typename T, typename U> T& IOTA(T& a, U b){iota(a.begin(),a.end(),b); return a;}
#pragma endregion

namespace atcoder {
struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}
    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }
    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }
    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }
    long long size(int a) {
        assert(0 <= a && a < _n);
        return (long long)(-parent_or_size[leader(a)]);
    }
    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }
  private:
    int _n;
    std::vector<int> parent_or_size;
};
}
using namespace atcoder;

void yesno(bool b){
    if(b) cout << "Yes" << el;
    if(!b) cout << "No" << el;
}

int main(){
    #ifdef pas4 
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////" << el;
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);
    //////////////////////////////////////////
    ll h,w; cin >> h >> w;
    vector<string> S(h); vecin(S);
    vector<vector<bool>> ok(h,vector<bool>(w,true));
    vector<ll> DX = {-1,1,0,0}, DY = {0,0,-1,1};
    for(ll i = 0; i < h; i++)for(ll j = 0; j < w; j++){
        if(S[i][j] == '#'){
            ok[i][j] = false;
            rep(k,4){
                ll dx = DX[k], dy = DY[k];
                if(!range(-1,i+dx,h) || !range(-1,j+dy,w)) continue;
                ok[i+dx][j+dy] = false;
            }
        }
    }
    dsu uf(h*w);
    for(ll i = 0; i < h; i++)for(ll j = 0; j < w; j++){
        if(!ok[i][j]) continue;
        rep(k,4){
            ll dx = DX[k], dy = DY[k];
            if(!range(-1,i+dx,h) || !range(-1,j+dy,w) || !ok[i+dx][j+dy]) continue;
            uf.merge(w*i+j, w*(i+dx)+(j+dy));
        }
    }
    ll ans = 1;
    queue<pair<ll,ll>> will;
    set<ll> K;
    vector<vector<ll>> D(h,vector<ll>(w,-1));
    for(ll i = 0; i < h; i++)for(ll j = 0; j < w; j++){
        if(ok[i][j] && uf.leader(w*i+j) == w*i+j){
            will.push(pair(i,j));
            K = {};
            D[i][j] = 0;
            while(!will.empty()){
                auto [x,y] = will.front();
                will.pop();
                rep(k,4){
                    ll dx = DX[k], dy = DY[k];
                    if(!range(-1,x+dx,h) || !range(-1,y+dy,w) || S[x+dx][y+dy] == '#') continue;
                    if(ok[x+dx][y+dy] && D[x+dx][y+dy] == -1){
                        will.push(pair(x+dx,y+dy));
                        D[x+dx][y+dy] = D[x][y]+1;
                    }
                    if(!ok[x+dx][y+dy]) K.insert(w*(x+dx)+(y+dy));
                }
            }
            ans = max(ans,ll(uf.size(w*i+j)+K.size()));
        }
    }
    cout << ans << el;
    //////////////////////////////////////////
    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms" << el; cout << "//////////////////////////////////////////////////////" << el;
    #endif
}