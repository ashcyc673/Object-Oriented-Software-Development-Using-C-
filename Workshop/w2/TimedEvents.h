//==============================================
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

#ifndef WS2_TIMEDEVENTS_H
#define WS2_TIMEDEVENTS_H

#include <iostream>
#include <string>
#include <chrono>

namespace sdds
{
    class TimedEvents{

        size_t  currentRecords;
        std::chrono::steady_clock::time_point startTime;
        std::chrono::steady_clock::time_point endTime;

        typedef struct
        {
            std::string eventName;
            std::string unitOfTime;
            std::chrono::steady_clock::duration duration;

        }EventArr;

        EventArr event[7];

    public:
        TimedEvents();
        void startClock();
        void stopClock();
        void recordEvent(const char* nameEvent);

        friend std::ostream& operator<<(std::ostream& os, const TimedEvents& timeEvent);
    };
}




#endif //WS2_TIMEDEVENTS_H
