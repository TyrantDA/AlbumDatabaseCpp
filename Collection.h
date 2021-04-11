/* 
 * File:   Collection.h
 * Author: Alexander
 *
 * Created on 20 April 2019, 18:31
 */

#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include "Album.h"


using namespace std;

class Collection {
public:
    Collection();
    Collection(string n);
    void addAlbum(Album album);
    void artistDurationLength(string art);
    void mostTrack();
    void CompareTracks();
    Collection sortCollection();
    string getTitle() const;
    Album getAlbum(int a) const;
    void setAlbum(int a, Album alb); 
    int getLength() const;
    
private:
    string title;
    vector<Album> albums;
};

inline ostream& operator<<(ostream& os, const Collection &c)
{
    os << c.getTitle() << "\n";
    for(int x = 0; x < c.getLength(); x++)
    {
        os << c.getAlbum(x) << "\n";
    }
    return os;
}

inline istream& operator>>(istream& is, Collection& c)
{
    Album album;
    
    while(is)
    {
        is >> album;
        c.addAlbum(album);
    }
    return is;
}
#endif /* COLLECTION_H */

    
