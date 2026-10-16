#include <stdio.h>
#include "Progress-Bar.h"

#ifdef _WIN32
#include <windows.h>
#endif

int windowsFlag = 0;

void printAboveBar(char* message)
{
    printf("%s\n", message);
    printf("\n");
}

void printBelowBar(char* message)
{
    printf("\n");
    printf("%s\n", message);
    printf("\n");
}

void printProgress(int progress)
{
    int fill, i;

    // Check if progress in within range
    if(!(progress >= 0 && progress <= 100))
    {
        printf("\t*** Progress not within displayable range! ***\n");
        return;
    }

    // Set Windows console to UTF-8 charset, if running on Windows OS, and set a flag in order to run only once
    if(windowsFlag == 0) setWindowsOutputMode();

    // Scale bar size based on BAR_WIDTH constant
    fill = (progress * BAR_WIDTH) / 100;

    printf("\r%s", BAR_MARGIN);
    for(i = 1; i <= fill; ++i)
    {
        printf("%s", PROGRESS_CHARACTER);
    }
    for(i = fill + 1; i <= BAR_WIDTH; ++i)
    {
        printf("%s", SPACE_CHARACTER);
    }
    printf("%s\t Progress: %d%%", BAR_MARGIN, progress);
    fflush(stdout);
}

void setWindowsOutputMode()
{
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    windowsFlag = 1;
}