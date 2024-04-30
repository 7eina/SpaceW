
#ifndef ROCKET_H
#define ROCKET_H

#include "Part.h"
#include "Array.h"

class Rocket {

    public:
        Rocket(const string& name);

        //true if this name matches the argument
        bool equals(const string& name) const;

        //true if any part on this Rocket requires inspection
        bool needInspection(const Date& d);

        //returns all parts on this requiring inspection in toInspect
        void getPartsToInspect(const Date& d, Array<Part*>& toInspect);

        //true if any part on this Rocket requires inspection
        bool install(Part* p, const Date& d);

        //false if any part on this Rocket requires inspection
        //else, call launch() on all parts & return true
        bool launch(const Date& d);

        friend ostream& operator<<(ostream& os, const Rocket& r);   //print rocket name only
        void print(ostream& os) const;

    private:
        string name;
        Array<Part*> parts;
};


#endif //ROCKET_H
