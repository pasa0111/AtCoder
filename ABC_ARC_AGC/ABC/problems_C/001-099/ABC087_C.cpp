#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int candy(int y, int x, vector<vector<int>> g){
    //cout << "Now:(" << x << "," << y << ")" << endl;
    if(x >= 2){
        if(y == 1){
            //cout << "A" << endl;
            return candy(y, x-1, g) + g.at(y).at(x);
        }

        else{
            //cout << "B" << endl;
            return max(candy(y, x-1, g) + g.at(y).at(x), candy(y-1, x, g) + g.at(y).at(x));
        }
    }
    if(y == 2 && x == 1){return candy(1,1,g) + g.at(2).at(1);}
    else{return g.at(1).at(1);}
}

int main(){
    int N;
    cin >> N;
    vector<vector<int>> G(3, vector<int>(N+1, 0));
    for(int i = 1; i <= N; i++){cin >> G.at(1).at(i);}
    for(int i = 1; i <= N; i++){cin >> G.at(2).at(i);}
    cout << candy(2, N, G) << endl;
}