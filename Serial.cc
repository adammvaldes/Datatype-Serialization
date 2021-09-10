#include "Serial.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <cmath>
	
	//std::vector<std::string> serial_vector;
	
	//default constructor
	//DONE!
	Serial::Serial(){
		//vector constructs itself
	}
	
	//destructor
	Serial::~Serial(){
		//vector destroys itself
	}
	
	//copy constructor
	//DONE!
	Serial::Serial(const Serial& other){
		serial_vector = other.serial_vector;
	}
	
	//operator overloads
	//assignment operator
	//DONE!
	Serial Serial::operator=(const Serial& other){
		serial_vector = other.serial_vector;
		return *this;
	}
	
	//+= operator overloads
	Serial& Serial::operator+=(const bool& rhs){
		put(rhs);
		return *this;
	}
	
	Serial& Serial::operator+=(const int& rhs){
		put(rhs);
		return *this;
	}
	
	Serial& Serial::operator+=(const short& rhs){
		put(rhs);
		return *this;
	}
	
	Serial& Serial::operator+=(const long& rhs){
		put(rhs);
		return *this;
	}
	
	Serial& Serial::operator+=(const char& rhs){
		put(rhs);
		return *this;
	}
	
	Serial& Serial::operator+=(const std::string& rhs){
		put(rhs);
		return *this;
	}
	
	Serial& Serial::operator+=(const Serial& rhs){
		for(std::string s : rhs.serial_vector){
			serial_vector.push_back(s);
		}
		return *this;
	}
	
	//Right hand side + operator overloads
	const Serial Serial::operator+(const bool& rhs) const{
		return Serial(*this) += rhs;
	}
	
	const Serial Serial::operator+(const int& rhs) const{
		return Serial(*this) += rhs;
	}
	
	const Serial Serial::operator+(const short& rhs) const{
		return Serial(*this) += rhs;
	}
	
	const Serial Serial::operator+(const long& rhs) const{
		return Serial(*this) += rhs;
	}
	
	const Serial Serial::operator+(const char& rhs) const{
		return Serial(*this) += rhs;
	}
	
	const Serial Serial::operator+(const std::string& rhs) const{
		return Serial(*this) += rhs;
	}
	
	//Left hand side + right hand side operator overloads
	const Serial operator+(const bool& lhs, const Serial& rhs){
		Serial temp;
		temp += lhs;
		return temp += rhs;
	}
	
	const Serial operator+(const int& lhs, const Serial& rhs){
		Serial temp;
		temp += lhs;
		return temp += rhs;
	}
	
	const Serial operator+(const short& lhs, const Serial& rhs){
		Serial temp;
		temp += lhs;
		return temp += rhs;
	}
	
	const Serial operator+(const long& lhs, const Serial& rhs){
		Serial temp;
		temp += lhs;
		return temp += rhs;
	}
	
	const Serial operator+(const char& lhs, const Serial& rhs){
		Serial temp;
		temp += lhs;
		return temp += rhs;
	}
	
	const Serial operator+(const std::string& lhs, const Serial& rhs){
		Serial temp;
		temp += lhs;
		return temp += rhs;
	}
	
	//Works with doubling current serial
	const Serial operator+(const Serial& lhs, const Serial& rhs){
		Serial temp;
		temp += lhs;
		return temp += rhs;
	}
	
	//Extraction operator overloads
	const void operator<<=(bool& lhs, Serial& rhs){
		rhs.get(lhs);
	}
	
	const void operator<<=(int& lhs, Serial& rhs){
		rhs.get(lhs);
	}
	
	const void operator<<=(short& lhs, Serial& rhs){
		rhs.get(lhs);
	}
	
	const void operator<<=(long& lhs, Serial& rhs){
		rhs.get(lhs);
	}
	
	const void operator<<=(char& lhs, Serial& rhs){
		rhs.get(lhs);
	}
	
	const void operator<<=(std::string& lhs, Serial& rhs){
		rhs.get(lhs);
	}
	
	//Equality operator overloads
	const bool Serial::operator==(const Serial& rhs) const{
		if(size() != rhs.size()){
			return false;
		}
		for(int i = 0 ; i < size(); i++){
			if(serial_vector[i] != rhs.serial_vector[i]){
				return false;
			}
		}
		return true;
	}
	
	const bool Serial::operator!=(const Serial& rhs) const{
		if(size() != rhs.size()){
			return true;
		}
		for(int i = 0 ; i < size(); i++){
			if(serial_vector[i] != rhs.serial_vector[i]){
				return true;
			}
		}
		return false;
	}
	
	//Next 5 methods are for calculating vnums
	int getNumBits(int num){
		if(num < 0){
			int length;
			int tempNum = num;
			while(tempNum <= 1 && tempNum != 0){
				tempNum /= 2;
				length++;
			}
			return length;
		}
		int length;
		int tempNum = num;
		while(tempNum >= 1){
			tempNum /= 2;
			length++;
		}
		return length;
	}

	int padNum(int numBits, int num){
		if(num >= -8 && num <= 8){
			return 0;
		}
		return (4 - (numBits % 4) + 4) % 4;
	}

	int vnumLength(int length){
		int tempLength = length;
		int vLength = 0;
		if(length <= 4){
			return 0;
		}
		tempLength -= 4;
		while(tempLength > 0){
			tempLength-=8;
			vLength++;
		}
		return vLength;
	}

	int maskNegative(int num, int length){
		int maskLength = length + padNum(getNumBits(num), num);
		int mask = 1 << maskLength;
		int maskBits = length + 4 - (length % 4);
		int start = 1 << (maskBits - 1);
		mask = start;
		for(int i = 0; i < maskBits; i++){
			start /= 2;
			mask += start;
		}
		int result = num & mask;
		return result;
	}

	std::string createVnum(std::string in){
		long input;
		std::stringstream convert(in);
		convert >> input;
		int bitLength = getNumBits(input);
		int vLength = vnumLength(bitLength);
		std::ostringstream os;
		if(input >= 0){
			os << std::hex << vLength << std::setw(padNum(bitLength, input)) << std::setfill('0') << input;
		}
		else{
			os << std::hex << vLength << std::setw(padNum(bitLength, input)) << std::setfill('1') << maskNegative(input, bitLength);
		}
		std::string s1 = os.str();
		if(s1.size() % 2 != 0){
			if(input > 0){
				s1.insert(1, "0");
			}
			else if(input < 0){
				s1.insert(1, "f");
			}
		}
		return s1;
	}
		
		
		
	//serialize methods
	//DONE!
	void Serial::put(bool b){
		std::string s = "";
		if(b){
			//true
			s += char(0x74);
			serial_vector.push_back(s);
		}else{
			//false
			s += char(0x66);
			serial_vector.push_back(s);
		}
	}
	
	//Need to add support for negative short/int/long values
	//DONE!
	void Serial::put(short s){
        std::string temp_string = "";
        temp_string += char(0x73);
        std::string vn = createVnum(std::to_string(s));
        for(unsigned i = 0; i < vn.length() - 1; i+=2){
            std::string temp2 = "";
            temp2 += vn.at(i);
            temp2 += vn.at(i+1);
            int ih = stoi(temp2,nullptr,16);
            temp_string += char(ih);
        }
        serial_vector.push_back(temp_string);
    }
    
    //DONE!
	void Serial::put(int in){
        std::string temp_string = "";
        temp_string += char(0x69);
        std::string vn = createVnum(std::to_string(in));
        for(unsigned i = 0; i < vn.length() - 1; i+=2){
            std::string temp2 = "";
            temp2 += vn.at(i);
            temp2 += vn.at(i+1);
            int ih = stoi(temp2,nullptr,16);
            temp_string += char(ih);
        }
        serial_vector.push_back(temp_string);
    }
	
	//DONE!
	void Serial::put(long l){
		std::string temp_string = "";
		temp_string += char(0x6c);
		std::string vn = createVnum(std::to_string(l));
		for(unsigned i = 0; i < vn.length() - 1; i+=2){
			std::string temp = "";
			temp += vn.at(i);
			temp += vn.at(i+1);
			int ih = stoi(temp,nullptr,16);
			temp_string += char(ih);
		}
		serial_vector.push_back(temp_string);
	}
	
	//DONE!
	void Serial::put(const char c){
		std::string s = "";
		s += char(0x63);
		s += char(c);
		serial_vector.push_back(s);
	}
	
	//NOT GENERATING VNUM CORRECTLY
	void Serial::put(std::string input_string){
		std::string s = "";
		s += char(0x53);
		std::string vnsize = createVnum(std::to_string(input_string.length()));
		for(unsigned i = 0; i < vnsize.length() - 1; i+=2){
			std::string temp = "";
			temp += vnsize.at(i);
			temp += vnsize.at(i+1);
			int hexint = stoi(temp,nullptr,16);
			s += char(hexint);
		}
		for(unsigned i = 0; i < input_string.length(); i++){
			s += char((int)input_string.at(i));
		}
		serial_vector.push_back(s);
	}
	
	//unserialize methods
	//DONE!
	void Serial::get(bool &b){
		if(Serial::empty()){
			std::string st = "There is nothing left to get()!\n";
			throw st;
		}else if(serial_vector[0].at(0) == char(0x74)){
			b = true;
			serial_vector.erase(serial_vector.begin());
			return;
		}else if(serial_vector[0].at(0) == char(0x66)){
			b = false;
			serial_vector.erase(serial_vector.begin());
		}else{
			std::string st = "You tried to get() the wrong type! The next entry is not a boolean value!\n";
			throw st;
		}
	}
	
	//negatives?
	void Serial::get(short &s){
		if(Serial::empty()){
			std::string st = "There is nothing left to get()!\n";
			throw st;
		}else if(char(serial_vector[0].at(0)) != char(0x73)){
			std::string st = "You tried to get() the wrong type! The next type is not a short value!\n";
			throw st;
		}else{
			
			std::string tstring = serial_vector[0];
			tstring.erase(0,1);
			if(tstring.length() > 1){
				tstring.erase(0,1);
			}
			int coll = 0;
			for(unsigned i = 0; i < tstring.length(); i++){
				int itemp = pow(10,i) * (int)tstring.at(i);
				coll += itemp;
			}
			s = coll;
		}
		serial_vector.erase(serial_vector.begin());
	}
	
	void Serial::get(int &i){
		if(Serial::empty()){
			std::string st = "There is nothing left to get()!\n";
			throw st;
		}else if(char(serial_vector[0].at(0)) != char(0x69)){
			std::string st = "You tried to get() the wrong type! The next type is not a integer value!\n";
			throw st;
		}else{
			std::string tstring = serial_vector[0];
			tstring.erase(0,1);
			if(tstring.length() > 1){
				tstring.erase(0,1);
			}
			int coll = 0;
			for(unsigned i = 0; i < tstring.length(); i++){
				int itemp = pow(10,i) * (int)tstring.at(i);
				coll += itemp;
			}
			i = coll;
		}
		serial_vector.erase(serial_vector.begin());
	}
	void Serial::get(long &l){
		if(Serial::empty()){
			std::string st = "There is nothing left to get()!\n";
			throw st;
		}else if(char(serial_vector[0].at(0)) != char(0x6c)){
			std::string st = "You tried to get() the wrong type! The next type is not a long value!\n";
			throw st;
		}else{
			std::string tstring = serial_vector[0];
			tstring.erase(0,1);
			if(tstring.length() > 1){
				tstring.erase(0,1);
			}
			int coll = 0;
			for(unsigned i = 0; i < tstring.length(); i++){
				int itemp = pow(10,i) * (int)tstring.at(i);
				coll += itemp;
			}
			l = coll;
		}
		serial_vector.erase(serial_vector.begin());
	}
	
	//DONE!
	void Serial::get(char &c){
		if(Serial::empty()){
			std::string st = "There is nothing left to get()!\n";
			throw st;
		}else if(char(serial_vector[0].at(0)) != char(0x63)){
			std::string st = "You tried to get() the wrong type! The next type is not a char value!\n";
			throw st;
		}else{
			c = char(serial_vector[0].at(1));
			serial_vector.erase(serial_vector.begin());
		}
	}
	
	//Almost done, need to change erase positions to be based on vnum size
	void Serial::get(std::string &str){
        if(Serial::empty()){
            std::string st = "There is nothing left to get()!\n";
            throw st;
        }else if(serial_vector[0].at(0) != char(0x53)){
           std::string st = "You tried to get() the wrong type! The next type is not a string value!\n";
           throw st;
        }else{
            serial_vector[0].erase(serial_vector[0].begin(), serial_vector[0].begin()+2);
            std::string return_string = "";
            for(unsigned i = 0; i < serial_vector[0].length(); i++){
                return_string += serial_vector[0].at(i);
            }
            str = return_string;
            serial_vector.erase(serial_vector.begin());
        }
    }
	//other methods
	
	//DONE!
	std::string Serial::str() const{
		std::string return_string = "";
		for(std::string s : serial_vector)
			return_string += s;
		return return_string;
	}
	
	//DONE!
	void Serial::str(std::string input_string){
        serial_vector.erase(serial_vector.begin(), serial_vector.end());
        serial_vector.push_back(input_string);
    }
    
	//DONE!
	int Serial::size() const{
		int size = 0;
		for(unsigned i = 0; i < serial_vector.size(); i++){
			size += serial_vector[i].length();
		}
		//std::cout << "Size: " << size << "\n";
		return size;
	}
	
	//DONE!
	bool Serial::empty() const{
		if(serial_vector.empty()){
			return true;
		}
		return false;
	}