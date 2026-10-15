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


using namespace std;
#define ll long long
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(unsigned ll i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));
#define MP make_pair
#define MT make_tuple

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

// AB == CD か判定する
bool equal(pair<int,int> A, pair<int,int> B, pair<int,int> C, pair<int,int> D){
    return (A.first-B.first)*(A.first-B.first)+(A.second-B.second)*(A.second-B.second) == (C.first-D.first)*(C.first-D.first)+(C.second-D.second)*(C.second-D.second);
}

int main(){
    set<pair<int,int>> point; //ポーンが置かれている座標を保存
    string S;
    rep(i,9){
        cin >> S;
        rep(j,9){
            if(S[j] == '#'){
                point.insert(MP(i,j));
            }
        }
    }
    int ans = 0;
    for(auto A:point){
        for(auto B:point){
            for(auto C:point){
                for(auto D:point){
                    //AB^2 == BC^2 && AB^2 == DA^2 && AB^2 == CD^2
                    if(A != B && A != C && A != D && B != C && B != D && C != D && equal(A,B,B,C) && equal(B,C,C,D) && equal(C,D,D,A) && equal(A,C,B,D)){
                        ans++;
                        //cout << "A:(" << A.first << "," << A.second << ")   B:(" << B.first << "," << B.second << ")   C:(" << C.first << "," << C.second << ")    D:(" << D.first << "," << D.second << ")" << endl;
                    }
                }
            }
        }
    }
    cout << ans/8 << endl;
}