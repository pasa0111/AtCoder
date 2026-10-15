#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <cctype>


using namespace std;
#define ll long long
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i);}
#define sumvecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i); if(i > 0) vec[i] += vec[i-1];}
#define REVERSE(vec) reverse(vecall(vec))
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec); REVERSE(vec)
#define MP make_pair
#define MT make_tuple

template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p){os << "(" << p.first << ", " << p.second << ")";return os;}
template <typename T, typename U> pair<T, U> operator+(const pair<T, U> & l, const pair<T, U> & r){return {l.first + r.first, l.second + r.second};}


/*
g++ path -o a.out && ./a.out < ./input.txt
*/

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int a,b;
    cin >> a >> b;
    string T = "", A = "";
    if(a == 0) T = "xxx";
    if(a == 1) T = "oxx";
    if(a == 2) T = "xox";
    if(a == 3) T = "oox";
    if(a == 4) T = "xxo";
    if(a == 5) T = "oxo";
    if(a == 6) T = "xoo";
    if(a == 7) T = "ooo";
    if(b == 0) A = "xxx";
    if(b == 1) A = "oxx";
    if(b == 2) A = "xox";
    if(b == 3) A = "oox";
    if(b == 4) A = "xxo";
    if(b == 5) A = "oxo";
    if(b == 6) A = "xoo";
    if(b == 7) A = "ooo";
    vector<int> s = {1,2,4};
    int ans = 0;
    rep(i,3){
        if(T[i] == 'o' || A[i] == 'o') ans += s[i];
    }
    cout << ans << endl;
}