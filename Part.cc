
#include "Part.h"

bool Part::equals(const string& partName) const {
    return this->name == partName;
}

void Part::inspect(const Date& d) {
    this->lastInspected = d;
    this->launches = 0;
}

void Part::launch() {
    this->launches++;
}

void Part::install(const string& rocketName, const Date& d) {
    this->rocket = rocketName;
    this->lastInspected = d;
}

bool Part::needsInspection(const Date& d) {
    return 0;
}

void Part::print(ostream& os) const {
    os << "Part: " << this->name << endl;
}

ostream& operator<<(ostream& os, const Part& p) {
    p.print(os);
    return os;
}


//Launch Threshold class
LT_Part::LT_Part(const string& name, const Date& manufactureDate, int launchThreshold) {
    this->name = name;
    this->lastInspected = manufactureDate;
    this->launchThreshold = launchThreshold;
    launches = 0;
}

LT_Part::~LT_Part() = default;

bool LT_Part::needsInspection(const Date& d) {
    return this->launches >= this->launchThreshold;
}

void LT_Part::print(ostream& os) const {
    Part::print(os);
    os << "Launch threshold (max launches btwn inspections): " << this->launchThreshold << endl << endl;
}


//Time Threshold class
TT_Part::TT_Part(const string& name, const Date& manufactureDate, int timeThreshold) {
    this->name = name;
    this->lastInspected = manufactureDate;
    this->timeThreshold = timeThreshold;
    launches = 0;
}

TT_Part::~TT_Part() = default;

bool TT_Part::needsInspection(const Date& d) {
    return d.toDays() - lastInspected.toDays() >= timeThreshold;
}

void TT_Part::print(ostream& os) const {
    Part::print(os);
    os << "Time threshold (max days btwn inspections): " << this->timeThreshold << endl << endl;
}


//LT_TT_Part class
LT_TT_Part::LT_TT_Part(const string& name, const Date& manufactureDate, int launchThreshold, int timeThreshold)
    :LT_Part(name, manufactureDate, launchThreshold), TT_Part(name, manufactureDate, timeThreshold){}

LT_TT_Part::~LT_TT_Part() = default;

bool LT_TT_Part::needsInspection(const Date& d) {
    bool a,b,c;
    a = LT_Part::needsInspection(d);
    b = TT_Part::needsInspection(d);
    c = a || b;
    return c;

}

void LT_TT_Part::print(ostream& os) const {
    LT_Part::print(os);
    TT_Part::print(os);
}

