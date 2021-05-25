// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NGG
// Date:           11/19/2020
//==============================================
// Milestone:     3
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#ifndef MS1_LINEMANAGER_H
#define MS1_LINEMANAGER_H
#include <vector>
#include <fstream>
#include "Workstation.h"


class LineManager {
    std::vector<Workstation*> AssemblyLine;
    std::deque<CustomerOrder> ToBeFilled;
    std::deque<CustomerOrder> Completed;
    Workstation* first;
    size_t iterationNum;
    unsigned int m_cntCustomerOrder;
public:
    LineManager(const std::string& filename, std::vector<Workstation*>& workstation, std::vector<CustomerOrder>& customerorder);
    bool run(std::ostream& os);
    void displayCompletedOrders(std::ostream& os) const;
    void displayStations() const;
    void displayStationsSorted() const;
    Workstation* lastWorkstation() const;

};


#endif //MS1_LINEMANAGER_H
