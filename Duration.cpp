
#include "Duration.h"

//constructor that create a blank duration  
Duration::Duration() {
    hour = 0;
    minute = 0;
    second = 0;
}

// constructor that is passed the hour, minute and second as ints
Duration::Duration(int h, int m, int s) {
    hour = h;
    minute = m;
    second = s;
}

// constructor this is passed the hour, minute and second as one string
Duration::Duration(string dur) {
    vector<string> result;
    const char* delim = ":";
    
    std::size_t current, previous = 0;
     // find the first - in the string and set it as the current positions
    current = dur.find(delim);
    while (current != std::string::npos) {
        // add to the vector the characters in the array between previous and 
        // current positions
        result.push_back(dur.substr(previous, current - previous));
        previous = current + 1;
        // find the next : in the string starting a the new previous position
        // and set it location as the current position
        current = dur.find(delim, previous);
    }
    result.push_back(dur.substr(previous, current - previous));
    hour = stoi(result[0]);
    minute = stoi(result[1]);
    second = stoi(result[2]);
}

// return the hours
inline int Duration::getHour() const{
    return hour;
}

// return the minute
inline int Duration::getMinute() const{
    return minute;
}

// return the second
inline int Duration::getSecond() const{
    return second;
}

// add two duration  together 
Duration Duration::addDuration(Duration dur) {
    int h = 0, m = 0, s = 0;
    // hold contain the number of minute/hour that can be made out of 
    // the seconds/minutes  
    int hold = 0;
    
    s = this->second + dur.getSecond();
    if(s >= 60)
    {
        hold = s/60;
        s = s % 60;
    }
    
    m = this->minute + dur.getMinute() + hold;
    hold = 0;
    if(m >= 60)
    {
        hold = m/60;
        m = m % 60;
    }
    
    h = this->hour + dur.getHour() + hold;
    
    Duration addValues(h,m,s);
    return addValues;
}

// compares two durations to each other
// 0 if there are the same 1 if the first is smaller than the second duration
// -1 if the second duration is smaller than the second duration
int Duration::compareDuration(Duration dur) {
    int durInSeconds1 = 0;
    int durInSeconds2 = 0;
    
    durInSeconds1 = this->second + (this->minute*60) + (this->hour*(60*60));
    durInSeconds2 = dur.getSecond() + (dur.getMinute()*60) + 
            (dur.getHour()*(60*60));
    
    if(durInSeconds1 > durInSeconds2)
    {
        return -1;
    }
    else if(durInSeconds1 < durInSeconds2)
    {
        return 1;
    }
    else if(durInSeconds1 == durInSeconds2)
    {
        return 0;
    }
    return 0;
}

Duration::~Duration() {
}

