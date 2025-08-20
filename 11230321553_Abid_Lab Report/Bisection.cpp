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
    double a, b, tol;
    int maxIter;

    // Input
    cout << "Enter the interval [a, b]: ";
    cin >> a >> b;

    // Check if f(a) and f(b) have opposite signs
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

    // Bisection method loop
    while ((b - a) >= tol && iter < maxIter) {
        c = (a + b) / 2;
        cout << iter + 1 << "\t\t " << a << "\t " << b << "\t " << c << "\t " << f(c) << endl;

        if (f(c) == 0.0) {
            break;  // Found exact root
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
