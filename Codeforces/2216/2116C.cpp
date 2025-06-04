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


        ////////////////////////////////////////////////

        //cout << "//// ";

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

            //cout << "////mdc = " << mdc << "\n";

            ll ans = 0;

            bool find = false;

            for ( int i = 0; i < n; i++){
                if ( core[i] == mdc) find = true;
                else ans++;
            }

            if ( find){
                cout << ans << '\n';
            } else{

                /// aqui não achou o mdc, então tem que produzir



                ll idx = 0, idx2 = 0;
                ll ramk = 0, score = 10000000;

                for ( int i = 0; i < n; i++){
                    for ( int j = i; j < n; j++){ // aqui vai testar todas as combinações

                    ll ram = 0, idp = 0;

                    ll result = gdc(core[i], core[j]); // entre todos os caras, pega o que tem menos fator

                    while(result != 1){
                        while ( result%primos[idp] != 0) idp++;
                        ram++; result /= primos[idp];
                    }


                    if ( ram <= score){
                        score = ram; 
                        idx = i; idx2 = j;
                    }


                    } 
                } // aqui achou idx e idx2


                //cout << "//alvos " << core[idx] << " " << core[idx2] << " " <<  gdc(core[idx], core[idx2]) << '\n';

                core[idx] = gdc(core[idx], core[idx2]);
                ans = 1;
                
                // aqui sempre vai rodar pelo menos 1 interação

                while ( !find){
                    // primeiro passa operando

                    // aqui tem que achar o idx

                    if ( core[idx] == mdc ) break; // aqui é quando produziu

                    ramk = 0; score = 10000000;

                    for ( int i = 0; i < n; i++){

                        ll result = gdc ( core[i], core[idx]); // aqui pegou o gdc do alvo e do atual
                        ll apk = result;
                        ll ram = 0, idp = 0;

                        while(result != 1){
                            while ( result%primos[idp] != 0) idp++;
                            ram++; result /= primos[idp];
                        }


                        if ( ram <= score){
                            score = ram; 
                            ramk = apk;
                        } // nisso acha o i cara que minimiza o gdc com target


                    }

                    core[idx] = ramk;
                    ans++;
                    

                }


                cout << ans + n - 1 << '\n';


            }





            


        }


    }
    return 0;
}

/*/
1
50
2100 3080 3570 3300 420 3630 4830 1386 990 1680 3850 4158 1980 840 3234 1540 1848 3780 
4410 4200 4950 3960 2730 3696 1050 2970 3465 2772 1320 3990 462 1470 770 3150 2520 1650 
2310 1890 1260 2940 2640 4290 1155 630 924 330 210 660 3360 4620


//*/