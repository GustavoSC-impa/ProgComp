#include <bits/stdc++.h>
using namespace std;    
#define ll long long
 
int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    int t; cin >> t;
 
    while (t--){

        int n; cin >> n;

        vector< pair<int,int> > S ( 3001, {0,0});

        vector<int> adj[n+1]; // isso vai guardar as arestas

        for ( int i = 1; i <= n; i++){
            ll a, b; cin >> a >> b;
            S[i] = {a, b};

            adj[a].push_back(b);
            adj[b].push_back(a);

        }

        vector<int> S_linhas ( 3001, false), tinta (7000, false);

        vector<int> v ( 7000, 0); // visitados com int

        int ans = 0;

        for ( int i = 1; i <= n; i++){
            // cada par

            bool add = false;

            for ( int idx = S[i].first; idx <= S[i].second; idx++){
                // vai percorrer a área do par

                if ( tinta[idx] == false){
                    tinta[idx] = true;
                    add = true;
                } // se o par aumentar a área pintada, então checa se ele fecha um ciclo

                int nodes = 0, edges = 0;

                
            
            }

            if ( add) ans++;
            S_linhas[i] = add;
        }



        //cout << "////// ";

        cout << ans << '\n';
        for ( int i = 1; i <= n; i++){
            if ( S_linhas[i]) cout << i << ' ';
        } cout << '\n';



    }
    return 0;
}


