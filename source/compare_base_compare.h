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
void compare_base<T>::start_algorithm_1() {
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	thread thread_algorithm_1 (algorithm_1<T>, ref(data), ref(result_algorithm_1)); //start thread of algorithm 1
	thread_algorithm_1.join();
	std::chrono::steady_clock::time_point stop = std::chrono::steady_clock::now();
	operation_time_algorithm_1 = stop - start;
}

template<typename T>
void compare_base<T>::start_algorithm_2() {
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	thread thread_algorithm_2 (algorithm_2<T>, ref(data), ref(result_algorithm_1)); //start thread of algorithm 1
	thread_algorithm_2.join();
	std::chrono::steady_clock::time_point stop = std::chrono::steady_clock::now();
	operation_time_algorithm_2 = stop - start;
}

template<typename T>
void compare_base<T>::compare_algorithms() {
	thread thread_start_algorithm_1(start_algorithm_1<T>);
	thread thread_start_algorithm_2(start_algorithm_2<T>);
	thread_start_algorithm_1.join();
	thread_start_algorithm_2.join();
}

template<typename T>
void compare_base<T>::start_algorithm_1_verbose(ostream& output) {
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	thread thread_algorithm_1 (algorithm_1<T>, ref(data), ref(result_algorithm_1)); //start thread of algorithm 1
	output << "Algorithm 1 started\n";
	thread_algorithm_1.join();
	std::chrono::steady_clock::time_point stop = std::chrono::steady_clock::now();
	output << "Algorithm 1 ended\n";
	operation_time_algorithm_1 = stop - start;
}

template<typename T>
void compare_base<T>::start_algorithm_2_verbose(ostream& output) {
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	thread thread_algorithm_2 (algorithm_2<T>, ref(data), ref(result_algorithm_1)); //start thread of algorithm 1
	output << "Algorithm 2 started\n";
	thread_algorithm_2.join();
	std::chrono::steady_clock::time_point stop = std::chrono::steady_clock::now();
	output << "Algorithm 2 ended\n";
	operation_time_algorithm_2 = stop - start;
}

template<typename T>
void compare_base<T>::compare_algorithms_verbose(ostream& output) {
	thread thread_start_algorithm_1(start_algorithm_1_verbose<T>, ref(output));
	thread thread_start_algorithm_2(start_algorithm_2_verbose<T>, ref(output));
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
