/* --------------------------- */
// Vince van Noort & Quentin Hoogwerf
// Miniproject CEOS
/* --------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "setupwpi.h"
#include "reaction.h"

int main(void) {
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
    static struct timeval begin;
    static struct timeval end;

    gettimeofday(&begin, NULL);
    printf("Winner: %d\n", checkForButtonInput(500, true));
    gettimeofday(&end, NULL);

    diff_t = difftime(end_t, start_t);
    printf("Time to press: %f\n", (1000 * (end.tv_sec - begin.tv_sec) + (end.tv_usec - begin.tv_usec) / 1000));

    // 5. Wachten op user input

    // 6. Gemeten tijd & wie gewonnen heeft tonen

    return 0;
}