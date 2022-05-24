#include <stdio.h>

/*

Review C + CP
    Data Types and Variable Syntax
    Operators
    Repetition
    Selection
    Array
    Recursive
    Sorting
        Merge Sort (Divide and Conquer)
    Searching
        Linear
        Binary
    File
        Read
        Write

Dynamic Programming
    Fibonacci
    Knapsack
    Coin Change
    Travelling Salesman Problem (TSP)

*/


int main(){

    // --- Pre and Post Increment or Decrement --- //
    // int b = 3;
    // int c = b++ + b++;

    // // b++ + b++
    // // 3 + b++
    // // b -> 4
    // // 3 + 4
    // // b -> 5
    // // c -> 7

    // printf("b: %d\n", b);
    // printf("c: %d\n", c);

    int b = 3;
    int c = ++b + b++;
    // ++b  + b++
    // ++b + 3
    // b -> 4
    // b -> 5
    // 5 + 3

    // --- Bitwise Operator --- //

    // Example bit
    // 101 (5)
    // 010 (2)

    // OR (|) [Only one has to be true to be true]
        // F F = F
        // F T = T
        // T F = T
        // T T = T
        // 111 (7)

    // AND (&) (Both has to be true to be true)
        // 100 (1)

    // XOR (^) [Both has to be opposite to be true]
        // 111 (7)

    // NOT (~) [Opposite all]
        // From 5 -> 010 (2)

    // << (Left Shift)
        // 001 (1)
        // 010 (2) (LS once)

    // >> (Right Shift)
        // 100 (4)
        // 010 (2) (RS on)

    printf("%d\n", sizeof(long));


    return 0;
}

