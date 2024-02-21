#include <stdio.h>
#include <string.h>
void single_line_comment_analyzer(char *input) {
    if (strncmp(input, "//", 2) == 0) {
        printf("Single-line comment: %s\n", input);
    } else {
        printf("Not a single-line comment\n");
    }
}
int main() {
    char input[] = "// This is a single-line comment";
    single_line_comment_analyzer(input);
    return 0;
}

