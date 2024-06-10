#include <bits/stdc++.h>
#include <cmath>

using namespace std;

struct pilots
{
    int id;
    int points;
};
struct gps
{
    pilots* pos[100];
};


int func(pilots a, pilots b);

int main(void){
    int g, p;
    cin >> g >> p;

    while(g != 0 and p != 0){
        pilots pilot[p];
        for(int i = 0; i < p; i++){
            pilot[i].id = (i+1);
            pilot[i].points = 0;
        }

        gps gp[g];
        for(int i = 0; i < g; i++){
            for(int j = 0; j < p; j++){
                int colocacao;
                cin >> colocacao;
                gp[i].pos[colocacao-1] = &pilot[j];
            }
        }

        int s;
        cin >> s;
        for(int i = 0; i < s; i++){
            int k;
            cin >> k;

            int pontuacao[k];
            for(int j = 0; j < k; j++){
                cin >> pontuacao[j];
            }

            for(int j = 0; j < g; j++){
                for(int n = 0; n < k; n++){
                    gp[j].pos[n]->points += pontuacao[n];
                }
            }
            sort(pilot, pilot+p, func);

            int max_points = pilot[0].points;
            for(int j = 0; pilot[j].points == max_points; j++){
                cout << pilot[j].id << " ";
            }
            cout << endl;
            for(int j = 0; j < p; j++){
                pilot[j].id = j+1;
                pilot[j].points = 0;
            }
        }
        cin >> g >> p;
    }
    



    return 0;
}







int func(pilots a, pilots b){
    if(a.points != b.points){
        return a.points > b.points;
    }
    return a.id < b.id;
}