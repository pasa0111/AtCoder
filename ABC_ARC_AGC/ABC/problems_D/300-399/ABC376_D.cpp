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

template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p){os << "(" << p.first << ", " << p.second << ")";return os;}
template <typename T, typename U> pair<T, U> operator+(const pair<T, U> & l, const pair<T, U> & r){return {l.first + r.first, l.second + r.second};}

/*
g++ ABC/problems_D/301-400/ABC376_D.cpp -o a.out && ./a.out < ./input.txt
*/

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    int a,b;
    rep(i,m){
        cin >> a >> b;
        graph[a].push_back(b);
    }
    const int inf = 1000000000;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> will;//(頂点1からその頂点までの距離,頂点の番号)
    vector<int> T(n+1,inf);//頂点1からの最短距離を保存
    T[1] = 0;
    will.push(MP(0,1));
    int ans = -1;
    while(will.size() > 0){
        int d = will.top().first, now = will.top().second;
        will.pop();
        //cout << "now:" << now << endl;
        for(int next:graph[now]){
            //cout << "next:" << next << endl;
            if(next == 1){
                ans = d+1;
                will = {};
                break;
            }
            if(T[next] == inf){
                T[next] = d+1;
                will.push(MP(d+1,next));
            }
        }
    }
    cout << ans << endl;
}