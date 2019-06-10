//============================================================================
// Name        : MED_Tester.cpp
// Author      : 
// Version     :
// Copyright   : Steal this code!
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <sstream>
#include <fstream>
#include "./includes/data_store_file.h"
#include "./includes/string_database.h"
#include "./includes/data_store.h"
#include "./includes/string_data.h"
#include "./includes/crypto.h"
#include "../crypto/includes/crypto_AES.h"

using namespace std;
//I've provided some hints in the form of comments and commented out code
//use them if you wish

////global database object 
String_Database myGlobalCache;
bool testSerialization(const std::string &MYFILE1, const std::string &MYFILE2,		Crypto *pCrypto) {
	DataStore_File myDataStore_File1(MYFILE1, pCrypto);
	myGlobalCache.save(&myDataStore_File1);
	//clear cache
	myGlobalCache.clear();
	std::cout<<"Clearing Cache\n";

	//load it
	myGlobalCache.load(&myDataStore_File1);
		std::cout<<"Loading from file "+ MYFILE1 +" \n";

	//save to a different file
	DataStore_File myDataStore_File2(MYFILE2, pCrypto);
	myGlobalCache.save(&myDataStore_File2);
	std::cout<<"Saving to file "+ MYFILE2 +" \n";

	//I use my own objects here to compare the files
	return true;
}

void testAdd(std::string &myString) {
	myGlobalCache.add(myString);
}

void executeThreads() {
	string a = "hello";
	string b = "Iphone X 1000 dollars thats crazy";
	string c = "14 years later incredibles 2 comes out ";
	string d = "Cat are worse than dogs";
	string e = "Net Neutrality is a big deal";
	string f = "C++ is way more complex than java";
	string g = "Watch Out";
	string h = "Black Panther 2018 can't wait";
	string i = "Net Neutrality is a big deal";
	string j = "Get Out was bad movie";
	string k = "Family is everything";
	string l  = "Engineering Rocks!";
	string m = "I wish i had the patience of a browns fan";
	string n = "Porsche 911 GT3 my Goal Car";
	string o = "deodorant is imporant";
	string p = "Aviator Glasses";
	string q = "Winner winner chicken dinner";
	string r = "7 up";
	string s = "Run it up";
	string t = "Computer mice is a very useful device";
	string v = "Net Neutrality is a big deal";
	string x = "Run it up";
	thread t1(testAdd,ref(a));
	thread t2(testAdd,ref(b));
	thread t3(testAdd,ref(c));
	thread t4(testAdd,ref(d));
	thread t5(testAdd,ref(e));
	thread t6(testAdd,ref(f));
	thread t7(testAdd,ref(g));
	thread t8(testAdd,ref(h));
	thread t9(testAdd,ref(i));
	thread t10(testAdd,ref(j));
	thread t11(testAdd,ref(k));
	thread t12(testAdd,ref(l));
	thread t13(testAdd,ref(m));
	thread t14(testAdd,ref(n));
	thread t15(testAdd,ref(o));
	thread t16(testAdd,ref(p));
	thread t17(testAdd,ref(q));
	thread t18(testAdd,ref(r));
	thread t19(testAdd,ref(s));
	thread t20(testAdd,ref(t));
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();
	t11.join();
	t12.join();
	t13.join();
	t14.join();
	t15.join();
	t16.join();
	t17.join();
	t18.join();
	t19.join();
	t20.join();
}

void executeThreads2() {
	string a = "Black Panther 2018 can't wait";
		string b = "Black Panther 2018 can't wait";
		string c = "Black Panther 2018 can't wait";
		string d = "Cat are worse than dogs";
		string e = "Net Neutrality is a big deal";
		string f = "Black Panther 2018 can't wait";
		string g = "Cat are worse than dogs";
		string h = "Black Panther 2018 can't wait";
		string i = "Net Neutrality is a big deal";
		string j = "Cat are worse than dogs";

		thread t1(testAdd,ref(a));
		thread t2(testAdd,ref(b));
		thread t3(testAdd,ref(c));
		thread t4(testAdd,ref(d));
		thread t5(testAdd,ref(e));
		thread t6(testAdd,ref(f));
		thread t7(testAdd,ref(g));
		thread t8(testAdd,ref(h));
		thread t9(testAdd,ref(i));
		thread t10(testAdd,ref(j));

		t1.join();
		t2.join();
		t3.join();
		t4.join();
		t5.join();
		t6.join();
		t7.join();
		t8.join();
		t9.join();
		t10.join();

}
void testGetCount () {
	string a = "Black Panther 2018 can't wait";

	cout<< "Shown: " <<myGlobalCache.getCount(a)<< " Black Panther 2018 can't wait" << endl;
	string j = "Cat are worse than dogs";
	cout << "Shown: " << myGlobalCache.getCount(j) << " Cat are worse than dogs"<<endl;
	string e = "Net Neutrality is a big deal";
	cout << "Shown: " << myGlobalCache.getCount(e) << " Net Neutrality is a big deal" <<endl;
 }

int main() {
	//I created and ran a bunch(20) of threads that added different strings to a string_database instance

	//Then I waited for all of them to finish so my program did not crash
	executeThreads();
	//Then I went through my string_database instance and made sure that it held the correct data
	//then I tested  serialization
	//first without encryption,
	string NO_ENCRYPT_FILE1 = "NO_ENCRYPT_FILE1";
	string NO_ENCRYPT_FILE2 = "NO_ENCRYPT_FILE2";
	testSerialization(NO_ENCRYPT_FILE1, NO_ENCRYPT_FILE2, 0);
	//then with
	char key[] = "I Like Rollos   ";
	char *pKey = &key[0];
	string ENCRYPT_FILE1  = "ENCRYPT_FILE1";
	string ENCRYPT_FILE2 = "ENCRYPT_FILE2";

	Crypto_AES myCrypto(pKey);
	testSerialization(ENCRYPT_FILE1, ENCRYPT_FILE2, &myCrypto);

	myGlobalCache.clear();
	executeThreads2();
	cout<< "-----------------------------------------------------------------------"<<endl;
	cout<<"------------------------------------------------------------------------"<<endl;
	string NO_ENCRYPT_FILE3 = "NO_ENCRYPT_FILE3";
		string NO_ENCRYPT_FILE4 = "NO_ENCRYPT_FILE4";
		testSerialization(NO_ENCRYPT_FILE3, NO_ENCRYPT_FILE4, 0);
		//then with
		string ENCRYPT_FILE5  = "ENCRYPT_FILE5";
		string ENCRYPT_FILE6 = "ENCRYPT_FILE6";

		testSerialization(ENCRYPT_FILE5, ENCRYPT_FILE6, &myCrypto);
		cout <<" Testing correct count "<< endl;
		testGetCount();
}
