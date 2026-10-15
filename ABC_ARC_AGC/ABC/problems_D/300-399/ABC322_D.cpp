#include <bits/stdc++.h> /*  ^__________^  */
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,n) for(ll i = 0; i < (ll)(n); i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) {return a * a;} template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;} struct set_stage{set_stage(){ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(20);}}set_stage; template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> auto sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); } template <typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p) { is >> p.first >> p.second; return is;} template <typename T> vector<T> rotate(vector<T>& S){assert(!S.empty()); int h = S.size(), w = S[0].size(); vector<T> res(w); for(int i = 0; i < w; i++) res[i].resize(h); for(int i = 0; i < w; i++){ for(int j = 0; j < h; j++){ res[i][j] = S[j][w-1-i];}} return res;}
template <typename T> T &SORT(T &a) {sort(a.begin(), a.end()); return a;} template <typename T> T& REVERSE(T &a) {reverse(a.begin(), a.end()); return a;} template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os,const R &a){if constexpr(is_same_v<ranges::range_value_t<R>,string>){bool f=true;for(const auto&x:a){if(!f)os<<'\n';f=false;os<<x;}return os;}else{os<<"{";bool f = 1;for(const auto&x:a){if(!f)os<<",";f=0;os<<x;}return os<<"}";}} template <typename T> vector<vector<T>>& sumvec2d(vector<vector<T>>& A){ll h = A.size(); if(h == 0) return A; ll w = A[0].size(); for(ll i = 0; i < h; i++)for(ll j = 1; j < w; j++) A[i][j] += A[i][j-1]; for(ll j = 0; j < w; j++)for(ll i = 1; i < h; i++) A[i][j] += A[i-1][j]; return A;} pair<ll,ll> dirvec(pair<ll,ll> a, pair<ll,ll> b){ll dx = a.first-b.first, dy = a.second-b.second; if(dx == 0 && dy == 0) return pair(0,0); else if(dx == 0) return pair(0,1); else if(dy == 0) return pair(1,0); if(dx < 0){dx = -dx; dy = -dy;} ll g = gcd(dx,abs(dy)); dx /= g, dy /= g; return pair(dx,dy);} template <typename T, typename U> vector<T>& operator*=(vector<T>& V,const U& k) {for(auto& x:V) x *= k; return V;}
template <typename T,typename U> vector<T> operator*(vector<T> V, const U& k) {return V *= k;} template <typename T,typename U> vector<T> operator*(const U& k,vector<T> V) {return V *= k;} template <typename T,typename U> pair<T,T>& operator*=(pair<T,T>& P,const U& k) {P.first *= k; P.second *= k; return P;} template <typename T,typename U> pair<T,T> operator*(pair<T,T> P,const U& k) {return P *= k;} template <typename T,typename U> pair<T,T> operator*(const U& k, pair<T,T> P) {return P *= k;} template <typename T> T dot(const vector<T>& A, const vector<T>& B){assert(A.size() == B.size()); ll s = A.size(); T res = 0; for(ll i = 0; i < s; i++) res += A[i]*B[i]; return res;} template <typename T> T dot(const pair<T,T>& A, const pair<T,T>& B){return A.first*B.first + A.second*B.second;} template <typename T> vector<T>& vecin(vector<T>& a) {for (auto &x:a) cin >> x; return a;} template <typename T> T &RSORT(T &a) {sort(a.rbegin(),a.rend()); return a;} template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;}
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

int main(){
    constexpr ll n = 4;
    vector<string> A(n), B(n), C(n); vecin(A), vecin(B), vecin(C);
    ll cnt = 0;
    for(ll i = 0; i < n; i++){
        cnt += count(A[i].begin(), A[i].end(), '#') + count(B[i].begin(), B[i].end(), '#') + count(C[i].begin(), C[i].end(), '#');
    }
    if(cnt != n*n){
        yesno(0);
        return 0;
    }

    auto gather = [&](vector<string>& S){
        while(S[0] == string(n,'.')){
            for(ll i = 0; i < n-1; i++) S[i] = S[i+1];
            S[n-1] = string(n,'.');
        }
    
        while('_'){
            bool cont = true;
            for(ll i = 0; i < n; i++){
                if(S[i][0] == '#'){
                    cont = false;
                    break;
                }
            }
            if(!cont) break;
    
            for(ll i = 0; i < n; i++){
                for(ll j = 0; j < n-1; j++){
                    S[i][j] = S[i][j+1];
                }
                S[i][n-1] = '.';
            }
        }
    };

    auto check = [&](vector<string>& S, vector<string>& T){
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                if(S[i][j] == T[i][j] && T[i][j] == '#') return false;
            }
        }
        return true;
    };

    auto right = [&](vector<string>& S){
        for(ll i = 0; i < n; i++) if(S[i][n-1] == '#') return false;
        for(ll i = 0; i < n; i++){
            for(ll j = n-1; j > 0; j--){
                S[i][j] = S[i][j-1];
            }
            S[i][0] = '.';
        }
        return true;
    };

    auto left = [&](vector<string>& S){
        for(ll i = 0; i < n; i++) if(S[i][0] == '#') return false;
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n-1; j++){
                S[i][j] = S[i][j+1];
            }
            S[i][n-1] = '.';
        }
        return true;
    };

    auto down = [&](vector<string>& S){
        for(ll j = 0; j < n; j++) if(S[n-1][j] == '#') return false;
        for(ll j = 0; j < n; j++){
            for(ll i = n-1; i > 0; i--){
                S[i][j] = S[i-1][j];
            }
            S[0][j] = '.';
        }
        return true;
    };


    bool ans = false;
    for(ll a = 0; a < 4; a++){
        gather(A);
        do{
            do{
                // cout << "A = \n" << A << el << el;
                for(ll b = 0; b < 4; b++){
                    gather(B);
                    do{
                        do{
                            // cout << "B = \n" << B << el << el;
                            if(!check(A,B)) continue;
                            for(ll c = 0; c < 4; c++){
                                gather(C);
                                do{
                                    do{
                                        ans |= (check(A,C) && check(B,C));
                                    }while(right(C));
                                    while(left(C));
                                }while(down(C));
                                C = rotate(C);
                            }
                        }while(right(B));
                        while(left(B));
                    }while(down(B));
                    B = rotate(B);
                }
            }while(right(A));
            while(left(A));
        }while(down(A));
        A = rotate(A);
    }

    yesno(ans);
}