#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void matrix_multiply(const vector<vector<double>>& A, const vector<vector<double>>& B, vector<vector<double>>& C) {
    int N = A.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0.0;
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    vector<int> sizes = {64, 128, 256, 512, 1024};

    for (int size : sizes) {
        vector<vector<double>> A(size, vector<double>(size, 1.0));
        vector<vector<double>> B(size, vector<double>(size, 2.0));
        vector<vector<double>> C(size, vector<double>(size, 0.0));

        timespec start, end;

        // System time
        clock_gettime(CLOCK_MONOTONIC, &start);
        matrix_multiply(A, B, C);
        clock_gettime(CLOCK_MONOTONIC, &end);
        double system_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        cout << "System time: " << size << "x" << size << " double matrix multiplication: " << system_time << " seconds" << endl;

        // CPU time
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
        matrix_multiply(A, B, C);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
        double cpu_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        cout << "CPU time: " << size << "x" << size << " double matrix multiplication: " << cpu_time << " seconds" << endl;
    }

    return 0;
}
