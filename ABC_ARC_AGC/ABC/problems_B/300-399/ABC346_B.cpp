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
    string S = "wbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbw";
    int W,B,w=0,b=0;
    cin >> W >> B;
    bool ans = false;
    rep(i,250){
        if(S.at(i) == 'w'){w++;}
        if(S.at(i) == 'b'){b++;}
        if(i+1 >= W+B){
            if(w == W && b == B){
                ans = true;
                break;
            }
            if(S.at(i-W-B+1) == 'w'){w--;}
            if(S.at(i-W-B+1) == 'b'){b--;}
        }
    }
    yesno(ans);
}