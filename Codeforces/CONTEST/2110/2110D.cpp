#include <bits/stdc++.h>
using namespace std;    
#define ll long long
 
int main(){
 
    int t; cin >> t;
 
    while (t--){
        ll n, m, soma = 0; cin >> n >> m;

        vector<pair<ll,ll>> adj[n+2];
        vector<ll> pilha (n+2, 0);

        for ( ll i = 1; i <= n; i++) cin >> pilha[i];

        for ( int i = 0; i < m; i++){
            ll a, b, w; cin >> a >> b >> w;
            soma +=w;
            adj[a].push_back({b, w});
        }

        ll a = 1, b = soma+1, idx = 0;

        while ( a < b){
            vector<ll> charge (n+2, 0);
            ll mid = (a + b)/2;
            // agora fazer a bfs ver se dá pra bater mid

            charge[1] = min(mid, pilha[1]);

            for ( int i = 1; i<=n; i++){

                for ( pair<ll,ll> p : adj[i]){ // para cada aresta
                    ll z = p.first, w = p.second;
                    if ( charge[i] >= w ){
                        charge[z] = min(mid, charge[i] + pilha[z]);
                    } 
                }
            }

            if ( charge[n] > 0){
                b = mid;
            } else{
                a = mid + 1;
            }


        }
        //cout << "//// ";
        if (a == soma+1){
            cout << -1 << '\n';
        } else {
            cout << a << '\n';
        }
        

    }
    return 0;
}