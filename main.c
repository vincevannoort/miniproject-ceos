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
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    printf("Winner: %d\n", checkForButtonInput(500, true));
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;
    printf("Took: %f", (double)delta_us);
    // 5. Wachten op user input

    // 6. Gemeten tijd & wie gewonnen heeft tonen

    return 0;
}