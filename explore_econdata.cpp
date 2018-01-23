/*********************************************************************
** Program Filename: econdata.cpp
** Author: Joshua Wentzel
** Date: 1/22/2018
** Description: Explore state and county economic data.
** Input: Path to file containing state and county economic data.
** Output: Statistics on state and county economic data.
*********************************************************************/

#include <iostream>
#include "econdata.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){


	cout << argc << endl;
	if(argc == 2){
		ifstream input_file(argv[1]);
		if(input_file.is_open()){
			//string line;
			//if(getline(input_file,line)){
			int number_of_states;
			input_file >> number_of_states;
			struct state* state_array = allocate_states(number_of_states);
			read_state_data(state_array,number_of_states,input_file);
			cout << "\033[2J";	// clear the screen
			while(true){
				if(display_choices(state_array,number_of_states) == 0){
				
				}
				else
				{
					break;
				}


			}			
				
			
			input_file.close();
			free_state_data(state_array,number_of_states);
		}
		else{
			cout << "Error: There was a problem opening the file." << endl;
		
		
		}
		//int n = atoi(argv[1]);
		//if (n <= 0){
		//	cout << "That is not a valid number greater than zero" << endl;
		//}
		//else{
			//cout << n << endl;
			//struct muldiv_entry** tables = generate_tables(n);
			//print_tables(tables,n);
			//free_tables(tables,n);
		//}	
	}
	else{
		cout << "Please enter a valid path to the data file." << endl;
	}
	
	
	
	return 0;
}