#include <bits/stdc++.h>
using namespace std;    
#define ll long long

vector<ll> primos;

ll gdc ( ll a, ll b){
    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}
 
int main(){

    map<ll, bool> ehprimo;

    for ( int i = 2; i <= 5000; i++) ehprimo[i] = true;
    
    for ( int i = 2; i <= 5000; i++){
        if ( ehprimo[i]){
            primos.push_back(i);
            int ram = 2*i;
            while( ram <= 5000){
                ehprimo[ram] = false;
                ram += i;
            }
        }
    }

    // computei os primo tudo
 
    int t; cin >> t;
 
    while (t--){
        int n; cin >> n;

        vector<ll> core; 

        for ( int i = 0; i < n; i++){
            ll ram; cin >> ram; core.push_back(ram);
        }

        bool one = false;

        for ( int i = 0; i < n; i++) if ( core[i] == 1) one = true;

        if ( one){
            int ans = 0;
            for ( int i = 0; i < n; i++) if ( core[i] != 1) ans++;

            cout << ans << '\n';
        } else {

            // aqui garante que não tem 1, então precisa saber se tem qq par primo entre si
            ll mdc = core[0];

            for ( int i = 1; i < n; i++){
                mdc = gdc(mdc, core[i]);
            }

            ll mdcAux = core[0];

            for ( int i = 1; i < n; i++){
                mdcAux = gdc(mdcAux, core[i]);
                if ( mdcAux = mdc);
            } // aqui achou o cara em que stopa

            ll ans = 0;

            bool find = false;

            for ( int i = 0; i < n; i++){
                if ( core[i] == mdc) find = true;
                else ans++;
            }

            if ( find){
                cout << ans << '\n';
            } else{
                // aqui preciso achar o jeito mais rápido de fazer o gdc


            }





            


        }


    }
    return 0;
}