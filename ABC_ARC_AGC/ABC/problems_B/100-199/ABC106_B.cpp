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
    int n, ans = 0;
    cin >> n;
    adrep(i,1,n,1){
        if(i % 2 == 0){continue;}
        set<int> s;
        s.insert(1);
        s.insert(i);
        adrep(j,3,i,2){
            if(i % j == 0){s.insert(j);}
        }
        //for(int j:s){cout << j << " ";}
        //cout << endl;
        if(s.size() == 8){ans++;}
    }
    cout << ans << endl;
}