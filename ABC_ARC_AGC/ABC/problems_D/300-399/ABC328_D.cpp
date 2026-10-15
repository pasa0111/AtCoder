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
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    string s;
    cin >> s;
    int n = s.size();
    string t = "", ans = "";
    bool hantei = false;
    rep(i,n){
        //cout << "i: " << i << "   " << hantei << "   " << t  << "   " << ans << endl;
        if(!hantei){
            t += s.at(i);
            if(i >= 2 && s.at(i-2) == 'A' && s.at(i-1) == 'B' && s.at(i) == 'C'){
                if(t.size() >= 4){
                    hantei = true;
                    i++;
                }
                t.erase(t.size()-3,3);
                continue;
            }
            if(i == 0 && s.at(i) != 'A'){
                ans += s.at(i);
                t = "";
            }
            if(i >= 1 && s.at(i-1) == 'B' && s.at(i) == 'B'){
                ans += t;
                t = "";
            }
            if(s.at(i) == 'C'){
                ans += t;
                t = "";
            }
            continue;
        }
        if(hantei){
            if(t.size() == 0){
                hantei = false;
                i -= 2;
                continue;
            }
            if(s.at(i-1) == 'B' && s.at(i) == 'C'){
                t.pop_back();
                if(i == n-1){ans += t;}
                if(i == n-2){ans += t + s.at(n-1);}
                if(i == n-1 || i == n-2){t = "";}
                i++;
                continue;
            }
            else{
                ans += t;
                t = "";
                i -= 2;
                hantei = false;
                continue;
            }
        }
    }
    ans += t;
    cout << ans << endl;
}