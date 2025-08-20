
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Define the function f(x)
double f(double x) {
    // Example: f(x) = x^3 - x - 2
    return x*x*x - x - 2;
}

int main() {
    double a, b, c, tol;
    int maxIter;

    // User input
    cout << "Enter the interval [a, b]: ";
    cin >> a >> b;

    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval. f(a) and f(b) must have opposite signs.\n";
        return 1;
    }

    cout << "Enter the tolerance: ";
    cin >> tol;

    cout << "Enter the maximum number of iterations: ";
    cin >> maxIter;

    int iter = 0;
    cout << fixed << setprecision(6);
    cout << "\nIteration\t a\t\t b\t\t c\t\t f(c)\n";

    // Regula Falsi loop
    while (iter < maxIter) {
        // Regula Falsi formula
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        cout << iter + 1 << "\t\t " << a << "\t " << b << "\t " << c << "\t " << f(c) << endl;

        // Check convergence
        if (fabs(f(c)) < tol) {
            break;
        }

        // Update interval
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        iter++;
    }

    cout << "\nApproximate root = " << c << endl;
    return 0;
}
