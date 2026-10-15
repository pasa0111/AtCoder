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
    int H,W,D,ans = 0;
    cin >> H >> W >> D;
    vector<string> Grid(H); //マスの情報
    vector<vector<int>> Dist(H,vector<int>(W,H*W+5000)); //最も近い加湿器から何マス離れているか保存
    vecin(Grid);
    queue<pair<int,int>> floor;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(Grid[i][j] == '#') Dist[i][j] = -1;
            if(Grid[i][j] == 'H') Dist[i][j] = 0;
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(Dist[i][j] == 0){
                floor.push(MP(i,j));
                    while(floor.size() > 0){
                        int p = floor.front().first, q = floor.front().second;
                        floor.pop();
                        if(p+1 < H && Dist[p+1][q] > Dist[p][q]+1 && Dist[p][q] < D){
                            Dist[p+1][q] = Dist[p][q]+1;
                            floor.push(MP(p+1,q));
                        }
                        if(p-1 >= 0 && Dist[p-1][q] > Dist[p][q]+1 && Dist[p][q] < D){
                            Dist[p-1][q] = Dist[p][q]+1;
                            floor.push(MP(p-1,q));
                        }
                        if(q+1 < W && Dist[p][q+1] > Dist[p][q]+1 && Dist[p][q] < D){
                            Dist[p][q+1] = Dist[p][q]+1;
                            floor.push(MP(p,q+1));
                        }
                        if(q-1 >= 0 && Dist[p][q-1] > Dist[p][q]+1 && Dist[p][q] < D){
                            Dist[p][q-1] = Dist[p][q]+1;
                            floor.push(MP(p,q-1));
                        }
                    }
            }
        }
    }
    int limit = H*W+5000;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(0 <= Dist[i][j] && Dist[i][j] < limit) ans++;
        }
    }
    cout << ans << endl;
}