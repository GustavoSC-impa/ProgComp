#include <bits/stdc++.h>
using namespace std;    
#define ll long long
 
int main(){
 
    int t; cin >> t;
 
    while (t--){
        int k; cin >> k;
        if ( k < 10){
            cout << k << '\n';
        }

        if ( k >= 10 && k < 100){
            cout << min( int(k%10), int(k/10) )<< '\n';
        }

        if ( k >= 100){
            cout << min( {k%10, int(k/10)%10, int(k/100)%10} ) << '\n';
        }

    }
    return 0;
}
