
#ifndef PART_H
#define PART_H

#include "Date.h"
#include "Part.h"
#include <iostream>
#include <string>

class Part { //Part abstract class
    friend ostream& operator<<(ostream& os, const Part& p); // prints part info
    public:
        bool equals(const string& name) const; // true if this name matches the argument

        void inspect(const Date& d); // sets lastInspected to d, launches to 0
        void launch(); // increments launches by 1
        void install(const string& rocket, const Date& d); // sets this->rocket to rocket, lastInspected to d

        virtual bool needsInspection(const Date& d); // true if this part needs inspection
        virtual void print(ostream& os) const; // prints part info

    protected:
        string name;
        string rocket;
        Date lastInspected;
        int launches;
};


class LT_Part : virtual public Part {
    public:
        LT_Part(const string& name, const Date& manufactureDate, int launchThreshold);
        virtual ~LT_Part();

        virtual bool needsInspection(const Date& d) override;
        virtual void print(ostream& os) const override;
    private:
        int launchThreshold;
};


class TT_Part : virtual public Part {
    public:
        TT_Part(const string& name, const Date& manufactureDate, int timeThreshold);
        virtual ~TT_Part();

        virtual bool needsInspection(const Date& d) override;
        virtual void print(ostream& os) const override;
    private:
        int timeThreshold;
};


class LT_TT_Part : public LT_Part, public TT_Part {
    public:
        LT_TT_Part(const string& name, const Date& manufactureDate, int launchThreshold, int timeThreshold);
        virtual ~LT_TT_Part();

        virtual bool needsInspection(const Date& d) override;
        virtual void print(ostream& os) const override;
};

#endif //PART_H
