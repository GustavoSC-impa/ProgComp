#include <bits/stdc++.h>
using namespace std;    
#define ll long long
 
int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    int t; cin >> t;
 
    while (t--){

        int n; cin >> n;

        vector<   pair<ll,pair<ll,ll>>   > S; // armazenar os pares

        vector<int> Retorno ( 7000, 0), v ( 7000, 0); // aqui vai guardar o anterior de cada par e os visitados

        vector<int> adj[n+1];

        for ( int i = 1; i <= n; i++){
            ll a, b; cin >> a >> b;
            S.push_back({i, {a, b}});

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<vector<int>> ciclos;

        function <void(int)> dfs = [&](int k) {
            // aqui uma dfs para encontrar os ciclos
            // recebi o índice não visitado
            v[k] = 1;

            for ( int viz : adj[k]){
                if ( v[viz] == 0){
                    Retorno[viz] = k;
                    dfs(viz);
                }

                if ( v[viz] == 1 && Retorno[k] != viz ){ 
                    //aqui encontrou um ciclo
                    
                }
            }

        };

        

        for ( int i = 1; i <= n; i++){ // aqui vai fazer a dfs em cada ciclo
                if ( v[i] == 0){
                    ciclos.push_back(dfs(i));
                }
        }

        // aqui eu li todos os pares
        
        // agora para encontrar os ciclos

        // fazer uma 





    }
    return 0;
}


