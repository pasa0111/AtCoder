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
    int n,m;
    cin >> n >> m;
    vector<vector<char>> G(n,vector<char>(n));
    rep(i,n){
        rep(j,n){
            cin >> G.at(i).at(j);
        }
    }
    set<vector<vector<char>>> F;
    for(int i = 0; i <= n-m; i++){
        for(int j = 0; j <= n-m; j++){
            vector<vector<char>> p(m,vector<char>(m));
            for(int k = i; k < i+m; k++){
                for(int l = j; l < j+m; l++){
                    p.at(k-i).at(l-j) = G.at(k).at(l);
                }
            }
            F.insert(p);
        }
    }
    cout << F.size() << endl;
}