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
    if(b) cout << "Prime" << endl;
    if(!b) cout << "Not Prime" << endl;
}

int main(){
    int n;
    cin >> n;
    bool ans = true;
    adjrep(i,2,sqrt(n)+1,1){
        if(n % i == 0 && n != i){
            ans = false;
            break;
        }
    }
    if(!ans){
        ans = true;
        int sum = 0;
        if((n%10) % 2 == 0 || (n%10) == 5){ans = false;}
        while(n > 0 && ans){
            sum += n%10;
            n /= 10;
        }
        if(sum % 3 == 0){ans = false;}
    }
    if(n == 1){ans = false;}
    yesno(ans);
}