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


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    ll r,R,c,C;
    cin >> r >> c >> R >> C;
    bool done = true;
    if(r == R && c == C){cout << 0 << endl; done = false;}
    if(done && abs(r-R)+abs(c-C) <= 3){cout << (abs(r-R)+abs(c-C) + 3 - 1)/3 << endl; done = false;}
    if(done){
        if(C == R-r+c || C == -R+r+c){
            cout << 1 << endl;
            done = false;
        }
        if(done){
        for(int a = -3; a <= 3; a++){
            for(int b = abs(a)-3; b <= 3-abs(a); b++){
                if(C+b == R+a-r+c || C+b == -R-a+r+c){
                    if(a == 0 && b == 0){cout << 1 << endl;}
                    if(a != 0 || b != 0){cout << 2 << endl;}
                    done = false;
                    a = 4;
                    break;
                }
            }
        }
        }
    }
    if(done && abs(r-R)+abs(c-C) <= 6){cout << (abs(r-R)+abs(c-C) + 3 - 1)/3 << endl; done = false;}
    if(done){
        if((R-r+c+C)%2 == 0 && (r+R-c+C)%2 == 0){
            cout << 2 << endl;
            done =false;
        }
        if(done && (r-R+c+C)%2 == 0 && (r+R+c-C)%2 == 0){
            cout << 2 << endl;
            done = false;
        }
        if(done){cout << 3 << endl;}
    }
}