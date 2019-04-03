#include <iostream>
#include "var.h"

using namespace std;

int main()
{
    cout << "Simulated Annealing" << endl<<endl;
    srand(time(NULL));
    int j;
    double n1, n2, r, curr_state, far_best, new_state, delta, p, x1min, x2min;
    const double e = 2.71828182845904523536;
    double alpha = 0.99999;
    double Tawal = 100000;
    double Takhir = 0.0000000001;
    for (int i=0; i<20; i++){
    n1 = fRand(-1,1);
    n2 = fRand(-1,1);
    curr_state = fungsi(n1, n2);
    cout<<n1<<" "<<n2<<" "<<curr_state<<endl;
    far_best = curr_state;
        while (Tawal>Takhir) {
            n1 = fRand(-1,1);
            n2 = fRand(-1,1);
            //cout<<n1<<" "<<n2<<endl;
            new_state = fungsi(n1, n2);
            delta = curr_state - new_state;
            if (delta > 0) { //solusi lebih baik
                curr_state = new_state;
                far_best = new_state;
                x1min = n1;
                x2min = n2;
                j++;
            } else {
                r = fRand(0,1);
                p = exp ( (-1*delta) / Tawal);
                if (p > r) {
                    curr_state = new_state;
                    far_best = new_state;
                    x1min = n1;
                    x2min = n2;
                    j++;
                }
            }
            if (j%5 == 0){
                Tawal = Tawal*alpha;
            }

        }
        cout<<"Suhu terakhir adalah "<<Tawal<<endl;
        cout<<"Nilai minimum adalah "<<far_best<<endl;
        cout<<"Nilai x1 dan x2 yang memenuhi nilai minimum adalah x1 = "<<x1min<<" x2 = "<<x2min<<endl<<endl;
    }
    return 0;
}
