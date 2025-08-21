
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


double f(double x) {

    return x*x*x - x - 2;
}

int main() {
    double x0, x1, x2, tol;
    int maxIter;

    
    cout << "Enter the first guess (x0): ";
    cin >> x0;
    cout << "Enter the second guess (x1): ";
    cin >> x1;
    cout << "Enter the tolerance: ";
    cin >> tol;
    cout << "Enter the maximum number of iterations: ";
    cin >> maxIter;

    cout << fixed << setprecision(6);
    cout << "\nIteration\t x0\t\t x1\t\t x2\t\t f(x2)\n";

    int iter = 0;
    while (iter < maxIter) {
        
        if (f(x1) - f(x0) == 0) {
            cout << "Division by zero error in iteration " << iter + 1 << ".\n";
            break;
        }


        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));

        
        cout << iter + 1 << "\t\t " << x0 << "\t " << x1 << "\t " << x2 << "\t " << f(x2) << endl;

    
        if (fabs(x2 - x1) < tol) {
            break;
        }


        x0 = x1;
        x1 = x2;
        iter++;
    }

    cout << "\nApproximate root = " << x2 << endl;
    return 0;
}

