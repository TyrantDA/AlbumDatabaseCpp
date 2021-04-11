/* 
 * File:   Duration.h
 * Author: Alexander
 *
 * Created on 22 March 2019, 15:28
 */


#ifndef DURATION_H
#define DURATION_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <iomanip>


using namespace std;

class Duration {
public:
    Duration();
    Duration(int h, int m, int s);
    Duration(string dur);
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    Duration addDuration(Duration dur);
    int compareDuration(Duration d);
    
    ~Duration();
private:
    int hour;
    int minute;
    int second;
};

inline ostream& operator<<(ostream& os, const Duration &d)
    {
        return os << std::setfill('0')
            << setw(2) << d.getHour()   << ":"
            << setw(2) << d.getMinute() << ":"
            << setw(2) << d.getSecond();
    }

inline istream& operator>>(istream& is, Duration& d)
{
    char a, b;
    int h, m, s;
    if(is >> h >> a >> m >> b >> s)
    {
        if(a == ':' && b == ':')
        {
            d = Duration(h,m,s);
        }
        else 
        {
            is.clear(ios_base::failbit);
        }
    }
    
    return is;
}
#endif /* DURATION_H */