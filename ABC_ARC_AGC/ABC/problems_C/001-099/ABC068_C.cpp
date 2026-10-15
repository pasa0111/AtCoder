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
    if(b) cout << "POSSIBLE" << endl;
    if(!b) cout << "IMPOSSIBLE" << endl;
}

int main(){
    set<int> start, goal;
    int n,m;
    cin >> n >> m;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        if(a == 1){start.insert(b);}
        if(b == n){goal.insert(a);}
    }
    bool b = false;
    for(int a:start){
        if(goal.count(a)){
            b = true;
            break;
        }
    }
    yesno(b);
}