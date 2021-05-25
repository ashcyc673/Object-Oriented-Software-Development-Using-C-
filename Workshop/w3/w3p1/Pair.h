// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NGG
// Date:           10/06/2020
//==============================================
// Workshop:     1
// Part:      1
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#ifndef W3_PAIR_H
#define W3_PAIR_H
#include <iostream>

namespace sdds
{
    template <typename K , typename V>
    class Pair {
        K m_key;
        V m_value;

    public:

        Pair() : m_key{}, m_value{}{}

        Pair(const K& key, const V& value) : m_key(key), m_value(value){}

        const K& key() const
        {
            return m_key;
        }
        const V& value() const
        {
            return m_value;
        }
        void display(std::ostream& os) const
        {
            os <<  m_key << " : " << m_value << std::endl;
        }

    };
    template<typename K, typename V>
    std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair)
    {
        pair.display(os);
        return os;
    }

}


#endif //W3_PAIR_H
