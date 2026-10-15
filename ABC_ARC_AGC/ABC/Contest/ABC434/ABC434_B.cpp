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
    cout << fixed << setprecision(15);
    int n,m;
    cin >> n >> m;
    vector<double> A(m+1),B(m+1); //重さ,個体数
    rep(i,n){
        double a,b;
        cin >> a >> b;
        A[a] += b;
        B[a]++;
    }
    for(int i = 1; i <= m; i++){
        cout << A[i]/B[i] << endl;
    }
}