#include <bits/stdc++.h>
using namespace std;    
#define ll long long
#define inf 1000000

int main(){
 
    int t; cin >> t;
 
    while (t--){
        int n; cin >> n;

        vector<int> core; core.push_back(0);

        for ( int i = 0; i < n; i++){
            int ram; cin >> ram; core.push_back(ram);
        }

        vector<int> tetos ( n+2, 0), pisos(n+2, 0), ganhos(n+2, 0);

        for ( int i = 1; i <= n; i++){
            cin >> pisos[i] >> tetos[i];
        } // aqui leu tudo

        //agora faz a dp dos ganhos

        for ( int i = 1; i <= n; i++){
            ganhos[i] = ganhos[i-1] + max(0, core[i]);
        } 

        for ( int i = 1; i <= n; i++){
            tetos[i] -= ganhos[i]; 
        } // essa conta reduz em cada teto, quanto de energia é ganha do inicio até ali

        vector<int> dpTetos ( n+2, inf), idxTetos (n+2, 0);

        // agora fazer a dp dos tetos "daqui pra frente, essa é a menor altura"

        for ( int i = n; i >= 1; i--){ 
            dpTetos[i] = min(tetos[i], dpTetos[i+1]);
        }

        int h = 0;

        bool fail = false;

        for ( int i = 1; i <=n; i++){

            if ( core[i] == -1){

                if ( h < dpTetos[i]){ // se a energia atual é menor do que a que eu posso atingir
                    h++;
                    core[i] = 1;
                }else{
                    core[i] = 0;
                }

            }

            if (h > tetos[i]) fail = true;
            if (h + ganhos[i] < pisos[i]) fail = true;


        }

        //cout << "///// ";
        if ( fail ){
            cout << -1 << '\n';
        } else {
            for ( int i = 1; i <= n; i++){
                cout << core[i] << ' ';
            } cout << '\n';
            
        }

        //for ( int i = 1; i <= n; i++) cout << tetos[i] << ' '; cout << '\n';
        //for ( int i = 1; i <= n; i++) cout << dpTetos[i] << ' '; cout << '\n';
        //for ( int i = 1; i <= n; i++) cout << ganhos[i] << ' '; cout << '\n';


    }
    return 0;
}

/*/
1
8
-1 -1 1 -1 -1 0 0 -1
0 0
0 1
0 2
0 2
1 3
0 4
2 5
4 5
 
//*/