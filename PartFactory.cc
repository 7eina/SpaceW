
#include "PartFactory.h"

Part* PartFactory::createPart(const string& name, const Date& manufactureDate, int LT, int TT) {
    Part* part = new Part();
    if(LT > 0 && TT > 0){
        part = new LT_TT_Part(name, manufactureDate, LT, TT);
    } else if(LT > 0){
        part = new LT_Part(name, manufactureDate, LT);
    } else if(TT > 0){
        part = new TT_Part(name, manufactureDate, TT);
    }
    return part;
}