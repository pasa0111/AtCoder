#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> requires (same_as<T,ll> || same_as<T,int> || floating_point<T>) && (same_as<U,ll> || same_as<U,int> || floating_point<U>) auto sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second);}
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {SORT(a); REVERSE(a); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

ld a,b,c,d, x,y,z,w;
ld lt, la;

// 時刻tにおける二人の距離の二乗
ld dist(ld t){
    ld xt = (t <= lt ? a + (c-a)/lt*t : c);
    ld yt = (t <= lt ? b + (d-b)/lt*t : d);
    ld xa = (t <= la ? x + (z-x)/la*t : z);
    ld ya = (t <= la ? y + (w-y)/la*t : w);
    //cout << "高橋: " << pair(xt,yt) << el << "青木: " << pair(xa,ya) << el;

    //return square(xt-xa) + square(yt-ya);
    return sqabs(pair(xt,yt) - pair(xa,ya));
}

void solve(){
    cin >> a >> b >> c >> d >> x >> y >> z >> w;
    // lt = sqrtl(square(a-c) + square(b-d));
    // la = sqrtl(square(x-z) + square(y-w));
    lt = sqrtl(sqabs(pair(a,b)-pair(c,d)));
    la = sqrtl(sqabs(pair(x,y)-pair(z,w)));

    // t = 0 ~ min(lt,la);
    ld l = 0, r = min(lt,la);
    ll cnt = 0;
    while('_'){
        cnt++;
        ld lm = l + (r-l)/3, rm = r - (r-l)/3;
        ld dl = dist(lm);
        ld dr = dist(rm);
        //cout << pair(l,r) << "   " << pair(lm,rm) << "   " << pair(dl,dr) << el;
        if(dl <= dr) r = rm;
        else l = lm;
        if(cnt == 100) break;
    }
    ld ans = dist(r);

    l = min(lt,la);
    r = max(lt,la);
    cnt = 0;
    while('_'){
        cnt++;
        ld lm = l + (r-l)/3, rm = r - (r-l)/3;
        ld dl = dist(lm);
        ld dr = dist(rm);
        // cout << pair(l,r) << "   " << pair(lm,rm) << "   " << pair(dl,dr) << el;
        if(dl <= dr) r = rm;
        else l = lm;
        if(cnt == 100) break;
    }
    ans = min(ans,dist(r));
    cout << sqrtl(ans) << el;
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cout << fixed << setprecision(10);
    ll t; cin >> t;
    rep(test,t) solve();

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}