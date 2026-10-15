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

int main(){
    cout << fixed << setprecision(15);
    double a,b,x;
    cin >> a >> b >> x;
    if(x >= a*a*b/2) cout << double(90) - atan(a*a*a/(2*a*a*b-2*x))*180/M_PI << endl;
    if(x < a*a*b/2) cout << double(90) - atan(2*x/(a*b*b))*180/M_PI << endl;
}