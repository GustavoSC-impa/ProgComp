#include <bits/stdc++.h>
using namespace std;    
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int, int>
 
int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int c, g; cin >> c >> g;

    if ( c == 1 ){
        cout << "vivo e morto";
    } else {
        if ( g == 1) cout << "vivo";
        else cout << "morto";
    }

    return 0;
}
