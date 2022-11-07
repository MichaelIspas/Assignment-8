#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>

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
  
    do{
        cout << "Input 1 to randomly select an agent, 0 to view the list of agents, ";
        cout << "or 2 to exit." << endl;
        cin >> option;
        cout << endl;
    
        if(option == 1){     
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

        cout << endl;
        } 
    
        else if(option == 0) {
        cout << endl;
        showlist();
        }

        else if (option == 2){
        }

        else {
            cout << "Invalid input. Please try again." << endl << endl;
        }

    }
    while(option != 2);  
    
    return 0;
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
