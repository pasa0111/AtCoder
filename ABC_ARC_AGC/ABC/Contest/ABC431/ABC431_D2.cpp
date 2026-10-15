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

void solve(int k, int &v, ll &ans, ll score, ll weight, ll &limit, vector<pair<ll,int>> &V, vector<ll> &H, vector<ll> &B, vector<ll> &W){
    
    if(k == -1){
        if(weight <= limit - weight){
            ans = max(ans,score);
        }
        return;
    }

    if(k >= 0){
        if(V.at(k).first+weight <= limit - (V.at(k).first+weight)){
            rep(i,k+1){score += H.at(V.at(i).second) - B.at(V.at(i).second);}
            solve(-1,v,ans,score,weight+V.at(k).first,limit,V,H,B,W);
            return;
        }
        if(k >= 1 && weight + V.at(k).first-V.at(k-1).first <= limit - (V.at(k).first-V.at(k-1).first+weight)){
            solve(k-1,v,ans,score+H.at(V.at(k).second)-B.at(V.at(k).second),weight+V.at(k).first-V.at(k-1).first,limit,V,H,B,W);
        }
        solve(k-1,v,ans,score,weight,limit,V,H,B,W);
    }
    return;
}


int main(){
    ll n,body=0, ans = 0;
    cin >> n;
    vector<ll> W(n);
    vector<ll> H(n);
    vector<ll> B(n);
    vector<pair<ll,int>> V;
    rep(i,n){
        cin >> W.at(i) >> H.at(i) >> B.at(i);
        body += W.at(i);
        ans += B.at(i);
        if(H.at(i) > B.at(i)){V.push_back(make_pair(W.at(i),i));}
    }
    sort(vecall(V));
    int v = V.size();
    adrep(i,1,v-1,1){V.at(i).first += V.at(i-1).first;}
    solve(v-1,v,ans,0,0,body,V,H,B,W);
    cout << ans << endl;
}