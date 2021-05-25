// Name:           Chiao-Ya Chang
// Student Number: 130402191
// Email:          cchang76@myseneca.ca
// Section:        NGG
// Date:           11/06/2020
//==============================================
// Workshop:     7
// Part:      2
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <algorithm>


namespace sdds {

    std::string secToMin(size_t sec);
    struct Song {

        std::string artist;
        std::string title;
        std::string album;
        double m_price;
        std::string releaseYear;
        size_t lengthOfSong;

        friend std::ostream &operator<<(std::ostream &out, const Song &theSong);
    };

    class SongCollection {
        std::vector<Song> songCollection;
        std::string omitSpace(const std::string& space);
    public:

        SongCollection(const std::string &file);
        void display(std::ostream &out) const;
        void sort(const std::string& value);
        void cleanAlbum();
        bool inCollection(const char* art) const;
        std::list<Song> getSongsForArtist(const char* art) const;



    };
}


#endif //SDDS_SONGCOLLECTION_H
