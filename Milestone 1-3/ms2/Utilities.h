// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NGG
// Date:           11/13/2020
//==============================================
// Milestone:     1
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#ifndef MS1_UTILITIES_H
#define MS1_UTILITIES_H
#include <iostream>

    class Utilities {

        size_t m_widthField = 0;
        static char m_delimiter;
        std::string omitSpace(const std::string& space);
    public:
        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;
        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
        static void setDelimiter(char newDelimiter);
        static char getDelimiter();
    };

    inline char Utilities::m_delimiter = ',';


#endif //MS1_UTILITIES_H
