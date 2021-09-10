#ifndef SERIAL_H_INCLUDED
#define SERIAL_H_INCLUDED

#include <vector>
#include <string>

class Serial{
	public:
		//vector to store data on each entry as strings
		std::vector<std::string> serial_vector;
		//default constructor
		Serial();
		//copy constructor
		Serial(const Serial &);
		//assignment operator
		Serial operator=(const Serial&);
		Serial& operator+=(const bool&);
		Serial& operator+=(const int&);
		Serial& operator+=(const short&);
		Serial& operator+=(const long&);
		Serial& operator+=(const char&);
		Serial& operator+=(const std::string&);
		Serial& operator+=(const Serial&);
		Serial& operator+=(const char*) = delete;
		const Serial operator+(const bool&) const;
		const Serial operator+(const int&) const;
		const Serial operator+(const short&) const;
		const Serial operator+(const long&) const;
		const Serial operator+(const char&) const;
		const Serial operator+(const std::string&) const;
		const Serial operator+(const char*) = delete;
		const friend Serial operator+(const bool&, const Serial&);
		const friend Serial operator+(const int&, const Serial&);
		const friend Serial operator+(const short&, const Serial&);
		const friend Serial operator+(const long&, const Serial&);
		const friend Serial operator+(const char&, const Serial&);
		const friend Serial operator+(const std::string&, const Serial&);
		const friend Serial operator+(const Serial&, const Serial&);
		const friend Serial operator+(const char*, const Serial&) = delete;
		const friend void operator<<=(bool&, Serial&);
		const friend void operator<<=(int&, Serial&);
		const friend void operator<<=(short&, Serial&);
		const friend void operator<<=(long&, Serial&);
		const friend void operator<<=(char&, Serial&);
		const friend void operator<<=(std::string&, Serial&);
		//destructor
		~Serial();
		//serialize methods
		void put(bool);
		void put(short);
		void put(int);
		void put(long);
		void put(char);
		void put(std::string);
		void put(const char*) = delete;
		//unserialize methods
		void get(bool&);
		void get(short&);
		void get(int&);
		void get(long&);
		void get(char&);
		void get(std::string&);
		//other methods
		std::string str() const;
		void str(std::string);
		int size() const;
		bool empty() const;
		//equality methods
		const bool operator==(const Serial&) const;
		const bool operator!=(const Serial&) const;
};

#endif