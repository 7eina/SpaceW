
#ifndef DATE_H
#define DATE_H



#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Date {

    friend ostream& operator<<(ostream& out, const Date&);

public:
    //constructor
    Date();
    Date(int, int, int);


    //setters
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    void setDate(int, int, int);
    void setDate(Date&);


    Date& addDays(int);

    //getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    const char* getMonthName() const;

    //other
    // bool operator<(const Date& d) const;
    //return the number of days since 1901/01/01
    int toDays() const;

    //increment Date by x days
    Date& operator+=(int x);

private:
    //functions
    int getMaxDay() const;

    int getDaysIn(int month) const;

    //variables
    int day;
    int month;
    int year;

    const char* months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    const char* smonths[12]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul","Aug", "Sep", "Oct", "Nov", "Dec"};

};


#endif //DATE_H
