#include <bits/stdc++.h>
using namespace std;    
#define ll long long
 
int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    int t; cin >> t;
 
    while (t--){

        int n; cin >> n;

        vector<int> core (n+1, 0);
        
        int zero = 0, one = 0, score = 0;
        for ( int i = 0; i < n; i++) {
            cin >> core[i];
            if ( core[i] == 0) zero++;
            score+= core[i];
        }

        score+= zero;

        cout << score << '\n';


    }
    return 0;
}


