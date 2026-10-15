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
#define adjrep(i,s,e,k) for(int i = s; i <= e; i+=k)
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
    vector<vector<ll>> V(n,vector<ll>(8));
    for(int i = n-1; i >= 0; i--){
        if(s.at(i) == 'c'){V.at(i).at(0)++;}
        if(s.at(i) == 'h'){V.at(i).at(1)++;}
        if(s.at(i) == 'o'){V.at(i).at(2)++;}
        if(s.at(i) == 'k'){V.at(i).at(3)++;}
        if(s.at(i) == 'u'){V.at(i).at(4)++;}
        if(s.at(i) == 'd'){V.at(i).at(5)++;}
        if(s.at(i) == 'a'){V.at(i).at(6)++;}
        if(s.at(i) == 'i'){V.at(i).at(7)++;}
        if(i < n-1){rep(j,8){V.at(i).at(j) += V.at(i+1).at(j);}}
    }
    /*rep(i,n){cout << V.at(i).at(0) << " ";}
    cout << endl;*/
    bool hantei = true;
    int c,h,o,k,u,d,a,i;
    ll ans = 0;
    for(c = 0; c <= n-8; c++){
        //cout << "c: " << c << endl;
        if(V.at(c).at(0) == 0){break;}
        if(s.at(c) == 'c'){
            hantei = true;
            adjrep(j,1,7,1){if(V.at(c).at(j) == 0){hantei = false;}}
                if(hantei){
                h = c;
                while(V.at(h).at(1) > 0 && h <= n-8){
                h++;
                //cout << "h: " << h << endl;
                hantei = true;
                if(s.at(h) == 'h'){
                adjrep(j,2,7,1){if(V.at(h).at(j) == 0){hantei = false;}}
                    if(hantei){
                    o = h;
                    while(V.at(o).at(2) > 0 && o <= n-7){
                    o++;
                    //cout << "o: " << o << endl;
                    if(s.at(o) == 'o'){
                    adjrep(j,3,7,1){if(V.at(o).at(j) == 0){hantei = false;}}
                        if(hantei){
                        k = o;
                        while(V.at(k).at(3) > 0 && k <= n-6){
                        hantei = true;
                        k++;
                        //cout << "k: " << k << endl;
                        if(s.at(k) == 'k'){
                        adjrep(j,4,7,1){if(V.at(k).at(j) == 0){hantei = false;}}
                            if(hantei){
                            u = k;
                            while(V.at(u).at(4) > 0 && o <= n-5){
                            hantei = true;
                            u++;
                            //cout << "u: " << u << endl;
                            if(s.at(u) == 'u'){
                            adjrep(j,5,7,1){if(V.at(u).at(j) == 0){hantei = false;}}
                                if(hantei){
                                d = u;
                                while(V.at(d).at(5) > 0 && d <= n-4){
                                hantei = true;
                                d++;
                                //out << "d: " << d << endl;
                                if(s.at(d) == 'd'){
                                adjrep(j,6,7,1){if(V.at(d).at(j) == 0){hantei = false;}}
                                    if(hantei){
                                    a = d;
                                    while(V.at(a).at(6) > 0 && a <= n-3){
                                    a++;
                                    //cout << c << " " << h << " " << o << " " << k << " " << u << " " << d << " " << a << " " << endl; 
                                    if(s.at(a) == 'a'){
                                        if(V.at(a).at(7) > 0){ans = (ans + V.at(a).at(7)) % 1000000007;}
                                    }
                                    }
                                }
                                }
                                }
                                }
                            }
                        }
                    }
                }
                }
                }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}