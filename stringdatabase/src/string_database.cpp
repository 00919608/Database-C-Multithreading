#include "../includes/string_database.h"
#include "../../datastore/includes/data_store_file.h"
#include<string>
#include <vector>
#include <mutex>

using namespace std;

String_Database::String_Database() {

}

String_Database::~String_Database() {

}
mutex mutex1;
int String_Database::getCount(std::string &myString) {
	std::lock_guard<std::mutex> guard(mutex1);
	for(myStringsIter = myStrings.begin(); myStringsIter != myStrings.end(); ++myStringsIter) {
				if(myStringsIter->operator==(myString)){
					return myStringsIter->getCount();
				}
	}
	return 0;
}

void String_Database::clear() {
	std::lock_guard<std::mutex> guard(mutex1);
	myStrings.clear();
}


bool String_Database::load(DataStore  *myDataStore) {
	if(myDataStore != 0) {
	std::lock_guard<std::mutex> guard(mutex1);
		myDataStore->load(myStrings);
		return true;
	}
	else {
		return false;
	}
}

bool String_Database::save(DataStore *myDataStore) {
	if(myDataStore != 0 ) {
	std::lock_guard<std::mutex> guard(mutex1);
		myDataStore->save(myStrings);
		return true;
	}
	else {
		return false;
	}
}

void String_Database::add(std::string &myString) {
	bool isThere = false;
	std::lock_guard<std::mutex> guard(mutex1);
	for(myStringsIter = myStrings.begin(); myStringsIter != myStrings.end(); ++myStringsIter) {
			if(myStringsIter->operator ==(myString)) {
				myStringsIter->increment();
				isThere = true;
			}
	}
	if(!isThere){
		myStrings.push_back(myString);
	}
	else {
		return;
	}

}
