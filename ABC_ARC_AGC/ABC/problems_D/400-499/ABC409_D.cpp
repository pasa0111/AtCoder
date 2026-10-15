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
    int T;
    cin >> T;
    rep(testcase,T){
        int n;
        string S;
        cin >> n >> S;
        char x = S[0];
        for(int i = 0; i < n; i++){
            //cout << "i:" << i << "   x:" << x <<endl;
            if(S[i] > x){x = S[i];}
            if(S[i] < x){
                int j = i;
                for(j = i; j < n; j++){
                    if(S[j] > x){
                        S.erase(i-1,1);
                        string y{x};
                        S.insert(j-1,y);
                        j = n+5;
                    }
                }
                if(j == n){
                    S.erase(i-1,1);
                    S += x;
                }
                break;
            }
        }
        cout << S << endl;
    }
}