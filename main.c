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
    int random = rand() % 500;
    printf("TIJDELIJK: wachten voor %d milliseconden.\n", random);

    // 3. In tussentijd kijken voor valse start
    printf("Valse start: %d \n", checkForButtonInput(random, false));

    // 4. Game starten en timer beginnnen (lichtjes of buzzer aanzetten)
    printf("Winner: %d\n", checkForButtonInput(500, true));

    // 5. Wachten op user input

    // 6. Gemeten tijd & wie gewonnen heeft tonen

    return 0;
}