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
    int n, Q, p, i, x, y = 0, z = 0;
    cin >> n;
    vector<pair<ll,int>> A(n);
    rep(i,n){
        cin >> A.at(i).first;
        A.at(i).second = 0;
    }
    cin >> Q;
    rep(q,Q){
        cin >> p;
        if(p == 1){
            cin >> y;
            z++;
        }
        if(p == 2){
            cin >> i >> x;
            if(A.at(i-1).second < z){
                A.at(i-1).second = z;
                A.at(i-1).first = 0;
            }
            A.at(i-1).first += x;
        }
        if(p == 3){
            cin >> i;
            if(A.at(i-1).second < z){
                A.at(i-1).first = 0;
                A.at(i-1).second = z;
            }
            cout << A.at(i-1).first + y << endl;
        }
    }
}