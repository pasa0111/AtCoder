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
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int h,w, N;
    cin >> h >> w;
    N = min(h,w);
    vector<int> ans(N+1);
    vector<string> C(h+2);
    string p = "";
    rep(i,w+2){p += ".";}
    C.at(0) = p;
    C.at(h+1) = p;
    for(int i = 1; i <= h; i++){
        string x = "", y = "";
        cin >> y;
        x += "." + y + ".";
        C.at(i) = x;
    }
    for(int i = 2; i <= h-1; i++){
        for(int j = 2; j <= w-1; j++){
            if(C.at(i).at(j) == '#' && C.at(i+1).at(j) == '.' && C.at(i-1).at(j) == '.' && C.at(i).at(j+1) == '.' && C.at(i).at(j-1) == '.' && C.at(i+1).at(j+1) == '#' && C.at(i+1).at(j-1) == '#' && C.at(i-1).at(j+1) == '#' && C.at(i-1).at(j-1) == '#'){
                int size = 0;
                while(true){
                    if(C.at(i+size+1).at(j+size+1) == '.'){
                        break;
                    }
                    size++;
                }
                ans.at(size)++;
            }
        }
    }
    for(int i = 1; i <= N; i++){cout << ans.at(i) << " ";}
    cout << endl;
}