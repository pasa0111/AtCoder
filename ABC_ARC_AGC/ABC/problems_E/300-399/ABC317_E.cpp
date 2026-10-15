#include <bits/stdc++.h> /*  ^__________^  */
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,n) for(ll i = 0; i < (ll)(n); i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) {return a * a;} template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;} struct set_stage{set_stage(){ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(20);}}set_stage; template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> auto sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); } template <typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p) { is >> p.first >> p.second; return is;}
template <typename T> T &SORT(T &a) {sort(a.begin(), a.end()); return a;} template <typename T> T& REVERSE(T &a) {reverse(a.begin(), a.end()); return a;} template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) {os << "{"; bool f = 1; for (const auto &x : a) {if (!f) os << ","; f = 0; os << x;} return os << "}";} template <typename T> vector<vector<T>>& sumvec2d(vector<vector<T>>& A){ll h = A.size(); if(h == 0) return A; ll w = A[0].size(); for(ll i = 0; i < h; i++)for(ll j = 1; j < w; j++) A[i][j] += A[i][j-1]; for(ll j = 0; j < w; j++)for(ll i = 1; i < h; i++) A[i][j] += A[i-1][j]; return A;} pair<ll,ll> dirvec(pair<ll,ll> a, pair<ll,ll> b){ll dx = a.first-b.first, dy = a.second-b.second; if(dx == 0 && dy == 0) return pair(0,0); else if(dx == 0) return pair(0,1); else if(dy == 0) return pair(1,0); if(dx < 0){dx = -dx; dy = -dy;} ll g = gcd(dx,abs(dy)); dx /= g, dy /= g; return pair(dx,dy);} template <typename T, typename U> vector<T>& operator*=(vector<T>& V,const U& k) {for(auto& x:V) x *= k; return V;}
template <typename T,typename U> vector<T> operator*(vector<T> V, const U& k) {return V *= k;} template <typename T,typename U> vector<T> operator*(const U& k,vector<T> V) {return V *= k;} template <typename T,typename U> pair<T,T>& operator*=(pair<T,T>& P,const U& k) {P.first *= k; P.second *= k; return P;} template <typename T,typename U> pair<T,T> operator*(pair<T,T> P,const U& k) {return P *= k;} template <typename T,typename U> pair<T,T> operator*(const U& k, pair<T,T> P) {return P *= k;} template <typename T> T dot(const vector<T>& A, const vector<T>& B){assert(A.size() == B.size()); ll s = A.size(); T res = 0; for(ll i = 0; i < s; i++) res += A[i]*B[i]; return res;} template <typename T> T dot(const pair<T,T>& A, const pair<T,T>& B){return A.first*B.first + A.second*B.second;} template <typename T> vector<T>& vecin(vector<T>& a) {for (auto &x:a) cin >> x; return a;} template <typename T> T &RSORT(T &a) {sort(a.rbegin(),a.rend()); return a;} template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;}
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif

    ll h,w; cin >> h >> w;
    vector<string> S(h); vecin(S);
    for(ll i = 0; i < h; i++){
        for(ll j = 0; j < w; j++){
            if(S[i][j] == '>'){
                for(ll y = j+1; y < w; y++){
                    if(S[i][y] != '.' && S[i][y] != '!') break;
                    S[i][y] = '!';
                }
            }
            else if(S[i][j] == '<'){
                for(ll y = j-1; y >= 0; y--){
                    if(S[i][y] != '.' && S[i][y] != '!') break;
                    S[i][y] = '!';
                }
            }
            else if(S[i][j] == '^'){
                for(ll x = i-1; x >= 0; x--){
                    if(S[x][j] != '.' && S[x][j] != '!') break;
                    S[x][j] = '!';
                }
            }
            else if(S[i][j] == 'v'){
                for(ll x = i+1; x < h; x++){
                    if(S[x][j] != '.' && S[x][j] != '!') break;
                    S[x][j] = '!';
                }
            }
        }
    }

    vector<vector<ll>> D(h,vector<ll>(w,-1));
    ll sx,sy,gx,gy;
    for(ll i = 0, j = 0; i < h; j++){
        if(j == w){
            i++;
            j = -1;
            continue;
        }
        if(S[i][j] == 'S'){
            sx = i;
            sy = j;
        }
        else if(S[i][j] == 'G'){
            gx = i;
            gy = j;
        }
    }
    queue<pair<ll,ll>> Q;
    Q.push(pair(sx,sy));
    D[sx][sy] = 0;
    // rep(i,h) cout << S[i] << el;
    while(!Q.empty()){
        auto [x,y] = Q.front(); Q.pop();
        for(ll i = 0; i < 4; i++){
            ll nx = x+DX[i], ny = y+DY[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w || D[nx][ny] != -1 || (S[nx][ny] != '.' && S[nx][ny] != 'G')) continue;
            D[nx][ny] = D[x][y] + 1;
            Q.push(pair(nx,ny));
        }
    }
    // rep(i,h) cout << D[i] << el;
    cout << D[gx][gy] << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}