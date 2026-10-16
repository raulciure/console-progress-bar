#define PROGRESS_CHARACTER "█"
#define BAR_MARGIN "│"
#define SPACE_CHARACTER " "
#define BAR_WIDTH 50

class ProgressBar
{
    private:
        char* progress_char;
        char* bar_margin;
        char* space_char;
        int bar_width;
        bool is_windows;

        char* above_bar_message;
        char* below_bar_message;
        
        void printAboveBar();
        void printBelowBar();
    public:
        ProgressBar(char* progress_char = PROGRESS_CHARACTER, char* bar_margin = BAR_MARGIN, 
                    char* space_char = SPACE_CHARACTER, int bar_width = BAR_WIDTH, 
                    char* above_bar_message = "", char* below_bar_message = "");
        void printProgress(int progress);
        void start();
        void finish();

        void setAboveBarMessage(char* message);
        void setBelowBarMessage(char* message);
};
