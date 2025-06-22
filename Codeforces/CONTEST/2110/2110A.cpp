#include <bits/stdc++.h>
using namespace std;    
#define ll long long
 
int main(){
 
    int t; cin >> t;
 
    while (t--){
        int n; cin >> n;
        vector<ll> core; 

        for ( int i = 0; i < n; i++){
            ll ram; cin >> ram; core.push_back(ram);
        }
        //cout << "//// ";

        sort(core.begin(), core.end());

        //for ( ll k : core) cout << k << ' ';
        //cout <<'\n';

        ll ans1 = 0, ans2 = 0;

        if ( (core[0] + core[n-1])%2 == 0  ){
            cout << 0 << '\n';
        } else{ // aqui 1 deles é par e o outro é impar

            for ( int i = 1; i < n; i++){
                ans1++;
                if ( (core[i] + core[0])%2 != 0) break;
            }

            for ( int i = n -2; i >= 0; i--){
                ans2++;
                if ( (core[i] + core[n-1])%2 != 0) break;
            }

            //cout << ans1 << ' ' << ans2 << '\n';
            //cout << "//*/ ";
            cout << min(ans1, ans2) << '\n';


        }
    }
    return 0;
}

/*/
1
7
2 7 4 6 9 11 5

 
//*/