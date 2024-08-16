import time

def matrix_multiply(A, B):
    size = len(A)
    C = [[0] * size for _ in range(size)]
    for i in range(size):
        for j in range(size):
            for k in range(size):
                C[i][j] += A[i][k] * B[k][j]
    return C

sizes = [64, 128, 256, 512, 1024]

for size in sizes:
    A = [[1] * size for _ in range(size)]
    B = [[2] * size for _ in range(size)]

    # System time
    start = time.time()
    C = matrix_multiply(A, B)
    end = time.time()
    system_time = end - start
    print(f"System time for {size}x{size} integer matrix multiplication: {system_time:.10f} seconds")

    # CPU time
    start = time.process_time()
    C = matrix_multiply(A, B)
    end = time.process_time()
    cpu_time = end - start
    print(f"CPU time for {size}x{size} integer matrix multiplication: {cpu_time:.10f} seconds")
