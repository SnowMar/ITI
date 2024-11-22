#define TERMINATOR '\0'

int nagyStringeLen(char str[]){

    unsigned int i =0;
    while(str[i] != TERMINATOR){
        i++;
    }
    return i;
}

void nagyStringecon(char str[]){

    unsigned int i =0;
    while(str[i] != TERMINATOR){
        i++;
    }
    return i;
    printf(i);
}


void nagyStringCopy(char dest[], const char source[], int size) {
    int i = 0;

    if (nagyStringeLen(source) <= size - 1) {

        while (source[i] != TERMINATOR) {
            dest[i] = source[i];
            i++;
        }

        dest[i] = TERMINATOR;
    } else {
        printf("Error: Source string exceeds destination size.\n");
    }
}
