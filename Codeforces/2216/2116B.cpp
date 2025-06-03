#include <bits/stdc++.h>
using namespace std;    
#define ll long long

ll mod = 998244353;


ll FastExp( long long exp) {
    ll base = 2;
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

 
int main(){
 
    int t; cin >> t;
 
    while (t--){
    
        ll n; cin >> n;

        vector<ll> core1, core2; 

        for ( int i = 0; i < n; i++){
            ll ram; cin >> ram; core1.push_back(ram);
        }

        for ( int i = 0; i < n; i++){
            ll ram; cin >> ram; core2.push_back(ram);
        }

        // feitas as leituras, guardar os ponteiros para o maior em cada vetor

        vector<ll> max1(n, 0), max2(n, 0);

        max1[0] = 0; max2[0] = 0;

        ll maisi1 = core1[0], maisi2 = core2[0];

        for ( int i = 1; i < n; i++){
            if (core1[i] > maisi1){
                maisi1 = core1[i];
                max1[i] = i;
            } else {
                max1[i] = max1[i-1];
            }

            if (core2[i] > maisi2){
                maisi2 = core2[i];
                max2[i] = i;
            } else {
                max2[i] = max2[i-1];
            }

        } // aqui tem o ponteiro pro máximo direto
        /*/
        cout << "/// ";
        
        for ( int i = 0; i < n; i++){
            cout << max1[i] << ' ';
        }

        cout << '\n';

        for ( int i = 0; i < n; i++){
            cout << max2[i] << ' ';
        }

        cout << '\n';

        //*/


        vector<pair<ll,ll>> maisi;

        for ( int i = 0; i < n; i++){
            if ( core1[max1[i]] > core2[max2[i]]){
                maisi.push_back({core1[max1[i]], core2[i - max1[i]]}); 
                continue;
            }
            if ( core1[max1[i]] < core2[max2[i]]){
                maisi.push_back({core2[max2[i]], core1[i - max2[i]]}); 
                continue;
            }

            maisi.push_back({core1[max1[i]], max(core2[i - max1[i]], core1[i - max2[i]])});

        }

        // for ( pair<ll,ll> p : maisi) cout << p.first << " / " << p.second << " /// ";
        

        for ( pair<ll,ll> p : maisi){
            ll a = FastExp(p.first), b = FastExp(p.second);
            ll ans =  ( a + b)%mod;

            cout << ans << ' ';
        }
    
        cout << '\n';

    }
    return 0;
}

/*/
1
10
5 8 9 3 4 0 2 7 1 6
9 5 1 4 0 3 2 8 7 6

 

//*/