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
    string s, t = "";
    cin >> s;
    int n = s.size(), k;
    rep(i,n){
        if(s.at(i) == '0'){
            t += '0';
        }
        if(s.at(i) == '1'){
            t += '1';
        }
        if(s.at(i) == 'B'){
            k = t.size();
            if(k > 0){t.erase(k-1,1);}
        }
    }
    cout << t << endl;
}