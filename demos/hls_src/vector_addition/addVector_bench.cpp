#include <iostream>
#include <cstdlib>
#include <ctime>

// Function proptopype
void add_vector(int A[4], int B[4], int C[4]);

// Add vector function - Software
void add_vector_sw(int A[4], int B[4], int C[4]) {
    for (int i = 0; i < 4; i++) {
        C[i] = A[i] + B[i];
    }
}

int main() {
    int A[4], B[4], C_hw[4], C_sw[4];

    // Init array with random values
    srand(time(NULL));
    for (int i = 0; i < 4; i++) {
        A[i] = rand() % 100;
        std::cout << "A [" << i << "]: " << A[i] << std::endl;
        B[i] = rand() % 100;
        std::cout << "B[" << i << "]: " << B[i] << std::endl;
    }


    // // Call to the add_vector function - Hardware
    add_vector(A, B, C_hw);

    // Call to the add_vector_sw function - Software
    add_vector_sw(A, B, C_sw);



    // Verification
    bool pass = true;
    for (int i = 0; i < 4; i++) {
        std::cout << "Result hardware C_hw[i]: " <<  C_hw[i] << std::endl;
        std::cout << "Result software C_sw[i]: " << C_sw[i] << std::endl;
        if (C_hw[i] != C_sw[i]) {
            std::cout << "Mismatch at index " << i << ": ";
            std::cout << "HW = " << C_hw[i] << ", SW = " << C_sw[i] << std::endl;
            pass = false;
        }
    }

    if (pass)
        std::cout << "Test PASSED!" << std::endl;
    else
        std::cout << "Test FAILED!" << std::endl;

    return pass ? 0 : 1;
}

