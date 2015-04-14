#include "../headers/compare_base.h"
#include <chrono>
#include <sstream>

using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::hours;
using std::chrono::minutes;
using std::chrono::seconds;
using std::chrono::milliseconds;
using std::chrono::microseconds;
using std::chrono::nanoseconds;
using std::stringstream;

namespace compare {

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

}
