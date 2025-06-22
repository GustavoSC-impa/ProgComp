#include <bits/stdc++.h>
using namespace std;    
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int, int>

bool Solve(){

    ll n, k; cin >> n >> k;

    vector<ll> trafic (n+2, 0), delay (n+2, 0);

    for ( int i = 1; i <= n; i++) cin >> trafic[i];
    for ( int i = 1; i <= n; i++) cin >> delay[i];

    vector<pll> core; for ( int i = 1; i <= n; i++) core.push_back({trafic[i], delay[i]});

    sort(core.begin(), core.end());
    
    // aqui tá ordenado por posição
    // basicamente o que eu quero saber é se tem ciclo, se achar um circulo retorna

    ll q; cin >> q;

    for ( int i = 0; i < q; i++){

        // cada querry

        ll pos; cin >> pos;

        // aqui pegou a posição inicial

        // encontrar o primeiro poste que ele tá olhando pra frente

        ll a = 0, b = n, mid = 0;

        while ( a < b){
            mid = (a+b)/2;
            if ( core[mid].first > pos) b = mid - 1;
            if ( core[mid].first < pos) a = mid + 1;
            if ( core[mid].first == pos) {a == mid; break;}
        }

        // a é o primeiro cara com posição maior ou igual

        ll range = core[a].first - pos; // aqui encontra a distancia até o cara

        ll v[n][2];

        for ( ll i = 0; i < n; i++){
            v[i][0] = 0; v[i][1] = 0;
        }

        // um ciclo vai se encontrado em se chegou num cara que já foi visitado
        

    }
    


}
 
int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
 
    while (t--){

        Solve();

    }
    return 0;
}
