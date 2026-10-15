#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
using namespace std;

int main(){
    set<int> white1, black1, white2, black2;
    int N, M, u, v, ans1 = 0, ans2 = 0;
    cin >> N >> M;
    vector<set<int>> g(N+1);
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        g.at(u).insert(v);
    }
    //1 == white
    for(int i = 1; i <= N-1; i++){
        if(black1.count(i) == false){
            white1.insert(i);
            for(int x:g.at(i)){
                if(white1.count(x) == false){
                    black1.insert(x);
                }
                if(white1.count(x)){
                    ans1++;
                }
            }
        }
        if(black1.count(i)){
            for(int x:g.at(i)){
                if(black1.count(x) == false){
                    white1.count(x);
                }
                if(black1.count(x)){
                    ans1++;
                }
            }
        }
    }

    //1 == black
    for(int i = 1; i <= N-1; i++){
        if(white2.count(i) == false){
            black2.insert(i);
            for(int x:g.at(i)){
                if(black2.count(x) == false){
                    white2.insert(x);
                }
                if(black2.count(x)){
                    ans2++;
                }
            }
        }
        if(white2.count(i)){
            for(int x:g.at(i)){
                if(white2.count(x) == false){
                    black2.insert(x);
                }
                if(white2.count(x)){
                    ans2++;
                }
            }
        }
    }
    cout << min(ans1,ans2) << endl;
}