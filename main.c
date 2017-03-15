/* --------------------------- */
// Vince van Noort & Quentin Hoogwerf
// Miniproject CEOS
/* --------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>
#include "setupwpi.h"
#include "reaction.h"

// Colors
#define ANSI_COLOR_RED     "\033[1m\x1b[31m"
#define ANSI_COLOR_GREEN   "\033[1m\x1b[32m"
#define ANSI_COLOR_YELLOW  "\033[1m\x1b[33m"
#define ANSI_COLOR_BLUE    "\033[1m\x1b[34m"
#define ANSI_COLOR_MAGENTA "\033[1m\x1b[35m"
#define ANSI_COLOR_CYAN    "\033[1m\x1b[36m"
#define ANSI_COLOR_RESET   "\033[1m\x1b[0m"

int main(void) {
    for (int i = 0; i < 10; ++i) {

        // 1. Er wordt game gestart
        setupPins();

        // 2. Random tijd wachten voordat de game echt start
        srand(time(NULL));
        int random = rand() % 500 + 1;
        printf("TIJDELIJK: wachten voor %d milliseconden.\n", random * 10);

        // 3. In tussentijd kijken voor valse start
        int falseStart = checkForButtonInput(random, false);
        if (falseStart) {
            printf("Valse start: %d \n", checkForButtonInput(random, false));
            return 0;
        }

        // 4. Game starten en timer beginnnen (lichtjes of buzzer aanzetten)
        struct timeval start, stop;
        double secs = 0;

        gettimeofday(&start, NULL);
        printf("Winner: " ANSI_COLOR_GREEN "player %d." ANSI_COLOR_RESET "\n", checkForButtonInput(500, true));
        gettimeofday(&stop, NULL);

        secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
        printf("time taken %f\n",secs);

        // 5. Save highscores
        // FILE *highscorefile = fopen("highscore.txt", "r");

    }


    return 0;
}