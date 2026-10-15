#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>


using namespace std;
#define ll long long
#define rep(i,e) for(int i = 0; i < e; i++)
#define adjrep(i,s,e) for(ll i = s; i <= e; i++)
#define vall(vec) vec.begin(),vec.end()
#define vin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define adjvin(vec) for(int i = 1, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int H,W;
    cin >> H >> W;
    vector<string> G(H);
    vin(G);
    bool ans = true;
    rep(i,H){
        rep(j,W){
            if(G.at(i).at(j) == '#'){
                int n = 0;
                if(i > 0){
                    if(G.at(i-1).at(j) == '#'){n++;}
                }
                if(i < H-1){
                    if(G.at(i+1).at(j) == '#'){n++;}
                }
                if(j > 0){
                    if(G.at(i).at(j-1) == '#'){n++;}
                }
                if(j < W-1){
                    if(G.at(i).at(j+1) == '#'){n++;}
                }
                if(n != 2 && n != 4){ans = false;}
            }
        }
    }
    yesno(ans);
}

