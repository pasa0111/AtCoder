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
#define MP make_pair

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int n,q;
    string S;
    cin >> n >> q >> S;
    vector<int> count(n); //S[0]~S[i]までに"AC"がいくつ含まれているか保存
    for(int i = 0; i < n; i++){
        if(i > 0 && S[i-1] == 'A' && S[i] == 'C') count[i]++;
        if(i > 0) count[i] += count[i-1];
    }
    //for(int i:count) cout << i << " ";
    //cout << endl;
    rep(query,q){
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        if(S[l] == 'C') l++;
        cout << count[r]-count[l] << endl;
    }
}