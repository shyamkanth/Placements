#include <iostream>
using namespace std;

int main() {
    int A[] = {54, 7, 986, 3, 45, 2, 55};
    int B[] = {7,12,99,77,5};
    int A_prime[] = {55,2,45,3,986,7,54};
    int B_prime[] = {12, 89, 99, 77, 5};
    int C[12];

    int nA = sizeof(A) / sizeof(A[0]);
    int nB_prime = sizeof(B_prime) / sizeof(B_prime[0]);

    for (int i = 0; i < nA; i++) {
        C[i] = A[i];
    }

    for (int i = 0; i < nB_prime; i++) {
        C[nA + i] = B_prime[i];
    }

    int nC = nA + nB_prime;

    cout << "C = {";
    for (int i = 0; i < nC; i++) {
        cout << C[i];
        if (i < nC - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;

    return 0;
}
