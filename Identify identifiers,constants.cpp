#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define IDENTIFIER 1
#define CONSTANT 2
#define OPERATOR 3

#define MAX_IDENTIFIER_LENGTH 50
int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '<' || c == '>';
}
int is_delimiter(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}
void lexical_analyzer(char *input) {
    int i = 0;
    int len = strlen(input);
    while (i < len) {
        if (is_delimiter(input[i])) {
            i++;
            continue;
        }
        
        if (input[i] == '/' && i+1 < len && input[i+1] == '/') {
            while (i < len && input[i] != '\n')
                i++;
            continue;
        }
        if (isalpha(input[i])) {
            char identifier[MAX_IDENTIFIER_LENGTH + 1];
            int j = 0;
            while (isalnum(input[i]) && j < MAX_IDENTIFIER_LENGTH) {
                identifier[j++] = input[i++];
            }
            identifier[j] = '\0';
            printf("Identifier: %s\n", identifier);
        }
        else if (isdigit(input[i])) {
            int constant = 0;
            while (isdigit(input[i])) {
                constant = constant * 10 + (input[i++] - '0');
            }
            printf("Constant: %d\n", constant);
        }
        else if (is_operator(input[i])) {
            printf("Operator: %c\n", input[i]);
            i++;
        }

        else {
            printf("Invalid character: %c\n", input[i]);
            i++;
        }
    }
}
int main() {
    char input[] = "int main() {\n    // This is a comment\n    int a = 5;\n    int b = 10;\n    int sum = a + b;\n    return 0;\n}";
    lexical_analyzer(input);
    return 0;
}

