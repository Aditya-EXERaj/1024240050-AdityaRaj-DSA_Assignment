/*6) Write a program to implement the following operations on a Sparse Matrix, 
assuming the matrix is represented using a triplet. 
(a) Transpose of a matrix. 
(b) Addition of two matrices. 
(c) Multiplication of two matrices.*/
#include <iostream>
using namespace std;

int main() {
    int rows, cols, terms;
    cout << "Enter rows, columns, number of non-zero terms of first matrix: ";
    cin >> rows >> cols >> terms;

    int a[100][3]; 
    cout << "Enter row, column, value for each non-zero term:\n";
    for (int i = 0; i < terms; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Display Matrix (triplet form)\n";
        cout << "2. Transpose\n";
        cout << "3. Addition\n";
        cout << "4. Multiplication\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Row  Col  Val\n";
            for (int i = 0; i < terms; i++) {
                cout << a[i][0] << "  " << a[i][1] << "  " << a[i][2] << endl;
            }
        }

        else if (choice == 2) {
            cout << "Transpose (triplet form):\n";
            cout << "Row  Col  Val\n";
            for (int c = 0; c < cols; c++) {
                for (int i = 0; i < terms; i++) {
                    if (a[i][1] == c) {
                        cout << a[i][1] << "  " << a[i][0] << "  " << a[i][2] << endl;
                    }
                }
            }
        }

        else if (choice == 3) {
            int rows2, cols2, terms2;
            cout << "Enter rows, columns, number of non-zero terms of second matrix: ";
            cin >> rows2 >> cols2 >> terms2;

            int b[100][3];
            cout << "Enter row, column, value for each non-zero term:\n";
            for (int i = 0; i < terms2; i++) {
                cin >> b[i][0] >> b[i][1] >> b[i][2];
            }

            if (rows != rows2 || cols != cols2) {
                cout << "Addition not possible\n";
            } else {
                cout << "Result of addition (triplet form):\n";
                cout << "Row  Col  Val\n";
                int i = 0, j = 0;
                while (i < terms && j < terms2) {
                    if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
                        cout << a[i][0] << "    " << a[i][1] << "    " << a[i][2] << endl;
                        i++;
                    }
                    else if (b[j][0] < a[i][0] || (b[j][0] == a[i][0] && b[j][1] < a[i][1])) {
                        cout << b[j][0] << "  " << b[j][1] << "  " << b[j][2] << endl;
                        j++;
                    }
                    else {
                        int sum = a[i][2] + b[j][2];
                        if (sum != 0)
                            cout << a[i][0] << "  " << a[i][1] << "  " << sum << endl;
                        i++; j++;
                    }
                }
                while (i < terms) {
                    cout << a[i][0] << "    " << a[i][1] << "    " << a[i][2] << endl;
                    i++;
                }
                while (j < terms2) {
                    cout << b[j][0] << "    " << b[j][1] << "    " << b[j][2] << endl;
                    j++;
                }
            }
        }

        else if (choice == 4) {
            int rows2, cols2, terms2;
            cout << "Enter rows, columns, number of non-zero terms of second matrix: ";
            cin >> rows2 >> cols2 >> terms2;

            int b[100][3];
            cout << "Enter row, column, value for each non-zero term:\n";
            for (int i = 0; i < terms2; i++) {
                cin >> b[i][0] >> b[i][1] >> b[i][2];
            }

            if (cols != rows2) {
                cout << "Multiplication not possible\n";
            } else {
                cout << "Result of multiplication (triplet form):\n";
                cout << "Row  Col  Val\n";
                // multiply a(rows x cols) * b(rows2 x cols2)
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols2; j++) {
                        int sum = 0;
                        for (int p = 0; p < terms; p++) {
                            if (a[p][0] == i) {
                                for (int q = 0; q < terms2; q++) {
                                    if (b[q][0] == a[p][1] && b[q][1] == j) {
                                        sum += a[p][2] * b[q][2];
                                    }
                                }
                            }
                        }
                        if (sum != 0) {
                            cout << i << "    " << j << "    " << sum << endl;
                        }
                    }
                }
            }
        }

        else if (choice == 5) {
            cout << "Exiting...\n";
        }

        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
