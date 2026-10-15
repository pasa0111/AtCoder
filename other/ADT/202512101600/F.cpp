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

template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p){os << "(" << p.first << ", " << p.second << ")";return os;}
template <typename T, typename U> pair<T, U> operator+(const pair<T, U> & l, const pair<T, U> & r){return {l.first + r.first, l.second + r.second};}


/*
g++ path -o a.out && ./a.out < ./input.txt
*/

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

bool equal(pair<int,int> A, pair<int,int> B, pair<int,int> C, pair<int,int> D){
    return((A.first-B.first)*(A.first-B.first) + (A.second-B.second)*(A.second-B.second) == (C.first-D.first)*(C.first-D.first) + (C.second-D.second)*(C.second-D.second));
}

int main(){
    vector<string> S(9);
    vecin(S);
    set<pair<int,int>> P;
    rep(i,9){
        rep(j,9){
            if(S[i][j] == '#') P.insert(MP(i,j));
        }
    }
    int ans = 0;
    for(auto A:P){
        for(auto B:P){
            for(auto C:P){
                for(auto D:P){
                    if(A != B && A != C && A != D && B != C && B != D && C != D && equal(A,B,B,C) && equal(B,C,C,D) && equal(C,D,D,A) && equal(A,C,B,D)){
                        ans++;

                    }
                }
            }
        }
    }
    cout << ans/8 << endl;
}