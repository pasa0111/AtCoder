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

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<pair<int,char>> V(n+m);
    rep(i,n){
        cin >> V.at(i).first;
        V.at(i).second = 'H';
    }
    rep(i,m){
        cin >> V.at(i+n).first;
        V.at(i+n).second = 'X';
    }
    sort(vecall(V));
    int h=0,b=0,j = n+m-1;
    bool ans = true;
    while(b < k){
        if(V.at(j).second == 'X'){b++;}
        if(V.at(j).second == 'H'){h++;}
        j--;
    }
    if(b == k && h <= b){ans = true;}
    else{ans = false;}
    yesno(ans);
}