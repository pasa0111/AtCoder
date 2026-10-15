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

int main(){
    int n;
    cin >> n;
    stack<pair<int,int>> S; //(数字,個数)
    int sum = 0;
    rep(i,n){
        int a;
        cin >> a;
        if(S.size() == 0){
            S.push(make_pair(a,1));
            sum++;
            cout << sum << endl;
            continue;
        }
        if(S.top().first == a){
            S.top().second++;
            sum++;
            if(S.top().second == a){
                sum -= a;
                S.pop();
            }
            cout << sum << endl;
            continue;
        }
        if(S.top().first != a){
            S.push(make_pair(a,1));
            sum++;
            cout << sum << endl;
            continue;
        }
    }
}