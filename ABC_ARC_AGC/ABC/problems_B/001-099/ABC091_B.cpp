#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
using namespace std;

int main(){
    int N, M;
    string s, t;
    map<string, int> game;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s;
        if(game.count(s)){
            game.at(s)++;
        }
        if(game.count(s) == false){
            game[s] = 1;
        }
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> t;
        if(game.count(t)){
            game.at(t)--;
        }
        if(game.count(t) == false){
            game[t] = -1;
        }
    }
    int ans = 0;

    for(pair<string, int> g: game){
        int m = g.second;
        ans = max(m, ans);
    }
    cout << ans << endl;
}