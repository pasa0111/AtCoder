#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <iomanip>


using namespace std;
#define ll long long
#define rep(i,e) for(int i = 0; i < e; i++)
#define adjrep(i,s,e) for(ll i = s; i <= e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define adjvecin(vec) for(int i = 1, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int n, ans = 1;
    cin >> n;
    queue<int> Q;
    set<int> S;
    Q.push(1);
    map<int,set<int>> M;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        if(!M.count(a)){M[a] = S;}
        if(!M.count(b)){M[b] = S;}
        M.at(a).insert(b);
        M.at(b).insert(a);
    }
    while(Q.size() > 0){
        ans = max(Q.front(),ans);
        if(!S.count(Q.front())){
            S.insert(Q.front());
            if(M.count(Q.front())){
                for(int x:M.at(Q.front())){
                    if(!S.count(x)){Q.push(x);}
                }
            }
        }
        Q.pop();
    }
    cout << ans << endl;
}
