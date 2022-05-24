#include <stdio.h>

int factorial(int n){

    // Base case
    if(n == 0){

        return 1;
    }

    return n * factorial(n - 1);
}

// factorial 5 = 5 * factorial 4
// factorial 4 = 4 * factorial 3
// ...
// factorial 0 = 1


int main(){

    // Factorial
    // 5! -> 5 * 4 * 3 * 2 * 1

    // 0! -> 1

    int n = 5;
    
    int factorial = 1;
    for(int i = 1; i <= n; i++){

        factorial *= i;
    }

    printf("%d\n", factorial);

    return 0;
}