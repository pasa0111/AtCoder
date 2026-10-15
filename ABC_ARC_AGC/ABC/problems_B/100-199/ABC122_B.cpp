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
    string S;
    cin >> S;
    int n = S.size(), ans = 0;
    adrep(i,1,n,1){
        bool b = true;
        adrep(j,0,n-i,1){
            b = true;
            string T = S.substr(j,i);
            int t = T.size();
            rep(k,t){
                if(T.at(k) != 'A' && T.at(k) != 'C' && T.at(k) != 'G' && T.at(k) != 'T'){b = false;}
            }
            if(b){
                ans = i;
                break;
            }
        }
        if(!b){break;}
    }
    cout << ans << endl;
}