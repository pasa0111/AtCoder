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
    ll n,body=0, ans = 0;
    cin >> n;
    vector<ll> W(n);
    vector<ll> H(n);
    vector<ll> B(n);
    vector<pair<double,int>> V; //頭の方が点数が高いパーツの番号を保存
    rep(i,n){
        cin >> W.at(i) >> H.at(i) >> B.at(i);
        body += W.at(i);
        ans += B.at(i);
        double h = H.at(i), w = W.at(i), b = B.at(i);
        if(H.at(i) > B.at(i)){V.push_back(make_pair((h-b)/w,i));}
    }
    sort(vecall(V));
    reverse(vecall(V));
    ll head = 0;
    rep(i,V.size()){
        int I = V.at(i).second;
        if(body < head){break;}
        if(body - W.at(I) >= head + W.at(I)){
            head += W.at(I);
            body -= W.at(I);
            ans -= B.at(I);
            ans += H.at(I);
        }
    }
    cout << ans << endl;
}