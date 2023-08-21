#include "concert.h"

Concert::Concert() : name("Unnamed Band"),
                     venue("Mystery Venue"),
                     ticket_price(0.0),
                     max_capacity(0) {}

void Concert::setCapacity(int cap)
{
    this->max_capacity = cap;
}

void Concert::setName(std::string const &name_in)
{
    this->name = name_in;
}

void Concert::setPrice(float price_in)
{
    this->ticket_price = price_in;
}

void Concert::setVenue(std::string const &venue_in)
{
    this->venue = venue_in;
}

void Concert::printStats()
{
    std::cout << this->name << " is playing at " << venue << "." << std::endl;
    std::cout << "Ticket's const " << this->ticket_price << " and there are " << this->max_capacity << "available." << std::endl;
}
