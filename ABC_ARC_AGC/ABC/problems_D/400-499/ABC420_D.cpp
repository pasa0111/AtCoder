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
#define MT make_tuple

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int h,w;
vector<string> grid(510);
int ans = 1e9, cnt = -1;

int main(){
    cin >> h >> w;
    int x,y;
    rep(i,h){
        cin >> grid[i];
        rep(j,w) if(grid[i][j] == 'S'){
            x = i,
            y = j;
        }
    }
    queue<tuple<int,int,int,bool>> search; //(座標,歩数,スイッチの状態)
    search.push(MT(x,y,0,true));
    bool open = true;
    
    //minimum[x][y][open] = スイッチの状態がopenで座標(x,y)に到達するのに必要な歩数の最小値
    vector<vector<vector<int>>> minimum(h,vector<vector<int>>(w,vector<int>(2,h*w)));

    while(search.size() > 0){
        x = get<0>(search.front());
        y = get<1>(search.front());
        cnt = get<2>(search.front());
        open = get<3>(search.front());
        search.pop();
        //cout << "now:(" << x << "," << y << ")   cnt = " << cnt << endl;


        //上の調査
        if(x-1 >= 0){
            char t = grid[x-1][y];
            if(t == 'G'){
                ans = cnt+1;
                break;
            }
            if((t == '.' ||  t == 'S' || (open && t == 'o') || (!open && t == 'x')) && minimum[x-1][y][open] > cnt+1){
                search.push(MT(x-1,y,cnt+1,open));
                minimum[x-1][y][open] = cnt+1;
            }
            if(t == '?' && minimum[x-1][y][open] > cnt+1){
                search.push(MT(x-1,y,cnt+1,!open));
                minimum[x-1][y][open] = cnt+1;
            }
        }

        //下の調査
        if(x+1 < h){
            char t = grid[x+1][y];
            if(t == 'G'){
                ans = cnt+1;
                break;
            }
            if(minimum[x+1][y][open] > cnt+1 && (t == '.' || t == 'S' || (open && t == 'o') || (!open && t == 'x'))){
                search.push(MT(x+1,y,cnt+1,open));
                minimum[x+1][y][open] = cnt+1;
            }
            if(minimum[x+1][y][open] > cnt+1 && t == '?'){
                search.push(MT(x+1,y,cnt+1,!open));
                minimum[x+1][y][open] = cnt+1;
            }
        }

        //左
        if(y-1 >= 0){
            char t = grid[x][y-1];
            if(t == 'G'){
                ans = cnt+1;
                break;
            }
            if(minimum[x][y-1][open] > cnt+1 && (t == '.' ||  t == 'S' || (open && t == 'o') || (!open && t == 'x'))){
                search.push(MT(x,y-1,cnt+1,open));
                minimum[x][y-1][open] = cnt+1;
            }
            if(minimum[x][y-1][open] > cnt+1 && t == '?'){
                search.push(MT(x,y-1,cnt+1,!open));
                minimum[x][y-1][open] = cnt+1;
            }
        }

        //右
        if(y+1 < w){
            char t = grid[x][y+1];
            if(t == 'G'){
                ans = cnt+1;
                break;
            }
            if(minimum[x][y+1][open] > cnt+1 && (t == '.' || t == 'S' || (open && t == 'o') || (!open && t == 'x'))){
                search.push(MT(x,y+1,cnt+1,open));
                minimum[x][y+1][open] = cnt+1;
            }
            if(t == '?'){
                search.push(MT(x,y+1,cnt+1,!open));
                minimum[x][y+1][open] = cnt+1;
            }
        }
    }
    if(ans == 1e9) ans = -1;
    cout << ans << endl;
}