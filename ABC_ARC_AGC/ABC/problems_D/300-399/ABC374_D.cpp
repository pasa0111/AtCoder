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

vector<double> a(6), b(6), c(6), d(6);
set<int> written;
double ans = 2e9, T = 0;
pair<double,double> now = MP(0,0);
int n;
double s,t;

void test(int cnt){
    if(cnt == n){
        //cout << T << endl;
        ans = min(ans,T);
        return;
    }

    for(int i = 0; i < n; i++){
        if(!written.count(i)){
            double save_T = T;
            pair<double,double> save_now = now;
            //now --> (a,b) --> (c,d)
            T += sqrt((now.first-a[i])*(now.first-a[i]) + (now.second-b[i])*(now.second-b[i]))/s;
            T += sqrt((a[i]-c[i])*(a[i]-c[i]) + (b[i]-d[i])*(b[i]-d[i]))/t;
            now = MP(c[i],d[i]);
            written.insert(i);
            test(cnt+1);
            T = save_T;
            now = save_now;

            //now --> (c,d) --> (a,b)
            T += sqrt((now.first-c[i])*(now.first-c[i]) + (now.second-d[i])*(now.second-d[i]))/s;
            T += sqrt((a[i]-c[i])*(a[i]-c[i]) + (b[i]-d[i])*(b[i]-d[i]))/t;
            now = MP(a[i],b[i]);
            test(cnt+1);
            T = save_T;
            now = save_now;
            written.erase(i);
        }
    }
    return;
}

int main(){
    cout << fixed << setprecision(15);
    cin >> n >> s >> t;
    rep(i,n) cin >> a[i] >> b[i] >> c[i] >> d[i];
    test(0);
    cout << ans << endl;
}