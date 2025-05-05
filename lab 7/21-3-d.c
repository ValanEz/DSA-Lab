#include <stdio.h>
#include <string.h>
void processString(char *input, char *output) {
    char stack[100]; 
    int top = -1; 
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '+') {
            if (top >= 0) {
                top--; 
            }
        } else {
            stack[++top] = input[i]; 
        }
    }


    for (int i = 0; i <= top; i++) {
        output[i] = stack[i];
    }
    output[top + 1] = '\0'; 
}

int main() {
    char input[100], output[100];

    printf("Enter the string: ");
    scanf("%s", input);

    processString(input, output);

    printf("Output: %s\n", output);

    return 0;
}
