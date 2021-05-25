// Name:                            Chiao-Ya Chang
// Seneca Student ID:               130402191
// Seneca email:                    cchang76@myseneca.c
// Date of completion:              11/27/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "LineManager.h"

LineManager::LineManager(const std::string &filename, std::vector<Workstation *> &workstation,std::vector<CustomerOrder> &customerorder)
{
    std::ifstream file(filename);
    if (file.is_open()) {
        size_t nextPos = 0;
        iterationNum= 0;
        bool more = false;
        std::string data;
        Utilities utilities;
        first = nullptr;
        while (!file.eof()) {
            std::getline(file, data);
            if (data.find(Utilities::getDelimiter()) != std::string::npos) {
                std::string firstToken = utilities.extractToken(data, nextPos, more);
                std::string secondToken = utilities.extractToken(data, nextPos, more);
                for (size_t i = 0; i < workstation.size(); i++) {
                    if (workstation[i]->getItemName() == firstToken) {
                        for (size_t j = 0; j < workstation.size(); j++) {
                            if (workstation[j]->getItemName() == secondToken) {
                                workstation[i]->setNextStation(*workstation[j]);
                                if (first == nullptr) {
                                    first = workstation[i];
                                }
                                nextPos = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }
        file.close();
        m_cntCustomerOrder = 0;
        for (auto i = customerorder.begin(); i < customerorder.end(); i++) {
            ToBeFilled.push_back(std::move(*i));
            ++m_cntCustomerOrder;
        }
        for (auto i = workstation.begin(); i < workstation.end(); i++) {
            AssemblyLine.push_back(*i);
        }
    }
}

bool LineManager::run(std::ostream &os)
{
    os << "Line Manager Iteration: " << ++iterationNum << std::endl;
    if(!ToBeFilled.empty())
    {
        *first += std::move(ToBeFilled.front());
        ToBeFilled.pop_front();
    }
    for(auto i = AssemblyLine.begin(); i < AssemblyLine.end(); i++)
    {
        (*i)->runProcess(os);
    }
    for(auto i = AssemblyLine.begin(); i < AssemblyLine.end(); i++)
    {
        (*i)->moveOrder();
    }
    CustomerOrder order;
   if(lastWorkstation()->getIfCompleted(order))
   {
       Completed.push_back(std::move(order));
   }
   return Completed.size() == m_cntCustomerOrder;
}

void LineManager::displayCompletedOrders(std::ostream &os) const
{
    for (auto i = Completed.begin(); i < Completed.end(); i++) {
        (*i).display(os);
    }
}

void LineManager::displayStations() const
{
    for (auto i = AssemblyLine.begin(); i < AssemblyLine.end(); i++) {
        (*i)->display(std::cout);
    }
}

void LineManager::displayStationsSorted() const
{
    Workstation *next = first;
    do {
        next->display(std::cout);
        next = const_cast<Workstation *>(next->getNextStation());
    } while (next != nullptr);
}

Workstation* LineManager::lastWorkstation() const {
    for (auto i : AssemblyLine) {
        if (i->getNextStation() == nullptr)
            return i;
    }
    return nullptr;
}