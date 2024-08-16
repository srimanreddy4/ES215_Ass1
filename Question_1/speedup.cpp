#include <iostream> 
#include <vector>
#include <ctime>
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

long long fib_rec(int n) {
    if(n==0) return 0;
    else if(n==1) return 1;
    else {
        return fib_rec(n-1)+fib_rec(n-2);
    }
}

void fib_loop(int n) {
    long long prev2 = 0, prev1 = 1, c;
    for (int i = 0; i < n; i++) {
        cout << prev2 << " ";
        c = prev2 + prev1;
        prev2 = prev1;
        prev1 = c;
    }
    cout << endl;
}

long long fib_rec_memo(int n, vector<long long>& memo) {
    if(memo[n]!=-1) {
        return memo[n];
    }
    if(n<=1) {
        return n;
    }
    memo[n] = fib_rec_memo(n-1,memo)+fib_rec_memo(n-2,memo);
    return memo[n];

}

void fib_loop_memo(int n) {
    vector<long long> store(n);
    store[0]=0;
    store[1]=1;
    for(int i=2;i<=n;i++) {
        store[i]=store[i-1]+store[i-2];
    }
}

int main(){
   
    auto start = high_resolution_clock::now();
    cout << "Fibonacci using Recursion: ";
    for (int i = 0; i < 50; i++) {
        cout << fib_rec(i) << " ";
    }
    cout << endl;
    auto stop = high_resolution_clock::now();
    auto duration_recursion = duration_cast<nanoseconds>(stop - start);
    cout << "Time taken by Recursion: " << duration_recursion.count() * 1e-9 << " seconds" << endl << endl;

    start = high_resolution_clock::now();
    cout << "Fibonacci using Loop: ";
    fib_loop(50);
    stop = high_resolution_clock::now();
    auto duration_loop = duration_cast<nanoseconds>(stop - start);
    cout << "Time taken by Loop: " << duration_loop.count() * 1e-9 << " seconds" << endl << endl;

    
    vector<long long> memo(50, -1);
    start = high_resolution_clock::now();
    cout << "Fibonacci using Recursion with Memoization: ";
    for (int i = 0; i < 50; i++) {
        cout << fib_rec_memo(i, memo) << " ";
    }
    cout << endl;
    stop = high_resolution_clock::now();
    auto duration_memo_recursion = duration_cast<nanoseconds>(stop - start);
    cout << "Time taken by Recursion with Memoization: " << duration_memo_recursion.count() * 1e-9 << " seconds" << endl << endl;


    start = high_resolution_clock::now();
    cout << "Fibonacci using Loop with Memoization: ";
    fib_loop_memo(50);
    stop = high_resolution_clock::now();
    auto duration_memo_loop = duration_cast<nanoseconds>(stop - start);
    cout << "Time taken by Loop with Memoization: " << duration_memo_loop.count() * 1e-9 << " seconds" << endl << endl;


    cout << "Speedup of Loop over Recursion: " << duration_recursion.count() / duration_loop.count() << "x" << endl;
    cout << "Speedup of Recursion with Memoization over Recursion: " << duration_recursion.count() / duration_memo_recursion.count() << "x" << endl;
    cout << "Speedup of Loop with Memoization over Recursion: " << duration_recursion.count() / duration_memo_loop.count() << "x" << endl;
 

    
    return 0;
}