// Name:                            Chiao-Ya Chang
// Seneca Student ID:               130402191
// Seneca email:                    cchang76@myseneca.c
// Date of completion:              11/27/2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include "Utilities.h"

void Utilities::setFieldWidth(size_t newWidth)
{
    if( newWidth > m_widthField)
    {
        m_widthField = newWidth;
    }
}
size_t Utilities::getFieldWidth() const
{
    return m_widthField;
}
std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{

        more = false  ;
        std::string result;
        size_t start = next_pos;

        if (start < str.length()) {
            size_t end = str.find(getDelimiter(), start);
            next_pos = end + 1;

            if (end == std::string::npos) {
                end = str.length();
                next_pos = end;
            }

            if (end != std::string::npos) {
                result = str.substr(start, end - start);
                if (result.empty()) {
                    throw std::string ("Invalid Record");
                }
                setFieldWidth(result.length());
                more = true;
            }
        }
        return omitSpace(result);
}

std::string Utilities::omitSpace(const std::string& space)
{
    std::string result;
    for (size_t i = 0; i < space.length(); ++i) {
        if (i >= space.find_first_not_of(' ') && i <= space.find_last_not_of(' ')) {
            result += space[i];
        }
    }
    return result;
}
void Utilities::setDelimiter(char newDelimiter)
{
    if(newDelimiter != '\0')
    {
        m_delimiter = newDelimiter;
    } else
    {
        if(m_delimiter == '\0')
        {
            m_delimiter = ',';
        }
    }
}
char Utilities::getDelimiter()
{
    return m_delimiter;
}