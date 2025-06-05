#include <bits/stdc++.h>
using namespace std;    
#define ll long long
 
int main(){
 
    int t; cin >> t;
 
    while (t--){

        string core; cin >> core;

        // sequencias grandes de ((())) devem ser ignoradas

        int state = 0; bool find = false;
        string ans = "NO";

        for ( char c : core){

            if ( c == '(' ) state++;
            else state--;
            //cout << state << ' ';
        

            if (state == 0 && find == false) {find = true; continue;}
            if ( state == 0 && find == true) ans = "YES";


        }
        //cout << "\n///// ";
        cout << ans << '\n';

    }
    return 0;
}

