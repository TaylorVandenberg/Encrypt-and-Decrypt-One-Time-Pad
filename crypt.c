#include "crypt.h"
#include <stdio.h>
#include <stdlib.h>

void nuclearSecrets(char sourceFile[], char destinationFile[], char padFile[]){
    //buffer is 4096
    char srcBuffer[4096];
    char padBuffer[4096];

    FILE*src = fopen(sourceFile, "rb");
    FILE*otp = fopen(padFile, "rb");
    FILE*dst = fopen(destinationFile, "wb");

    int position;
    while (position = fread(srcBuffer, 1, 4096, src)){
        fread(padBuffer, 1, 4096, otp);
        for(int i = 0; i < sizeof(srcBuffer); i++){
            srcBuffer[i] ^= padBuffer[i];
        }
        fwrite(srcBuffer, 1, position, dst);
    }
}