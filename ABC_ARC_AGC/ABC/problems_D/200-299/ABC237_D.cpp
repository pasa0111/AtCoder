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
    int n;
    cin >> n >> s;
    queue<int> ansr;
    stack<int> ansl;
    rep(i,n){
        if(s.at(i) == 'L'){ansl.push(i);}
        if(s.at(i) == 'R'){ansr.push(i);}
    }
    while(ansr.size() > 0){
        cout << ansr.front() << " ";
        ansr.pop();
    }
    cout << n << " ";
    while(ansl.size() > 0){
        cout << ansl.top() << " ";
        ansl.pop();
    }
    cout << endl;
}