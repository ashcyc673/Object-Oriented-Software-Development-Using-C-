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

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <sstream>
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds
{

    Vehicle* createInstance(std::istream& in);
    std::string omitSpace(const std::string& space);
}



#endif //SDDS_UTILITIES_H
