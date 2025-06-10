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

        vector<int> tetos ( n+2, inf), pisos(n+2, 0), ganhos(n+2, 0);

        for ( int i = 1; i <= n; i++){
            cin >> pisos[i] >> tetos[i];
        } // aqui leu tudo

        //agora faz a dp dos ganhos

        for ( int i = 1; i <= n; i++){
            if ( core[i] == 1){ // se tiver um pulo aqui
                ganhos[i] = ganhos[i-1] + 1;
            } else{
                ganhos[i] = ganhos[i-1];
            }
        } // a d

        vector<int> dpTetos ( n+2, inf);

        for ( int i = 1; i <=n; i++){
            tetos[i] -= ganhos[i];
        } 

        // agora fazer a dp dos tetos "daqui pra frente, essa é a menor altura"

        for ( int i = n; i >= 1; i--) dpTetos[i] = min(tetos[i], dpTetos[i+1]);
        
        // nesse ponto, cada teto será a altura dele, menos tudo que o drone certamente ganhará de altura até chegar nele

        int h = 0;

        bool fail = false;

        for ( int i = 1; i <=n; i++){
            if ( core[i] != -1){
                // aqui se o drone não pode ser pilotado
                h += core[i];
            }else{
                if ( h < dpTetos[i]){
                    h++; core[i] = 1;
                } else{
                    core[i] = 0;
                }
            }

            if ( h < pisos[i] || h > tetos[i] + ganhos[i]) {
                fail = true;
                //cout << "//bateu = " << i << " " << h<<" " <<tetos[i]<< '\n';
            }

        }

        //cout << "///// ";
        if ( fail ){
            cout << -1 << '\n';
        } else {
            for ( int i = 1; i <= n; i++){
                cout << core[i] << ' ';
            } cout << '\n';
            
        }

        //for ( int i = 1; i <= n; i++) cout << ganhos[i] << ' '; cout << '\n';
        //for ( int i = 1; i <= n; i++) cout << tetos[i] << ' '; cout << '\n';


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