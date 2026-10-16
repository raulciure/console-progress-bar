#include "Progress-Bar.h"
#include <unistd.h>
#include <stdio.h>

int main()
{
    printf("Test of the progress bar below:\n");

    printAboveBar("Loading...\nPlease stand by...");

    for(int i = 0; i <= 100; i+=10)
    {
        printProgress(i);
        sleep(1);
    }

    printBelowBar("Process complete!\nThank you for your patience!");

    return 0;
}