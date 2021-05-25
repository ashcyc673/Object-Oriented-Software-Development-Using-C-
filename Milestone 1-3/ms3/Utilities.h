// Name:                            Chiao-Ya Chang
// Seneca Student ID:               130402191
// Seneca email:                    cchang76@myseneca.c
// Date of completion:              11/27/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

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
