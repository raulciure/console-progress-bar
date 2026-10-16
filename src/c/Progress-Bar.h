#define PROGRESS_CHARACTER "█"
#define BAR_MARGIN "│"
// #define PROGRESS_CHARACTER "\xE2\x96\x88"
#define SPACE_CHARACTER " "
#define BAR_WIDTH 50

/// @brief Prints the auxiliary elements on the lines above the progress bar.
/// @param message The message to be shown.
void printAboveBar(char* message);

/// @brief Prints the auxiliary elements on the lines below the progress bar.
/// @param message The message to be shown.
void printBelowBar(char* message);

/// @brief Prints the given progress on the progress bar.
/// @param progress Integer representing current progress. Must be in range [0 - 100].
void printProgress(int progress);

/// @brief Function that sets Windows console to UTF-8 charset, if running on Windows OS, and setting a flag so that it only runs once.
void setWindowsOutputMode();