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
    int a,b,c,d,e,f,ans = 0;
    cin >> a >> b >> c >> d >> e >> f;
    vector<vector<int>> G(3,vector<int>(3));
    for(int x = 1; x <= min(a,d)-2; x++){
        for(int y = 1; x+y <= a-1; y++){
            for(int z = 1; z <= min(b,d)-2; z++){
                for(int w = 1; z+w <= b-1; w++){
                    for(int s = 1; s <= min(c,d)-2; s++){
                        for(int t = 1; s+t <= c-1; t++){
                            if(x+z+s == d && y+w+t == e && a-x-y+b-z-w+c-s-t == f){
                                ans++;
                                /*cout << x << " " << y << " " << a-x-y << endl;
                                cout << z << " " << w << " " << b-z-w << endl;
                                cout << s << " " << t << " " << c-s-t << endl;*/
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
