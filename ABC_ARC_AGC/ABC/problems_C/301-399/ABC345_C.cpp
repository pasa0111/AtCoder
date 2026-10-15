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
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));
#define MP make_pair
#define MT make_tuple

template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p){
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}
template <typename T, typename U> 
pair<T, U> operator+(const pair<T, U> & l, const pair<T, U> & r){
     return {l.first + r.first, l.second + r.second};
}

/*
g++ path -o a.out && ./a.out < ./input.txt
*/

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    string S;
    cin >> S;
    int n = S.size();
    map<char,ll> M;
    int cnt = 0;
    rep(i,n){
        M[S[i]]++;
        if(M[S[i]] > 1) cnt = 1;
    }
    char x = 'a', y = 0;
    vector<ll> V(26);
    for(auto m:M){
        while(m.first != x){
            x++;
            y++;
        }
        V[y] = m.second;
    }
    ll ans = cnt;
    for(int i = 0; i < 25; i++){
        for(int j = i+1; j < 26; j++){
            ans += V[i]*V[j];
        }
        //cout << ans << endl;
    }
    cout << ans << endl;
}