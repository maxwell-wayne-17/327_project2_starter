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
	string word = "";
	int number_occurences = 0;
};

//TODO add a global array of entry structs (global to this file)
entry globalArray[MAX_WORDS];

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

	return trackNext;
}

std::string getArrayWordAt(int i){

	return globalArray[i].word;

}

int getArrayWord_NumbOccur_At(int i){
	if (i > trackNext or i < 0){
		return FAIL_NO_ARRAY_DATA;
	}
	else{
		return globalArray[i].number_occurences;
	}
}

/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(std::fstream &myfstream){

	bool fileOpen = myfstream.is_open();
	if (!fileOpen){
		return fileOpen;
	}

	string line;

	while (!myfstream.eof()){
		getline(myfstream, line);
		processLine(line);
	}

	return fileOpen;
}

void processLine(std::string &myString){

	stringstream ss(myString);
	string tempToken;

	while (getline(ss, tempToken, CHAR_TO_SEARCH_FOR)){
		processToken(tempToken);
	}
}

void processToken(std::string &token){


	if (strip_unwanted_chars(token)){
		string upToken = token;
		toUpper(upToken);
		for (int i = 0; i < trackNext; i++){
			string upWord = globalArray[i].word;
			toUpper(upWord);
			if (upToken == upWord){
				globalArray[i].number_occurences += 1;
				return;
			}
		}

		entry newEntry;
		newEntry.word = token;
		newEntry.number_occurences = 1;
		globalArray[trackNext] = newEntry;
		trackNext++;
	}
	else{ //not a valid token, only unwanted chars, do nothing
		return;
	}
}

bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode ){ //= std::ios_base::in


	myfile.open(myFileName.c_str(), mode);
	if (myfile.is_open()){
		return true;
	}
	else{
		return false;
	}
}

void closeFile(std::fstream& myfile){
	if (myfile.is_open()){
	myfile.close();
	}

}

int writeArraytoFile(const std::string &outputfilename){

	fstream outputFile;

	bool openAttempt = openFile(outputFile, outputfilename, fstream::out);
	if (!openAttempt){
		return FAIL_FILE_DID_NOT_OPEN;
	}

	if (getArraySize() == 0){
		return FAIL_NO_ARRAY_DATA;
	}

	for (int i = 0; i < trackNext; i++){
		outputFile << globalArray[i].word << " " << globalArray[i].number_occurences << endl;
	}

	return SUCCESS;

}

void sortArray(constants::sortOrder so){ //taking the sort order enums

	entry trackEntry;

	switch(so){
		case NONE:{break;}

		case ASCENDING:{
			bool swap = true;
			while(swap){
				swap = false;
				for (int i = 0; i < trackNext - 1; i++){
					string mainWord = globalArray[i].word;
					string compWord = globalArray[i+1].word;

					toUpper(mainWord);
					toUpper(compWord);
					if(mainWord > compWord){
						swap = true;
						entry holder = globalArray[i];
						globalArray[i] = globalArray[i+1];
						globalArray[i+1] = holder;
					}
				}
			}
		break;
		}
	case DESCENDING:{
		bool swap = true;
					while(swap){
						swap = false;
						for (int i = 0; i < trackNext - 1; i++){
							string mainWord = globalArray[i].word;
							string compWord = globalArray[i+1].word;

							toUpper(mainWord);
							toUpper(compWord);
							if(mainWord < compWord){
								swap = true;
								entry holder = globalArray[i];
								globalArray[i] = globalArray[i+1];
								globalArray[i+1] = holder;
							}
						}
					}
		break;
	}
	case NUMBER_OCCURRENCES:{
		bool swap = true;
					while(swap){
						swap = false;
						for (int i = 0; i < trackNext - 1; i++){

							if(globalArray[i].number_occurences > globalArray[i+1].number_occurences){
								swap = true;
								entry holder = globalArray[i];
								globalArray[i] = globalArray[i+1];
								globalArray[i+1] = holder;
							}
						}
					}
		break;
	}
	}

}






