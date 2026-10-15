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

int main(){
    int n;
    cin >> n;
    vector<bool> visited(n+1,false); //訪れたことのある街の番号を保存
    stack<int> back; //訪れた街を積んでいく
    vector<set<int>> town(n+1); //街iと繋がっている街の番号を保存
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        town[a].insert(b);
        town[b].insert(a);
    }
    int now = 1;
    //back.push(1);
    bool go = true;
    int pre;
    while(true){
        if(!go){
            back.pop();
            town[now].erase(pre);
        }
        cout << now << " ";
        visited[now] = true;
        go = false;
        for(int next:town[now]){
            if(!visited[next]){
                back.push(now);
                now = next;
                go = true;
                break;
            }
        }
        if(go) continue;
        if(now == 1) break;
        pre = now;
        now = back.top();
    }
    cout << endl;
}