#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double f(double x) {
    
    return x*x*x - x - 2;
}

int main() {
    double a, b, tol;
    int maxIter;

    
    cout << "Enter the interval [a, b]: ";
    cin >> a >> b;

    
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval. f(a) and f(b) must have opposite signs." << endl;
        return 1;
    }

    cout << "Enter the tolerance: ";
    cin >> tol;

    cout << "Enter the maximum number of iterations: ";
    cin >> maxIter;

    double c;
    int iter = 0;

    cout << fixed << setprecision(6);
    cout << "\nIteration\t a\t\t b\t\t c\t\t f(c)\n";

    
    while ((b - a) >= tol && iter < maxIter) {
        c = (a + b) / 2;
        cout << iter + 1 << "\t\t " << a << "\t " << b << "\t " << c << "\t " << f(c) << endl;

        if (f(c) == 0.0) {
            break; 
        } else if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }

        iter++;
    }

    cout << "\nApproximate root = " << c << endl;
    return 0;
}

