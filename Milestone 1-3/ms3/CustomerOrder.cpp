// Name:                            Chiao-Ya Chang
// Seneca Student ID:               130402191
// Seneca email:                    cchang76@myseneca.c
// Date of completion:              11/27/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "CustomerOrder.h"

CustomerOrder::CustomerOrder()
{
    m_cntItem = 0;
    m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(const std::string& record)
{
    size_t nextPos = 0;
    bool more = false;
    std::string data;
    Utilities utilities;
    m_lstItem = nullptr;
    m_cntItem = 0;
    data = utilities.extractToken(record,nextPos,more);
    m_name = data;
    data = utilities.extractToken(record,nextPos,more);
    m_product = data;
    while(more)
    {
        data = utilities.extractToken(record,nextPos,more);
        if (!data.empty()) {
            if(m_lstItem == nullptr)
            {
                m_lstItem = new Item* [++m_cntItem];
                m_lstItem[0] = new Item(data);

            } else
            {
                Item** item_temp = new Item* [++m_cntItem];
                for(size_t i = 0; i < m_cntItem - 1; i++)
                {
                    item_temp[i] = m_lstItem[i];
                }
                item_temp[m_cntItem-1] = new Item(data);
                delete[] m_lstItem;
                m_lstItem = item_temp;
            }
            if(utilities.getFieldWidth() > m_widthField)
            {
                m_widthField = utilities.getFieldWidth();
            }
        }
    }
}

CustomerOrder::CustomerOrder(const CustomerOrder& copy)
{
    throw std::string("ERROR: Cannot make copies.");
}

CustomerOrder::CustomerOrder(CustomerOrder&& copy) noexcept
{
    m_lstItem = nullptr;
    m_cntItem = 0;
    *this = std::move(copy);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& copy) noexcept
{
    if(this != &copy)
    {
        deleteObj();
        m_name = copy.m_name;
        copy.m_name = "";
        m_product = copy.m_product;
        copy.m_product = "";
        m_cntItem = copy.m_cntItem;
        copy.m_cntItem = 0;
        m_lstItem = copy.m_lstItem;
        copy.m_lstItem = nullptr;
    }
    return *this;
}

bool CustomerOrder::isOrderFilled() const
{
    bool state = true;
    for(size_t i = 0; i < m_cntItem; i++)
    {
        if(!m_lstItem[i]->m_isFilled)
        {
            state = false;
            break;
        }
    }
    return state;
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const
{
    bool state = true;
    for(size_t i = 0; i < m_cntItem; i++)
    {
        if(m_lstItem[i]->m_itemName == itemName)
        {
            state = m_lstItem[i]->m_isFilled;
            break;
        }
    }
    return state;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os)
{
    for(size_t i = 0; i < m_cntItem; i++)
    {
        if(station.getItemName() == m_lstItem[i]->m_itemName)
        {
            if(station.getQuantity() > 0)
            {
                station.updateQuantity();
                m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                m_lstItem[i]->m_isFilled = true;
                os << "    Filled " << m_name << ", " << m_product << " ["<< m_lstItem[i]->m_itemName << "]"<< std::endl;
            } else
            {
                os << "    Unable to fill " << m_name << ", " << m_product << m_lstItem[i]->m_itemName << std::endl;
            }
        }
    }
}

void CustomerOrder::display(std::ostream& os) const
{
    os << m_name << " - " << m_product << std::endl;
    for(size_t i = 0; i < m_cntItem; i++)
    {
        os << "[";
        os.width(6);
        os.fill('0');
        os << std::right << m_lstItem[i]->m_serialNumber;
        os.fill(' ');
        os << "] ";
        os.width(m_widthField);
        os << std::left << m_lstItem[i]->m_itemName << std::right;
        os << " - ";
        os << (m_lstItem[i]->m_isFilled ? "FILLED" : "MISSING") << std::endl;
    }
}

void CustomerOrder::deleteObj()
{
    for(size_t i = 0; i < m_cntItem; i++)
    {
        delete m_lstItem[i];
        m_lstItem[i] = nullptr;
    }
    delete[] m_lstItem;
    m_lstItem = nullptr;
    m_cntItem = 0;
}

CustomerOrder::~CustomerOrder()
{
    deleteObj();
}