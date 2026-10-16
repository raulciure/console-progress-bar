#include "Progress-Bar.h"
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

ProgressBar::ProgressBar(char* progress_char, char* bar_margin, char* space_char, int bar_width, 
                        char* above_bar_message, char* below_bar_message)
{
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        this->is_windows = true;
    #endif

    // Allocate size for class char objects
    this->progress_char = new char[strlen(progress_char) + 1];
    this->bar_margin = new char[strlen(bar_margin) + 1];
    this->space_char = new char[strlen(space_char) + 1];
    this->above_bar_message = new char[strlen(above_bar_message) + 1];
    this->below_bar_message = new char[strlen(below_bar_message) + 1];

    // Set the value of the class attributes from the constructor args
    strcpy(this->progress_char, progress_char);
    strcpy(this->bar_margin, bar_margin);
    strcpy(this->space_char, space_char);
    this->bar_width = bar_width;

    strcpy(this->above_bar_message, above_bar_message);
    strcpy(this->below_bar_message, below_bar_message);
}

void ProgressBar::printAboveBar()
{
    printf("%s\n", this->above_bar_message);
    printf("\n");
}

void ProgressBar::printBelowBar()
{
    printf("\n");
    printf("%s\n", this->below_bar_message);
    printf("\n");
}

void ProgressBar::printProgress(int progress)
{
    int fill, i;

    // Check if progress in within range
    if(!(progress >= 0 && progress <= 100))
    {
        printf("\t*** Progress not within displayable range! ***\n");
        return;
    }

    // Scale bar size based on BAR_WIDTH constant
    fill = (progress * this->bar_width) / 100;

    printf("\r%s", this->bar_margin);
    for(i = 1; i <= fill; ++i)
    {
        printf("%s", this->progress_char);
    }
    for(i = fill + 1; i <= this->bar_width; ++i)
    {
        printf("%s", this->space_char);
    }
    printf("%s\t Progress: %d%%", this->bar_margin, progress);
    fflush(stdout);
}

void ProgressBar::start()
{
    printAboveBar();
}

void ProgressBar::finish()
{
    printBelowBar();
}

void ProgressBar::setAboveBarMessage(char* message)
{
    delete above_bar_message;
    above_bar_message = new char[strlen(message) + 1];
    strcpy(this->above_bar_message, message);
}

void ProgressBar::setBelowBarMessage(char* message)
{
    delete below_bar_message;
    below_bar_message = new char[strlen(message) + 1];
    strcpy(this->below_bar_message, message);
}
