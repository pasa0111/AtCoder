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
    int Q=1,a,x,c;
    map<int,int> m; //整数[i]が何個Sに含まれているか保存
    set<int> s; //Sに含まれる整数を保存
    cin >> Q;
    rep(q,Q){
        cin >> a;

        if(a == 1){
            cin >> x;
            if(!m.count(x)){m[x]=0;}
            if(m.at(x) == 0){s.insert(x);}
            m.at(x)++;
        }

        if(a == 2){
            cin >> x >> c;
            if(!m.count(x)){m[x]=0;}
            m.at(x) -= c;
            if(m.at(x) <= 0){
                m.at(x) = 0;
                s.erase(x);
            }
        }

        if(a == 3){
            cout << *rbegin(s) - *begin(s) << endl;
        }
    }
}