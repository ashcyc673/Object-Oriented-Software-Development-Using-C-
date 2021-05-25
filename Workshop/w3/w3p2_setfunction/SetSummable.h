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

#ifndef W3_SETSUMMABLE_H
#define W3_SETSUMMABLE_H
#include "Set.h"
#include "PairSummable.h"

namespace sdds
{
    template<typename T, int N>
    class SetSummable : public Set<T,N>{

    public:

        T accumulate(const std::string& filter) const
        {
            T accumulateObj = T(filter);
            for(size_t i = 0; i < Set<T,N>::size(); i++)
            {
                accumulateObj += Set<T,N>::operator[](i);
            }
            return accumulateObj;
        }



    };
}


#endif //W3_SETSUMMABLE_H
