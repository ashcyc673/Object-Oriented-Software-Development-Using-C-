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

#include "RecordSet.h"

namespace sdds {
    RecordSet::RecordSet() {
        filename = nullptr;
        numOfRecord = 0;
    }

    RecordSet::RecordSet(const char *fname)  {
        if (fname != nullptr) {
            filename = new char[strlen(fname) + 1];
            strcpy(filename, fname);
            char buffer[256];
            std::ifstream textFile(this->filename);
            if (textFile.is_open()) {
                numOfRecord = 0;
                while (textFile.good()) {
                    textFile.getline(buffer, 255, ' ');
                    addWord(buffer);
                }
                textFile.close();
            }
        } else {
            *this = RecordSet();
        }
    }

    void RecordSet::addWord(const char *word) {
        if (word != nullptr) {
            data.push_back(word);
            numOfRecord++;
        }
    }

    RecordSet::RecordSet(const RecordSet &other) {
        filename = nullptr;
        *this = other;
    }

    RecordSet &RecordSet::operator=(const RecordSet &other) {
        if (this != &other) {
            if (
                filename != nullptr) {
                delete[] filename;
                filename = nullptr;
            }

            numOfRecord = other.numOfRecord;
            filename = new char[strlen(other.filename) + 1];
            strcpy(filename, other.filename);

            for (size_t i = 0; i < numOfRecord; i++) {

                data.push_back(other.data[i]);
            }

        } else {
            *this = RecordSet();
        }
        return *this;
    }

    RecordSet::~RecordSet() {

        delete[] filename;
        filename = nullptr;
    }

    size_t RecordSet::size() {
        return numOfRecord;
    }

    std::string RecordSet::getRecord(size_t record) {
        if (record >= 0 && numOfRecord != 0 && record <= numOfRecord) {
            return data[record];

        } else {
            return "";
        }
    }

    RecordSet::RecordSet( RecordSet &&other)  {

        filename = nullptr;
        numOfRecord = 0u;
        *this = std::move(other);
    }

    RecordSet &RecordSet::operator=(RecordSet &&other) {
        if (this != &other) {
            if(filename != nullptr)
            {
                delete[] filename;
                filename = nullptr;
            }

            numOfRecord = other.numOfRecord;
            filename = other.filename;
            other.filename  = nullptr;
            other.numOfRecord = 0u;
            data = std::move(other.data);
        }
        return *this;
    }
}
