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
    ll n;
    cin >> n;
    vector<ll> A(n);
    vector<ll> B(n);
    vector<ll> memo(n+1,1e18);
    vector<ll> X(n);
    rep(i,n-1){cin >> A[i+1] >> B[i+1] >> X[i+1];}
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> Q; //(かかる時間,ステージ番号)
    set<ll> S; //かかる時間が確定したステージ番号
    Q.push(make_pair(0,1));
    while(Q.size() > 0){
        pair<ll,ll> q = Q.top();
        //cout << "(" << q.first << "," << q.second << ")" << endl;
        Q.pop();
        if(!S.count(q.second)){
            memo[q.second] = q.first;
            //cout << "stage" << q.second << ": " << q.first << endl;
            S.insert(q.second);
            if(q.second == n){break;}
            if(!S.count(q.second+1)){
                memo[q.second+1] = min(memo[q.second+1], memo[q.second]+A[q.second]);
                Q.push(make_pair(memo[q.second+1], q.second+1));
            }
            if(!S.count(X[q.second])){
                memo[X[q.second]] = min(memo[X[q.second]], memo[q.second] + B[q.second]);
                Q.push(make_pair(memo[X[q.second]], X[q.second]));
            }
        }
    }
    cout << memo[n] << endl;
}