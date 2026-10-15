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
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define adjvecin(vec) for(int i = 1, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}



int main(){
    ll D;
    cin >> D;
    ll d = sqrt(D), ans = D;
    adjrep(y,1,d+1){
        ll Y = y*y;
        if(y == d+1){
            ans = min(ans,Y-D);
            break;
        }
        ll t = sqrt(D-Y);
        ans = min(ans,min(abs(t*t-D+Y),(t+1)*(t+1)-D+Y));
    }
    cout << ans << endl;
}

