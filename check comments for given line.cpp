#include <stdio.h>
#include <string.h>
void multi_line_comment_analyzer(char *input) {
    char *start = strstr(input, "/*");
    if (start != NULL) {
        char *end = strstr(start + 2, "*/");
        if (end != NULL) {
            printf("Multi-line comment: %.*s\n", (int)(end - start + 2), start);
        } else {
            printf("Incomplete multi-line comment: %s\n", input);
        }
    } else {
        printf("Not a multi-line comment\n");
    }
}
int main() {
    char input[] = "/* This is a multi-line comment */";
    multi_line_comment_analyzer(input);
    return 0;
}

