#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX_SIZE 100

int isPalindrome(char* string, int left, int right) {
    int mid = left + (right-left)/2;
    int i = left;
    while (i<=mid) {
        if (string[i] == string[left+right - i]) {
            i++;
        }
        else {
            return 0;
        }
    }
    return 1;
}

char* longestPalindromeSubstring(char* string) {
    const int len = strlen(string); int start = 0; int end = 0;
    for (int i = 0; i<len; i++) {
            for (int j = i; j<len; j++) {
                if (isPalindrome(string, i, j)) {
                    if (j-i>end-start) {
                        start = i; end = j;
                    }
                }
            }
    }
    char* ptr = (char*)malloc((end-start+2)*sizeof(char));
    for (int i = start; i<end+1; i++) {
        ptr[i-start] = string[i];
    }
    return ptr;
}

int main(void){
    char string[MAX_SIZE];
    fgets(string, MAX_SIZE, stdin);
    char* lsp = longestPalindromeSubstring(string);
    printf("%s\n", lsp);
    free(lsp);
    return 0;
}