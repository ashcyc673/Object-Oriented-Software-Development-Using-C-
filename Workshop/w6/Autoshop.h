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

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H


#include "Vehicle.h"
#include <vector>
#include <list>

namespace sdds
{

    class Autoshop {

        std::vector<Vehicle*> m_vehicles;

    public:
        Autoshop& operator +=(Vehicle* theVehicle);
        void display(std::ostream& out) const;
        ~Autoshop();

        template<typename T>
        void select(T test, std::list<const Vehicle*>& vehicles)
        {
            for(auto i = m_vehicles.begin(); i != m_vehicles.end(); i++)
            {
                if(test(*i))
                {
                    vehicles.push_back(*i);
                }
            }
        }
    };

}


#endif //SDDS_AUTOSHOP_H
