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

#include "Car.h"

char delimeter;

namespace sdds
{
    Car::Car()
    {
        m_maker = ' ';
        m_condition = ' ';
        m_top_speed = 0.0;
    }

    Car::Car(std::istream& read)
    {
        char data[256];
        read.getline(data,255,',');
        m_maker = omitSpace(data);
        read.getline(data,255,',');
        m_condition = omitSpace(data);
        if(m_condition != "n" && m_condition != "u" && m_condition != "b" && m_condition != "")
        {
            read.clear();
            read.ignore(2000,'\n');
            throw std::string("Invalid record!");
        }
        read.getline(data,255, delimeter);
        std::string speed = omitSpace(data);
        if(!isNum(speed))
        {
            read.clear();
            read.ignore(2000,'\n');
            throw std::string("Invalid record!");
        }
        m_top_speed = stoi(speed);

    }

    bool Car::isNum(std::string num) const
    {
        for(size_t i = 0u; i < num.length(); i++)
        {
            if(!isdigit(num[i]))
            {
                return false;
            }
        }
        return true;
    }

    std::string Car::omitSpace(const std::string& space)
    {
        std::string result;
        for (size_t i = 0; i < space.length(); ++i) {
            if (i >= space.find_first_not_of(' ') && i <= space.find_last_not_of(' ')) {
                result += space[i];
            }
        }
        return result;
    }

    double Car::topSpeed() const
    {
        return m_top_speed;
    }

    void Car::display(std::ostream& os) const
    {
        os << "| ";
        os.width(10);
        os << std::right << m_maker;
        os << " | ";
        os.width(6);
        os << std::left <<condition();
        os << " | ";
        os.setf(std::ios::fixed);
        os.precision(2);
        os << topSpeed();
        os.unsetf(std::ios::fixed);
        os << " |";

    }

    std::string Car::condition() const
    {
        if(m_condition == "n" || m_condition == "")
        {
            return "new";
        }
        if(m_condition == "u")
        {
            return "used";
        }
        if(m_condition == "b")
        {
            return "broken";
        }
        return "";
    }

    Car::~Car()
    {

    }

}
