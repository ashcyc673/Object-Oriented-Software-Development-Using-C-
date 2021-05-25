// Name:                            Chiao-Ya Chang
// Seneca Student ID:               130402191
// Seneca email:                    cchang76@myseneca.c
// Date of completion:              11/27/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Workstation.h"

Workstation::Workstation(const std::string& record) : Station(record)
{
    m_pNextStation = nullptr;
}

void Workstation::runProcess(std::ostream& os)
{
    if(!m_orders.empty())
    {
        m_orders.front().fillItem(*this,os);
    }
}

bool Workstation::moveOrder()
{
    bool state = false;
    if(!m_orders.empty())
    {
        if(m_orders.front().isItemFilled(getItemName()))
        {
            if (m_pNextStation != nullptr) {
                m_pNextStation->operator+=(std::move(m_orders.front()));
                m_orders.pop_front();
                state = true;
            }
        }
    }
    return state;
}

void Workstation::setNextStation(Station& station)
{
    m_pNextStation = (Workstation *) &station;
}

const Workstation* Workstation::getNextStation() const
{
    return m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder& order)
{
    bool state = false;
    if(!m_orders.empty())
    {
        if(m_orders.front().isOrderFilled())
        {
            order = std::move(m_orders.front());
            m_orders.pop_front();
            state = true;
        }
    }
    return state;
}

void Workstation::display(std::ostream& os)
{
    os << getItemName() << " --> ";
    if(m_pNextStation == nullptr)
    {
        os << "END OF LINE" << std::endl;
    } else{
        os << m_pNextStation->getItemName() << std::endl;
    }
}

Workstation& Workstation::operator+=(CustomerOrder&& order)
{
    m_orders.push_back(std::move(order));
    return *this;
}