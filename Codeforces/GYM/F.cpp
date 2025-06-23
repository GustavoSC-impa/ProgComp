#include <bits/stdc++.h>
using namespace std;    
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int, int>
 
int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;

    vector<ll> a (n+1, 0);

    for ( int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<ll>> dp (100000, vector<ll> (5, 0)); 

    // esse vetor dp vai ser: quantas são as formas de somar i


    /*/
    for ( int i = 1; i<= n; i++){
        dp[a[i]][1]++; 

        // aqui conta cada número, que equivale a quantidade de jeitos de escolher 1 número e formar a soma
    }
    //*/



    // para 2, tem que tomar o cuidado pra não repetir termo

    // exemplo 1 1 1 1 1 1 

    // dp[1][1] = 6, a dp[2][2] tem que ser 15

    // eu tenho que percorrer o vetor a só 1 vez pra evitar repetição


    /*
    
    cout << "\n";
    for ( int l = 4 ; l >= 0; l--){
        for ( int i = 4000; i <= 4005; i++){
            cout << dp[i][l] << ' ';
        }
        cout << '\n';
    }
    
    //*/



    //*/
    for ( int i = 1; i <= n; i++){ // cada inteiro só vai ser computado uma vez
        ll k = a[i];
        for ( int l = 3; l >=0 ; l--){

            for ( int ki = 1000; ki <= 7000; ki++){ // para cada soma possível entre -4000 e 4000

                // pra cada andar da DP

                // a lore é garantir que cada número só vai ser usado uma vez

                //Se eu uso o número atual na dp atual

                dp[ki+k][l+1] += dp[ki][l];

                // na soma atual + cara, eu coloco o tanto de somas possíveis


            }

        }

        dp[4000 + k][1]++;
        /*
        cout << "\n";
        for ( int i = -5; i <= 30; i++) cout << std::setfill('0') << std::setw(2) << i << ' ';
        cout << '\n';
        for ( int l = 4 ; l >= 0; l--){
            for ( int i = 3995; i <= 4030; i++){
                cout << std::setfill('0') << std::setw(2) << dp[i][l] << ' ';
            }
            cout << '\n';
        }
        //*/

    }
    //*/

    int q; cin >> q;

    for ( int i = 0; i < q; i++){
        ll ram; cin >> ram; cout << dp[ram+4000][4] << '\n';
    }





    return 0;
}
