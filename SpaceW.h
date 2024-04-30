
#ifndef SPACEW_H
#define SPACEW_H

#include <string>

#include "Array.h"
#include "Part.h"
#include "PartFactory.h"
#include "Rocket.h"

using namespace std;


class SpaceW {

    public:
        void addRocket(const string& name); //make new Rocket, add to rockets

        //makes new Part, adds to Parts
        void addPart(const string& name, const Date& MD, int LT, int TT);

        //if the Rocket & Part exist, install the Part on the Rocket
        void installPart(const string& rocketName, const string& partName, const Date& d);

        //if the Rocket exists & doesn't require inspection, launch Rocket
        void launch(const string& name, const Date& d);

        //if Rocket exists & requires inspection,
        //inspect all parts requiring inspection on the Rocket
        void inspect(const string& name, const Date& d);

        //print all Rockets that require inspection
        void inspectionReport(const Date& d);

        void printRockets(); //print all Rockets
        void printParts();   //print all Parts

        Part* getPart(const string& name);
        Rocket* getRocket(const string& name);

    private:
        Array<Rocket*> rockets;
        Array<Part*> parts;
        PartFactory* factory;

};


#endif //SPACEW_H
