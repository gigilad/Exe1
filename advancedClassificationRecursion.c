#include "NumClass.h"

int power(int base, int exponent) {
    int result = 1;
    while (exponent > 0) {
        result *= base;
        exponent--;
    }
    return result;
}

int countDig(int num) {
    if (num == 0) return 0;
    return 1 + countDig(num / 10);
}

int isArmstrongHelper(int num, int numDigits, int originalNum) {
    if (num == 0) {
        return (originalNum == 0);
    } else {
        int digit = num % 10;
        return (power(digit, numDigits) + isArmstrongHelper(num / 10, numDigits, originalNum));
    }
}

int isArmstrong(int num) {
    int numDigits = countDig(num);
    return (isArmstrongHelper(num, numDigits, num) == num);
}


int isPalindromeHelper(int num, int original, int digits) {
    // Base case: if there is only one digit, it's a palindrome
    if (digits <= 1) {
        return 1;
    }

    // Extract the first and last digits
    int firstDigit = num / (power(10, digits - 1));
    int lastDigit = num % 10;

    // Check if the first and last digits are the same
    if (firstDigit != lastDigit) {
        return 0;
    }

    // Remove the first and last digits
    int newNum = (num % (power(10, digits - 1)) / 10);

    // Recursive call with the reduced number
    return isPalindromeHelper(newNum, original, digits - 2);
}

int isPalindrome(int num) {
    if (num < 0) {
        return 0; // Negative numbers are not palindromes
    }

    int digits = countDig(num);
    return isPalindromeHelper(num, num, digits);
}
