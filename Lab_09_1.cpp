#include <iostream>
#include <cmath>
#include <iomanip>
#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;
using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main() {
    cout << "x_p = "; cin >> x_p;
    cout << "x_k = "; cin >> x_k;
    cout << "dx  = "; cin >> dx;
    cout << "e   = "; cin >> e;
    cout << endl;

    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(8) << "x" << " |"
        << setw(13) << "arctg(x)" << " |"
        << setw(13) << "S" << " |"
        << setw(6) << "n" << " |" << endl;
    cout << "-------------------------------------------------" << endl;

    x = x_p;
    while (x <= x_k + dx / 2.0) {   
        if (fabs(x) <= 1.0) {       
            sum();
            cout << "|" << setw(8) << setprecision(2) << fixed << x << " |"
                << setw(13) << setprecision(6) << fixed << atan(x) << " |"
                << setw(13) << setprecision(6) << fixed << s << " |"
                << setw(6) << n << " |" << endl;
        }
        else {
            cout << "|" << setw(8) << setprecision(2) << fixed << x << " |"
                << setw(35) << "Out of domain (|x| <= 1)" << " |" << endl;
        }
        x += dx;
    }
    cout << "-------------------------------------------------" << endl;

    return 0;
}