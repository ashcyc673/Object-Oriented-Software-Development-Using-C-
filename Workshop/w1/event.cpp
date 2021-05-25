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
#include "event.h"
using namespace std;

unsigned int g_sysClock;

namespace sdds
{
    event::event()
    {
        eventDesc = nullptr;
        startTime = 0;
    }
    event::event(const event& otherEvent)
    {
        if(otherEvent.eventDesc != nullptr)
        {
            eventDesc = new char[strlen(otherEvent.eventDesc)+1];
            strcpy(eventDesc,otherEvent.eventDesc);
            startTime = otherEvent.startTime;
        } else
        {
            even tDesc = nullptr;
            startTime = 0;
        }
    }

    event & event::operator=(const event &otherEvent)
    {
        if(eventDesc != nullptr)
        {
            delete[] eventDesc;
            eventDesc = nullptr;
            startTime = 0;
        }
        if(otherEvent.eventDesc != nullptr)
        {
            eventDesc = new char[strlen(otherEvent.eventDesc)+1];
            strcpy(eventDesc,otherEvent.eventDesc);
            startTime = otherEvent.startTime;
        } else
        {
            eventDesc = nullptr;
            startTime = 0;
        }
        return *this;
    }

    void event::display() const
    {
        static unsigned int counter = 1;
        cout.width(3);
        cout << right << counter << ". ";

        if(eventDesc ==  nullptr)
        {
           cout << "[ No Event ]" << endl;
        }
        else{
            cout.width(2);
            cout.fill('0');
            cout << right << startTime / 3600 << ":";

            cout.width(2);
            cout.fill('0');
            cout << right << startTime % 3600 / 60 << ":";

            cout.width(2);
            cout.fill('0');
            cout << right << startTime % 3600 % 60 << " -> " << eventDesc << endl;
            cout.fill(' ');
        }
        ++counter;
    }

    void event::setDescription(const char* desc)
    {

        delete[] eventDesc;
        eventDesc = nullptr;
        if(desc != nullptr)
        {
            eventDesc = new char[strlen(desc) + 1];
            strcpy(eventDesc,desc);
            startTime = g_sysClock;
        }
    }

    event::~event()
    {
        delete[] eventDesc;
        eventDesc = nullptr;
    }

}
