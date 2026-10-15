#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

//頂点を辿るシミュレーションを行い、閉路を発見する
//ans:発見した閉路の数
//k:今いる点の番号
//l:直前にいた点の番号
//v:頂点iに繋がっている頂点の番号を保存
//w:シミュレート中に通った点の番号を保存
//b:閉路が見つかったらtrue
void solve(int &ans, int k, int l, vector<map<int,bool>> &v, set<int> &w, bool &b){
    //cout << ans << "  " << k << "  " << endl; 
    for(pair<int,bool> i:v.at(k)){
        if(i.first != l && i.second){
            if(w.count(i.first)){
                v.at(k).at(i.first) = false;
                v.at(i.first).at(k) = false;
                //cout << "delete (" << k << ", " << i.first << ")" << endl;
                ans++;
                b = true;
                return;
            }

            if(!w.count(i.first)){
                w.insert(i.first);
                solve(ans,i.first,k,v,w,b);
                w.erase(i.first);
            }
        }

        if(b == true){
            b = false;
            break;
        }
    }
    return;
}


int main(){
    int N, M, ans = 0;
    cin >> N >> M;
    set<int> w, x;
    vector<map<int,bool>> v(N);
    for(int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        v.at(A-1)[B-1] = true;
        v.at(B-1)[A-1] = true;
    }
    bool b = false;
    for(int i = 0; i < N; i++){solve(ans,i,-1,v,w,b);}
    cout << ans << endl;
}