#include <iostream>
#include <vector>
#include <fstream>


#include "../includes/data_store_file.h"
using namespace std;

vector<String_Data>::iterator vectorIterator;


DataStore_File::DataStore_File(std::string fileName, Crypto* crypto):DataStore(crypto),myFileName(fileName){

}


DataStore_File::~DataStore_File(void) {
}


bool DataStore_File::load(std::vector<String_Data> &myVector) {
	ifstream myFile;
	myFile.open(myFileName);
	if(myFile.is_open()){
		while(!myFile.eof()) {
			string line;
			getline(myFile,line);
			string data;
			int useCount;
			decrypt(line);
			String_Data::parseData(line,data,useCount);
			if(line != "") {
				myVector.push_back(String_Data(data,useCount));
			}
		}
		myFile.close();
		return true;
	}

	return false;
}


bool DataStore_File::save(std::vector<String_Data> &myVector) {
	ofstream myFile;
	myFile.open(myFileName);
		if(myFile.is_open()){
			for(vectorIterator = myVector.begin(); vectorIterator != myVector.end(); ++vectorIterator) {
				string a = vectorIterator->serialize();
				encrypt(a);
				myFile << a << endl;
			}
			myFile.close();
			return true;
		}
		return false;
}

bool DataStore_File::openFile(std::fstream& myfile,const std::string& myFileName, std::ios_base::openmode ) {
		myfile.open(myFileName.c_str());
		if(myfile.is_open()) {
			return true;
		}
		else {
			return false;
		}
}


void DataStore_File::closeFile(std::fstream& myfile) {
	myfile.close();

}
