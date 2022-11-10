#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;
using namespace chrono;
using namespace this_thread;

void showlist();

int main () {
    srand(time(NULL));
    fstream agent_file;
    fstream curragent_file;
    ifstream file_("agentlist.txt");
    int option;
    string line_;
    string line;
    vector<string> lines;
 
  
    while (true){
        this_thread::sleep_for(chrono::seconds(3));

        cout << "Checking for '1' in currentagent.txt..." << endl;

        curragent_file.open("currentagent.txt", ios::in);
        curragent_file >> option;
        curragent_file.close();

        if (option == 1){
            ifstream agent_file("agentlist.txt");
            int total_lines = 0;
                
                while(getline(agent_file,line)){
                    total_lines++; 
                    lines.push_back(line);  
                }
   
            int random_number=rand()%total_lines;

            cout << endl;
            cout << "1 has been entered, selecting random agent..." << endl;
            cout << lines[random_number] << " has been chosen." << endl;
            cout << endl;

            curragent_file.open("currentagent.txt", ios::out | ios::trunc);
            curragent_file << lines[random_number];
            curragent_file.close();
        }
    }
}
