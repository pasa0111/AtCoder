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
#define adjrep(i,s,e) for(ll i = s; i <= e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define adjvecin(vec) for(int i = 1, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> ans(n*k);
    if(n % 2 == 0){
        ans.at(0) = n/2;
        int a = 1;
        for(int i = n; i >= 1; i--){
            if(i != n/2){
                rep(j,k){
                    ans.at(a) = i;
                    a++;
                }
            }
            if(i == n/2){
                rep(j,k-1){
                    ans.at(a) = i;
                    a++;
                }
            }
        }
    }

    if(n % 2 == 1){
        rep(i,k){ans.at(i) = (n+1)/2;}
        if(n >= 2){
            ans.at(k) = (n-1)/2;
            int a = k+1;
            for(int i = n; i >= 1; i--){
                if(i != (n+1)/2 && i != (n-1)/2){
                    rep(j,k){
                        ans.at(a) = i;
                        a++;
                    }
                }
                if(i == (n-1)/2){
                    rep(j,k-1){
                        ans.at(a) = i;
                        a++;
                    }
                }
            }
        }
    }
    rep(i,n*k){cout << ans.at(i) << " ";}
    cout << endl;
}