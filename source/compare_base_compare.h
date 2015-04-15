#include "../headers/compare_base.h"
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ostream>

using std::thread;
using std::ref;
using std::ostream;

namespace compare {

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
