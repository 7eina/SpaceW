
#include "TestControl.h"

const string TestControl::rocket_name[ROCKET_NUM] = {"Falcon Heavy", "Starship", "Tie Fighter"};
const string TestControl::parts[PART_NUM]={"Merlin Engine", "Booster", "Oxidiser Tank", "Fuel Tank", "Vehicle Equipment Bay", "Cyogenic Upper Stage","Cryogenic Main Core", "Fuzzy Dice", "Fairing", "Upper Stage"};

const int TestControl::max_launches[PART_NUM] = {1, 2, 3, 4, 3, 2, 3, 0, 0, 0};
const int TestControl::max_days[PART_NUM] = {0, 0, 0, 0, 30, 60, 45, 50, 100, 90};

const string TestControl::menu[TEST_MENU] ={
    "addRocket and printRockets Test",
    "addPart and printParts Test",
    "installPart Test",
    "inspectionReport Test",
    "inspectRocket Test",
    "launchRocket Test"
};

/*  void addRocket();
    void addPart();
    void installPart();
    void inspectionReport();
    void inspectRocket();
    void launchRocket();*/

void TestControl::launch(){

    int choice = -1;

    while (choice!= 0){
        cout<<endl<<today<<endl;
        view.menu(menu, TEST_MENU, choice);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(choice){
            case 1: addRocket(); break;
            case 2: addPart(); break;
            case 3: installPart(); break;
            case 4: inspectionReport(); break;
            case 5: inspectRocket(); break;
            case 6: launchRocket(); break;
        }
    }
    cout<<"exiting program!!!"<<endl;
}

void TestControl::addRocket(){
    SpaceW sw;
    cout<<"Adding a single rocket and printing"<<endl;
    sw.addRocket(rocket_name[0]);
    initCapture();
    sw.printRockets();
    endCapture();

    int error = 0;
    vector<int> keys = {0};
    find(keys, rocket_name, error);

    if (error == 0){
        cout<<"add a single rocket and print Test passed, 2 marks"<<endl;
    }
    else{
        cout<<"add a single rocket and print Test failed (you may assign part marks out of 2)"<<endl;
    }

    pressEnterToContinue();

    cout<<"Adding multiple rockets and printing"<<endl;
    for (int i = 1; i < ROCKET_NUM; ++i){
        sw.addRocket(rocket_name[i]);
    }

    initCapture();
    sw.printRockets();
    endCapture();

    error = 0; 
    keys = {0, 1, 2};
    find(keys, rocket_name, error);

    if (error == 0){
        cout<<"add multiple rockets and print Test passed, 2 marks"<<endl;
    }
    else{
        cout<<"add multiple rockets and print Test failed (you may assign part marks out of 2)"<<endl;
    }

    cout<<"Test complete, please assign a mark out of 4 (2 for add rocket, 2 for print rockets)"<<endl;
}

void TestControl::addPart(){
   SpaceW sw;
    cout<<"Adding a single part and printing"<<endl;
    sw.addPart(parts[0], today, max_launches[0], max_days[0]);
    initCapture();
    sw.printParts();
    endCapture();

    int error = 0;
    vector<int> keys = {0};
    find(keys, parts, error);

    if (error == 0){
        cout<<"add a single part and print Test passed, 2 marks"<<endl;
    }
    else{
        cout<<"add a single part and print Test failed (you may assign part marks out of 2)"<<endl;
    }

    pressEnterToContinue();
    cout<<"Adding multiple parts and printing"<<endl;
    for (int i = 1; i < PART_NUM; ++i){
        sw.addPart(parts[i], today, max_launches[i], max_days[i]);
    }

    initCapture();
    sw.printParts();
    endCapture();

    error = 0; 
    keys = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    find(keys, parts, error);

    if (error == 0){
        cout<<"Add multiple parts and print Test passed, 2 marks."<<endl<<endl;
    }
    else{
        cout<<"Add multiple parts and print Test failed (you may assign part marks out of 2)."<<endl<<endl;
    }

    cout<<"Please inspect the output and assign an additional mark out of 3 ";
    cout<<"for proper formatting of different Parts. 3 (more) marks for proper formatting, ";
    cout<<"that is, different Part types print differently. ";
    cout<<"1 (more) mark if all Parts print the same (that is, printing without polymorphism)."<<endl<<endl;

    cout<<"Test complete, please assign a mark out of 5 (2 for add parts, 3 for print parts)"<<endl;
}

void TestControl::installPart(){
    SpaceW sw;
    initSpaceW(sw);
    

    int error = 0;
    vector<int> keys = {0, 1, 3, 2, 4, 5, 8, 9};

    cout<<"Installing parts and printing"<<endl;
    sw.printRockets();
    cout<<"Please inspect output for proper installation."<<endl<<endl;
    cout<<"Falcon Heavy:   Merlin Engine, Booster, Fuel Tank"<<endl;
    cout<<"Starship:       Oxidiser Tank, Vehicle Equipment Bay"<<endl;
    cout<<"Tie Fighter:    Cyogenic Upper Stage, Fairing, Upper Stage"<<endl<<endl;
    cout<<"3 marks if all Parts installed correctly, 2 marks if some Parts installed correctly"<<endl;
    cout<<"0 marks if no Parts installed (you may assign 1 mark at your discretion)."<<endl<<endl;

    cout<<"Test complete, please assign a mark out of 3"<<endl;
}

void TestControl::inspectionReport(){
    SpaceW sw;
    initSpaceW(sw);

    cout<<"Inspection Report"<<endl;
    sw.inspectionReport(today+=20);

    cout<<"Please inspect output for proper inspection report (should be none, 1 mark)"<<endl;

    pressEnterToContinue();

    cout<<"Inspection Report"<<endl;
    sw.inspectionReport(today+=20);

    cout<<"Please inspect output for proper inspection report (should be Starship, 1 mark)"<<endl;

    pressEnterToContinue();

    cout<<"Launching rockets:"<<endl;

    for (int i = 0; i < ROCKET_NUM; ++i){
        sw.launch(rocket_name[i], today+=7);
    }

    cout<<"Inspection Report"<<endl<<endl;

    pressEnterToContinue();
    sw.inspectionReport(today);

    cout<<"1 mark for Falcon Heavy needs inspection"<<endl;
    cout<<"1 mark for Tie Fighter needs inspection."<<endl;
    cout<<"(Starship should be there but Starship mark was given earlier.)"<<endl<<endl;

    pressEnterToContinue();

    cout<<"Test complete"<<endl<<endl;


}

void TestControl::inspectRocket(){
    SpaceW sw;
    initSpaceW(sw);

    today+=60; 


    cout<<"Inspection Report"<<endl;
    sw.inspectionReport(today);

    cout<<endl<<"Should show Starship and Tie Fighter need inspection"<<endl;

    pressEnterToContinue();

    cout<<"Inspecting all rockets: "<<endl;

    for (int i = 0; i < ROCKET_NUM; ++i){
        cout<<"Inspecting "<<rocket_name[i]<<endl;
        sw.inspect(rocket_name[i], today); 
        // cout<<"Inspection Report"<<endl;
        // sw.inspectionReport(today);
    }

    cout<<endl<<"Inspection Report"<<endl;
    sw.inspectionReport(today);
    cout<<"All three rockets should not require inspection, 2 marks" <<endl;
    pressEnterToContinue();

    cout<<"Launching rockets:"<<endl;

    for (int i = 0; i < ROCKET_NUM; ++i){
        sw.launch(rocket_name[i], today);
        sw.launch(rocket_name[i], today+=7);
    }

    cout<<"Inspection Report..."<<endl;
    pressEnterToContinue();
    sw.inspectionReport(today);

    cout<<"Should show Falcon Heavy and Tie Fighter needs inspection"<<endl;
    pressEnterToContinue();

    cout<<"Inspecting all rockets: "<<endl;

    for (int i = 0; i < ROCKET_NUM; ++i){
        cout<<"Inspecting "<<rocket_name[i]<<endl;
        sw.inspect(rocket_name[i], today); 
        // cout<<"Inspection Report"<<endl;
        // sw.inspectionReport(today);
    }

    cout<<endl<<"Inspection Report"<<endl;
    sw.inspectionReport(today);
    cout<<"All three rockets should not require inspection, 2 marks" <<endl;
    pressEnterToContinue();

    cout<<"Test complete, please assign a mark out of 4."<<endl<<endl;
    
}


void TestControl::launchRocket(){
    SpaceW sw;
    initSpaceW(sw);

    today+=7; 

    cout<<"Inspection Report"<<endl;
    sw.inspectionReport(today);

    cout<<"Attempting to launch all space vehicles 3 times"<<endl;

    for (int i = 0; i < ROCKET_NUM; ++i){
        cout<<"Launching "<<rocket_name[i]<<endl;
        sw.launch(rocket_name[i], today); 
        sw.launch(rocket_name[i], today+=7); 
        sw.launch(rocket_name[i], today+=7); 
    }

    pressEnterToContinue();

    cout<<"Output should look something like this:"<<endl;
    pressEnterToContinue();
    cout<<"Launching Falcon Heavy"<<endl;
    cout<<"Rocket Falcon Heavy has been launched!"<<endl;
    cout<<"Rocket Falcon Heavy requires an inspection before being launched"<<endl;
    cout<<"Rocket Falcon Heavy requires an inspection before being launched"<<endl;
    cout<<"Launching Starship"<<endl;
    cout<<"Rocket Starship has been launched!"<<endl;
    cout<<"Rocket Starship has been launched!"<<endl;
    cout<<"Rocket Starship requires an inspection before being launched"<<endl;
    cout<<"Launching Tie Fighter"<<endl;
    cout<<"Rocket Tie Fighter has been launched!"<<endl;
    cout<<"Rocket Tie Fighter has been launched!"<<endl;
    cout<<"Rocket Tie Fighter requires an inspection before being launched"<<endl<<endl;

    cout<<"1 mark for launching, 1 mark if rockets requiring inspection do not launch"<<endl;

    cout<<"Test complete, please assign a mark out of 2."<<endl<<endl;

    pressEnterToContinue();

    //sw.printRockets();

}

void TestControl::initSpaceW(SpaceW& sw){
    for (int i = 0; i < ROCKET_NUM; ++i){
        sw.addRocket(rocket_name[i]);
    }

    for (int i = 0; i < PART_NUM; ++i){
        sw.addPart(parts[i], today+=(i*2), max_launches[i], max_days[i]);
    }

    sw.installPart(rocket_name[0],parts[0], today+=1);
    sw.installPart(rocket_name[0],parts[1], today);
    sw.installPart(rocket_name[0],parts[3], today);
    sw.installPart(rocket_name[1],parts[2], today);
    sw.installPart(rocket_name[1],parts[4], today);
    sw.installPart(rocket_name[2],parts[5], today);
    sw.installPart(rocket_name[2],parts[8], today);
    sw.installPart(rocket_name[2],parts[9], today);
}



// s is the set to store count random numbers from 0 to range - 1
void TestControl::ran(vector<int>& list, int count, int range){
    unordered_set<int> s;
    const int range_from  = 0;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range-1);

    while (s.size() < count){
        s.insert(distr(generator));
    }
    unordered_set<int>::iterator it;
    for (it = s.begin(); it!=s.end();++it){
        list.push_back(*it);
    }
}

// generate and return a single random number in the range range_from to range_to - 1
int TestControl::ran(int range_from, int range_to){
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range_to-1);
    return distr(generator);
}

// strangely difficult to get this to work correctly
void TestControl::pressEnterToContinue(){
    std::cout << "Press enter to continue..."<<endl;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    char c = cin.get();
    while ( c != '\n') { 
        c = cin.get();
    }
}

void TestControl::find(vector<int>& keys, const string* search, int& error){
    int found = -1;
    error = 0;
    vector<int>::iterator ivid;
    for (ivid = keys.begin(); ivid != keys.end(); ++ivid){
        found = output.find(search[*ivid]);
        if (found == string::npos){
            std::cout<<"ERROR: "<<search[*ivid]<<" not found"<<endl;
            ++error;
        } 
    }
}

void TestControl::findInOrder(vector<int>& keys, const string* search, int& error){
    int found = -1;
    error = 0;
    vector<int>::iterator ivid;
    for (ivid = keys.begin(); ivid != keys.end(); ++ivid){
        found = output.find(search[*ivid], found+1);
        if (found == string::npos){
            std::cout<<"ERROR: "<<search[*ivid]<<" not found in order"<<endl;
            ++error;
        } 
    }
}

void TestControl::initCapture(){
    oldCoutStreamBuf = std::cout.rdbuf();
    ostringstream temp;
    strCout.swap(temp);
    std::cout.rdbuf( strCout.rdbuf() );
}

void TestControl::endCapture(){
    std::cout.rdbuf( oldCoutStreamBuf );
    output = strCout.str();
    std::cout << output;
}

