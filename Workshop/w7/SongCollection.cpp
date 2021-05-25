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

#include "SongCollection.h"

namespace sdds
{
    SongCollection::SongCollection(const std::string& file)
    {
        if(file.length() != 0)
        {
            std::ifstream fin(file);
            if(fin.is_open())
            {
                while(fin.good())
                {
                    std::string artist;
                    std::string title;
                    std::string album;
                    double price;
                    std::string releaseYear;
                    size_t lengthOfSong;
                    char buffer[256];
                    fin.getline(buffer,26);
                    fin.clear();
                    if (buffer[0] == '\0')
                    {
                        fin.clear();
                        fin.ignore(2000,'\n');
                        fin.close();
                        break;
                    }
                    title = omitSpace(buffer);
                    fin.getline(buffer,26);
                    fin.clear();
                    artist = omitSpace(buffer);
                    fin.getline(buffer,26);
                    fin.clear();
                    album = omitSpace(buffer);
                    fin.getline(buffer,6);
                    fin.clear();
                    releaseYear = omitSpace(buffer);
                    fin.getline(buffer,6);
                    fin.clear();
                    lengthOfSong = std::stoi(buffer);
                    fin.getline(buffer,6,'\n');
                    price = std::stod(buffer);
                    songCollection.push_back(Song({artist,title,album,price,releaseYear,lengthOfSong}));
                }
            }
            fin.close();
        }
    }

    std::string SongCollection::omitSpace(const std::string& space)
    {
        std::string result;
        for (size_t i = 0; i < space.length(); ++i) {
            if (i >= space.find_first_not_of(' ') && i <= space.find_last_not_of(' ')) {
                result += space[i];
            }
        }
        return result;
    }

    std::string secToMin(size_t sec)
    {
        size_t min;
        size_t secs;
        size_t hour;
        min = (sec % 3600) / 60;
        secs = (sec % 3600) % 60 ;
        hour = sec / 3600;
       return (hour > 0 ? std::to_string(hour) + ":" : "") + std::to_string(min) + ":" + (secs < 10 ? "0" : "") + std::to_string(secs);
    }

    void SongCollection::display(std::ostream& out) const
    {
        size_t sum = 0;
       for(auto i = songCollection.begin(); i != songCollection.end(); i++)
       {
           out << (*i) << std::endl;
           sum += (*i).lengthOfSong;
       }
       out << "----------------------------------------------------------------------------------------\n";
       out << "| ";
       out.width(86);
       std::string total = "Total Listening Time: " + secToMin(sum) + " |";
       out << std::right <<total << std::endl;
    }

    std::ostream& operator<<(std::ostream& out, const Song& theSong)
    {
        out << "| " ;
        out.width(20);
        out << std::left << theSong.title;
        out << " | ";
        out.width(15);
        out << std::left << theSong.artist;
        out << " | ";
        out.width(20);
        out << std::left << theSong.album;
        out << " | ";
        out.width(6);
        out << std::right << theSong.releaseYear;
        out << " | " << std::right << secToMin(theSong.lengthOfSong);
        out << " | " << std::right << theSong.m_price << " |";
       return out;
    }

    void SongCollection::sort(const std::string& value)
    {
        if(value == "title")
        {
            std::sort(songCollection.begin(),songCollection.end(),[&](const Song& first,const Song& last){
                return first.title < last.title;
            });
        }
        else if(value == "album")
        {
            std::sort(songCollection.begin(),songCollection.end(),[&](const Song& first,const Song& last){
                return first.album < last.album;
            });
        }
        else if(value == "length")
        {
            std::sort(songCollection.begin(),songCollection.end(),[&](const Song& first,const Song& last){
                bool order = first.lengthOfSong < last.lengthOfSong || (first.lengthOfSong == last.lengthOfSong && first.m_price < last.m_price);
                return order;
            });
        }
    }

    void SongCollection::cleanAlbum()
    {
        for(auto i = songCollection.begin(); i != songCollection.end(); i++)
        {
            if((*i).album == "[None]")
            {
                (*i).album = "";
            }
        }
    }

    bool SongCollection::inCollection(const char* art) const
    {
        for(auto i = songCollection.begin(); i != songCollection.end(); i++)
        {
            if((*i).artist == art)
            {
                return true;
            }
        }
        return false;
    }

    std::list<Song> SongCollection::getSongsForArtist(const char* art) const
    {
        std::list<Song> fullList;
        for(auto i = songCollection.begin(); i != songCollection.end(); i++)
        {
            if((*i).artist == art)
            {
                fullList.push_back(*i);
            }
        }
        return fullList;
    }
}