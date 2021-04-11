
#include "Album.h"

// constructor that creates a blank 
Album::Album()
{
  artist = string();
  title = string();
}

// constructor that is passed a string of the artist and the title of the album
Album::Album(string art,string t){
    artist = art;
    title = t;
}

// add a track to the list of tracks
void Album::addTrack(Track track){
    tracks.push_back(track);
}

// compare album using the artist 
// it the artists are the same the titles of the albums are compared
// if the first album is smaller than the second -1 is returned
// if the first album is larger than the second 1 is returned
// if the first album is the same as is other 0 is returned 
int Album::compareAlbum(Album alb) {
    
    if(this->artist.compare(alb.getArtist()) < 0)
    {
        return -1;
    }
    else if(this->artist.compare(alb.getArtist()) > 0)
    {
        return 1;
    }
    else if(this->artist.compare(alb.getArtist()) == 0)
    {
        if(this->title.compare(alb.getTitle()) < 0)
        {
            return -1;
        }
        else if(this->title.compare(alb.getTitle()) > 0)
        {
            return 1;
        }
        else if(this->title.compare(alb.getTitle()) == 0)
        {
            return 0;
        }
    }
    
}

// return the Artist name
string Album::getArtist() const{
    return artist;
}
// return the title of the album
string Album::getTitle() const{
    return title;
}

// return a certain track
// this is passed an int 
Track Album::getTrack(int a) const{
    return tracks[a];
}

// return a vector of tracks 
vector<Track> Album::getTotalTrack() {
    return tracks;
}

// returns the length of the list of the tracks
int Album::getLength() const{
    return tracks.size();
}