
#include "Collection.h"

// constructor that create a blank constructor 
Collection::Collection(){
    title = "MyCollection";
}

// constructor that is passed the name of the collection
Collection::Collection(string n){
    title = n;
}

// adds an album to the the list of albums in the collection  
void Collection::addAlbum(Album album){
    albums.push_back(album);
}

// find the total length of all a given artist track duration 
// it is passed the artist name as a string
void Collection::artistDurationLength(string art){
    Duration durationTotal("00:00:00");
    
    for(Album a : albums)
    {
        if(a.getArtist().compare(art) == 1)
        {
            for(int y = 0; y < a.getLength(); y++)
            {
                durationTotal = durationTotal.addDuration(a.getTrack(y).getDuration());
            }
        }
    }
    cout << "Total Duration of " << art << " albums: " << durationTotal << endl;
}

// find the albums with the most tracks
void Collection::mostTrack() {
    int trackInAlbum = 0;
    int temp = 0;
    Album hold("hold", "hold");
    
    for(Album a : albums)
    {
        for(int y = 0; y < a.getLength(); y++)
        {
            temp++;
        }
        if(temp > trackInAlbum)
        {
            trackInAlbum = temp;
            hold = a;
        }
        temp = 0;
    }
    
    cout << hold << endl;
}

// finds the longest track
void Collection::CompareTracks(){
    Duration time("00:00:00");
    string song = "test";
    Track longestTrack(time, song);
    
    for(Album a : albums)
    {
        for(Track t : a.getTotalTrack())
        {
            int comp = longestTrack.getDuration().compareDuration(t.getDuration());
            if(comp == 1)
            {
                longestTrack = t;
            }
        }
    }
    cout << "The longest Track is: " << longestTrack << endl;
}

// sort the Collection in to alphabetical order using the compareAlbum function 
Collection Collection::sortCollection() {
    Collection sorted("sortedCollection");
    int a = 0;
    Album hold;
    
    
    // create copy of the collection 
    for(int x = 0; x < this->albums.size(); x++)
    {
        sorted.addAlbum(this->albums[x]);
    }
    
    for(int x = 0; x < sorted.getLength(); x++)
    {
        for(int y = (x+1); y < sorted.getLength(); y++)
        {
            if(sorted.getAlbum(x).compareAlbum(sorted.getAlbum(y)) == 1)
            {
                hold = sorted.getAlbum(y);
                sorted.setAlbum(y,sorted.getAlbum(x));
                sorted.setAlbum(x,hold);
            }
        }
    }
    return sorted;
}

// returns the title to the collection
string Collection::getTitle() const{
    return title;
}

// return a given Albums
// it is passed the position of the albums in the list as an int 
Album Collection::getAlbum(int a) const{
    return albums[a];
}

// set a given album to a given location in the albums vector
void Collection::setAlbum(int a, Album alb) {
    albums[a] = alb;
}

// returns the length of the list
int Collection::getLength() const{
    return albums.size();
}
