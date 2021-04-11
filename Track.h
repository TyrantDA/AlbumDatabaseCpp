/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Track.h
 * Author: Alexander
 *
 * Created on 08 April 2019, 00:00
 */

#ifndef TRACK_H
#define TRACK_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <iomanip>
#include "Duration.h"


using namespace std;

class Track {
public:
    Track();
    Track(Duration d, string t);
    Track(string tra);
    string getTrack() const;
    Duration getDuration() const;
    
private:
    string track;
    Duration duration;
};

inline ostream& operator<<(ostream& os, const Track &t)
    {
        return os << t.getDuration() << " - " << t.getTrack();
    }

inline istream& operator>>(istream& is, Track& t)
{
    Duration duration;
    string hold;
    string track;
    
    getline(is, hold, '-');
    
    duration = hold;
    
    getline(is, hold, ' ');
    getline(is, hold);
    
    track = hold;
    
    t = Track(duration, track);
    
    return is;
}

#endif /* TRACK_H */

