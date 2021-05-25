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

#ifndef W4_RESERVATION_H
#define W4_RESERVATION_H
#include <iostream>
#include <iomanip>
#include <sstream>

namespace sdds
{

    class Reservation{

        std::string reservation_id;
        std::string name;
        std::string email;
        size_t human;
        size_t day;
        size_t hour;

    public:
        Reservation();
        Reservation(const std::string& res);
        void setEmpty();
        std::string omitSpace(const std::string& space);
        friend std::ostream& operator<<(std::ostream& os, const Reservation& res);

    };
}


#endif //W4_RESERVATION_H
