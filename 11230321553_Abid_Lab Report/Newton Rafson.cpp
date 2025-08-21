
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


double f(double x) {
    
    return x*x*x - x - 2;
}


double df(double x) {
    
    return 3*x*x - 1;
}

int main() {
    double x0, x1, tol;
    int maxIter;
    cout << "Enter the initial guess (x0): ";
    cin >> x0;

    cout << "Enter the tolerance: ";
    cin >> tol;

    cout << "Enter the maximum number of iterations: ";
    cin >> maxIter;

    int iter = 0;
    cout << fixed << setprecision(6);
    cout << "\nIteration\t x0\t\t f(x0)\t\t f'(x0)\t\t x1\n";

    while (iter < maxIter) {
        double f_x0 = f(x0);
        double df_x0 = df(x0);

        
        if (df_x0 == 0) {
            cout << "Derivative is zero. Method fails." << endl;
            return 1;
        }

        x1 = x0 - f_x0 / df_x0;

    
        cout << iter + 1 << "\t\t " << x0 << "\t " << f_x0 << "\t " << df_x0 << "\t " << x1 << endl;

        
        if (fabs(x1 - x0) < tol) {
            break;
        }

        x0 = x1;
        iter++;
    }

    cout << "\nApproximate root = " << x1 << endl;
    return 0;
}

