#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;


void judge(int n, int k, int &num, int &ans, vector<int> &p, set<int> &s, bool v){
    if(k == n && v){ans = num;}

    if(k <= n-1){
        num--;
        for(int i = 1; i <= n; i++){
            if(!s.count(i)){
                num++;
                s.insert(i);
                if(p.at(k) != i){judge(n,k+1,num,ans,p,s,false);}
                if(p.at(k) == i){judge(n,k+1,num,ans,p,s,v);}
                s.erase(i);
            }
        }
    }
    return;
}

int main(){
    int N;
    cin >> N;
    vector<int> P(N),Q(N);
    for(int i = 0; i < N; i++){cin >> P.at(i);}
    for(int i = 0; i < N; i++){cin >> Q.at(i);}
    int a=0, b=0, c=1, d=1;
    set<int> S, T;
    judge(N,0,c,a,P,S,true);
    judge(N,0,d,b,Q,T,true);
    //cout << "a:" << a << "  b:" << b << endl;
    cout << abs(a-b) << endl;
}