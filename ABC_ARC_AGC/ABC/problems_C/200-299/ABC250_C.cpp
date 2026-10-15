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
#define vall(vec) vec.begin(),vec.end()
#define vin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define adjvin(vec) for(int i = 1, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int N,Q,x,y;
    cin >> N >> Q;
    vector<int> A(N);
    vector<int> &B = A;
    map<int,int> m; //整数[i]がAの何番目にあるか保存
    rep(i,N){
        B.at(i) = i+1;
        m[i+1] = i;
    }
    rep(q,Q){
        cin >> x;
        int t = m.at(x);
        if(t == N-1){
            y = B.at(t-1);
            B.at(t-1) = x;
            B.at(t) = y;
            m.at(x)--;
            m.at(y)++;
        }
        if(t < N-1){
            y = B.at(t+1);
            B.at(t+1) = x;
            B.at(t) = y;
            m.at(x)++;
            m.at(y)--;
        }
    }
    rep(i,N){cout << B.at(i) << " ";}
    cout << endl;
}