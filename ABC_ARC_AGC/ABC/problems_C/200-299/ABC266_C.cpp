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
    pair<int,int> a,b,c,d;
    bool ans = false;
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;
    if(a.first != c.first){
        int ac = ((a.first-c.first)*(b.second-a.second)-(a.second-c.second)*(b.first-a.first))*((a.first-c.first)*(d.second-a.second)-(a.second-c.second)*(d.first-a.first));
        if(b.first != d.first){
            int bd = ((b.first-d.first)*(a.second-b.second)-(b.second-d.second)*(a.first-b.first))*((b.first-d.first)*(c.second-b.second) - (b.second-d.second)*(c.first-b.first));
            if(ac < 0 && bd < 0){ans = true;}
        }
        if(b.first == d.first){
            if(a.first > b.first && c.first < b.first){ans = true;}
            if(a.first < b.first && c.first > b.first){ans = true;}
        }
    }

    if(a.first == c.first){
        if(b.first > a.first && d.first < a.first){ans = true;}
        if(b.first < a.first && d.first > a.first){ans = true;}
    }
    yesno(ans);
}