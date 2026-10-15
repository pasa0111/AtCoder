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
#include <cctype>


using namespace std;
#define ll long long
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i);}
#define sumvecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i); if(i > 0) vec[i] += vec[i-1];}
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));
#define MP make_pair
#define MT make_tuple

/*
g++ ABC/problems_D/301-400/ABC392_D.cpp -o a.out && ./a.out < ./input.txt
*/

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    cout << fixed << setprecision(15);
    int n,a,size1,size2,y;
    cin >> n;
    vector<double> k(n);
    vector<map<int,int>> cnt1(n);
    rep(i,n){
        int c;
        cin >> c;
        k[i] = c;
        rep(j,c){
            cin >> a;
            cnt1[i][a]++;
        }
    }
    double ans = 0;
    vector<vector<pair<int,int>>> cnt(n);
    rep(i,n) for(auto x:cnt1[i]) cnt[i].push_back(x);
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            double sum = 0;
            size1 = cnt[i].size();
            size2 = cnt[j].size();
            y = 0;
            for(int x = 0; x < size1; x++){
                while(y < size2 && cnt[i][x].first > cnt[j][y].first)y++;
                if(y < size2 && cnt[i][x].first == cnt[j][y].first) sum += (double)cnt[i][x].second*cnt[j][y].second/k[i]/k[j];
            }
            ans = max(ans,sum);
        }
    }
    cout << ans << endl;
}