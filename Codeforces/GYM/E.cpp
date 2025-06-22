#include <bits/stdc++.h>
using namespace std;    
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int, int>
 
int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll y, k; cin >> y >> k;

    ll Y = y;

    // y energia k o tanto de saltos.

    vector<ll> fatores;

    // pegar todos os fatores primos do número, equivalente a decompor ele

    ll target = ceil(sqrt(y));

    for ( ll i = 2; i <= target; i++){
        while(y%i == 0){
            fatores.push_back(i);
            y/=i;
        }
        if ( y == 1) break;
    }

    // agora tenho todos os fatores

    if ( y != 1) fatores.push_back(y);

    ll ans = 1;

    /*/

    for ( ll p : fatores) cout << p << ' ';
    cout << '\n';

    //*/

    for ( ll p : fatores){
        //cout << ans << ' ';

        if ( k >= p - 1){
            ans*= p;
            k -=p; k++;
        }else{
            // se não tem pulos o bastante, adiciona k vezes ans
            ans += k*ans; 
            k = 0;
        }
    }
    if ( k != 0) ans += k*Y;
    //cout << "\n //// ";
    cout << ans << '\n';

    return 0;
}
