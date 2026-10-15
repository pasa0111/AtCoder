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
    int a,b,n, ans = 0;
    string s;
    cin >> n >> a >> b >> s;
    vector<int> A;
    vector<int> B;
    vector<pair<int,int>> t(n);
    t.at(0) = make_pair(0,0);
    for(int i = 0; i < n; i++){
        if(s.at(i) == 'a'){
            A.push_back(i);
            t.at(i).first++;
        }
        if(s.at(i) == 'b'){
            B.push_back(i);
            t.at(i).second++;
        }
        if(i >= 1){
            t.at(i).first += t.at(i-1).first;
            t.at(i).second += t.at(i-1).second;
        }
    }
    int Asize = A.size(), Bsize = B.size();
    if(Asize >= a){
        for(int q = 0; q < Bsize-b; q++){
            for(int p = 0; p < Asize-a+1; p++){
                cout << B.at(q) << "  " << A.at(p) << "  " <<  A.at(p+a-1) << "  " <<  B.at(q+b) << endl;
                if(A.at(p) > B.at(q) && A.at(p+a-1) < B.at(q+b)){
                    cout << "ok" << endl;
                    ans += (A.at(p)-B.at(q)+1)*(B.at(q+b)-A.at(p+a-1));
                    if(q >= 2-b){
                        if(A.at(p+a-1) < B.at(q+b-2)){
                            ans -= (A.at(p)-B.at(q)+1)*(B.at(q+b-2)-A.at(p+a-1)+1);
                        }
                    }
                    p = Asize+1;
                }
                cout << ans << endl;
            }
        }
    }
    cout << ans << endl;
}