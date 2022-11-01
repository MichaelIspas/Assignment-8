#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

void showlist();

int main () {
    srand(time(NULL));
    fstream agent_file;
    fstream curragent_file;
    ifstream file_("agentlist.txt");
    string userAnswer;
    int option;
    string line_;
    string line;
    vector<string> lines;

    showlist();  
  
    cout << "Input 1 to manually select an agent or input 0 to randomly select an agent." << endl << endl;
    cin >> option;
  
    if(option == 1){      
    cout << "Enter agent name" << endl;
    cin >> userAnswer;

    curragent_file.open("currentagent.txt", ios::out | ios::trunc);
    curragent_file.close();

    this_thread::sleep_for(chrono::seconds(3));

    ofstream curragent_file("currentagent.txt");
    curragent_file << userAnswer;
    curragent_file.close();

    cout << "Agent selected: " << userAnswer << endl;
    return 0;
    }
  
    if(option == 0) {
    ifstream agent_file("agentlist.txt");
    int total_lines = 0;
    while(getline(agent_file,line))
    {
        total_lines++; 
        lines.push_back(line);  
    }
   
    int random_number=rand()%total_lines;

    
    cout << lines[random_number] << endl;

    curragent_file.open("currentagent.txt", ios::out | ios::trunc);
    curragent_file << lines[random_number];
    curragent_file.close();
  
    return 0;
  }
}

void showlist(){
    ifstream file_("agentlist.txt");
    fstream agent_file;
    fstream curragent_file;
    string line_;
    string line;
    vector<string> lines;

    if(file_.is_open()){
        while(getline(file_,line_)){
            std::cout << line_<< '\n';
        }
        file_.close();
    }
        else{
            std::cout<<"file is not open"<< '\n';
            std::cin.get();
        }

    cout << endl;
}