
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of variables: ";
    cin >> n;

    double mat[20][21]; // Augmented matrix

    // Input augmented matrix
    cout << "Enter the augmented matrix (coefficients and constants):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j <= n; j++) {
            cin >> mat[i][j];
        }
    }

    // Forward Elimination
    for (int i = 0; i < n - 1; i++) {
        // Check for zero pivot (can be extended to do row swapping)
        if (mat[i][i] == 0) {
            cout << "Math Error: Division by zero (zero pivot)." << endl;
            return 1;
        }

        for (int k = i + 1; k < n; k++) {
            double factor = mat[k][i] / mat[i][i];
            for (int j = 0; j <= n; j++) {
                mat[k][j] -= factor * mat[i][j];
            }
        }
    }

    // Back Substitution
    double x[20];
    for (int i = n - 1; i >= 0; i--) {
        x[i] = mat[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= mat[i][j] * x[j];
        }
        x[i] /= mat[i][i];
    }

    // Output result
    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(6) << x[i] << endl;
    }

    return 0;
}
