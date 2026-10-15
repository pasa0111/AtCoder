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

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}


vector<int> X(200001,-1);
vector<set<int>> V(200001); //頂点iに繋がっている頂点の番号たちを保存
bool hantei = true;

void dfs(int now){
    //cout << "now:" << now << endl;
    for(int next:V[now]){
        if(X[next] == -1){
            if(X[now] == 0) X[next] = 1;
            if(X[now] == 1) X[next] = 0;
            dfs(next);
        }
        if(X[next] == X[now]) hantei = false;
    }
    return;
}


int main(){
    int n,m;
    cin >> n >> m;
    vector<int> A(m),B(m);
    vecin(A); vecin(B);
    rep(i,m){
        int a = A[i], b = B[i];
        if(a == b) hantei = false;
        V[a].insert(b);
        V[b].insert(a);
    }
    if(hantei){
        for(int i = 1; i <= n; i++){
            if(X[i] == -1){
                X[i] = 0;
                dfs(i);
            }
        }
    }
    yesno(hantei);
}