#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

void ureshii(int &ans, int x, int y, int H, int W, set<int> num, vector<vector<int>> G){
    if(!num.count(G.at(x).at(y))){
        num.insert(G.at(x).at(y));

        if(x == H-1 && y == W-1){
            ans++;
            return;
        }

        if(x == H-1 && y < W-1){ureshii(ans,x,y+1,H,W,num,G);}

        if(x < H-1 && y == W-1){ureshii(ans,x+1,y,H,W,num,G);}

        if(x < H-1 && y < W-1){
            ureshii(ans,x+1,y,H,W,num,G);
            ureshii(ans,x,y+1,H,W,num,G);
        
        }
    }
    return;
}


int main(){
    int H, W, ans = 0;
    cin >> H >> W;
    vector<vector<int>> G(H,vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> G.at(i).at(j);
        }
    }
    set<int> num;
    ureshii(ans,0,0,H,W,num,G);
    cout << ans << endl;
}