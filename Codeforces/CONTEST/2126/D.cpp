#include <bits/stdc++.h>
using namespace std;    
#define ll long long
 
int main(){
    int t; cin >> t;
 
    while (t--){

        

        ll n, k; cin >> n >> k;

        vector<tuple<ll,ll,ll>> cassino;

        for ( int i = 0; i < n; i++){
            ll l, r, real; cin >> l >> r >> real;
            cassino.push_back({real, l, r});
        }

        sort(cassino.begin(), cassino.end());

        for ( tuple<ll,ll,ll> cas : cassino){
            ll real, l, r; tie(real, l, r) = cas;
            //cout << "==" << l << ' ' << real << ' ' << r << '\n';

            if ( k >= l && k <= r && k <= real) k = real;
        }

        cout<< k << '\n';

    }
    return 0;
}
