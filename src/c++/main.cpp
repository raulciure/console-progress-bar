#include "Progress-Bar.h"
#include <unistd.h>
#include <stdio.h>

int main()
{
    printf("Test of the progress bar below:\n");

    ProgressBar bar = ProgressBar();
    bar.setAboveBarMessage("Loading...\nPlease stand by...");
    bar.setBelowBarMessage("Process complete!\nThank you for your patience!");

    bar.start();
    for(int i = 0; i <= 100; i+=2)
    {
        bar.printProgress(i);
        sleep(1);
    }
    bar.finish();

    return 0;
}
