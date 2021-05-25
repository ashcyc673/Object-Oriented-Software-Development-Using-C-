//==============================================
// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NGG
// Date:           09/22/2020
//==============================================
// Workshop:     1
// Part:      2
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#ifndef PRACTICEC__17_EVENT_H
#define PRACTICEC__17_EVENT_H
#include <iostream>
#include <cstring>

extern unsigned int g_sysClock;

namespace sdds
{
    class event{
        char* eventDesc;
        unsigned int startTime;

    public:
        event();
        event(const event& otherEvent);
        event &operator=(const event& otherEvent);
        void display() const;
        void setDescription(const char* desc);
        ~event();
    };
}



#endif //PRACTICEC__17_EVENT_H
