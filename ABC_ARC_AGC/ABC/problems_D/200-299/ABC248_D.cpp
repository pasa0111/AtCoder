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


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int n,Q;
    cin >> n;
    vector<int> A(n);
    vector<vector<int>> V(n+1); //(値,インデックス)
    rep(i,n){
        cin >> A[i];
        V[A[i]].push_back(i+1);
    }
    rep(i,n+1){SORT(V[i]);}
    cin >> Q;
    rep(q,Q){
        int L,R,X;
        cin >> L >> R >> X;
        int start = -1, end = V[X].size(), t = -10, u, size = V[X].size();
        if(end == 0){
            cout << 0 << endl;
            continue;
        }
        while(start != end){
            u = t;
            t = (start+end)/2;
            if(t == u){break;}
            if(V[X][t] >= L){end = t;}
            if(V[X][t] < L){start = t;}
        }
        while(t >= 0 && V[X][t] > L){t--;}
        if(t == -1){t++;}
        while(t < size && V[X][t] < L){t++;}
        if(t == size){t--;}
        if(V[X][t] < L){cout << 0 << endl; continue;}
        int save = t;
        start = -1, end = V[X].size(), t = -10;
        while(start != end){
            u = t;
            t = (start+end)/2;
            if(t == u){break;}
            if(V[X][t] > R){end = t;}
            if(V[X][t] <= R){start = t;}
        }
        while(t >= 0 && V[X][t] > R){t--;}
        if(t == -1){t++;}
        while(t < size && V[X][t] < R){t++;}
        if(t == size){t--;}
        if(V[X][t] > R){t--;}
        //cout << "L: " << save << "  R: " << t << endl;
        cout << t-save+1 << endl;
    }
}