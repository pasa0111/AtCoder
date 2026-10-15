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


//s.at(b)がs.at(a)とs.at(c)と異なる文字になるようにs.at(b)を変更する
//変更した場合,res++;
void change(ll &res, string &s, int a, int b, int c){
    if(s.at(a) != s.at(b) && s.at(b) != s.at(c)){return;}
    if(s.at(a) != 'a' && s.at(c) != 'a'){s.at(b) = 'a';}
    if(s.at(a) == 'a' && s.at(c) != 'b'){s.at(b) = 'b';}
    if(s.at(a) != 'b' && s.at(c) == 'a'){s.at(b) = 'b';}
    if(s.at(a) == 'a' && s.at(c) == 'b'){s.at(b) = 'c';}
    if(s.at(a) == 'b' && s.at(c) == 'a'){s.at(b) = 'c';}
    res++;
    return;
}

int main(){
    string S, copy, copy2;
    ll K,ans = 0, res = 0, t = 0, u = 0;
    cin >> S >> K;
    ll n = S.size();
    if(n == 1){ans = K/2;}
    if(n == 2){
        if(S.at(0) == S.at(1)){ans = K;}
        if(S.at(0) != S.at(1)){ans = 0;}
    }
    if(n >= 3){
        copy = S;
        if(S.at(0) == S.at(n-1) && K >= 2){
            if(S.at(n-2) != S.at(n-1)){t = -1;}
            change(ans,S,0,n-1,n-2);
        }
        u = ans;
        copy2 = S;
        for(int i = n-1; i >= 0; i-=2){
            if(i == 0){
                change(ans,S,n-1,0,1);
                continue;
            }
            if(i == n-1){
                change(ans,S,n-2,n-1,0);
                continue;
            }
            else{change(ans,S,i-1,i,i+1);}
        }
        ans = ans * K + t;
        S = copy2;
        t = 0;
        res = u;

        for(int i = n-2; i >= 0; i-=2){
            if(i == 0){
                change(res,S,n-1,0,1);
                continue;
            }
            else{change(res,S,i-1,i,i+1);}
        }
        res = res * K + t;
        ans = min(ans,res);
        S = copy;
        t = 0;
        res = 0;

        if(S.at(0) == S.at(n-1) && K >= 2){
            if(S.at(n-1) != S.at(n-2)){t = -1;}
            change(res,S,n-1,0,1);
        }
        u = res;
        copy2 = S;
        for(int i = n-1; i >= 0; i-=2){
            if(i == 0){
                change(res,S,n-1,0,1);
                continue;
            }
            if(i == n-1){
                change(res,S,n-2,n-1,0);
                continue;
            }
            else{change(res,S,i-1,i,i+1);}
        }
        res = res * K + t;
        ans = min(ans,res);
        S = copy2;
        t = 0;
        res = u;
        for(int i = n-2; i >= 0; i-=2){
            if(i == 0){
                change(res,S,n-1,0,1);
                continue;
            }
            else{change(res,S,i-1,i,i+1);}
        }
        res = res * K + t;
        ans = min(ans,res);
    }
    cout << ans << endl;
}