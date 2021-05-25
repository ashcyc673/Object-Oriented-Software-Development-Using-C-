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

#include "Autoshop.h"

namespace sdds
{
    Autoshop& Autoshop::operator +=(Vehicle* theVehicle)
    {
        m_vehicles.push_back((theVehicle));
        return *this;
    }

    void Autoshop::display(std::ostream& out) const
    {
        out << "--------------------------------" << std::endl;
        out << "| Cars in the autoshop!        |" << std::endl;
        out << "--------------------------------" << std::endl;
        for(auto i = m_vehicles.begin(); i != m_vehicles.end(); i++)
        {
            (*i)->display(out);
            out << std::endl;
        }
        out << "--------------------------------" << std::endl;
    }

    Autoshop::~Autoshop()
    {
        for(auto i = m_vehicles.begin(); i != m_vehicles.end(); i++)
        {
           delete *i;
        }
    }
}