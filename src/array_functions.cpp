/*
 * functionstocomplete.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: Max Wayne
 */

//============================================================================
//	TODO add necessary includes here
//============================================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <array>

#include "utilities.h"
#include "array_functions.h"
#include "constants.h"

using namespace std;
using namespace constants;

//============================================================================
//	stuff you will need
//============================================================================
//TODO define a structure to track words and number of times they occur
struct entry
{
	string word;
	int number_occurences;
};

//TODO add a global array of entry structs (global to this file)
entry globalArray[2000];

//TODO add variable to keep track of next available slot in array
	//entry nextVar = globalArray[0];
int trackNext = 0;

//TODO define all functions in header file

//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!
const int NOT_DONE = -9;
const bool FALSE_NOT_DONE = false;
const std::string STR_NOT_DONE = "not done";

void clearArray(){
	trackNext = 0;
}

int getArraySize(){
	int size = *(&globalArray + 1) - globalArray;
	return size;
}

std::string getArrayWordAt(int i){
	return STR_NOT_DONE;
}

int getArrayWord_NumbOccur_At(int i){
	return NOT_DONE;
}

bool processFile(std::fstream &myfstream){
	return FALSE_NOT_DONE;
}

void processLine(std::string &myString){

}

void processToken(std::string &token){

}

bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode ){ //= std::ios_base::in

	myfile.open(myFileName);
	if (myfile.is_open()){
		return true;
	}
	else{
		return false;
	}
}

void closeFile(std::fstream& myfile){
	myfile.close();
}

int writeArraytoFile(const std::string &outputfilename){
	return NOT_DONE;
}

void sortArray(constants::sortOrder so){

}






