#include <bits/stdc++.h>
using namespace std;    
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int, int>
 
int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll m; cin >> m;

    vector<ll> powers (62, 0);

    powers[0] = 1;

    for ( int i = 1; i <= 60; i++){
        powers[i] = 2*powers[i-1];
    }

    for ( int i = 1; i <= 60; i++){
        if ( powers[i] >= 8*m*1000000) {cout << i << '\n';break;}
    }

    return 0;
}
