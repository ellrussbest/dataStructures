#include "concert.h"
#include <iostream>

int main()
{
    Concert myConcert = Concert();
    myConcert.setCapacity(100);
    myConcert.setName("The Grateful Dead");
    myConcert.setPrice(2.50);
    myConcert.setVenue("Red Rocks");
    myConcert.printStats();

    return 0;
}
