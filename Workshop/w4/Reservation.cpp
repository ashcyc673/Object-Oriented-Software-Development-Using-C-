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

#include "Reservation.h"

namespace sdds
{
    Reservation::Reservation()
    {
        setEmpty();
    }
    Reservation::Reservation(const std::string& res)
    {
        std::string filter = omitSpace(res);
        std::istringstream read(filter);
        std::getline(read, reservation_id, ':');
        std::getline(read, name, ',');
        std::getline(read, email, ',');
        std::string space = "";
        std::getline(read, space, ',');
        human = std::stoi(space);
        std::getline(read,space,',');
        day = std::stoi(space);
        std::getline(read,space,'\n');
        hour = std::stoi(space);
    }


    void Reservation::setEmpty()
    {
        reservation_id = "";
        name = "";
        email = "";
        human = 0u;
        day = 0u;
        hour = 0u;
    }

    std::string Reservation::omitSpace(const std::string &space)
    {
        std::string noSpace;
        for(size_t i = 0; i < space.length(); i++)
        {
            if(space[i] != ' ')
            {
                noSpace += space[i];
            }
        }
        return noSpace;
    }

    std::ostream& operator<<(std::ostream& os, const Reservation& res)
    {
        os << "Reservation " << res.reservation_id << ": ";
        os.width(10);
        os << std::right<< res.name << " ";
        os.width(25);
        std::string email = " <" + res.email + "> ";
        os << std::left << email;
        if(res.hour >= 6 && res.hour <= 9)
        {
            os << "Breakfast ";
        }
        else if(res.hour >= 11 && res.hour <=15)
        {
            os << "Lunch ";
        }
        else if(res.hour >= 17 && res.hour <= 21)
        {
            os << "Dinner ";
        } else
        {
            os << "Drinks ";
        }
        os << "on day " << res.day << " @ " << res.hour << ":00" << " for " << res.human << " people." << std::endl;

        return os;
    }
}
