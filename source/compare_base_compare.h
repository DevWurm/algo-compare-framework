/*
	 * License

	 * Copyright 2015 DevWurm

	 * This file is part of compare_library.

	 *  compare_library is free software: you can redistribute it and/or modify
	    it under the terms of the GNU General Public License as published by
	    the Free Software Foundation, either version 3 of the License, or
	    (at your option) any later version.

	    compare_library is distributed in the hope that it will be useful,
	    but WITHOUT ANY WARRANTY; without even the implied warranty of
	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	    GNU General Public License for more details.

	    You should have received a copy of the GNU General Public License
	    along with compare_library.  If not, see <http://www.gnu.org/licenses/>.

	    Diese Datei ist Teil von compare_library.

	    compare_library ist Freie Software: Sie können es unter den Bedingungen
	    der GNU General Public License, wie von der Free Software Foundation,
	    Version 3 der Lizenz oder (nach Ihrer Wahl) jeder späteren
	    veröffentlichten Version, weiterverbreiten und/oder modifizieren.

	    compare_library wird in der Hoffnung, dass es nützlich sein wird, aber
	    OHNE JEDE GEWÄHRLEISTUNG, bereitgestellt; sogar ohne die implizite
	    Gewährleistung der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
	    Siehe die GNU General Public License für weitere Details.

	    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
	    Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.
*/

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
