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


template<unsigned int char_size, unsigned int base>
struct Trie {
    using uint = unsigned int;
    using uchar = unsigned char;
    using ll = long long;
    
    struct TrieNode {
        array<int,char_size> next;  // 次の文字のインデックス
        uint accept;                // このノードを終端とする文字列の数
        uint count;                 // このノードを通る接頭辞を持つ文字列の個数
    
        TrieNode() : accept(0), count(0) {
            next.fill(-1);
        }
    };


    vector<TrieNode> nodes;
    Trie() : nodes(1,TrieNode()) {}

    // 文字列をTrie木に追加する
    void insert(const string& word){
        uint now = 0;
        nodes[0].count++;
        for(uchar c:word){
            uint id = c-base;
            assert(id < char_size);
            if(nodes[now].next[id] == -1){
                nodes[now].next[id] = nodes.size();
                nodes.push_back(TrieNode());
            }
            now = nodes[now].next[id];
            nodes[now].count++;
        }
        nodes[now].accept++;
    }

    // 指定した文字列が存在する個数
    ll search(const string& word){
        uint now = 0;
        for(uchar c:word){
            uint id = c-base;
            assert(id < char_size);
            if(nodes[now].next[id] == -1) return 0;
            now = nodes[now].next[id];
        }
        return nodes[now].accept;
    }

    // 指定した接頭辞（prefix）を持つ文字列の個数
    ll count_prefix(const string& prefix){
        uint now = 0;
        for(uchar c:prefix){
            uint id = c-base;
            assert(id < char_size);
            if(nodes[now].next[id] == -1) return 0;
            now = nodes[now].next[id];
        }
        return nodes[now].count;
    }

    // 指定した文字列を1つ削除する
    bool erase(const string& word){
        if(search(word) == 0) return false;
        uint now = 0;
        nodes[0].count--;
        for(uchar c:word){
            uint id = c-base;
            now = nodes[now].next[id];
            nodes[now].count--;
        }
        nodes[now].accept--;
        return true;
    }

    // 保存されている文字列の個数(重複あり)
    ll size()const{
        return nodes[0].count;
    }

    // 指定した文字列より辞書順で小さいものの個数
    ll order(const string& word)const{
        uint now = 0;
        ll res = 0;
        for(uchar c:word){
            res += nodes[now].accept;
            uint id = c-base;
            assert(id < char_size);
            for(uint i = 0; i < id; i++){
                if(nodes[now].next[i] == -1) continue;
                res += nodes[nodes[now].next[i]].count;
            }
            if(nodes[now].next[id] == -1) return res;
            now = nodes[now].next[id];
        }
        return res;
    }

    // word自身を除いた最長共通部分接頭辞の長さ
    ll LCP(const string& word)const{
        assert(search(word) > 0);
        uint now = 0;
        ll res = 0;
        for(uchar c:word){
            uint id = c-base;
            if(nodes[nodes[now].next[id]].count == 1) return res;
            res++;
            now = nodes[now].next[id];
        }
        return res;
    }


    ll count1(const string& word, int idx, bool changed, uint now){
        if(changed){
            for(int i = idx+1; i < ssize(word); i++){
                uint id = word[i]-base;
                if(nodes[now].next[id] == -1) return 0;
                now = nodes[now].next[id];
            }
            return nodes[now].accept;
        }

        ll res = 0;
        for(ll i = 0; i < ssize(word); i++){
            for(uint id = 0; id < char_size; id++){
                if((uchar)word[i] == base+id) continue;
                if(nodes[now].next[id] == -1) continue;
                res += count1(word,i,true,nodes[now].next[id]);
            }
            now = nodes[now].next[word[i]-base];
        }
        return res;
    }
};

// Trie<26,'a'> prefix_tree
// S:Trieに登録済み, word:任意の文字列
// insert(word)        wordを登録
// search(word)        wordの個数
// count_prefix(word)  wordを接頭辞として持つような文字列の個数
// erase(word)         wordが存在すればそれを1つ削除しtrueを返す
// size()              保存されている文字列の個数(重複あり)
// order(word)         辞書順でwordより小さい文字列の個数
// LCP(S)              Sの最長共通部分接頭辞の長さ

int main(){
    ll n,m; cin >> n >> m;
    vector<string> S(n); vecin(S);
    vector<array<ll,2>> C(n);
    {
        Trie<26,'a'> T;
        rep(i,n) T.insert(S[i]);
        for(ll i = 0; i < n; i++){
            T.erase(S[i]);
            C[i][0] += T.search(S[i]);
            C[i][1] += T.count1(S[i],0,false,0);
        }
    }
    vector<ll> D(n);
    for(ll bit = 0; bit < (1LL<<m); bit++){
        if(__builtin_popcount(bit) != m-2) continue;
        vector<string> A(n);
        Trie<26,'a'> T;
        rep(i,n){
            rep(j,m){
                if(((bit>>j)&1) == 0) continue;
                A[i] += S[i][j];
            }
            T.insert(A[i]);
        }
        // cout << A << el;
        rep(i,n){
            T.erase(A[i]);
            D[i] += T.search(A[i]);
        }
    }
    // cout << D << el;
    // cout << C << el;
    vector<ll> cnt2(n);
    // cout << cnt2 << el;
    rep(i,n) cnt2[i] = D[i] - C[i][0]*m*(m-1)/2 - (m-1)*C[i][1];
    ll ans = 0;
    rep(i,n) ans += C[i][0] + C[i][1] + cnt2[i];
    cout << ans << el;
}