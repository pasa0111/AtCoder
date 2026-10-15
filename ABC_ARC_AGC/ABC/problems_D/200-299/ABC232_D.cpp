#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
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
    queue<tuple<int,int,int>> Q;
    set<pair<int,int>> S;
    int h,w,ans = 1;
    cin >> h >> w;
    vector<string> G(h);
    vecin(G);
    Q.push(make_tuple(0,0,1));
    while(Q.size() > 0){
        ans = max(ans,get<2>(Q.front()));
        pair<int,int> q = make_pair(get<0>(Q.front()), get<1>(Q.front()));
        //cout << "now: (" << q.first+1 << "," << q.second+1 << ")" << endl;
        if(!S.count(q)){
            S.insert(q);
            pair<int,int> right = make_pair(q.first, q.second+1);
            pair<int,int> down = make_pair(q.first+1, q.second);
            if(q.second+1 < w){
                if(!S.count(right) && G.at(q.first).at(q.second+1) != '#'){Q.push(make_tuple(q.first,q.second+1,get<2>(Q.front())+1));}
            }
            if(q.first+1 < h){
                if(!S.count(down) && G.at(q.first+1).at(q.second) != '#'){Q.push(make_tuple(q.first+1,q.second,get<2>(Q.front())+1));}
            }
        }
        Q.pop();
    }
    cout << ans << endl;
}