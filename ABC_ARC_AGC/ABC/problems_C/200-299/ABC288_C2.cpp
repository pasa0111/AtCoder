#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

void solve(int k, map<int,bool> &v, vector<set<int>> &w){
    for(int i:w.at(k)){
        if(!v.count(i)){
            v[i] = true;
            solve(i,v,w);
        }
    }
    return;
}

int main(){
    int N, M, C = 0;
    cin >> N >> M;
    vector<set<int>> w(N); //w.at(i) = 頂点iと辺で繋がっている頂点の番号
    map<int,bool> v; //頂点[i]に行くことが可能かどうか
    set<int> x;
    for(int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        w.at(A-1).insert(B-1);
        w.at(B-1).insert(A-1);
    }
    for(int i = 0; i < N; i++){
        if(!v.count(i)){v[i] = false;}
        if(!v.at(i)){
            C++;
            solve(i,v,w);
        }
    }
    cout << M - N + C << endl;
}