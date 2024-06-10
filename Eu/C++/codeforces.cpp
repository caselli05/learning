#include <bits/stdc++.h>

using namespace std;

int transferir(int maior, int menor, int balde);

int main(void){
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        int a, b, c; cin >> a >> b >> c;
        if(a < b){
            cout << transferir(b, a, c);
        }
        else if(a > b){
            cout << transferir(a, b, c);
        }
        else{
            cout << 0;
        }
    }


    return 0;
}


int transferir(int maior, int menor, int balde){
    if(maior <= menor){
        return 0;
    }
    return (1+transferir((maior-balde), (menor+balde), balde));
}

