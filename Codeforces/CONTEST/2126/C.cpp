#include <bits/stdc++.h>
using namespace std;    
#define ll long long
 
int main(){
 
    int t; cin >> t;
 
    while (t--){

        int n, k; cin >> n >> k;

        vector<ll> tower ( n+1 , 0);
        for ( int i = 1; i <= n; i++) cin >> tower[i];
        ll start = tower[k];
        sort( tower.begin(), tower.end());

        ll idx = 1, water = 1;
        while ( tower[idx] < start) idx++;

        // momento inicial, water = 1
        // aqui pegar o gap máximo

        ll gap = - 1;

        while ( idx < n){
            ll jump = tower[idx + 1] - tower[idx];
            gap = max(gap, jump);
            idx++;
        }

        if ( gap > start) cout << "NO\n";
        else cout << "YES\n";



    }
    return 0;
}


