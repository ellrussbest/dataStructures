#ifndef CONCERT_H
#define CONCERT_H

#include <iostream>

class Concert
{
public:
    Concert();
    void setName(std::string const &name);
    void setVenue(std::string const &venue);
    void setCapacity(int cap);
    void setPrice(float price_in);
    void printStats();

private:
    std::string name;
    std::string venue;
    int max_capacity;
    float ticket_price;
};

#endif
