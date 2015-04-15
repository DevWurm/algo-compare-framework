/*
 * libcompare.h
 *
 *  Created on: 14.04.2015
 *      Author: leo
 */

#ifndef LIB_LIBCOMPARE_H_
#define LIB_LIBCOMPARE_H_

#include <string>
#include <chrono>
#include <ostream>
#include <thread>
#include <cstdlib>
#include <sstream>

using std::string;
using std::chrono::steady_clock;
using std::ostream;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::hours;
using std::chrono::minutes;
using std::chrono::seconds;
using std::chrono::milliseconds;
using std::chrono::microseconds;
using std::chrono::nanoseconds;
using std::stringstream;
using std::thread;
using std::ref;

namespace compare {


template<typename T>
class compare_base {
private:
	T data;
	T result_algorithm_1;
	T result_algorithm_2;
	string type;
	steady_clock::duration operation_time_algorithm_1;
	steady_clock::duration operation_time_algorithm_2;

	void start_algorithm_1(compare_base& object, T& data, T& result); //start and join thread for algorithm 1 and measure time
	void start_algorithm_2(compare_base& object, T& data, T& result); //start and join thread for algorithm 2 and measure time
	void start_algorithm_1_verbose(compare_base& object, T& data, T& result, ostream& output); //start and join thread for algorithm 1 and measure time and write status information into output
	void start_algorithm_2_verbose(compare_base& object, T& data, T& result, ostream& output); //start and join thread for algorithm 2 and measure time and write status information into output
public:
	compare_base(); //standard constructor
	compare_base(const T& input); //copy constructor from type

	compare_base<T>& operator=(const T& input); //assign operator from type

	virtual void algorithm_1 (const T& input, T& result) = 0; //interface for implementing algorithm 1
	virtual void algorithm_2 (const T& input, T& result) = 0; //interface for implementing algorithm 2

	void compare_algorithms(); //start every algorithm-starter in another thread
	void compare_algorithms_verbose(ostream& output); //start every verbose algorithm-starter in another thread

	void set_data(const T& input); //set data from type

	T get_data() const; //get data as type
	T get_result_algorithm_1() const; //get result of algorithm 1
	T get_result_algorithm_2() const; //get result of algorithm 2
	string get_type() const; //get type
	steady_clock::duration get_operation_time_algorithm_1(string unit) const; //get operation time as duration
	steady_clock::duration get_operation_time_algorithm_1() const; //get operation time as duration (milliseconds)
	steady_clock::duration get_operation_time_algorithm_2(string unit) const; //get operation time as duration
	steady_clock::duration get_operation_time_algorithm_2() const; //get operation time as duration (milliseconds)
	string get_operation_time_algorithm_1_string(string unit) const; //get operation time as string
	string get_operation_time_algorithm_1_string() const; //get operation time as string (milliseconds)
	string get_operation_time_algorithm_2_string(string unit) const; //get operation time as string
	string get_operation_time_algorithm_2_string() const; //get operation time as string (milliseconds)

	bool vaildate_results(); //check if results of the algorithms are equal

	virtual ~compare_base();

};

template<typename T>
compare_base<T>::compare_base() {
	type = typeid(T).name();
}

template<typename T>
compare_base<T>::compare_base(const T& input):data(input) {
	type = typeid(T).name();
}

template<typename T>
compare_base<T>::~compare_base(){}; //empty virtual constructor to securely call the destructor of derivated classes

template<typename T>
compare_base<T>& compare_base<T>::operator =(const T& input) {
	data = input;
}

template<typename T>
void compare_base<T>::set_data(const T& input) {
	data = input;
}

template<typename T>
T compare_base<T>::get_data() const {
	return data;
}

template<typename T>
T compare_base<T>::get_result_algorithm_1() const {
	return result_algorithm_1;
}

template<typename T>
T compare_base<T>::get_result_algorithm_2() const {
	return result_algorithm_2;
}

template<typename T>
string compare_base<T>::get_type() const {
	return type;
}

template<typename T>
steady_clock::duration compare_base<T>::get_operation_time_algorithm_1(string unit) const { //return duration casted in given unit (default: milliseconds)
	if (unit == "h") {
		return duration_cast<hours>(operation_time_algorithm_1);
	}
	else if (unit == "m") {
		return duration_cast<minutes>(operation_time_algorithm_1);
	}
	else if (unit == "s") {
		return duration_cast<seconds>(operation_time_algorithm_1);
	}
	else if (unit == "mic") {
		return duration_cast<microseconds>(operation_time_algorithm_1);
	}
	else if (unit == "nan") {
		return duration_cast<nanoseconds>(operation_time_algorithm_1);
	}
	else {
		return duration_cast<milliseconds>(operation_time_algorithm_1);
	}
}

template<typename T>
steady_clock::duration compare_base<T>::get_operation_time_algorithm_1() const { //return duration casted in milliseconds
	return duration_cast<milliseconds>(operation_time_algorithm_1);
}

template<typename T>
string compare_base<T>::get_operation_time_algorithm_1_string(string unit) const { //return duration casted in given unit (default: milliseconds)
	stringstream converter;
	if (unit == "h") {
		converter << duration_cast<hours>(operation_time_algorithm_1).count();
		return converter.str();
	}
	else if (unit == "m") {
		converter << duration_cast<minutes>(operation_time_algorithm_1).count();
		return converter.str();
	}
	else if (unit == "s") {
		converter << duration_cast<seconds>(operation_time_algorithm_1).count();
		return converter.str();
	}
	else if (unit == "mic") {
		converter << duration_cast<microseconds>(operation_time_algorithm_1).count();
		return converter.str();
	}
	else if (unit == "nan") {
		converter << duration_cast<nanoseconds>(operation_time_algorithm_1).count();
		return converter.str();
	}
	else {
		converter << duration_cast<milliseconds>(operation_time_algorithm_1).count();
		return converter.str();
	}
}

template<typename T>
string compare_base<T>::get_operation_time_algorithm_1_string() const { //return duration casted in milliseconds
	stringstream converter;
	converter << duration_cast<milliseconds>(operation_time_algorithm_1).count();
	return converter.str();
}

template<typename T>
steady_clock::duration compare_base<T>::get_operation_time_algorithm_2(string unit) const { //return duration casted in given unit (default: milliseconds)
	if (unit == "h") {
		return duration_cast<hours>(operation_time_algorithm_2);
	}
	else if (unit == "m") {
		return duration_cast<minutes>(operation_time_algorithm_2);
	}
	else if (unit == "s") {
		return duration_cast<seconds>(operation_time_algorithm_2);
	}
	else if (unit == "mic") {
		return duration_cast<microseconds>(operation_time_algorithm_2);
	}
	else if (unit == "nan") {
		return duration_cast<nanoseconds>(operation_time_algorithm_2);
	}
	else {
		return duration_cast<milliseconds>(operation_time_algorithm_2);
	}
}

template<typename T>
steady_clock::duration compare_base<T>::get_operation_time_algorithm_2() const { //return duration casted in milliseconds
	return duration_cast<milliseconds>(operation_time_algorithm_2);
}

template<typename T>
string compare_base<T>::get_operation_time_algorithm_2_string(string unit) const { //return duration casted in given unit (default: milliseconds)
	stringstream converter;
	if (unit == "h") {
		converter << duration_cast<hours>(operation_time_algorithm_2).count();
		return converter.str();
	}
	else if (unit == "m") {
		converter << duration_cast<minutes>(operation_time_algorithm_2).count();
		return converter.str();
	}
	else if (unit == "s") {
		converter << duration_cast<seconds>(operation_time_algorithm_2).count();
		return converter.str();
	}
	else if (unit == "mic") {
		converter << duration_cast<microseconds>(operation_time_algorithm_2).count();
		return converter.str();
	}
	else if (unit == "nan") {
		converter << duration_cast<nanoseconds>(operation_time_algorithm_2).count();
		return converter.str();
	}
	else {
		converter << duration_cast<milliseconds>(operation_time_algorithm_2).count();
		return converter.str();
	}
}

template<typename T>
string compare_base<T>::get_operation_time_algorithm_2_string() const { //return duration casted in milliseconds
	stringstream converter;
	converter << duration_cast<milliseconds>(operation_time_algorithm_2).count();
	return converter.str();
}

template<typename T>
bool compare_base<T>::vaildate_results() {
	return (result_algorithm_1 == result_algorithm_2);
}

template<typename T>
void compare_base<T>::start_algorithm_1(compare_base& object, T& data, T& result) {
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	object.algorithm_1(data, result); //start algorithm 1
	std::chrono::steady_clock::time_point stop = std::chrono::steady_clock::now();
	operation_time_algorithm_1 = stop - start;
}

template<typename T>
void compare_base<T>::start_algorithm_2(compare_base& object, T& data, T& result) {
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	object.algorithm_2(data,result); //start algorithm 2
	std::chrono::steady_clock::time_point stop = std::chrono::steady_clock::now();
	operation_time_algorithm_2 = stop - start;
}

template<typename T>
void compare_base<T>::compare_algorithms() {
	thread thread_start_algorithm_1(&compare_base<T>::start_algorithm_1, this, ref(*this), ref(data), ref(result_algorithm_1));
	thread thread_start_algorithm_2(&compare_base<T>::start_algorithm_2, this, ref(*this), ref(data), ref(result_algorithm_2));
	thread_start_algorithm_1.join();
	thread_start_algorithm_2.join();
}

template<typename T>
void compare_base<T>::start_algorithm_1_verbose(compare_base& object, T& data, T& result, ostream& output) {
	output << "Algorithm 1 started\n";
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	object.algorithm_1(data, result); //start algorithm 1
	std::chrono::steady_clock::time_point stop = std::chrono::steady_clock::now();
	output << "Algorithm 1 ended\n";
	operation_time_algorithm_1 = stop - start;
}

template<typename T>
void compare_base<T>::start_algorithm_2_verbose(compare_base& object, T& data, T& result, ostream& output) {
	output << "Algorithm 2 started\n";
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	object.algorithm_2(data, result); //start thread of algorithm 1
	std::chrono::steady_clock::time_point stop = std::chrono::steady_clock::now();
	output << "Algorithm 2 ended\n";
	operation_time_algorithm_2 = stop - start;
}

template<typename T>
void compare_base<T>::compare_algorithms_verbose(ostream& output) {
	thread thread_start_algorithm_1(&compare_base<T>::start_algorithm_1_verbose, this, ref(*this), ref(data), ref(result_algorithm_1), ref(output));
	thread thread_start_algorithm_2(&compare_base<T>::start_algorithm_2_verbose, this, ref(*this), ref(data), ref(result_algorithm_2), ref(output));
	thread_start_algorithm_1.join();
	thread_start_algorithm_2.join();
	output << "Duration of Algorithm 1: " << get_operation_time_algorithm_1_string() << "ms\n";
	output << "Duration of Algorithm 2: " << get_operation_time_algorithm_2_string() << "ms\n";
	if (vaildate_results()) {
		output << "The results are equal\n";
	}
	else {
		output << "The results are NOT equal\n";
	}
}

}



#endif /* LIB_LIBCOMPARE_H_ */
