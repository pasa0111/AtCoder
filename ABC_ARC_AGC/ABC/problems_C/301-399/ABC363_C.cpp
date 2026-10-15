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

map<char,int> word; //(文字,個数)
int n,k, ans = 0;

bool kaibun(string T){
    int m = T.size();
    if(m < 2) return true;
    if(T[0] == T[m-1]) return kaibun(T.substr(1,m-2));
    return false;
}

string s = "";

void solve(int i){
    if(i == n){
        //cout << s << endl;
        bool hantei = false;
        for(int j = 0; j <= n-k; j++){
            hantei = kaibun(s.substr(j,k));
            if(hantei) break;
        }
        if(!hantei){
            //cout << "ans:" << ans << " --> " << ans+1 << endl;
            ans++;
        }
        return;
    }

    for(auto &w:word){
        if(w.second > 0){
            w.second--;
            s += w.first;
            //cout << w.first << ":" << w.second << endl;
            solve(i+1);
            w.second++;
            if(w.second)
            s.pop_back();
        }
    }
    return;
}


int main(){
    string S;
    cin >> n >> k >> S;
    for(char i:S){
        if(!word.count(i)) word[i] = 0;
        word.at(i)++;
    }
    solve(0);
    cout << ans << endl;
}