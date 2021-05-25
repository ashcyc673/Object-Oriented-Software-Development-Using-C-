// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NGG
// Date:           10/06/2020
//==============================================
// Workshop:     3
// Part:      2
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#ifndef W3_PAIRSUMMABLE_H
#define W3_PAIRSUMMABLE_H
#include <iostream>
#include <iomanip>
#include "Pair.h"

namespace sdds
{
    template <typename K , typename V>
    class PairSummable : public Pair<K,V>{

        static V initial;
        static size_t minFieldWidth ;

    public:
        PairSummable(){}
        PairSummable(const K& key, const V& value = initial) : Pair<K,V> (key,value)
        {
            if(key.size() > minFieldWidth)
            {
                minFieldWidth = key.size();
            }
        }

        PairSummable& operator+=(const PairSummable& init){

            if(this != &init)
            {
                if(init.key() == Pair<K,V>::key())
                {
                   *this = PairSummable(Pair<K,V>::key(),init.value() + Pair<K,V>::value());
                }
            }
            return *this;
        }

        using Pair<K,V>::display;
        void display(std::ostream& os) const
        {
            os.setf(std::ios::left);
            os.width(minFieldWidth);
            Pair<K,V>::display(os);
            os.unsetf(std::ios::left);
        }
    };
    template <typename K , typename V>
    size_t PairSummable<K,V>::minFieldWidth = 0u;

    template<>
    inline std::string PairSummable<std::string,std::string>::initial = "";
    template<>
    inline int PairSummable<std::string,int>::initial = 0;
    template<>
    inline PairSummable<std::string,std::string>& PairSummable<std::string,std::string>::operator+=(const PairSummable& init)
    {
        if(this != &init)
        {
            if(init.key() == Pair<std::string,std::string>::key())
            {
                if(Pair<std::string,std::string>::value() != "")
                {
                   *this = PairSummable(Pair<std::string,std::string>::key(),Pair<std::string,std::string>::value() + ", ");
                }
                *this = PairSummable(Pair<std::string,std::string>::key(),(Pair<std::string,std::string>::value() + init.value()));
            }
        }
        return *this;
    }
}

#endif //W3_PAIRSUMMABLE_H
