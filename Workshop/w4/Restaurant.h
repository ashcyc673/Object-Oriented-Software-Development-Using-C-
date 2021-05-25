// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NGG
// Date:           14/10/2020
//==============================================
// Workshop:     4
// Part:      2
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#ifndef W4_RESTAURANT_H
#define W4_RESTAURANT_H
#include "Reservation.h"


namespace sdds
{

    class Restaurant {
        Reservation* count;
        size_t length;

    public:
        Restaurant(Reservation* reservations[], size_t cnt);
        Restaurant(Restaurant&& mv);
        size_t size() const;
        void setEmpty();
        Restaurant(const Restaurant& copy);
        friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);
        ~Restaurant();

    };
}


#endif //W4_RESTAURANT_H
