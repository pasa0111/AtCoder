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

/*101010001 -> 10101000
100000000 -> 01110000
101000000 -> 10011000
101100000 -> 10110000*/

int main(){
    int T;
    cin >> T;
    rep(t,T){
        ll N;
        cin >> N;
        if(N < 7){
            cout << -1 << endl;
            continue;
        }
        vector<int> bit(60);
        int k = 0, x = -1, y = -1, z = -1;
        while(N > 0){
            bit.at(k) = N%2;
            if(bit.at(k) == 1){
                if(z != -1){
                    x = y;
                    y = z;
                    z = k;
                }
                if(z == -1 && y != -1){z = k;}
                if(y == -1 && x != -1){y = k;}
                if(x == -1){x = k;}
            }
            N /= 2;
            k++;
        }
        /*rep(i,60){cout << bit.at(i) << " ";}
        cout << endl;
        cout << x << " " << y << " " << z << " ";
        cout << endl;*/
        ll X=1, Y=1, Z=1;
        if(z != -1){
            rep(i,x){X *= 2;}
            rep(i,y){Y *= 2;}
            rep(i,z){Z *= 2;}
        }
        if(z == -1 && y != -1){
            if(x >= 2){
                rep(i,y){Y *= 2;}
                rep(i,x-1){X *= 2;}
                Z = X/2;
            }
            if(x <= 1){
                rep(i,y-1){Y *= 2;}
                X = Y/2;
                Z = X/2;
            }
        }
        if(y == -1){
            rep(i,x-1){X *= 2;}
            Y = X/2;
            Z = Y/2;
        }
        cout << X+Y+Z << endl;
    }
}