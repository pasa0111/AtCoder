#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    map<char,int> moji;
    moji['a'] = 0;
    moji['b'] = 0;
    moji['c'] = 0;
    moji['d'] = 0;
    moji['e'] = 0;
    moji['f'] = 0;
    moji['g'] = 0;
    moji['h'] = 0;
    moji['i'] = 0;
    moji['j'] = 0;
    moji['k'] = 0;
    moji['l'] = 0;
    moji['m'] = 0;
    moji['n'] = 0;
    moji['o'] = 0;
    moji['p'] = 0;
    moji['q'] = 0;
    moji['r'] = 0;
    moji['s'] = 0;
    moji['t'] = 0;
    moji['u'] = 0;
    moji['v'] = 0;
    moji['w'] = 0;
    moji['x'] = 0;
    moji['y'] = 0;
    moji['z'] = 0;
    moji['S'] = 0;
    moji['T'] = 0;
    
    string S, T;
    cin >> S >> T;
    for(unsigned long i = 0; i < S.size(); i++){
        if(S.at(i) != '@'){moji.at(S.at(i))++;}
        if(S.at(i) == '@'){moji.at('S')++;}
    }
    for(unsigned long i = 0; i < T.size(); i++){
        if(T.at(i) != '@'){moji.at(T.at(i))--;}
        if(T.at(i) == '@'){moji.at('T')++;}
    }
    //for(auto i:moji){cout << i.first << "," << i.second << endl;}

    if(moji.at('a')<0 && moji.at('S')+moji.at('a')>=0){moji.at('S')+=moji.at('a'); moji.at('a')=0;}
    if(moji.at('a')>0 && moji.at('T')-moji.at('a')>=0){moji.at('T')-=moji.at('a'); moji.at('a')=0;}
    if(moji.at('t')<0 && moji.at('S')+moji.at('t')>=0){moji.at('S')+=moji.at('t'); moji.at('t')=0;}
    if(moji.at('t')>0 && moji.at('T')-moji.at('t')>=0){moji.at('T')-=moji.at('t'); moji.at('t')=0;}
    if(moji.at('c')<0 && moji.at('S')+moji.at('c')>=0){moji.at('S')+=moji.at('c'); moji.at('c')=0;}
    if(moji.at('c')>0 && moji.at('T')-moji.at('c')>=0){moji.at('T')-=moji.at('c'); moji.at('c')=0;}
    if(moji.at('o')<0 && moji.at('S')+moji.at('o')>=0){moji.at('S')+=moji.at('o'); moji.at('o')=0;}
    if(moji.at('o')>0 && moji.at('T')-moji.at('o')>=0){moji.at('T')-=moji.at('o'); moji.at('o')=0;}
    if(moji.at('d')<0 && moji.at('S')+moji.at('d')>=0){moji.at('S')+=moji.at('d'); moji.at('d')=0;}
    if(moji.at('d')>0 && moji.at('T')-moji.at('d')>=0){moji.at('T')-=moji.at('d'); moji.at('d')=0;}
    if(moji.at('e')<0 && moji.at('S')+moji.at('e')>=0){moji.at('S')+=moji.at('e'); moji.at('e')=0;}
    if(moji.at('e')>0 && moji.at('T')-moji.at('e')>=0){moji.at('T')-=moji.at('e'); moji.at('e')=0;}
    if(moji.at('r')<0 && moji.at('S')+moji.at('r')>=0){moji.at('S')+=moji.at('r'); moji.at('r')=0;}
    if(moji.at('r')>0 && moji.at('T')-moji.at('r')>=0){moji.at('T')-=moji.at('r'); moji.at('r')=0;}

    bool ans = true;
    for(auto i:moji){
        //cout << i.first << "," << i.second << endl;
        if(i.first != 'S' && i.first != 'T' && i.second != 0){
            ans = false;
            break;
        }
        if(i.first == 'S' || i.first == 'T'){
            if(moji.at('S') != moji.at('T')){
                ans = false;
                break;
            }
        }
    }

    if(ans == true){cout << "Yes" << endl;}
    if(ans == false){cout << "No" << endl;}
}