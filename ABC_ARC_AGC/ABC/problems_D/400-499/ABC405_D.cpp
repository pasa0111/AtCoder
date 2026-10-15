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

/*
g++ ABC/problems_D/401-500/ABC405_D.cpp -o a.out && ./a.out < ./input.txt
*/

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    const int inf = 1000000000;
    int h,w;
    cin >> h >> w;
    vector<string> grid(h);
    //(歩数,座標)
    queue<tuple<int,int,int>> will;
    vector<vector<int>> cnt(h,vector<int>(w,inf));
    rep(i,h){
        cin >> grid[i];
        rep(j,w){
            if(grid[i][j] == 'E'){
                will.push(MT(0,i,j));
                cnt[i][j] = 0;
            }
        }
    }
    while(will.size() > 0){
        int t = get<0>(will.front()), x = get<1>(will.front()), y = get<2>(will.front());
        will.pop();
        if(x > 0 && grid[x-1][y] != '#' && cnt[x-1][y] > t){
            cnt[x-1][y] = t;
            grid[x-1][y] = 'v';
            will.push(MT(t+1,x-1,y));
        }
        if(x < h-1 && grid[x+1][y] != '#' && cnt[x+1][y] > t){
            cnt[x+1][y] = t;
            grid[x+1][y] = '^';
            will.push(MT(t+1,x+1,y));
        }
        if(y > 0 && grid[x][y-1] != '#' && cnt[x][y-1] > t){
            cnt[x][y-1] = t;
            grid[x][y-1] = '>';
            will.push(MT(t+1,x,y-1));
        }
        if(y < w-1 && grid[x][y+1] != '#' && cnt[x][y+1] > t){
            cnt[x][y+1] = t;
            grid[x][y+1] = '<';
            will.push(MT(t+1,x,y+1));
        }
    }
    rep(i,h) cout << grid[i] << endl;
}