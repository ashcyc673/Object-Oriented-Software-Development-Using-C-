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

#include "Utilities.h"
extern char delimeter;
namespace sdds
{
    Vehicle* createInstance(std::istream& in)
    {
        char data[256];
        in.getline(data,255,',');
        std::string tag = omitSpace(data);
        if(tag == "c" || tag == "C")
        {
            delimeter = '\n';
            return new Car(in);
        }
        else if(tag == "r" || tag == "R")
        {
            delimeter = ',';
            return new Racecar(in);
        }
        else if(tag == "")
        {
            return nullptr;
        }
        else {
            in.clear();
            in.ignore(2000,'\n');
            throw std::string("Unrecognized record type: [" + tag + "]");;
        }
    }

    std::string omitSpace(const std::string& space)
    {
        std::string noSpace;
        for(size_t i = 0u; i < space.size(); i++)
        {
            if(space[i] != ' ')
            {
                noSpace += space[i];
            }
        }
        return noSpace;
    }
}