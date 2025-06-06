#include <bits/stdc++.h>
using namespace std;    
#define ll long long
#define inf 10000000
 
int main(){
 
    int t; cin >> t;
 
    while (t--){

        int n; cin >> n;
        vector<int> core; core.push_back(0);

        for ( int i = 0; i < n; i++){
            int ram; cin >> ram; core.push_back(ram);
        } // aqui leu tudo

        vector<pair<int,int>> obstacle; obstacle.push_back({0,inf}); // deixar tudo 1 indexado

        for ( int i = 0; i < n; i++){
            int a, b; cin >> a >> b; obstacle.push_back({a, b});
        } // aqui leu os obstáculo

        vector<int> tetos ( n + 1, inf), pisos (n + 1, 0), ganhos(n + 1, 0);
        tetos[n] = n; pisos[n] = obstacle[n].first; 

        // guardar o índice o menor cara

        for ( int i = n -1; i >= 0; i--){

            if ( obstacle[i].second <= tetos[i+1]){ // se trocou o  menor
                tetos[i] = i;
            } else tetos[i] = tetos[i + 1]; // se o atual não é menor ou igual o anterior.


        }

        for ( int i = n - 1; i >= 0; i--){
            pisos[i] = max(pisos[i+1], obstacle[i].first);

        }

        for ( int i = 1; i <= n; i++){
            if ( core[i] == 1) ganhos[i] = ganhos[i-1] + 1;
            else ganhos[i] = ganhos[i-1];
        } // os ganhos são do começo até aqui

        /*/
        for ( int k : tetos) cout << k << ' ';
        cout << '\n';

        for ( int k : pisos) cout << k << ' ';
        cout << '\n';

        for ( int k : ganhos) cout << k << ' ';
        cout << '\n';
        //*/
        int h = 0;

        // agora vamo simula
        bool fail = false;
        for ( int i = 1; i <= n; i++){
            if ( core[i] != -1){ // aqui não faz nada feijoada
                h+=core[i];
                if ( h < obstacle[i].first || h > obstacle[i].second) fail = true;
            }else{
                // ver se até o prox menor, eu posso subir

                if ( h < obstacle[i].first - 1 || h > obstacle[i].second) fail = true;
                // obstacle[tetos[i]].second é o menor teto daqui até o final
                if ( h < obstacle[tetos[i]].second - ( ganhos[tetos[i]] - ganhos[i-1])){
                    // ou seje, se daqui até o menor ate o final, o ganho for menor que a altura que me faz bater
                    h++;
                    core[i] = 1;

                } else{
                    core[i] = 0;
                }
            }
        }

        for ( int i = 1; i <= n; i++) cout << core[i] << ' ';
        //cout << "//// ";
        if ( fail) cout << -1 << '\n';
        else{
            for ( int i = 1; i <= n; i++) cout << core[i] << ' ';
            cout << '\n';
        }

    }
    return 0;
}

/*/
1
2
-1 -1
0 1
0 0

 
//*/