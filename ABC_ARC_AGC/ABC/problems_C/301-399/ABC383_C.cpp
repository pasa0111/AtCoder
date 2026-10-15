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

void humid(int d, int i, int j, int &H, int &W, int &D, int &ans, vector<string> &Grid, set<pair<int,int>> visited){
    if(d == D) return;

    if(d+1 <= D && i+1 < H && Grid[i+1][j] != '#' && Grid[i+1][j] != 'H' && !visited.count(MP(i+1,j))){
        visited.insert(MP(i+1,j));
        if(Grid[i+1][j] == 'w'){
            humid(d+1,i+1,j,H,W,D,ans,Grid,visited);
        }
        if(Grid[i+1][j] == '.'){
            Grid[i+1][j] = 'w';
            ans++;
            humid(d+1,i+1,j,H,W,D,ans,Grid,visited);
        }
    }

    if(d+1 <= D && i-1 >= 0 && Grid[i-1][j] != '#' && Grid[i-1][j] != 'H' && !visited.count(MP(i-1,j))){
        visited.insert(MP(i-1,j));
        if(Grid[i-1][j] == 'w'){
            humid(d+1,i-1,j,H,W,D,ans,Grid,visited);
        }
        if(Grid[i-1][j] == '.'){
            Grid[i-1][j] = 'w';
            ans++;
            humid(d+1,i-1,j,H,W,D,ans,Grid,visited);
        }
    }

    if(d+1 <= D && j+1 < W && Grid[i][j+1] != '#' && Grid[i][j+1] != 'H' && !visited.count(MP(i,j+1))){
        visited.insert(MP(i,j+1));
        if(Grid[i][j+1] == 'w'){
            humid(d+1,i,j+1,H,W,D,ans,Grid,visited);
        }
        if(Grid[i][j+1] == '.'){
            Grid[i][j+1] = 'w';
            ans++;
            humid(d+1,i,j+1,H,W,D,ans,Grid,visited);
        }
    }

    if(d+1 <= D && j-1 >= 0 && Grid[i][j-1] != '#' && Grid[i][j-1] != 'H' && !visited.count(MP(i,j-1))){
        visited.insert(MP(i,j-1));
        if(Grid[i][j-1] == 'w'){
            humid(d+1,i,j-1,H,W,D,ans,Grid,visited);
        }
        if(Grid[i][j-1] == '.'){
            Grid[i][j-1] = 'w';
            ans++;
            humid(d+1,i,j-1,H,W,D,ans,Grid,visited);
        }
    }
    return;
}

int main(){
    int H,W,D,ans = 0;
    cin >> H >> W >> D;
    vector<string> Grid(H);
    vecin(Grid);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(Grid[i][j] == 'H'){
                set<pair<int,int>> visited;
                ans++;
                humid(0,i,j,H,W,D,ans,Grid,visited);
            }
        }
    }
    /*cout << endl;
    for(int i = 0; i < H; i++){
        cout << Grid[i] << endl;
    }
    */
    cout << ans << endl;
}