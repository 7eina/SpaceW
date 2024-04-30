
#include "SpaceW.h"

void SpaceW::addRocket(const string& name) {
    Rocket* r = new Rocket(name);
    rockets.operator+=(r);
    cout << "Rocket " << name << " added" << endl;
}

void SpaceW::addPart(const string& name, const Date& MD, int LT, int TT) {
    Part* p = factory->createPart(name, MD, LT, TT);
    parts.operator+=(p);
    cout << "Part " << name << " added" << endl;
}

void SpaceW::installPart(const string& rocketName, const string& partName, const Date& d) {
    Rocket* r = getRocket(rocketName);
    Part* p = getPart(partName);
    if (r == nullptr) {
        cout << "Rocket " << rocketName << " not found" << endl;
        return;
    }
    if (p == nullptr) {
        cout << "Part " << partName << " not found" << endl;
        return;
    }
//    if (r->install(p, d)) {
//        cout << "Part " << partName << " installed in rocket " << rocketName << endl;
//    } else {
//        cout << "Part " << partName << " requires inspection, couldn't install" << endl;
//        p->inspect(d);
//        r->install(p, d);
//        cout << "Inspected Part " << partName << " & installed in rocket " << rocketName << endl;
//    }
    r->install(p, d);
    cout << "Installing Part: " << partName << ", on Rocket: " << rocketName << endl << endl;
}

void SpaceW::launch(const string& name, const Date& d) {
    if (getRocket(name) == nullptr) {
        cout << "Rocket " << name << " not found" << endl;
        return;
    }
    if (getRocket(name)->needInspection(d)) {
        cout << "Rocket " << name << " needs inspection, cannot launch" << endl;
        return;
    }
    getRocket(name)->launch(d);
    cout << "Rocket " << name << " launched!" << endl;
}

void SpaceW::inspect(const string& name, const Date& d) {
    if (getRocket(name) == nullptr) {
        cout << "Rocket " << name << " not found" << endl;
        return;
    }
    if (!getRocket(name)->needInspection(d)) {
        cout << "Rocket " << name << " doesn't require inspection" << endl;
        return;
    }
    cout << "Inspecting parts on: " << name << endl;
    Array<Part*> toInspect = Array<Part*>();
    getRocket(name)->getPartsToInspect(d, toInspect);
    for (int i = 0; i < toInspect.getSize(); ++i) {
        toInspect[i]->inspect(d);
    }
    cout << name << ": Inspection Complete :)" << endl;
}

void SpaceW::inspectionReport(const Date& d) {
    cout << "Rockets requiring inspection:" << endl;
    for (int i = 0; i < rockets.getSize(); ++i) {
        if (rockets[i]->needInspection(d)) {
            rockets[i]->print(cout);
        }
    }
    cout<< endl;
}

void SpaceW::printRockets() {
    cout << "Rockets:" << endl;
    for (int i = 0; i < rockets.getSize(); ++i) {
        rockets[i]->print(cout);
    }
    cout << endl;
}

void SpaceW::printParts() {
    cout << "Parts:" << endl;
    for (int i = 0; i < parts.getSize(); ++i) {
        parts[i]->print(cout);
    }
}



// helper f(x)
Part* SpaceW::getPart(const std::string &name) {
    int i = 0;
    while (i < parts.getSize()) {
        if (parts[i]->equals(name)) {
            break;
        }
        ++i;
    }
    if (i == parts.getSize() && !parts[i]->equals(name)) {
        cout << "Part " << name << " not found" << endl;
        return nullptr;
    }
    return parts[i];
}

Rocket* SpaceW::getRocket(const std::string &name) {
    int i = 0;
    while (i < rockets.getSize()) {
        if (rockets[i]->equals(name)) {
            break;
        }
        ++i;
    }
    if (i == rockets.getSize() && !rockets[i]->equals(name)) {
        cout << "Rocket " << name << " not found" << endl;
        return nullptr;
    }
    return rockets[i];
}