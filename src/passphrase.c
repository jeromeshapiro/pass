#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "crypto/rand.h"

int main() {
    unsigned int rand = rand_uint(1, 1001);
    printf("Hello %i \n", rand);
}

