#include <avr/io.h>
#define F_CPU 8000000UL

#include "timer.hpp"

class Son {

public:
    son();
    jouerSon();
    arreterSon();
    
private:
    Timer timer_;
    uint16_t calcOcr_(float frequence);
}