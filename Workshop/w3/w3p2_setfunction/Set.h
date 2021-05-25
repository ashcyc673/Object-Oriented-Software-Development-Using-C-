// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NGG
// Date:           10/06/2020
//==============================================
// Workshop:     1
// Part:      2
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
#ifndef W3_SET_H
#define W3_SET_H
#include <iostream>


namespace sdds {
    template<typename T, int N>
    class Set {

        T arrayData[N];
        size_t currentNumEle {0u};

    public:
        size_t size() const
        {
            return currentNumEle;
        }

        const T &operator[](size_t idx) const
        {
                return arrayData[idx];
        }

        void operator+=(const T &item)
        {
            if(currentNumEle < N)
            {
                currentNumEle += 1;
                arrayData[currentNumEle - 1] = item;
            }
        }
    };
}


#endif //W3_SET_H
