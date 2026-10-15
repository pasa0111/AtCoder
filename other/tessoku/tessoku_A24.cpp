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
#define rep(i,e) for(int i = 0; i < e; i++)
#define adrep(i,s,e,k) for(int i = s; i <= e; i+=k)
#define rerep(i,s,e,k) for(int i = s; i >= e; i-=k)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}


//Bの要素のうちx以上の最小値のインデックスを返す
int find(int x, vector<int> &B){
    int start = -1, end = B.size(),t=0,u;
    while(B.at(t) != x){
        u = t;
        t = (start+end)/2;
        if(B.at(t) > x){end = t;}
        if(B.at(t) < x){start = t;}
        if(u == t){break;}
    }
    if(B.at(t) < x){t++;}
    return t;
}


int main(){
    int n;
    cin >> n;
    vector<int> A(n), B;
    set<int> S;
    rep(i,n){
        cin >> A.at(i);
        if(!S.count(A.at(i))){
            B.push_back(A.at(i));
            S.insert(A.at(i));
        }
    }
    sort(vecall(B));
    rep(i,n){A.at(i) = find(A.at(i),B)+1;}
    vector<int> dp;
    dp.push_back(A.at(0));
    adrep(i,1,n-1,1){
        int d = dp.size();
        if(dp.at(d-1) < A.at(i)){
            dp.push_back(A.at(i));
            continue;
        }
        dp.at(find(A.at(i),dp)) = A.at(i);
    }
    cout << dp.size() << endl;
}