/* 
 * File:   main.cpp
 * Author: Alexander
 *
 * Created on 22 March 2019, 15:26
 */

#include <cstdlib>
#include "Duration.h"
#include "Track.h"
#include "Album.h"
#include "Collection.h"
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

void test() {
     Duration e(1,15,20);
    Duration d("4:15:30");
    
    // output should be 4
    cout << e.getHour() << endl;
    cout << d.getHour() << endl;
    // output should be 04:15:30
    cout << d << endl;
    // output should be 05:30:50
    Duration t = e.addDuration(d);
    cout << t << endl;
    // output should be 1
    int hold = e.compareDuration(d);
    cout << hold << endl;
    
    Track track(e,"MySong");
    cout << track.getTrack() << endl;
    cout << track << endl;
    
    Album album("Me","MyAlbum");
    album.addTrack(track);
    cout << album << endl;
    
    Collection collection("MyCollection");
    collection.addAlbum(album);
    collection.addAlbum(album);
    cout << collection << endl;
}

int main(int argc, char** argv) {
    
    Collection collection;
    
     ifstream is("albums.txt", ifstream::in);
    if(is)
    {   
        is >> collection;
        cout << collection << endl;
    }
    else 
    {
        cerr << "Error: unable to open input file" << endl;
    }
    
     // sortCollection creates a copy of the collection for better versatility
     // e.g. when sorting for display being able to return to the original 
     // order without needing another sorting algorithm 
     Collection sorted = collection.sortCollection();
     collection = sorted;
     cout << "sorted Collection" << endl;
     cout << collection << endl;

     
     collection.CompareTracks();
     cout << endl;
     collection.artistDurationLength("Pink Floyd");
     cout << endl;
     cout << "Album with most tracks" << endl;
     collection.mostTrack();
     
    return 0;
}

