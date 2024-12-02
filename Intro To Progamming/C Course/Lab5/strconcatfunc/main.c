#include <stdio.h>
#include <stdlib.h>
#include "strconcat.h"



int main()
{
    char dest[20];
    char source[]="Mohamed nagyMohamed nagyMohamed nagy";

    nagyStringCopy(dest, source, sizeof(dest));
    printf("After modified: %s\n", dest);
    return 0;
}
