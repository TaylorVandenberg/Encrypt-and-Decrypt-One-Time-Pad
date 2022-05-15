#include <stdio.h>
#include <stdlib.h>
#include "crypt.h"

int main(){
    printf("Please note, all file names have a 50 character limit.\n");
    
    //getting inputs
    printf("\nEnter the source file: ");
    char sourceFile[50];
    scanf("%s", sourceFile);

    printf("\nEnter the destination file: ");
    char destinationFile[50];
    scanf("%s", destinationFile);

    printf("\nEnter the one-time-pad file: ");
    char padFile[50];
    scanf("%s", padFile);
  
    //checking input files
    FILE*src;
    FILE*otp;
    FILE*dst;
    if((src = fopen(sourceFile, "rb")) == 0){
        printf("\n Could not open the source file!");
    }
    if((otp = fopen(padFile, "rb")) == 0){
        printf("\n Could not open the one-time-pad file!");
    }
  
    nuclearSecrets(sourceFile, destinationFile, padFile);
    printf("\nThank you Kanye, very cool!\n");
    return 0;
}
