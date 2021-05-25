// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NGG
// Date:           10/02/2020
//==============================================
// Workshop:     1
// Part:      2
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#include "TimedEvents.h"

namespace sdds
{
    TimedEvents::TimedEvents()
    {
        currentRecords = 0;
        startTime = std::chrono::steady_clock::now();
        endTime = std::chrono::steady_clock::now();
    }

    void TimedEvents::startClock()
    {
        startTime = std::chrono::steady_clock::now();
    }

    void TimedEvents::stopClock()
    {
        endTime = std::chrono::steady_clock::now();
    }

    void TimedEvents::recordEvent(const char* nameEvent)
    {

        if (currentRecords < 7 && nameEvent != nullptr)
        {
            event[currentRecords].eventName = nameEvent;
            event[currentRecords].unitOfTime = "nanoseconds";
            event[currentRecords].duration = endTime - startTime;
            currentRecords++;
        }
    }

    std::ostream& operator<<(std::ostream& os, const TimedEvents& timeEvent)
    {
        os << "--------------------------"<< std::endl;
        os << "Execution Times:" << std::endl;
        os << "--------------------------"<< std::endl;
        for(size_t i = 0; i < timeEvent.currentRecords; i++)
        {
            os.width(20);
            os << std::left << timeEvent.event[i].eventName;
            os.width(12);
            os << std::right << std::chrono::duration_cast<std::chrono::nanoseconds>(timeEvent.event[i].duration).count() << ' ';
            os << timeEvent.event[i].unitOfTime << std::endl;

        }
        os << "--------------------------" << std::endl;
        return os;
    }
}
