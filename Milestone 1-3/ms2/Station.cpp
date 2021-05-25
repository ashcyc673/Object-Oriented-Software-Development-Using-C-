// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NGG
// Date:           11/13/2020
//==============================================
// Milestone:     1
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#include "Station.h"

Station::Station(const std::string& record)
{
    size_t nextPos = 0;
    bool more = false;
    std::string data;
    Utilities utilities;
    data = utilities.extractToken(record,nextPos,more);
    m_name = data;
    data = utilities.extractToken(record,nextPos,more);
    m_serial = stoi(data);
    data = utilities.extractToken(record,nextPos,more);
    m_numCurrentItems = stoi(data);
    if(utilities.getFieldWidth() > m_widthField)
    {
        m_widthField = utilities.getFieldWidth();
    }
    data = utilities.extractToken(record,nextPos,more);
    m_desc = data;
    m_ID = ++id_generator;

}
const std::string& Station::getItemName() const
{
    return m_name;
}
unsigned int Station::getNextSerialNumber()
{
    return m_serial++;
}
unsigned int Station::getQuantity() const
{
    return m_numCurrentItems;
}
void Station::updateQuantity()
{
    if(m_numCurrentItems != 0)
    {
        --m_numCurrentItems;
    }
}
void Station::display(std::ostream& os, bool full) const
{
    os << "[";
    os.width(3);
    os.fill('0');
    os << std::right << m_ID;
    os.fill(' ');
    os << "]" << " Item: ";
    os.width(m_widthField);
    os << std::left << m_name << " ";
    os << "[";
    os.width(6);
    os.fill('0');
    os << std::right << m_serial;
    os.fill(' ');
    os << "]";


    if(full)
    {
        os << " Quantity: ";
        os.width(m_widthField);
        os << std::left << m_numCurrentItems;
        os << " Description: " << m_desc;
    }
    os << std::endl;
}