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



void com(int n, int k, int &ans, vector<int> &res, vector<set<int>> &VH, vector<set<int>> &VG, vector<vector<int>> &A){
    //cout << "k: " << k << endl;
    if(k == n){
        int M = 0;
        vector<int> Res(n);
        vector<set<int>> vh = VH;
        rep(i,n){Res.at(res.at(i)) = i;}
        rep(i,n){
            for(int j:VG.at(i)){
                if(!vh.at(res.at(i)).count(res.at(j))){
                    vh.at(res.at(i)).insert(res.at(j));
                    vh.at(res.at(j)).insert(res.at(i));
                    M += A.at(min(res.at(i),res.at(j))).at(max(res.at(j),res.at(i)));
                    if(M > ans){return;}
                }
            }
        }
        set<pair<int,int>> deleted;
        rep(i,n){
            for(int j:vh.at(i)){
                if(!VG.at(Res.at(i)).count(Res.at(j)) && !deleted.count(make_pair(min(i,j),max(i,j)))){
                    deleted.insert(make_pair(min(i,j),max(i,j)));
                    M += A.at(i).at(j);
                    if(M > ans){return;}
                }
            }
        }
        ans = min(ans,M);
        return;
    }

    rep(i,n){
        if(res.at(i) == -1){
            res.at(i) = k;
            com(n,k+1,ans,res,VH,VG,A);
            res.at(i) = -1;
        }
    }
    return;
}

int main(){
    int n,g,h;
    cin >> n >> g;
    vector<set<int>> VG(n);
    rep(i,g){
        int u,v;
        cin >> u >> v;
        VG.at(u-1).insert(v-1);
        VG.at(v-1).insert(u-1);
    }

    cin >> h;
    vector<set<int>> VH(n);
    rep(i,h){
        int a,b;
        cin >> a >> b;
        VH.at(a-1).insert(b-1);
        VH.at(b-1).insert(a-1);
    }

    //map<pair<int,int>,int> A;
    vector<vector<int>> A(n-1,vector<int>(n));
    for(int i = 0; i <= n-2; i++){
        for(int j = i+1; j <= n-1; j++){
            cin >> A.at(i).at(j);
            //cin >> A[make_pair(i,j)];
        }
    }


    int ans = 1000000000;
    vector<int> r(n,-1);
    com(n,0,ans,r,VH,VG,A);
    cout << ans << endl;
}