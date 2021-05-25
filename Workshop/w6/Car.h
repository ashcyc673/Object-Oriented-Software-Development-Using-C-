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

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cctype>
#include "Vehicle.h"



namespace sdds
{

    class Car : public Vehicle {
        std::string m_maker;
        std::string m_condition;
        double  m_top_speed;
        bool isNum(std::string num) const;
    protected:
        std::string omitSpace(const std::string& space);
    public:
        Car();
        Car(std::istream& read);
        double topSpeed() const;
        void display(std::ostream&) const;
        std::string condition() const;
        ~Car();

    };
}


#endif //SDDS_CAR_H
