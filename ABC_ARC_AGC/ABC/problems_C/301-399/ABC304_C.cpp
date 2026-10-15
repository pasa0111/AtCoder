#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

//n:感染者の番号
//nから近い人を感染させ、同様の処理を新たな感染者で行う
void virus(int n, vector<set<int>> &near, vector<string> &infection){
    for(int i:near.at(n)){
        if(infection.at(i) == "No"){
            infection.at(i) = "Yes";
            virus(i,near,infection);
        }
    }
    return;
}

int main(){
    int N, D;
    cin >> N >> D;
    vector<pair<int,int>> c(N);//人iの座標(x,y)
    vector<set<int>> near(N);//人iに近い人の番号を保存
    vector<string> infection(N,"No");//Yes:人iは感染している,No:感染していない
    for(int i = 0; i < N; i++){cin >> c.at(i).first >> c.at(i).second;}
    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            if(D*D >= (c.at(i).first - c.at(j).first)*(c.at(i).first - c.at(j).first) + (c.at(i).second - c.at(j).second)*(c.at(i).second - c.at(j).second)){
                near.at(i).insert(j);
                near.at(j).insert(i);
            }
        }
    }
    infection.at(0) = "Yes";
    virus(0,near,infection);
    for(int i = 0; i < N; i++){cout << infection.at(i) << endl;}
}