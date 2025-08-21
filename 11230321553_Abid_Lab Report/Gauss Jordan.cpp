
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of variables: ";
    cin >> n;

    double mat[20][21];  

    
    cout << "Enter the augmented matrix (coefficients and constants):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j <= n; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        
        double pivot = mat[i][i];
        if (pivot == 0) {
            cout << "Math Error: Zero pivot encountered." << endl;
            return 1;
        }

        for (int j = 0; j <= n; j++) {
            mat[i][j] /= pivot;
        }

        
        for (int k = 0; k < n; k++) {
            if (k == i) continue;

            double factor = mat[k][i];
            for (int j = 0; j <= n; j++) {
                mat[k][j] -= factor * mat[i][j];
            }
        }
    }

    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(6) << mat[i][n] << endl;
    }

    return 0;
}

