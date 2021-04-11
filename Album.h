/* 
 * File:   Album.h
 * Author: Alexander
 *
 * Created on 08 April 2019, 14:51
 */

#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include "Track.h"
#include "Duration.h"


using namespace std;

class Album {
public:
    Album();
    Album(string art, string t);
    void addTrack(Track track);
    int compareAlbum(Album alb);
    string getArtist() const;
    string getTitle() const;
    Track getTrack(int a) const;
    vector<Track> getTotalTrack();
    int getLength() const;

private:
    string artist;
    string title;
    vector<Track> tracks;
};

inline ostream& operator<<(ostream& os, const Album &a)
    {
        os << a.getArtist() << ": " << a.getTitle();
        os << "\n";
        for(int x = 0; x < a.getLength(); x++)
        {
        os << a.getTrack(x) << "\n";
        }
        return os;        
    }

inline istream& operator>>(istream& is, Album& a)
{
    Track track;
    string artist;
    string title;
    string hold;
   
    getline(is, hold, ':');
    
    artist = hold;
   
    
    getline(is, hold, ' ');
    getline(is,hold);
    
    title = hold;
    a = Album(artist, title);
    
    getline(is,hold);
    while(isdigit(hold[0]) && is)
    {
        track = hold;
        a.addTrack(track);
        getline(is,hold);
    }
    if(!isdigit(hold[0]))
    {
        is.seekg(-(hold.length()+1),ios::cur);
    }
    return is;
}



#endif /* ALBUM_H */

