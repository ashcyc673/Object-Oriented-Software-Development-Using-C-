// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NGG
// Date:           11/15/2020
//==============================================
// Workshop:     8
// Part:        2
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
    List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
        List<Product> priceList;
        // TODO: Add your code here to build a list of products
        //         using raw pointers

        for(size_t i = 0; i < desc.size(); i++)
        {
            for(size_t j = 0; j < price.size(); j++)
            {
                if(desc[i].code == price[j].code)
                {
                    Product* pd;
                    pd = new Product(desc[i].desc,price[j].price);
                    pd->validate();
                    priceList += pd;
                    delete pd;
                    pd = nullptr;
                }
            }
        }
        return priceList;
    }

    List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
        List<Product> priceList;
        // TODO: Add your code here to build a list of products
        //         using smart pointers
        for(size_t i = 0; i < desc.size(); i++)
        {
            for(size_t j = 0; j < price.size(); j++)
            {
                if(desc[i].code == price[j].code)
                {
                    std::unique_ptr<Product> pd(new Product(desc[i].desc,price[j].price));
                    pd->validate();
                    priceList += pd;
                }
            }
        }
        return priceList;
    }
}
