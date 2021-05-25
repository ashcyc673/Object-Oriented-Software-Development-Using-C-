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

#ifndef W4_CONFIRMATIONSENDER_H
#define W4_CONFIRMATIONSENDER_H
#include "Reservation.h"

namespace sdds
{
    class ConfirmationSender {
        Reservation** reserve;
        size_t cnt;
    public:
        ConfirmationSender();
        ConfirmationSender(ConfirmationSender& copy);
        ConfirmationSender(ConfirmationSender&& copy);
        void setEmpty();
        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);
        friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& res);
        ~ConfirmationSender();
    };
}


#endif //W4_CONFIRMATIONSENDER_H
