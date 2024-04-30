
#ifndef PARTFACTORY_H
#define PARTFACTORY_H

#include "Part.h"

class PartFactory {
    public:
        //if LT = 0, return new TT_Part
        //if TT = 0, return new LT_Part
        //if LT > 0 and TT > 0, return new LT_TT_Part
        Part* createPart(const string& name, const Date& manufactureDate, int LT, int TT);

};


#endif //PARTFACTORY_H
