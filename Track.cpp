
#include "Track.h"

// constructor that creates a blank track
Track::Track(){
    track = string();
    duration = Duration();
}

// constructor that is passed the duration and a string of the title
Track::Track(Duration d, string t){
    track = t;
    duration = d;
}

// constructor that is passed a string for the hold track
// this is divided into the two parts before being input to the track 
Track::Track(string tra)
{
     vector<string> result;
    const char* delim = " - ";
    
    std::size_t current, previous = 0;
    // find the first - in the string and set it a the current positions
    current = tra.find(delim);
    while (current != std::string::npos) {
        // add to the vector the characters in the array between previous and 
        // current positions
        result.push_back(tra.substr(previous, current - previous));
        previous = current + 3;
        // find the next - in the string starting a the new previous position
        // and set it location as the current position
        current = tra.find(delim, previous);
    }
    result.push_back(tra.substr(previous, current - previous));
    Duration dur(result[0]);
    track = result[1];
    duration = dur;
    
    
}

// return the track
string Track::getTrack() const{
    return track;
}

// return the Duration
Duration Track::getDuration() const{
    return duration;
}
