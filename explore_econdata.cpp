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
			//while(true){
				display_choices(state_array,number_of_states);


			//}			
				
			
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
/*
struct muldiv_entry** generate_tables(int n){
	struct muldiv_entry **c;
	c = new struct muldiv_entry *[n];
	for(int i=0; i <n; i++){
		c[i] = new struct muldiv_entry [n];
	}
	for(int i = 0; i< n; i++){
		for(int j = 0; j<n; j++){
			c[i][j].mul = (i+1)*(j+1);
			c[i][j].div = (float)(i+1)/(float)(j+1);
		}
	}
	return c;
}

void print_tables(struct muldiv_entry** tables, int n){
	cout << endl << "Multiplication Table:" << endl << endl;
	for(int i = 0; i < n; i++){
		for(int j=0; j < n; j++){
			cout << tables[i][j].mul << "   ";
		}
		cout << endl;
	}
	cout << endl << "Division Table:" << endl << endl;
	for(int i=0; i< n; i++){
		for(int j=0;j<n;j++){
			//cout << tables[i][j].div << "   ";
			printf("%.2f  " , tables[i][j].div);
		}
		cout << endl;
	}
	return;
}

void free_tables(struct muldiv_entry** tables, int n){
	for(int i = 0; i < n;i++){
		delete [] tables[i];
	}
	//for(int i = 0; i < n; i++){
	delete [] tables;
	//}
}
*/
