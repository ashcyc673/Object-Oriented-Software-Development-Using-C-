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

#include "Racecar.h"

namespace sdds
{
    Racecar::Racecar(std::istream& in) : Car(in)
    {
        char data[256];
        in.getline(data,255,'\n');
        m_booster = stod(Car::omitSpace(data));
    }

    void Racecar::display(std::ostream& out) const
    {
        Car::display(out);
        out << "*";
    }

    double Racecar::topSpeed() const
    {
        return Car::topSpeed() * (1 + m_booster );
    }
}