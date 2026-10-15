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
#define rerep(i,s,e,k) for(int i = s; i >= e; i-=k)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int a,b,c,x,y,ans = 2000000000;
    cin >> a >> b >> c >> x >> y;
    //A+C/2 >= x    B+C/2 >= y
    adrep(i,0,max(x*2,y*2),2){
        ans = min(ans,a*max((x-i/2),0)+b*max((y-i/2),0)+c*i);
    }
    cout << ans << endl;
}