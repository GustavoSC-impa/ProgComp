#include <bits/stdc++.h>
using namespace std;    
#define ll long long
#define pll pair<ll,ll>
 
int main(){
 
    int t; cin >> t;
 
    while (t--){
        ll n; cin >> n; 

        vector<pll> core (n+2, {0,0});

        for ( int i = 1; i <= n; i++){
            ll a, b; core[i] = {a, b};
        }

        // eu tenho sons que tem mesmo volume e mesmo campo que podem ser percorridos

        vector<pll> adj[n+2][2];

        map<ll,vector<pll>> volume, campo;

        // usar 0 para volume e 1 para campo
        for ( int i = 1; i <= n; i++){
            ll vol = core[i].first, pit = core[i].second;
            volume[vol].push_back(core[i]);
            campo[pit].push_back(core[i]);
        } // em cada desse vetores, tem todos os caras com mesmo volume ou mesmo campo

        // um cara com certeza faz parte da música, então pode começar em qualquer 1

        // tem 4 opções, do 1, vai para um 
        

    }

    return 0;
}
