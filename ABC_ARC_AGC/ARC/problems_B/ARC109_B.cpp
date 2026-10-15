#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

// (m+1)(m+4) <= 2n を満たす最大のmを返す
long long solve(long long n){
    long long a = -2, b = sqrt(2*n);
    long long m;
    while(true){
        m = (a+b)/2;
        /*cout << "(a,b) = (" << a << ", " <<  b << ")" << endl;
        cout << m << "  " << (m+1)*(m+4) << endl;*/
        if((m+1)*(m+4) > 2*n){b = m;}
        if((m+1)*(m+4) < 2*n){a = m;}
        if((m+1)*(m+4) <= 2*n && (m+2)*(m+5) > 2*n){break;}
    }
    //cout << m << endl;
    return m;
}



int main(){
    long long n;
    cin >> n;
    long long k = 0, ans = 0, m = 0;
    m = solve(n);
    k = (m+1)*(m+4)/2;
    ans = (m+1)*(m+2)/2 + n - k;
    cout << ans << endl;
}