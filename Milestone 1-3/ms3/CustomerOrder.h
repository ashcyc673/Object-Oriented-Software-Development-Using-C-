// Name:                            Chiao-Ya Chang
// Seneca Student ID:               130402191
// Seneca email:                    cchang76@myseneca.c
// Date of completion:              11/27/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

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
