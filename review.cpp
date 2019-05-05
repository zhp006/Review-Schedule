#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<windows.h>
using namespace std;

/*
* This function print out the welcome message to the screen
*/
void Welcome(){
	cout << " __     __     ______     __         ______     ______     __    __     ______     "                           << endl;
	cout << "/\\ \\  _ \\ \\   /\\  ___\\   /\\ \\       /\\  ___\\   /\\  __ \\   /\\ \"-./  \\   /\\  ___\\   "           << endl;
	cout << "\\ \\ \\/ \".\\ \\  \\ \\  __\\   \\ \\ \\____  \\ \\ \\____  \\ \\ \\/\\ \\  \\ \\ \\-./\\ \\  \\ \\  __\\   "<< endl;
	cout << " \\ \\__/\".~\\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\  \\ \\_\\ \\ \\_\\  \\ \\_____\\ "  << endl;
	cout << "  \\/_/   \\/_/   \\/_____/   \\/_____/   \\/_____/   \\/_____/   \\/_/  \\/_/   \\/_____/ "                   << endl;
}

void Quest(vector<string> today){

	int num_task = today.size();

	bool extra = false;
	bool flags[10];
	for(int i = 0; i < 10; i ++){
		flags[i] = false;
	}

	vector<string> printout;
	string padding = "                                   /";
	string tmp = padding;



	if(num_task <= 9){
		for(int i = 0; i < today.size(); i++){
			for(int j = 0; j < today.at(i).length(); j++){
				padding.at(j+2) = today.at(i).at(j);
			}

			padding.at(1) = '.';

			flags[i] = true;

			printout.push_back(padding);
			padding = tmp;

		}
	}
	else{
		extra = true;
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < today.at(i).length(); j++){
				padding.at(j+2) = today.at(i).at(j);
			}

			padding.at(1) = '.';

			flags[i] = true;

			printout.push_back(padding);
			padding = tmp;
		}
	}

	cout <<"                    ___________________________________________________________              "<< endl;
	cout <<"                  /                                                     /  __   \\           "<< endl;
	cout <<"                 /                                                     /  / _ \\  \\	     "<< endl;
	cout <<"                 |                                                    |	 |   | \\ |          "<< endl;
	cout <<"                 \\                                                     \\  \\_/  / /        "<< endl;
	cout <<"                   \\_____________________________________________________\\____/_/          "<< endl;
	cout <<"                         /                                                /                 "<< endl;
	
	if(flags[0])
	cout <<"                        /            " << '1' << printout.at(0) << endl;		
	else
	cout <<"                        /                                                /                  "<< endl;
	cout <<"                       /                                                /					 "<< endl;
	
	if(flags[1])
	cout <<"                      /            " << '2' << printout.at(1) << endl;
	else
	cout <<"                      /                                                /                    "<< endl;
	cout <<"                     /                                                /                     "<< endl;
	
	if(flags[2])
	cout <<"                    /            " << '3' << printout.at(2) << endl;
	else
	cout <<"                    /                                                /                      "<< endl;
	cout <<"                   /                                                /                       "<< endl;
	
	if(flags[3])
	cout <<"                  /            " << '4' << printout.at(3) << endl;
	else
	cout <<"                  /                                                /                        "<< endl;
	cout <<"                 /                                                /                         "<< endl;
	
	if(flags[4])
	cout <<"                /            " << '5' << printout.at(4) << endl;
	else
	cout <<"                /                                                /                          "<< endl;
	cout <<"               /                                                /                           "<< endl;
	
	if(flags[5])
	cout <<"              /            " << '6' << printout.at(5) << endl;
	else
	cout <<"              /                                                /                            "<< endl;
 	cout <<"             /                                                /                             "<< endl;
 	
 	if(flags[6])
 	cout <<"            /            " << '7' << printout.at(6) << endl;
 	else
 	cout <<"            /                                                /                              "<< endl;
 	cout <<"           /                                                /                               "<< endl;
	
	if(flags[7])
	cout <<"          /            " << '8' << printout.at(7) << endl;
	else
	cout <<"          /                                                /                                 "<< endl;
	cout <<"         /                                                /                                  "<< endl;
	
	if(flags[8])
	cout <<"        /            " << '9' << printout.at(8) << "____" << endl;
	else
	cout <<"        /                                                /____                               "<< endl;
	cout <<"       /                                                /  /   \\                            "<< endl;
	cout <<"      /                                                /  / _   |                            "<< endl;
	cout <<"     |                                                /  | | |  |                            "<< endl;
	cout <<"     \\                                                |   \\__/ /                           "<< endl;
	cout <<"      \\________________________________________________\\_____ /                            "<< endl;

	if(extra){
		cout << endl;
		cout << "Below are extra review tasks on your schedule: \n";

		for(int i = 9; i < today.size(); i++){
			cout << i+1 << ". "  << today.at(i) << endl;
		}
	}

}
/*
* This function print out the menu and return the user choice
*/
int Menu(){

	bool invalid = true;
	int i;

	while(invalid){
	cout << endl;
	cout << "Hello, what would you like to review today?" << endl;
	cout << "1. Today's review plan"                      << endl;
	cout << "2. Full reivew paln (15 days)"               << endl;
	cout << "3. Add items to the review plan"             << endl;
	cout << "4. Proceed to the next day"				  << endl;
	cout << "5. Exit"                                     << endl;
	
	cout << endl;
	cout << "Please select a number"                      << endl;
	cout << "I would like to do: ";

	cin >> i;

	if(i > 5 || i <= 0){
		cout << endl;
		cout << "Error! Invalid input please check and try again." << endl;
	}
	else
		invalid = false;


	}

	return i;
}

/*
* This function update the plan file when any change happened
*/
void Update(vector<vector<string>> *schedule){
	ofstream outFile;
	outFile.open("plan");

	for(int i = 0; i < schedule->size(); i++){
		for(int j = 0; j < schedule->at(i).size(); j++){
			outFile << schedule->at(i).at(j) << endl;
		}
		outFile << '#' << endl;
	}

	outFile.close();
	return;
}


/*
* Implementing pop functionality. Moving all elements in the vector
* one unit ahead and return the frist one
*/
//vector<string> pop(vector<vector<string>> *schedule){

void pop(vector<vector<string>> *schedule){

	//review list for today
	//vector<string> today;
	//empty list to append to the tail
	vector<string> empty;

	//get the front of vector
	//today = schedule->front();

	for(int i = 0; i < schedule->size()-1; i++){
		schedule->at(i) = schedule->at(i+1);
	}

	schedule->back() = empty;

	//return today;	
	return;
}


/*
* This function add tasks into the schedule
*/
void addTask(vector<vector<string>> *schedule){

	bool looping = true;

	string task;

	while(looping){
	cout << "Please keep it simple for your task name (less then 20 characters)" << endl;
	cout << "Please enter the item you want to review: " << endl;

	//clear the buffer and then get the user input
	cin.clear();
	fflush(stdin);
	getline(cin,task);

	if(task.length() < 20)
		break;

	cout << "Please pick a task name that is less then 20 characters and try again." << endl;
	
	}


	/*---------------------------------adding tasks to important day------------------------*/
	schedule->at(1).push_back(task);
	schedule->at(2).push_back(task);
	schedule->at(4).push_back(task);
	schedule->at(7).push_back(task);
	schedule->at(15).push_back(task);

	cout << "your task has been added sucessfully!" << endl;

	cout << "Your task is : " << task << endl;
	/*---------------------------------adding tasks to important day------------------------*/

}

void FullSchedule(vector<vector<string>> *schedule){

	cout << "            --------------------Full Schedule--------------------------" << endl;

	for(int i = 0; i < schedule->size(); i++){

		cout << "            Day " << i << ": \n";

		for(int j = 0; j < schedule->at(i).size(); j++){
			cout << "            	-" << schedule->at(i).at(j) << endl;
		}
		cout << endl;
	}
	
	cout << "            --------------------Full Schedule--------------------------" << endl;
}

/*
* This function do the corresponding task based on the user input
*/
void Task(int n, vector<vector<string>> *schedule){

	switch(n){
		case 1:
			Quest(schedule->front());
			break;
		case 2:
			FullSchedule(schedule);
			break;
		case 3:
			addTask(schedule);
			Update(schedule);
			break;
		case 4:
			pop(schedule);
			Update(schedule);
			break;
		case 5:
			Update(schedule);
			exit(1);
	}

}


int main(){

	/*------------------------------------------Loading data from file------------------------------------------------------------ */
	ifstream inFile;
	inFile.open("plan");

	//check if the file "plan" exists
	if(!inFile){
		cerr << "Error! Unable to load data from the file \"plan\". Please check and try again.";
		exit(1);
	}

	//initialize an empty schedule
	vector<vector<string>>schedule;

	//reading from the file
	string line;
	vector<string> tmp;
	while(getline(inFile,line)){

		if(line.at(0) == '#'){
			schedule.push_back(tmp);
			tmp.clear();
		}
		else{
			tmp.push_back(line);
		}
	}

	inFile.close();
	/*------------------------------------------Loading data from file------------------------------------------------------------ */






	//print the welcome message
	Welcome();

	while(1){
	
	//get the user input
	int i = Menu();

	//start executing chosen task
	Task(i, &schedule);
	
	}


}