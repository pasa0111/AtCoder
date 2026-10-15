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

int f(int i, int j, int &t, string &T, vector<vector<string>> &S, vector<vector<int>> &memo){
    //cout << "i: " << i << "   j: " << j << endl;

    int b = S.at(i).size();
    //末尾にS.at(i)の要素を使う場合の処理
    bool hantei = true;
    rep(a,b){
        int x = S.at(i).at(a).size();
        if(j-x+1 >= 0 && S.at(i).at(a) == T.substr(j-x+1,x)){
            hantei = false;
            if(j-x+1 == 0){memo.at(i).at(j) = 1;}
            if(i == 0 && j-x+1 > 0){memo.at(i).at(j) = -1;}
            if(i >= 1 && j-x+1 > 0 && memo.at(i-1).at(j-x) == 10000){memo.at(i-1).at(j-x) = f(i-1,j-x,t,T,S,memo);}
            if(i >= 1 && j-x+1 > 0 && memo.at(i-1).at(j-x) != -1){memo.at(i).at(j) = min(memo.at(i).at(j),memo.at(i-1).at(j-x)+1);}
        }
    }

    //末尾にS.at(i)の要素を使わない場合の処理
    if(i >= 1 && memo.at(i-1).at(j) == 10000){memo.at(i-1).at(j) = f(i-1,j,t,T,S,memo);}
    if(i >= 1 && memo.at(i-1).at(j) != -1){memo.at(i).at(j) = min(memo.at(i).at(j),memo.at(i-1).at(j)); hantei = false;}

    if(hantei || memo.at(i).at(j) == 10000){memo.at(i).at(j) = -1;}
    //cout << "f(" << i << "," << j << ")" << " = " << memo.at(i).at(j) << endl;
    return memo.at(i).at(j);
}

int main(){
    string T;
    int n,t;
    cin >> T >> n;
    t = T.size();
    vector<vector<string>> S(n);
    vector<vector<int>> memo(n,vector<int>(t,10000));
    rep(i,n){
        int a;
        string s;
        cin >> a;
        rep(j,a){
            cin >> s;
            S.at(i).push_back(s);
        }
    }
    cout << f(n-1,t-1,t,T,S,memo) << endl;
}