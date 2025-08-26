#include <iostream>
using namespace std;

int main() {
    int choice, n;
    cout << "Matrix Storage Optimization\n";
    cout << "1. Diagonal Matrix\n";
    cout << "2. Tri-Diagonal Matrix\n";
    cout << "3. Lower Triangular Matrix\n";
    cout << "4. Upper Triangular Matrix\n";
    cout << "5. Symmetric Matrix\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter size of square matrix: ";
    cin >> n;

    int mat[n][n];

    cout << "Enter elements of " << n << "x" << n << " matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    if (choice == 1) {
        // Diagonal
        int diag[n];
        for (int i = 0; i < n; i++) diag[i] = mat[i][i];

        cout << "\nStored 1D array: ";
        for (int i = 0; i < n; i++) cout << diag[i] << " ";

        cout << "\nReconstructed Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) cout << diag[i] << " ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }

    else if (choice == 2) {
        // Tri-diagonal
        int tri[3*n - 2];
        for (int i = 0; i < 3*n - 2; i++) tri[i] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i - j == 0) tri[n-1 + i] = mat[i][j];
                if (i - j == 1) tri[i-1] = mat[i][j];
                if (i - j == -1) tri[2*n - 1 + i] = mat[i][j];
            }
        }

        cout << "\nStored 1D array: ";
        for (int i = 0; i < 3*n - 2; i++) cout << tri[i] << " ";

        cout << "\nReconstructed Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i - j == 0) cout << tri[n-1 + i] << " ";
                else if (i - j == 1) cout << tri[i-1] << " ";
                else if (i - j == -1) cout << tri[2*n - 1 + i] << " ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }

    else if (choice == 3) {
        // Lower triangular
        int lower[n*(n+1)/2], k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= j) {
                    lower[k] = mat[i][j];
                    k++;
                }
            }
        }

        cout << "\nStored 1D array: ";
        for (int i = 0; i < n*(n+1)/2; i++) cout << lower[i] << " ";

        cout << "\nReconstructed Matrix:\n";
        k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= j) cout << lower[k++] << " ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }

    else if (choice == 4) {
        // Upper triangular
        int upper[n*(n+1)/2], k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i <= j) {
                    upper[k] = mat[i][j];
                    k++;
                }
            }
        }

        cout << "\nStored 1D array: ";
        for (int i = 0; i < n*(n+1)/2; i++) cout << upper[i] << " ";

        cout << "\nReconstructed Matrix:\n";
        k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i <= j) cout << upper[k++] << " ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }

    else if (choice == 5) {
        // Symmetric
        int sym[n*(n+1)/2], k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= j) {
                    sym[k] = mat[i][j];
                    k++;
                }
            }
        }

        cout << "\nStored 1D array: ";
        for (int i = 0; i < n*(n+1)/2; i++) cout << sym[i] << " ";

        cout << "\nReconstructed Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= j) {
                    int idx = i*(i+1)/2 + j;
                    cout << sym[idx] << " ";
                } else {
                    int idx = j*(j+1)/2 + i;
                    cout << sym[idx] << " ";
                }
            }
            cout << endl;
        }
    }

    else {
        cout << "Invalid choice!";
    }
}
