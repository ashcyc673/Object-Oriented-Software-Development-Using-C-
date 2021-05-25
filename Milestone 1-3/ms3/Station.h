// Name:                            Chiao-Ya Chang
// Seneca Student ID:               130402191
// Seneca email:                    cchang76@myseneca.c
// Date of completion:              11/27/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef MS1_STATION_H
#define MS1_STATION_H
#include "Utilities.h"
#include <iostream>

    class Station {

     size_t m_ID;
     std::string m_name;
     std::string m_desc;
     size_t m_serial;
     size_t m_numCurrentItems;
     static size_t m_widthField;
     static size_t id_generator;
    public:
        Station(const std::string& record);
        const std::string& getItemName() const;
        unsigned int getNextSerialNumber();
        unsigned int getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;

    };

    inline size_t Station::m_widthField = 1;
    inline size_t Station::id_generator = 0;



#endif //MS1_STATION_H
