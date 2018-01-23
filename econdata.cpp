/*********************************************************************
** Program Filename: econdata.cpp
** Author: Joshua Wentzel
** Date: 1/22/2018
** Description: Explore state and county economic data.
** Input: Path to file containing state and county economic data.
** Output: Statistics on state and county economic data.
*********************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <algorithm>
#include "econdata.hpp"
using namespace std;

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
struct state* allocate_states(int n){
	struct state *state_array;
	state_array = new struct state[n];
	return state_array;
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void read_state_data(struct state* state_array, int n, std::ifstream& input_file){
	for(int i = 0; i < n; i++){
		input_file >> state_array[i].name
			>> state_array[i].unemployed_2007
			>> state_array[i].unemployed_2015
			>> state_array[i].med_income
			>> state_array[i].n_counties;
		
		cout << endl;
		cout << state_array[i].name << state_array[i].unemployed_2007 << state_array[i].med_income << state_array[i].n_counties << endl << endl;
		
		state_array[i].counties = allocate_counties(state_array[i].n_counties);
		read_county_data(state_array[i].counties,state_array[i].n_counties,input_file);

	}

}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
struct county* allocate_counties(int n){
	struct county *county_array;
	county_array = new struct county[n];
	return county_array;
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void read_county_data(struct county* county_array, int n, std::ifstream& input_file){
	for(int i = 0; i < n; i++){
		input_file >> county_array[i].name
			>> county_array[i].unemployed_2007
			>> county_array[i].unemployed_2015
			>> county_array[i].med_income;
		
			cout << county_array[i].name << county_array[i].unemployed_2007 << county_array[i].med_income << endl;
	}
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void free_state_data(struct state* state_array, int n){
	for(int i = 0; i < n; i++){
		//for(int c = 0; c < state_array[i].n_counties; c++){
		delete [] state_array[i].counties;
		//}
	}
	delete [] state_array;

}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
int display_choices(struct state* state_array, int n){
	cout << "\033[2J";	// clear the screen
	cout << "To quit the program, enter '0'." << endl;
	cout << "To print the state with the highest median household income, ";
	cout << "enter '1'." << endl;
	cout << "To print the state with the lowest median household income, ";
	cout << "enter '2'." << endl;
	cout << "To print the state with the highest unemployment in 2015, ";
	cout << "enter '3'." << endl;
	cout << "To print the state with the lowest unemployment in 2015, ";
	cout << "enter '4'." << endl;
	cout << "To print the states sorted in order by change in ";
	cout << "unemployment from 2007 to 2015 (largest decrease to largest increase), ";
	cout << "enter '5'." << endl;
	cout << "To print the states sorted in order based on median household income, ";
	cout << "enter '6'." << endl;
	cout << "To get a list of states to do the above on a county level, ";
	cout << "enter '7'." << endl;
	
	int choice;
	cin >> choice;
	cout << "\033[2J";	// clear the screen
	switch(choice){
		case 0:
			cout << "exit program";
			return 1;
		case 1:
		{
			cout << "State with highest median household income: ";
			struct state* target_state= seek_state_highest_income(state_array,n);
			cout << target_state->name << " with " << target_state->med_income;
			cout << " dollars." << endl;
			return 0;
		}
		case 2:
		{
			cout << "State with lowest median household income: ";
			struct state* target_state= seek_state_lowest_income(state_array,n);
			cout << target_state->name << " with " << target_state->med_income;
			cout << " dollars." << endl;
			return 0;
		}
		case 3:
		{
			cout << "State with highest unemployment in 2015: ";
			struct state* target_state = seek_state_highest_unemployment(state_array, n);
			cout << target_state->name << " with " << target_state->unemployed_2015;
			cout << " percent." << endl;
			return 0;
		}
		case 4:
		{
			cout << "State with lowest unemployment in 2015: ";
			struct state* target_state= seek_state_lowest_unemployment(state_array,n);
			cout << target_state->name << " with " << target_state->unemployed_2015;
			cout << " percent." << endl;
			return 0;
		}
		case 5:
		{
			cout << "States sorted in order by change in ";
			cout << "unemployment from 2007 to 2015:" << endl;
			struct state* target_state= sort_state_unemployment_change(state_array,n);
			for(int i = 0; i < n; i++){
			cout << target_state[i].name << " with " << target_state[i].unemployed_2015;
			cout << " percent." << endl;
			}
			
			return 0;
		}
		
		case 6:
		{
			cout << "States sorted in order by median household income: ";
			cout << endl;
			struct state* target_state= sort_state_income(state_array,n);
			for(int i = 0; i < n; i++){
			cout << target_state[i].name << " with " << target_state[i].med_income;
			cout << " dollars." << endl;
			}
			
			return 0;
		}
		case 7:
			if(display_choices_states(state_array,n) == 0) {
				return 0;
			}
			else {
				return 1;
			}
		default:
			return 2;
			
	}
	
	return 1;

}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
int display_choices_states(struct state* state_array, int n){
	cout << "\033[2J";	// clear the screen
	cout << "To quit the program, enter '0'." << endl;
	for(int i = 0; i < n; i++){
		cout << "To select " << state_array[i].name << ", enter '" << i+1 << "'."<< endl;
	
	}
	int choice;
	cin >> choice;
	if(choice > 0){
		if(choice <= n){
			int total_counties = state_array[choice-1].n_counties;
			int quit = display_choices_specific(state_array[choice-1].counties
			, total_counties, state_array[choice-1].name);
			if(quit == 0)
				return 0;
			else
				return 1;
		}
	}

}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
int display_choices_specific(struct county* county_array, int n, string state_name){
	cout << "\033[2J";	// clear the screen
	cout << "With the state of " << state_name << " in mind..." << endl;
	cout << "To quit the program, enter '0'." << endl;
	cout << "To print the county with the highest median household income, ";
	cout << "enter '1'." << endl;
	cout << "To print the county with the lowest median household income, ";
	cout << "enter '2'." << endl;
	cout << "To print the county with the highest unemployment in 2015, ";
	cout << "enter '3'." << endl;
	cout << "To print the county with the lowest unemployment in 2015, ";
	cout << "enter '4'." << endl;
	cout << "To print the states sorted in order by change in ";
	cout << "unemployment from 2007 to 2015 (largest decrease to largest increase), ";
	cout << "enter '5'." << endl;
	cout << "To print the states sorted in order based on median household income, ";
	cout << "enter '6'." << endl;
	
	int choice;
	cin >> choice;
	
	cout << "\033[2J";	// clear the screen
	cout << "With the state of " << state_name << " in mind..." << endl;
	switch(choice){
		case 0:
			cout << "exit program";
			return 1;
		case 1:
		{
			cout << "County with highest median household income: ";
			struct county* target_county= seek_county_highest_income(county_array,n);
			cout << target_county->name << " with " << target_county->med_income;
			cout << " dollars." << endl;
			return 0;
		}
		case 2:
		{
			cout << "County with lowest median household income: ";
			struct county* target_county= seek_county_lowest_income(county_array,n);
			cout << target_county->name << " with " << target_county->med_income;
			cout << " dollars." << endl;
			return 0;
		}
		case 3:
		{
			cout << "County with highest unemployment in 2015: ";
			struct county* target_county = seek_county_highest_unemployment(county_array
			, n);
			cout << target_county->name << " with " << target_county->unemployed_2015;
			cout << " percent." << endl;
			return 0;
		}
		case 4:
		{
			cout << "County with lowest unemployment in 2015: ";
			struct county* target_county= seek_county_lowest_unemployment(county_array,n);
			cout << target_county->name << " with " << target_county->unemployed_2015;
			cout << " percent." << endl;
			return 0;
		}
		case 5:
			return 0;
		case 6:
			return 0;
		default:
			return 2;
			
	}

}


struct state* seek_state_highest_income(struct state* state_array,int n){
	int highest = 0;
	int index_highest = 0;
	for(int i = 0; i < n; i++){
		if(highest < state_array[i].med_income){
			highest = state_array[i].med_income;
			index_highest = i;
		}
	}
	return &state_array[index_highest];
}

struct state* seek_state_lowest_income(struct state* state_array,int n){
	int lowest = 9999999;
	int index_lowest = 0;
	for(int i = 0; i < n; i++){
		if(lowest > state_array[i].med_income){
			lowest = state_array[i].med_income;
			index_lowest = i;
		}
	}
	return &state_array[index_lowest];
}

struct state* seek_state_highest_unemployment(struct state* state_array,int n){
	float highest = 0;
	int index_highest = 0;
	for(int i = 0; i < n; i++){
		if(highest < state_array[i].unemployed_2015){
			highest = state_array[i].unemployed_2015;
			index_highest = i;
		}
	}
	return &state_array[index_highest];
}
struct state* seek_state_lowest_unemployment(struct state* state_array,int n){
	float lowest = 9999999;
	int index_lowest = 0;
	for(int i = 0; i < n; i++){
		if(lowest > state_array[i].unemployed_2015){
			lowest = state_array[i].unemployed_2015;
			index_lowest = i;
		}
	}
	return &state_array[index_lowest];
}


struct county* seek_county_highest_income(struct county* county_array,int n){
	int highest = 0;
	int index_highest = 0;
	for(int i = 0; i < n; i++){
		if(highest < county_array[i].med_income){
			highest = county_array[i].med_income;
			index_highest = i;
		}
	}
	return &county_array[index_highest];
}

struct county* seek_county_lowest_income(struct county* county_array,int n){
	int lowest = 9999999;
	int index_lowest = 0;
	for(int i = 0; i < n; i++){
		if(lowest > county_array[i].med_income){
			lowest = county_array[i].med_income;
			index_lowest = i;
		}
	}
	return &county_array[index_lowest];
}

struct county* seek_county_highest_unemployment(struct county* county_array,int n){
	float highest = 0;
	int index_highest = 0;
	for(int i = 0; i < n; i++){
		if(highest < county_array[i].unemployed_2015){
			highest = county_array[i].unemployed_2015;
			index_highest = i;
		}
	}
	return &county_array[index_highest];
}
struct county* seek_county_lowest_unemployment(struct county* county_array,int n){
	float lowest = 9999999;
	int index_lowest = 0;
	for(int i = 0; i < n; i++){
		if(lowest > county_array[i].unemployed_2015){
			lowest = county_array[i].unemployed_2015;
			index_lowest = i;
		}
	}
	return &county_array[index_lowest];
}


struct state* sort_state_unemployment_change(struct state* state_array, int n){
	
	struct state* states_copy = new struct state[n];
	std::copy(state_array, &state_array[n], states_copy);
	
	std::sort(states_copy, &states_copy[n], [] (const state& a, const state& b) {
		float change_1 = a.unemployed_2015 - a.unemployed_2007;
		float change_2 = b.unemployed_2015 - b.unemployed_2007;
		return (change_1 < change_2);
	});
	
	return states_copy;
}

struct state* sort_state_income(struct state* state_array, int n){
	
	
	struct state* states_copy = new struct state[n];
	std::copy(state_array, &state_array[n], states_copy);
	
	std::sort(states_copy, &states_copy[n], [] (const state& a, const state& b) {
		return (a.med_income < b.med_income);
	});
	
	return states_copy;
}




struct county* sort_county_unemployment_change(struct county* county_array, int n){
	
	struct county* counties_copy = new struct county[n];
	std::copy(county_array, &county_array[n], counties_copy);
	
	std::sort(counties_copy, &counties_copy[n], [] (const county& a, const county& b) {
		float change_1 = a.unemployed_2015 - a.unemployed_2007;
		float change_2 = b.unemployed_2015 - b.unemployed_2007;
		return (change_1 < change_2);
	});
	
	return counties_copy;
}
struct county* sort_county_income(struct county* county_array, int n);
