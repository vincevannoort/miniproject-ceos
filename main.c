/* --------------------------- */
// Vince van Noort & Quentin Hoogwerf
// Miniproject CEOS
/* --------------------------- */
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "setupwpi.h"
#include "reaction.h"

int main(void) {
    // 1. Er wordt game gestart
    setupPins();

    // 2. Random tijd wachten voordat de game echt start
    int random = rand() % 5;
    printf("TIJDELIJK: wachten voor %d seconden.\n", random);

    // 3. In tussentijd kijken voor valse start
    printf("Valse start: %d", checkForButtonInput(random, false));

    // 4. Game starten en timer beginnnen (lichtjes of buzzer aanzetten)
    printf("Winner: %d", checkForButtonInput(5, true));

    // 5. Wachten op user input

    // 6. Gemeten tijd & wie gewonnen heeft tonen

    return 0;
}