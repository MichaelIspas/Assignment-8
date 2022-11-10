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
        // loop every 3 seconds
        this_thread::sleep_for(chrono::seconds(3));

        cout << "Checking for '1' in currentagent.txt..." << endl;

        // open file, write from file to option variable, then close
        curragent_file.open("currentagent.txt", ios::in);
        curragent_file >> option;
        curragent_file.close();

        // if option holds integer '1', trigger random selection process
        if (option == 1){
            
            // read from pre-made text file, randomly select based on line number
            // and update a string variable with the information
            ifstream agent_file("agentlist.txt");
            int total_lines = 0;
                
                while(getline(agent_file,line)){
                    total_lines++; 
                    lines.push_back(line);  
                }
   
            int random_number=rand()%total_lines;

            // displays message when '1' is updated in text file and display agent name
            cout << endl;
            cout << "1 has been entered, selecting random agent..." << endl;
            cout << lines[random_number] << " has been chosen." << endl;
            cout << endl;
            
            //open file, erase file, write agent to file, then close file
            curragent_file.open("currentagent.txt", ios::out | ios::trunc);
            curragent_file << lines[random_number];
            curragent_file.close();
        }
    }
}
