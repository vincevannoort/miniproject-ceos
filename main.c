/* --------------------------- */
// Vince van Noort & Quentin Hoogwerf
// Miniproject CEOS
/* --------------------------- */
#include <stdio.h>
#include "setupwpi.h"
#include "reaction.h"

int main(void) {
    // 1. Er wordt game gestart
    setupPins();
    printf("Winner: %d", checkForButtonInput(5));
    // 2. Random tijd wachten voordat de game echt start
    // 3. In tussentijd kijken voor valse start
    // 4. Game starten en timer beginnnen (lichtjes of buzzer aanzetten)
    // 5. Wachten op user input
    // 6. Gemeten tijd & wie gewonnen heeft tonen
    return 0;
}