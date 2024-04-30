
#include "Date.h"

Date::Date(){
    //cout <<"In default constructor"<<endl;
    setDate(1901,1,1);
}

Date::Date(int y, int m, int d){
    setDate(y,m,d);
}

//setters
void Date::setDay(int d){
    int max = getMaxDay();
    //cout <<"setting day: "<<d<<endl;
    if (d>max) d=max;
    if (d<1) d=1;
    day = d;
}

void Date::setMonth(int m){
    if (m > 12) m = 12;
    if (m < 1) m = 1;
    month = m;
}

void Date::setYear(int y){
    if (y < 1901) y = 1901;
    year = y;
}

void Date::setDate(int y, int m, int d){
    setMonth(m);
    setDay(d);
    setYear(y);
}

void Date::setDate(Date& d){
    setDate(d.year, d.month, d.day);
}


Date& Date::addDays(int days){
    int max = getMaxDay();
    day += days;
    while (day > max){
        day -= max;
        month++;
        if (month > 12){
            month = 1;
            year++;
        }
        max = getMaxDay();
    }
    return *this;
}



//getters
int Date::getDay()const{ return day; }
int Date::getMonth()const{ return month; }
int Date::getYear()const{ return year; }
const char* Date::getMonthName()const{return months[month-1];}


//other

// bool Date::operator<(const Date& d) const{
// 	if (year == d.year){
// 		if (month == d.month){
// 			return day < d.day;
// 		}else{
// 			return month  < d.month;
// 		}
// 	}else{
// 		return year < d.year;
// 	}
// }

int Date::toDays() const{
    int days = (year-1901)*365 + day;
    for (int i = 1; i < month; ++i){
        days += getDaysIn(i);
    }
    return days;
}

ostream& operator<<(ostream& out, const Date& d){
    return out << d.getMonthName()<<" "<<d.day<<", "<<d.year;
}

int Date::getMaxDay() const{
    return getDaysIn(getMonth());
}

int Date::getDaysIn(int month) const{
    switch(month){
        case 4:
        case 6:
        case 9:
        case 11: 			return 30;
        case 2:				return 28;
        default:			return 31;
    }
}

Date& Date::operator+=(int x) {
    int max = getMaxDay();
    day += x;
    while (day > max){
        day -= max;
        month++;
        if (month > 12){
            month = 1;
            year++;
        }
        max = getMaxDay();
    }
    return *this;
}