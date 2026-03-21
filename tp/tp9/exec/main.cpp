#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <libstatique.hpp>

int main() {
    Son son;

    // jouer La 440 Hz (note 69) pendant 1 seconde
    son.jouer(69);
    _delay_ms(1000);
    son.arreter();

    _delay_ms(500);

    // jouer Do 261 Hz (note 60) pendant 1 seconde
    son.jouer(60);
    _delay_ms(1000);
    son.arreter();

    _delay_ms(500);

    // jouer La grave 110 Hz (note 45) pendant 1 seconde
    son.jouer(45);
    _delay_ms(1000);
    son.arreter();

    _delay_ms(500);

    // test note invalide (ne devrait rien faire)
    son.jouer(200);
    _delay_ms(500);
    son.arreter();

    while (true) {}
}
