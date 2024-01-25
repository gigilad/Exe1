#include <stdio.h>
int printAllPrimes(int num1 , int num2){
    printf("The Prime numbers are:");
    while(num2>=num1){
        if(isPrime(num1)){
            printf(" %d", num1  );
        }
            num1++;
    }

printf("\n");
return 0;
}
int printAllArmstrong(int num1,int num2){
    printf("The Armstrong numbers are:");
     while(num2>=num1){
        if(isArmstrong(num1)){
            printf(" %d", num1);
        }
            num1++;
    }

printf("\n");
return 0;
}

int printAllStrongNums(int num1,int num2){
    printf("The Strong numbers are:");
    while(num2>=num1){
        if(isStrong(num1)){
            printf(" %d", num1 );
        }
            num1++;
    }

printf("\n");
return 0;
}

int PrintAllpalindrome(int num1,int num2){
    printf("The Palindromes are:");
       while(num2>=num1){
        if(isPalindrome(num1)){
            printf(" %d", num1 );
        }
            num1++;
    }

printf("\n");
return 0;
}

int main(){
    int num1,num2;
    // printf("Enter 2 numbers with space");
    scanf("%d %d", &num1, &num2);
    int smallerNum,bigerNum;
    if (num1>num2)
    {
        smallerNum=num2;
        bigerNum=num1;
    }else{
        smallerNum=num1;
        bigerNum=num2;
    }
    printAllArmstrong(smallerNum,bigerNum);
    PrintAllpalindrome(smallerNum,bigerNum);
    printAllPrimes(smallerNum,bigerNum);
    printAllStrongNums(smallerNum,bigerNum);


    
    return 0;
}