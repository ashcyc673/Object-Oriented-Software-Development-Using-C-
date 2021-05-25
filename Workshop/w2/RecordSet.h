// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NGG
// Date:           10/02/2020
//==============================================
// Workshop:     1
// Part:      2
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#ifndef WS2_RECORDSET_H
#define WS2_RECORDSET_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include <utility>

namespace sdds
{
    class RecordSet {
        char* filename;
        std::vector<std::string> data;
        size_t numOfRecord;

    public:
        RecordSet();
        explicit  RecordSet(const char* fname) ;
        RecordSet(const RecordSet& other);
        RecordSet &operator=(const RecordSet& otherEvent);
        ~RecordSet();
        size_t size();
        std::string getRecord(size_t);
        void addWord(const char* word);
        RecordSet( RecordSet&& other) ;
        RecordSet &operator=(RecordSet&& other);

    };
}



#endif //WS2_RECORDSET_H
