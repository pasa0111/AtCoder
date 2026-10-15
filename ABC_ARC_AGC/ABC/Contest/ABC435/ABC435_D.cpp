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
#include <cctype>


using namespace std;
#define ll long long
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i);}
#define sumvecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i); if(i > 0) vec[i] += vec[i-1];}
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));
#define MP make_pair
#define MT make_tuple

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}
set<int> visited;
bool ans = false;

int main(){
    int n,m;
    cin >> n >> m;
    //vector<vector<int>> graph(n+1);
    vector<vector<int>> back(n+1);
    vector<bool> ok(n+1,false);
    int Q;
    rep(i,m){
        int x,y;
        cin >> x >> y;
        //graph[x].push_back(y);
        back[y].push_back(x);
    }
    cin >> Q;
    rep(query,Q){
        int x,v;
        cin >> x >> v;
        if(x == 1){
            if(!ok[v]){
            ok[v] = true;
            queue<int> will;
            for(int i:back[v])if(!ok[i]) will.push(i);
            while(will.size() > 0){
                int now = will.front();
                will.pop();
                ok[now] = true;
                for(int i:back[now]){
                    if(!ok[i]){
                        will.push(i);
                    }
                }
            }
        }
        }
        if(x == 2){
            yesno(ok[v]);
        }
    }
}