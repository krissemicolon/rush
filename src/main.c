#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    char *prefix;
    char cmd[128];
    char buffer[128];

    if(argc == 1) {
        fprintf(stderr, "Usage: csh <prefix>\n");
        exit(1);
    }

    if(sizeof(argv[1]) > sizeof(char) * 128) {
        fprintf(stderr, "Error: Prefix too big -> set an alias\n");
    } else {prefix = argv[1];}

    for(;;) {
        printf("csh(%s) -> ", prefix);
        #pragma GCC diagnostic ignored "-Wunused-result" 
        fgets(cmd, 128, stdin);
        if(sizeof(cmd) > sizeof(char) * 128) {
            fprintf(stderr, "Error (csh): Command too big (over 128 chars)");
            continue;
        }

        sprintf(buffer, "%s %s", prefix, cmd);
        system(buffer);
    }

    return 0;
}
