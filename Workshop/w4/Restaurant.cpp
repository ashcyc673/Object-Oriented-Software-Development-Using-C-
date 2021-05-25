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

#include "Restaurant.h"

namespace sdds
{
    Restaurant::Restaurant(Reservation* reservations[], size_t cnt)
    {
        if(reservations != nullptr && cnt > 0)
        {
            count = new Reservation[cnt];
            for(size_t i = 0; i < cnt ; i++)
            {
                count[i] = Reservation(*reservations[i]);
            }
            length = cnt;
        } else{
            setEmpty();
        }
    }
    Restaurant::Restaurant(Restaurant&& mv)
    {
        if(this != &mv)
        {
            length = mv.length;
            count = mv.count;
            mv.length = 0u;
            mv.count = nullptr;
        } else
        {
           setEmpty();
        }
    }

    size_t Restaurant::size() const
    {
        return length;
    }

    Restaurant::Restaurant(const Restaurant& copy)
    {
        if(this != &copy)
        {
            if(copy.length > 0 || copy.count != nullptr)
            {
                length = copy.length;
                count = new Reservation[length];
                for(size_t i = 0; i < copy.length; i++)
                {
                   count[i] = Reservation(copy.count[i]);
                }
            } else
            {
                setEmpty();
            }
        }
    }

    void Restaurant::setEmpty()
    {
        count = nullptr;
        length = 0;
    }
    std::ostream& operator<<(std::ostream& os, const Restaurant& res)
    {
        os << "--------------------------" << std::endl;
        os << "Fancy Restaurant" << std::endl;
        os << "--------------------------" << std::endl;

        if(res.count == nullptr || res.length == 0)
        {
            os << "The object is empty!" << std::endl;
        } else
        {
           for(size_t i = 0; i < res.length; i++)
           {
               os << res.count[i];
           }
        }
        os << "--------------------------" << std::endl;
        return os;
    }
    Restaurant::~Restaurant()
    {
        delete[] count;
    }
}