#include <bits/stdc++.h>
using namespace std;    
#define ll long long
 
int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    int t; cin >> t;
 
    while (t--){

        int n; cin >> n;

        vector< pair<int,int> > S ( 3001, {0,0});

        //vector<int> adj[2*n+2]; // isso vai guardar as arestas

        for ( int i = 1; i <= n; i++){
            ll a, b; cin >> a >> b;
            S[i] = {a, b};

            //adj[a].push_back(b);
            //adj[b].push_back(a);

        }

        vector<int> S_linhas ( 3010, 0), tinta (7000, 0);

        vector<int> v ( 7000, 0); // visitados com int

        int ans = 0;

        for ( int i = 1; i <= n; i++){
            // cada par

            bool add = false;

            int a = S[i].first, b = S[i].second;

            for ( int idx = a; idx < b; idx++){
                // vai percorrer a área do par

                if ( tinta[idx] == 0){
                    tinta[idx] = 1;
                    add = true;
                } // se o par aumentar a área pintada, então ele não fecha um ciclo
                
            
            }
            
            /*/
            int nodes = 0, edges = 0;
            queue<int> q;
            q.push(a);

            while ( !q.empty()){
                int k = q.front(); q.pop();
                v[k] = i;
                nodes++;

                for ( int viz : adj[k]){
                    if ( v[viz] != i){
                        q.push(viz);
                        edges++;
                    }
                }
            }

            if ( edges >= nodes ) add = false; 

            //*/

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


