// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NGG
// Date:           11/05/2020
//==============================================
// Workshop:     6
// Part:      2
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include <iostream>
#include "Car.h"

namespace sdds
{
    class Racecar : public Car{
        double m_booster;
    public:
        Racecar(std::istream& in);
        void display(std::ostream& out) const;
        double topSpeed() const;

    };
}


#endif //SDDS_RACECAR_H
