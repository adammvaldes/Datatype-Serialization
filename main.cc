#include "Serial.h"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int main(){
	Serial s;
	/*string st = "test";
	string st2 = "test2";
	s.put(st);
	s.put(st2);
	s.put("test3"s);
	s.put(true);
	s.put(false);
	s.put('a');
	s.put('b');
	cout << s.str() << "\n";
	cout << "Size: " << s.size() << "\n";
	Serial s2 = s;
	//cout << "Value at [0]: " << s2.serial_vector[0] << "\n";
	cout << "Empty? " << s.empty() << "\n" << s2.empty() << "\n";
	cout << s2.str() << "\n";*/
	
	
	
	/*\\s.put("Jack Applin"s);
	cout << s.str() << "\n";
	Serial s2;
	s2.put(true);
	cout << "Before: " << s2.str() << "Size: " << s2.size() << "\n";
	bool b;
	s2.get(b);
	cout << "B: " << b << "After: " << s2.str() << "Size: " << s2.size() << "\n";
	
	Serial s3;
	s3.put('c');
	cout << "Before: " << s3.str() << "\n";
	char c;
	s3.get(c*/
	
	Serial s4;
	//assert(s4.str() == "" && s4.size() == 0 && s.empty());
	//string testString = "";
	//testString += 'c';
	//testString += 'a';
	//cout << "TESTSTRING: " << testString << "\n";
	
	//s4.put('a');
	
	//assert(s4.str() == "ca");
	char c;
	cout << "Empty test 1: " << s4.empty() << "\n";
	s4.put(true);
	cout << "Str: " << s4.str() << "\n";
	cout << "Empty test 2: " << s4.empty() << "\n";
	bool b;
	try{
		s4.get(c);
		}
		catch(string st){
			cout << "Caught this string: " << st << "\n";
		}
	cout << "Empty test 3: " << s4.empty() << "\n";
	try{
		s4.get(b);
	}catch(string st){
		cout << "Caught this string: " << st << "\n";
	}
	// CHECK CONST CORRECTNESS
	Serial s5;
	const Serial s6;
	const char d = 'd';
	//char d = 'd';
	s5.put(d);
	//s6.put(d);
	cout << "Const test for size: " << s5.size() << "\n";
	cout << "Const test for size2: " << s6.size() << "\n";
	cout << "Const test for str: " << s6.str() << "\n";
	cout << "Const test for empty: " << s6.empty() << "\n";
	//cout << "GETTED C: " << c << "\n";
	//assert(c == 'a');
	Serial s7(s5);
	
	cout << "Copy constructor test: " << s7.str() << "\n";
	s7.put('t');
	Serial s8 = s7;
	cout << "Assignment operator test: " << s8.str() << "\n";
	
	Serial s9;
	const string tstring = "Jack";
	s9.put(tstring);
	cout << "String test: " << s9.str() << "\n";
    
    s9.str("S\x03xyz");
    string str_test = "foobar";
    s9.get(str_test);
    assert(str_test == "xyz" && s9.empty());
    int sh = 4;
    s9.put(sh);
    cout << "i\x04\n";
    assert(s9.str() == "i\x04");
	//cout << "Zero check\n";
	try{
    s9.get(str_test);
	}catch(string st){
		cout << st;
	}
	Serial s10;
	short shr = 4;
	s10.put(shr);
	cout << s10.str() << "\n";
	assert(s10.str() == "s\x04");
	long l = 66;
	s10.put(l);
	assert(s10.str() == "s\x04" "l\x10\x42");
	
	Serial s11;
	short sh2 = 66;
	s11.put(sh2);
	short sh3;
	try{
		s11.get(sh3);
	}catch(string st){
		cout << st;
	}
	cout << "S11 str: " << s11.str() << "\n";
	assert(sh3 == sh2);
	
	Serial s12;
	int it = 66;
	int it2;
	s12.put(it);
	try{
		s12.get(it2);
	}catch(string st){
		cout << st;
	}
	assert(it2 == it);
	
	Serial s13;
	long l3 = 6;
	long l2;
	s13.put(l3);
	try{
		s13.get(l2);
	}catch(string st){
		cout << st;
	}
	assert(l2 == l3);
	
	Serial s14;
	bool b14 = true;
	s14 += b14;
	s14 += false;
	s14 += 'a';
	Serial s15;
	s15.put('b');
	s15.put(false);
	s15.put('d');
	s14 += s15;
	//s14 += s14;
	cout << s14.str() << "\n";
	Serial s16;
	cout << "Overloading tests: \n";
	s16 += true;
	cout << s16.str() << "\n";
	s16 += 'a';
	cout << s16.str() << "\n";
	s16 += "Jack"s;
	cout << s16.str() << "\n";
	int i16 = 4;
	s16 += i16;
	cout << s16.str() << "\n";
	short sh16 = 4;
	s16 += sh16;
	cout << s16.str() << "\n";
	long l16 = 4;
	s16 += l16;
	cout << s16.str() << "\n";
	
	Serial s17;
	s17 += "Separate"s;
	//s17 += s16;
	s17 = s17 + true;
	cout << s17.str() << "\n";
	s17 = s17 + int(4);
	cout << s17.str() << "\n";
	s17 = s17 + short(4);
	cout << s17.str() << "\n";
	s17 = s17 + long(4);
	cout << s17.str() << "\n";
	s17 = s17 + 'a';
	cout << s17.str() << "\n";
	s17 = s17 + "End"s;
	cout << s17.str() << "\n";
	Serial s18;
	s18.put(false);
	s17 = s18 + "New"s;
	cout << s17.str() << "\n";
	s17 = true + s17;
	cout << s17.str() << "\n";
	s17.put('T');
	cout << s17.str() << "\n";
	bool b17;
	try{
		s17.get(b17);
	}catch(string st){
		cout << st <<"\n";
	}
	assert(b17);
	cout << s17.str() << "\n";
	s17 = int(4) + s17;
	cout << s17.str() << "\n";
	s17 = short(4) + s17;
	cout << s17.str() << "\n";
	s17 = long(4) + s17;
	cout << s17.str() << "\n";
	s17 = 'a' + s17;
	cout << s17.str() << "\n";
	s17 = "Begin"s + s17;
	cout << s17.str() << "\n";
	Serial s19;
	s19 += "Left"s;
	s17 = s19 + s17;
	cout << s17.str() << "\n";
	s17 = s17 + s17;
	cout << s17.str() << "\n";
	
	Serial s20;
	s20.put(false);
	cout << "<<= operator tests: \n";
	cout << s20.str() << "\n";
	bool b20 = true;
	b20 <<= s20;
	cout << b20 << " " << s20.str() << "\n";
	s20 += true;
	cout << s20.str() << "\n";
	s20 += int(4);
	cout << s20.str() << "\n";
	s20 += short(4);
	cout << s20.str() << "\n";
	s20 += long(4);
	cout << s20.str() << "\n";
	s20 += 'a';
	cout << s20.str() << "\n";
	s20 += "Test"s;
	cout << s20.str() << "\n";
	bool b21 = false;
	b21 <<= s20;
	cout << b21 << " " << s20.str() << "\n";
	int i20;
	i20 <<= s20;
	cout << i20 << " " << s20.str() << "\n";
	short sh20;
	sh20 <<= s20;
	cout << sh20 << " " << s20.str() << "\n";
	long l20;
	l20 <<= s20;
	cout << l20 << " " << s20.str() << "\n";
	char c20;
	c20 <<= s20;
	cout << c20 << " " << s20.str() << "\n";
	string st20 = "";
	st20 <<= s20;
	cout << st20 << " " << s20.str() << "\n";
	Serial s21;
	s21 += true;
	Serial s22;
	s22 += true;
	bool bcomp;
	if(s21 == s22){
		bcomp = true;
	}else{
		bcomp = false;
	}
	cout << bcomp << "\n";
	s21 += false;
	if(s21 == s22){
		bcomp = true;
	}else{
		bcomp = false;
	}
	cout << bcomp << "\n";
	if(s21 != s22){
		bcomp = true;
	}else{
		bcomp = false;
	}
	cout << bcomp << "\n";
	cout << "S21: " << s21.str() << " S22: " << s22.str() << "\n";
	Serial s23 = s21 + s22;
	cout << "S21: " << s21.str() << " S22: " << s22.str() << " S23: " << s23.str() << "\n";
	
	cout << "+= double test: \n";
	Serial s24;
	s24 += "double"s;
	cout << s24.str() << "\n";
	s24 += s24.str();
	cout << s24.str() << "\n";
	
	/*char c_string[15] = "Cstring";
	Serial cstest;*/
	//cstest.put(c_string);
	//cstest += c_string;
	/*char c_string[15] = "Cstring";
	s21 += c_string;
	cout << s21.str() << "\n";*/
	//cout << s11.str() << "\n";
	//assert(c2 == 'a');
	//cout << "Retesting: " << s4.str() << ", " << c2 << "\n";
}
