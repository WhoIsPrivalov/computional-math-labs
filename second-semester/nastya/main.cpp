#include <iostream>
#include "matrix-master/dist/matrix.h"
#include "matrix-master/dist/matrix.cpp"
#include <cmath>
#include <sys/time.h>
#include <time.h>

#define NS_IN_S  1E9

//Demention of matrix
#define N 4
//Sample matrix 3x3
/*
4x4:
0.68
0.05
-0.11
0.08
2.15
-0.11
0.84
0.28
0.06
-0.83
-0.08
0.15
1
-0.12
1.16
0.21
-0.13
0.27
1
0.44
 ---------------------
10
-1
2
0
6
-1
11
-1
3
25
2
-1
10
-1
-11
0
3
-1
8
15
-----------------------
Answer: x1= 3.57144
x2= -0.957051
x3= 1.48894
x4= -0.836499
*/
/*
9.2
2.5
-3.7
-17.5
0.9
9.0
0.2
4.4
4.5
-1.6
-10.3
-22.1
 */
// Instert matrix
void insert_matrix(Matrix A);
// Fill up matrix
void fill_up_matrix(Matrix A);
// Normalization ||x||(infinity) = max(|xi|) by i
struct timespec start, stop, duration;
double norm_inf(Matrix vector_plus, Matrix vector);


int main() {
    //Source matrix
    Matrix A(N, N + 1);

//Matrix for iteration x(i) = b - x1 - x2 - ... - x(i-1) - x(i+1) - ... - x(n)

    Matrix A_k_iter(N, N + 1);

// K-s iteration

    Matrix K(N, 1);

// K+1-s iteration

    Matrix K_plus(N, 1);

//Iteration parametr

    double tetta = 1.4;

// zero or one vectors when K=0

    bool init;

//epsilon :)

    double epsilon;

//Number of iteration

    int iteration = 0;
    //A size is 4x5(5 is vector b)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + 1; j++) {
            std::cout << "A[" << i + 1 << "][" << j + 1 << "]: ";
            std::cin >> A(i, j);
        }
    }

//Input tetta and initialization iteration matrix

    std::cout << "Input tetta(iter parametr): ";

    std::cin >> tetta;

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N + 1; j++) {

            if(j == N) {
                A_k_iter(i, j) = ((A(i, j)) / A(i, i)) * tetta;
            } else {

                A_k_iter(i, j) = ((-1)*(A(i, j) / A(i, i))) * tetta;
            }

            if (i == j) {

                A_k_iter(i, j) = (1 - tetta) * (A(i, j) / A(i, i));

            }

        }

    }

//Input epsilon

    std::cout << "Input Epsilon: ";

    std::cin >> epsilon;

// K=0 vectors

    std::cout << "Input initial approximation(1 if (1,1,...,1), 0 if (0,0,...,0)): ";

    std::cin >> init;

    if (init == 0) {

        for (int i = 0; i < N; i++) {

            K(i, 0) = 0;

            K_plus(i, 0) = 0;

        }

    } else {

        for (int i = 0; i < N; i++) {

            K(i, 0) = 1;

            K_plus(i, 0) = 0;

        }
    }

//first iteration

    for(int l = 0; l < N; l++){

        for(int m = 0; m < N; m++) {

            K_plus(l, 0) += (A_k_iter(l, m) * K(m, 0));

        }

        K_plus(l, 0) += A_k_iter(l, N);

    }

    std::cout << A_k_iter;

    std::cout << "===================================\n";

    std::cout << "N = " << iteration << std::endl;

    std::cout << "k:\n" << K << std::endl;

    std::cout << "k+1:\n"<<K_plus << std::endl;

// while ||x^(K+1) - x^(k)||(inf) > epsilon do:
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    while(norm_inf(K_plus, K) > epsilon){

// last iteration now iteration

        K = K_plus;

//clear K_plus

        for(int i = 0; i < N; i++){

            K_plus(i, 0) = 0;

        }

// Iterate

        for(int l = 0; l < N; l++){

            for(int m = 0; m < N; m++) {

                K_plus(l, 0) += (A_k_iter(l, m) * K(m, 0));

            }

            K_plus(l, 0) += A_k_iter(l, N);

        }

        iteration++;

        std::cout << "===================================\n";

        std::cout << "N = " << iteration << std::endl;

        std::cout << "k:\n" << K << std::endl;

        std::cout << "k+1:\n"<<K_plus << std::endl;

    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
    if ((stop.tv_nsec - start.tv_nsec) < 0)
    {
        duration.tv_sec = stop.tv_sec - start.tv_sec - 1;
        duration.tv_nsec = NS_IN_S + stop.tv_nsec - start.tv_nsec;
    }
    else
    {
        duration.tv_sec = stop.tv_sec - start.tv_sec;
        duration.tv_nsec = stop.tv_nsec - start.tv_nsec;
    }
    double result = duration.tv_sec + duration.tv_nsec / NS_IN_S;
    std::cout << "TIME: " << result;
    return 0;

}

void insert_matrix(Matrix A){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + 1; j++) {
            std::cout << "A[" << i + 1 << "][" << j + 1 << "]: ";
            std::cin >> A(i, j);
        }
    }
}

double norm_inf(Matrix vector_plus, Matrix vector){

    double max = 0;

    Matrix difference(N,1);

// Find x^(k+1) - x^(k) (k-s iteration)

    for(int i = 0; i < N; i++){

        difference(i,0) = vector_plus(i, 0) - vector(i, 0);

    }

    std::cout << "difference:\n" << difference;

//find max element of normal

    max = std::abs(difference(0,0));

    for(int i = 0; i < N; i++){

        if(max < std::abs(difference(i, 0))){

            max = std::abs(difference(i, 0));

        }

    }

    return max;

}
