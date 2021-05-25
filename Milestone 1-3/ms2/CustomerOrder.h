// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NGG
// Date:           11/17/2020
//==============================================
// Milestone:     2
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#ifndef MS1_CUSTOMERORDER_H
#define MS1_CUSTOMERORDER_H
#include <iostream>
#include <string>
#include "Station.h"

struct Item
{
    std::string m_itemName;
    unsigned int m_serialNumber = 0;
    bool m_isFilled = false;

    Item(const std::string& src) : m_itemName(src) {};
};

class CustomerOrder {
    std::string m_name;
    std::string m_product;
    unsigned int m_cntItem;
    Item** m_lstItem;
    static size_t m_widthField;
public:
    CustomerOrder();
    CustomerOrder(const std::string& record);
    CustomerOrder(const CustomerOrder& copy);
    CustomerOrder& operator=(const CustomerOrder& copy) = delete;
    CustomerOrder(CustomerOrder&& copy) noexcept;
    CustomerOrder& operator=(CustomerOrder&& copy) noexcept;
    bool isOrderFilled() const;
    bool isItemFilled(const std::string& itemName) const;
    void fillItem(Station& station, std::ostream& os);
    void display(std::ostream& os) const;
    ~CustomerOrder();
    void deleteObj();
    
};

inline size_t CustomerOrder::m_widthField = 0;

#endif //MS1_CUSTOMERORDER_H
