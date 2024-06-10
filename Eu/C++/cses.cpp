#include <bits/stdc++.h>
using namespace std;



int main(void){
    int n, m, k; cin >> n >> m >> k;
    vector<int> applicants;
    vector<int> apartaments;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        applicants.push_back(x);
        sort(applicants.begin(), applicants.end());
    }
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        apartaments.push_back(x);
        sort(apartaments.begin(), apartaments.end());
    }



    int count = 0;
    for(int i = 0; i < n and apartaments.size() != 0; i++){
        for(int j = 0; j < m-count; j++){
            if((apartaments[j] >= applicants[i]-k) && (apartaments[j] <= applicants[i]+k)){
                count++;
                // cout << "apartamento:" << apartaments[j] << " aplicante: " << applicants[i] << endl;
                apartaments.erase(apartaments.begin()+j);
                break;
            }
        }
        
    }


    cout << count << endl;
    return 0;
}