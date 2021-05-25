// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NGG
// Date:           14/10/2020
//==============================================
// Workshop:     4
// Part:      2
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#include "ConfirmationSender.h"

namespace sdds
{
    ConfirmationSender::ConfirmationSender()
    {
        setEmpty();
    }

    void ConfirmationSender::setEmpty()
    {
        reserve = nullptr;
        cnt = 0;
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender& copy)
    {
        if(this != &copy)
        {
            if(copy.reserve != nullptr || copy.cnt > 0)
            {
                cnt = copy.cnt;
                reserve = new Reservation*[cnt];
                for(size_t i = 0; i < cnt; i++)
                {
                //    reserve[i] = new Reservation(*copy.reserve[i]);
                    reserve[i] = copy.reserve[i];
                }
            } else
            {
                setEmpty();
            }
        }
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender&& mv)
    {
        if(this != &mv)
        {
            cnt = mv.cnt;
            reserve = mv.reserve;
            mv.cnt = 0u;
            mv.reserve = nullptr;
        } else
        {
            setEmpty();
        }
    }

    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
    {
        bool state = true;
        for(size_t i = 0; i < cnt; i++)
        {
            if(&res == reserve[i])
            {
                state = false;
            }
        }
        if(state)
        {
            cnt++;
            Reservation** temp;
            temp = new Reservation*[cnt];
            for(size_t i = 0; i < cnt - 1; i++)
            {
                temp[i] = reserve[i];
            }
            temp[cnt - 1] = &(const_cast<Reservation&>(res));
            delete[] reserve;
            reserve = temp;
        }
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
    {
        size_t position = -1;
        bool state = false;
        for(size_t i = 0; i < cnt; i++)
        {
            if(&res == reserve[i])
            {
                position = i;
                state = true;
            }
        }
        if(state)
        {
            cnt--;
            Reservation** temp;
            temp = new Reservation*[cnt];
            for(size_t i = 0; i < cnt + 1; i++)
            {
                if(position != i)
                {
                    temp[i] = reserve[i];
                }
            }
            delete[] reserve;
            reserve = temp;
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const ConfirmationSender& res)
    {
        os << "--------------------------" << std::endl;
        os << "Confirmations to Send" << std::endl;
        os << "--------------------------" << std::endl;

        if(res.reserve == nullptr || res.cnt == 0)
        {
            os << "The object is empty!" << std::endl;
        } else
        {
            for(size_t i = 0; i < res.cnt; i++)
            {
                os << *res.reserve[i];
            }
        }
        os << "--------------------------" << std::endl;
        return os;
    }

    ConfirmationSender::~ConfirmationSender()
    {
//        for(size_t i = 0; i < cnt; i++)
//        {
//            if(reserve[i] != nullptr)
//            {
//                delete reserve[i];
//            }
//        }
        delete[] reserve;

    }
}
