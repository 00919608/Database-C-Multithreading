#include "../includes/data_store.h"

#include <string>
#include <vector>


using namespace std;


DataStore::DataStore(Crypto *pCrypt):myCrypto(pCrypt) {

}

DataStore::~DataStore(void){

}
bool DataStore::decrypt(std::string &myString) {
	if(myCrypto != 0) {
		myCrypto->decrypt(myString);
		return true;
	}
	return false;
}


bool DataStore::encrypt(std::string &myString) {
	if(myCrypto != 0) {
			myCrypto->encrypt(myString);
			return true;
	}
		return false;
}



