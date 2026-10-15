#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    int ans = 0;
    string S;
    cin >> S;
    map<char,int> p; //文字[k]が文字列の何番目にあるか保存
    for(int i = 0; i < 7; i++){p[S.at(i)] = i;}
    for(int i = 0; i < p.at('a'); i++){p.at(S.at(i))++;}
    ans += p.at('a');
    S.erase(p.at('a'),1);
    S.insert(0,"a");
    //cout << "a " << ans << endl;
    for(int i = 1; i < p.at('t'); i++){p.at(S.at(i))++;}
    ans += p.at('t')-1;
    S.erase(p.at('t'),1);
    S.insert(1,"t");
    //cout << "t " << ans << endl;
    for(int i = 2; i < p.at('c'); i++){p.at(S.at(i))++;}
    ans += p.at('c')-2;
    S.erase(p.at('c'),1);
    S.insert(2,"c");
    //cout << "c " << ans << endl;
    for(int i = 3; i < p.at('o'); i++){p.at(S.at(i))++;}
    ans += p.at('o')-3;
    S.erase(p.at('o'),1);
    S.insert(3,"o");
    //cout << "o " << ans << endl;
    for(int i = 4; i < p.at('d'); i++){p.at(S.at(i))++;}
    ans += p.at('d')-4;
    S.erase(p.at('d'),1);
    S.insert(4,"d");
    //cout << "d " << ans << endl;
    for(int i = 5; i < p.at('e'); i++){p.at(S.at(i))++;}
    ans += p.at('e')-5;
    S.erase(p.at('e'),1);
    S.insert(5,"e");
    //cout << "e " << ans << endl;

    cout << ans << endl;
}