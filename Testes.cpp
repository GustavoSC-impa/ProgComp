#include <bits/stdc++.h>
using namespace std;    
#define ll long long

ll gdc ( ll a, ll b){
    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}
 
 
int main(){
 

    cout << gdc(4, 30);

}