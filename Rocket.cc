
#include "Rocket.h"

Rocket::Rocket(const string& name) : name(name) {
    parts = *new Array<Part*>();
}

bool Rocket::equals(const string& name) const {
    return this->name == name;
}

bool Rocket::needInspection(const Date& d) {
    int i = 0;
    int j = 0;
    while (i < parts.getSize()) {
        if (parts[i]->needsInspection(d)) {
            ++j;
        }
        ++i;
    }
    return j > 0;
}

bool Rocket::install(Part* p, const Date& d) {
    p->inspect(d);
    parts.operator+=(p);
    return p->needsInspection(d);
}

bool Rocket::launch(const Date& d) {
    if (this->needInspection(d)) return false;
    else {
        for (int i = 0; i < parts.getSize(); ++i) {
            parts[i]->launch();
        }
    }
    return true;
}

void Rocket::getPartsToInspect(const Date& d, Array<Part*>& toInspect) {
    for (int i = 0; i < parts.getSize(); ++i) {
        if (parts[i]->needsInspection(d)) {
            toInspect.operator+=(parts[i]);
        }
    }
}

void Rocket::print(ostream& os) const {
    os << "Rocket: " << name << endl;
}

ostream& operator<<(ostream& os, const Rocket& r) {
    r.print(os);
    return os;
}