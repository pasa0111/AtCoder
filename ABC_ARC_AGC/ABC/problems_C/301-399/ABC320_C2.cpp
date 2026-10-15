#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <iomanip>


using namespace std;
#define ll long long
#define rep(i,e) for(int i = 0; i < e; i++)
#define adrep(i,s,e,k) for(int i = s; i <= e; i+=k)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

char int_char(int x){
    char res;
    if(x == 0){res = '0';}
    if(x == 1){res = '1';}
    if(x == 2){res = '2';}
    if(x == 3){res = '3';}
    if(x == 4){res = '4';}
    if(x == 5){res = '5';}
    if(x == 6){res = '6';}
    if(x == 7){res = '7';}
    if(x == 8){res = '8';}
    if(x == 9){res = '9';}
    return res;
}

int main(){
    int m, ans = 100000000;
    string s0, s1, s2;
    cin >> m >> s0 >> s1 >> s2;
    //iでスロットを揃えてみる
    rep(i,10){
        char I = int_char(i);
        vector<vector<int>> v(3);
        rep(j,m){
            if(s0.at(j) == I){
                v.at(0).push_back(j);
                v.at(0).push_back(j+m);
                v.at(0).push_back(j+m+m);
            }
            if(s1.at(j) == I){
                v.at(1).push_back(j);
                v.at(1).push_back(j+m);
                v.at(1).push_back(j+m+m);
            }
            if(s2.at(j) == I){
                v.at(2).push_back(j);
                v.at(2).push_back(j+m);
                v.at(2).push_back(j+m+m);
            }
        }
        if(v.at(0).size() == 0 || v.at(1).size() == 0 || v.at(2).size() == 0){continue;}
        int res = 100000000;
        for(int x:v.at(0)){
            for(int y:v.at(1)){
                for(int z:v.at(2)){
                    if(x != y && y != z && z != x){res = min(res,max(max(x,y),z));}
                }
            }
        }
        ans = min(res,ans);
    }
    if(ans == 100000000){cout << -1 << endl;}
    if(ans < 100000000){cout << ans << endl;}
}