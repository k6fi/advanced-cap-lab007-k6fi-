#include "project/recursive_algorithms.h"

#include <stdexcept>
#include <utility>
#include <vector>

// TODO: Implement factorial recursively.
// Base case: n == 0 or n == 1.
// Recursive case: n * factorial(n - 1).
int factorial(int n) {
if (n < 0) {
        throw std::invalid_argument("Negative input not allowed for factorial");
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// TODO: Implement an iterative factorial comparison.
int factorialIterative(int n) {
    if (n <0) {
    throw std::invalid_argument("Negative input not allowed for factorial");
    }
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// TODO: Implement fibonacci recursively.
// Base case: fib(0) = 0, fib(1) = 1.
// Recursive case: fib(n) = fib(n - 1) + fib(n - 2).
int fibonacci(int n) {
    if (n < 0) {
    throw std::invalid_argument("Invalid input, Fibonacci requires n >= 0");
}
    if (n == 0) {
        return 0;
    }   

    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// TODO: Implement iterative fibonacci comparison.
int fibonacciIterative(int n) {
    if (n < 0) {
    throw std::invalid_argument("Invalid input, Fibonacci requires n >= 0");
}
    if (n <= 1) {
        return n;
    }
    int previous = 0;
    int current = 1;
    for (int i = 2; i <= n; ++i) {
        int next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}

int binarySearchHelper(const std::vector<int>& array, int target, int left, int right) {
    if (left > right) {
        return -1; 
    }
    int mid = left + (right - left) / 2;
    if (array[mid] == target) {
        return mid; 
    } else if (array[mid] < target) {
        return binarySearchHelper(array, target, mid + 1, right); 
    } else {
        return binarySearchHelper(array, target, left, mid - 1); 
    }
}

// TODO: Implement recursive binary search on a sorted array.
// Base case: target not found or left > right.
// Recursive case: compare middle element and recurse on the appropriate half.
int binarySearch(const std::vector<int>& array, int target) {
    if (array.empty()) {
        return -1; 
    }
    return binarySearchHelper(array, target, 0, array.size() - 1);
}

// TODO: Implement iterative binary search comparison.
int binarySearchIterative(const std::vector<int>& array, int target) {
    int left = 0;
    int right = array.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == target) {
            return mid; 
        } else if (array[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }

    return -1; 
}

// TODO: Implement recursive array sum.
// Base case: empty array.
// Recursive case: first element + arraySum(rest-of-array).
int arraySum(const std::vector<int>& array) {
    if (array.empty()) {
        return 0; 
    }
    std::vector<int> rest(array.begin() + 1, array.end());
    return array[0] + arraySum(rest);
}

// TODO: Implement iterative array sum comparison.
int arraySumIterative(const std::vector<int>& array) {
    int sum = 0;
    for (int num : array) {
        sum += num; 
    }
    return sum;
}

// TODO: Implement recursive in-place reversal.
// Base case: size <= 1.
// Recursive case: swap first and last elements, then recurse on the remaining middle.
void reverseArray(std::vector<int>& array) {
    if (array.empty()) {
        return; 
    }
    std::size_t left = 0;
    std::size_t right = array.size() - 1;
    while (left < right) {
        std::swap(array[left], array[right]);
        ++left;
        --right;
    }
}
// TODO: Implement iterative reverse comparison.
void reverseArrayIterative(std::vector<int>& array) {
    std::size_t left = 0;
    std::size_t right = array.size() - 1;

    while (left < right) {
        std::swap(array[left], array[right]);
        ++left;
        --right;
    }
}
