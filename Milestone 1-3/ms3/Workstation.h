// Name:                            Chiao-Ya Chang
// Seneca Student ID:               130402191
// Seneca email:                    cchang76@myseneca.c
// Date of completion:              11/27/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef MS1_WORKSTATION_H
#define MS1_WORKSTATION_H
#include <deque>
#include "Station.h"
#include "CustomerOrder.h"


class Workstation : public Station {
    std::deque<CustomerOrder> m_orders;
    Workstation* m_pNextStation;
public:
    Workstation(const std::string& record);
    void runProcess(std::ostream& os);
    bool moveOrder();
    void setNextStation(Station& station);
    const Workstation* getNextStation() const;
    bool getIfCompleted(CustomerOrder& order);
    void display(std::ostream& os);
    Workstation& operator+=(CustomerOrder&& order);
    Workstation(const Workstation& copy) = delete;
    Workstation& operator=(const CustomerOrder& copy) = delete;
    Workstation(Workstation&& copy) = delete;
    Workstation& operator=(Workstation&& copy) = delete;
};


#endif //MS1_WORKSTATION_H
