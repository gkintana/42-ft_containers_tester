/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_templates.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 22:11:55 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/10 10:43:14 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TEMPLATES_HPP
#define VECTOR_TEMPLATES_HPP

// C++ Library
#include <iostream>
#include <sstream>
#include <cfloat>
// #include <cstring>
#include <iomanip>
#include <iterator>
#include <vector>
// #include <fstream>

// C Library
#include <limits.h>

// Project Library
#include <vector.hpp>
#include <stack.hpp>


#define DEFAULT    "\033[0m"
#define RED        "\033[1;31m"
#define GREEN      "\033[1;32m"
#define YELLOW     "\033[1;33m"
#define PURPLE     "\033[1;35m"
#define CYAN       "\033[1;36m"

#define BEGIN     1
#define END       2
#define RBEGIN    3
#define REND      4

#define RNG       std::rand() % 999999999
// #define OK         1
// #define WARNING    2
// #define KO         3

// size_t test_no = 1;

class vectorTester {
	private:
		size_t OK;
		size_t WARNING;
		size_t KO;
		size_t test_no;
		// std::ofstream report;

	public:
		vectorTester() : OK(0), WARNING(0), KO(0), test_no(0) {}
		~vectorTester() {}

		void addOK() {
			this->test_no++;
			this->OK++;
		}

		void addWarning() {
			this->test_no++;
			this->WARNING++;
		}

		void addKO() {
			this->test_no++;
			this->KO++;
		}

		void printOK() { std::cout << GREEN "OK" DEFAULT << std::endl; }

		void printWarning() { std::cout << YELLOW "WARNING: " << this->WARNING << " potential error(s)" << DEFAULT << std::endl; }

		void printKO() { std::cout << RED "KO: " << this->KO << " error(s)" << DEFAULT << std::endl; }

		void printWarningAndKO () {
			std::cout << YELLOW "WARNING: " << this->WARNING << " potential error(s)" << DEFAULT << std::endl
			          << RED "KO: " << this->KO << " error(s)" << DEFAULT << std::endl;
		}

		void resetTestCount() {
			this->OK = 0;
			this->WARNING = 0;
			this->KO = 0;
			this->test_no = 0;
		}

		template <typename T>
		void checkContent(ft::vector<T> &ft, std::vector<T> &std) {
			std::stringstream ft_ss, std_ss;

			for (size_t i = 0; i < ft.size(); i++) {
				ft_ss << ft[i] << " ";
			}
			for (size_t i = 0; i < std.size(); i++) {
				std_ss << std[i] << " ";
			}

			ft_ss.str() == std_ss.str() ? addOK() : addKO();
		}

		template <typename T>
		void checkContent(ft::vector<T> &lhs, ft::vector<T> &rhs) {
			std::stringstream lhs_ss, rhs_ss;

			for (size_t i = 0; i < lhs.size(); i++) {
				lhs_ss << lhs[i] << " ";
			}
			for (size_t i = 0; i < rhs.size(); i++) {
				rhs_ss << rhs[i] << " ";
			}

			lhs_ss.str() == rhs_ss.str() ? addOK() : addKO();
		}

		template <typename T>
		void checkEmpty(ft::vector<T> &ft, std::vector<T> &std) { ft.empty() == std.empty() ? addOK() : addKO(); }

		template <typename T>
		void checkEmpty(ft::vector<T> &lhs, ft::vector<T> &rhs) { lhs.empty() == rhs.empty() ? addOK() : addKO(); }

		template <typename T>
		void checkSize(ft::vector<T> &ft, std::vector<T> &std) { ft.size() == std.size() ? addOK() : addKO(); }

		template <typename T>
		void checkSize(ft::vector<T> &lhs, ft::vector<T> &rhs) { lhs.size() == rhs.size() ? addOK() : addKO(); }

		template <typename T>
		void checkCapacity(ft::vector<T> &ft, std::vector<T> &std) { ft.capacity() == std.capacity() ? addOK() : addWarning(); }

		template <typename T>
		void checkCapacity(ft::vector<T> &lhs, ft::vector<T> &rhs) { lhs.capacity() == rhs.capacity() ? addOK() : addWarning(); }

		#if __APPLE__
			template <typename T>
			void checkMaxSize(ft::vector<T> &ft, std::vector<T> &std) { (ft.max_size() == ULONG_MAX && std.max_size() == LONG_MAX) || (ft.max_size() == std.max_size()) ? addOK() : addKO(); }

			template <typename T>
			void checkMaxSize(ft::vector<T> &lhs, ft::vector<T> &rhs) { (lhs.max_size() == ULONG_MAX && rhs.max_size() == LONG_MAX) || (lhs.max_size() == rhs.max_size()) ? addOK() : addKO(); }
		#endif

		#if __linux__
			template <typename T>
			void checkMaxSize(ft::vector<T> &ft, std::vector<T> &std) { ft.max_size() == std.max_size() ? addOK() : addKO(); }

			template <typename T>
			void checkMaxSize(ft::vector<T> &lhs, ft::vector<T> &rhs) { lhs.max_size() == rhs.max_size() ? addOK() : addKO(); }
		#endif

		template <typename T>
		void compareVectors(ft::vector<T> &ft, std::vector<T> &std) {
			checkContent(ft, std);
			checkEmpty(ft, std);
			checkSize(ft, std);
			checkCapacity(ft, std);
			checkMaxSize(ft, std);
		}

		template <typename T>
		void compareVectors(ft::vector<T> &lhs, ft::vector<T> &rhs) {
			checkContent(lhs, rhs);
			checkEmpty(lhs, rhs);
			checkSize(lhs, rhs);
			checkCapacity(lhs, rhs);
			checkMaxSize(lhs, rhs);
		}

		void printTestResults(std::string test_name) {
			if (test_name.empty()) {
				std::cout << "  ➢ General Tests\t\t";
			} else {
				std::cout << "  ➢ " << test_name << "\t\t";
			}

			this->WARNING && this->KO ? printWarningAndKO() :
			!this->WARNING && !this->KO ? printOK() :
			this->WARNING && !this->KO ? printWarning() : printKO();

			if (this->WARNING || this->KO) {
				std::cout << RED "\t\t\t\tCheck report.txt for more details" DEFAULT << std::endl;
				// report.open()
			}
			this->resetTestCount();
		}



		/**
		** @brief    pushes random values to both ft and std containers
		**
		** @param ft             address of container with ft namespace
		** @param std            address of container with std namespace
		** @param len            desired vector size
		** @param compare_vec    determines if the ft and std vector will be compared once
		**                       the push_back loop ends
		** @param add_newline    checks if the function should print a newline after testing
		*/
		template <typename T>
		void pushLoop(ft::vector<T> &ft, std::vector<T> &std, size_t len) {
			for (size_t i = 0; i < len; i++) {
				size_t random_value = std::rand() % 123456789;
				ft.push_back(random_value);
				std.push_back(random_value);
				compareVectors(ft, std);
			}
		}

		/**
		** @brief    pushes the exact same string to both ft and std containers according to
		**           the size of len
		**
		** @param str    std::string to be pushed to the ft and std vectors
		*/
		template <typename T>
		void pushLoop(ft::vector<T> &ft, std::vector<T> &std, size_t len, std::string str) {
			for (size_t i = 0; i < len; i++) {
				ft.push_back(str);
				std.push_back(str);
				compareVectors(ft, std);
			}
		}

		/**
		** @brief    checks if value at the position ft iterator and std iterator are currently
		**           at are equal
		**
		** @param ft             address of container with ft namespace
		** @param std            address of container with std namespace
		** @param offset         integer which represents a value to be added or subtracted
		**                       to the iterator's position
		** @param option         integer that indicates which type of iterator or reverse
		**                       iterator will be compared with the std equivalent
		*/
		template <typename T>
		void compareIterToStd(ft::vector<T> &ft, std::vector<T> &std, int offset, int option) {
			if (option == BEGIN) {
				*(ft.begin() + offset) == *(std.begin() + offset) ? addOK() : addKO();
			} else if (option == END) {
				*(ft.end() - offset) == *(std.end() - offset) ? addOK() : addKO();
			} else if (option == RBEGIN) {
				*(ft.rbegin() + offset) == *(std.rbegin() + offset) ? addOK() : addKO();
			} else if (option == REND) {
				*(ft.rend() - offset) == *(std.rend() - offset) ? addOK() : addKO();
			}
		}

		template <typename T>
		void iterLoop(ft::vector<T> &ft, std::vector<T> &std,
		              typename ft::vector<T>::iterator start,
		              typename ft::vector<T>::iterator end) {
			typedef typename std::vector<T>::iterator STD_ITERATOR;
			typedef typename ft::vector<T>::iterator FT_ITERATOR;

			size_t pos = 0;
			for (FT_ITERATOR temp = ft.begin(); temp != start; temp++) {
				pos++;
			}

			STD_ITERATOR std_iter = std.begin() + pos;
			for (FT_ITERATOR ft_iter = start; ft_iter != end; ft_iter++) {
				*ft_iter == *std_iter++ ? addOK() : addKO();
			}
		}

		template <typename T>
		void revIterLoop(ft::vector<T> &ft, std::vector<T> &std,
		                 typename ft::vector<T>::reverse_iterator start,
		                 typename ft::vector<T>::reverse_iterator end) {
			typedef typename std::vector<T>::reverse_iterator STD_REVERSE;
			typedef typename ft::vector<T>::reverse_iterator FT_REVERSE;

			size_t pos = 0;
			for (FT_REVERSE temp = ft.rend(); temp != start; temp--) {
				pos++;
			}

			STD_REVERSE std_iter = std.rend() - pos;
			for (FT_REVERSE ft_iter = start; ft_iter != end; ft_iter--) {
				*ft_iter == *std_iter-- ? addOK() : addKO();
			}
		}



		// https://stackoverflow.com/questions/30835980/c-error-deduced-conflicting-types-for-parameter-t-string-vs-const-char
		template <typename T>
		struct identity {
			typedef T type;
		};

		template <typename T>
		void resizeAndCompare(ft::vector<T> &ft,std::vector<T> &std, size_t new_size,
		                      typename identity<T>::type value) {
			ft.resize(new_size, value);
			std.resize(new_size, value);
			compareVectors(ft, std);
		}

		template <typename T>
		void reserveAndCompare(ft::vector<T> &ft,std::vector<T> &std, size_t new_cap) {
			ft.reserve(new_cap);
			std.reserve(new_cap);
			compareVectors(ft, std);
		}

		template <typename T>
		void checkExceptions(ft::vector<T> &ft,std::vector<T> &std, size_t new_size,
		                     bool is_resize) {
			bool ft_exception = false,
                 std_exception = false;

			try {
				is_resize ? ft.resize(new_size) : ft.reserve(new_size);
			} catch (std::exception &e) {
				ft_exception = true;
			}

			try {
				is_resize ? std.resize(new_size) : std.reserve(new_size);
			} catch (std::exception &e) {
				std_exception = true;
			}

			ft_exception == std_exception ? addOK() : addKO();
		}


		template <typename T>
		void clearVectors(ft::vector<T> &ft, std::vector<T> &std) {
			ft.clear();
			std.clear();
			compareVectors(ft, std);
		}

		template <typename T>
		void singleInsert(ft::vector<T> &ft, std::vector<T> &std, size_t option,
		                  size_t offset, typename identity<T>::type value) {
			if (option == BEGIN) {
				ft.insert(ft.begin() + offset, value);
				std.insert(std.begin() + offset, value);
			} else if (option == END) {
				ft.insert(ft.end() - offset, value);
				std.insert(std.end() - offset, value);
			}
			compareVectors(ft, std);
		}

		template <typename T>
		void rangedInsert(ft::vector<T> &ft, std::vector<T> &std, size_t option,
		                  size_t offset, size_t n, typename identity<T>::type value) {
			if (option == BEGIN) {
				ft.insert(ft.begin() + offset, n, value);
				std.insert(std.begin() + offset, n, value);
			} else if (option == END) {
				ft.insert(ft.end() - offset, n, value);
				std.insert(std.end() - offset, n, value);
			}
			compareVectors(ft, std);
		}

		template <typename T>
		void singleErase(ft::vector<T> &ft, std::vector<T> &std, size_t option,
		                 size_t offset) {
			if (option == BEGIN) {
				ft.erase(ft.begin() + offset);
				std.erase(std.begin() + offset);
			} else if (option == END) {
				ft.erase(ft.end() - offset);
				std.erase(std.end() - offset);
			}
			compareVectors(ft, std);
		}

		template <typename T>
		void rangedErase(ft::vector<T> &ft, std::vector<T> &std, size_t option1,
		                 size_t offset1, size_t option2, size_t offset2) {
			size_t size_before_erase = ft.size();

			if (option1 == BEGIN && option2 == BEGIN) {
				ft.erase(ft.begin() + offset1, ft.begin() + offset2);
				std.erase(std.begin() + offset1, std.begin() + offset2);
			} else if (option1 == BEGIN && option2 == END) {
				ft.erase(ft.begin() + offset1, ft.end() - offset2);
				std.erase(std.begin() + offset1, std.end() - offset2);
			} else if (option1 == END && option2 == BEGIN) {
				ft.erase(ft.end() - offset1, ft.begin() + offset2);
				std.erase(std.end() - offset1, std.begin() + offset2);
			} else if (option1 == END && option2 == END) {
				ft.erase(ft.end() - offset1, ft.end() - offset2);
				std.erase(std.end() - offset1, std.end() - offset2);
			}
			compareVectors(ft, std);

			/**
			** @brief    encountered some segmentation faults when using the rangedErase multiple times, in
			**           order to fix that issue I added this for loop to fill back the values that were erased
			**           and allow continuous use of rangedErase without having to reconstruct the vector
			*/
			for (size_t i = ft.size(); i < size_before_erase; i++) {
				size_t random_value = std::rand() % 123456789;
				ft.push_back(random_value);
				std.push_back(random_value);
			}
		}

		// Element Access Test Templates
		template <typename T>
		void KOLoop(ft::vector<T> &ft, std::vector<T> &std);
		template <typename T>
		void operatorLoop(ft::vector<T> &ft, std::vector<T> &std);
		template <typename T>
		void operatorModify(ft::vector<T> &ft, std::vector<T> &std, size_t n, typename identity<T>::type value);
		template <typename T>
		void atLoop(ft::vector<T> &ft, std::vector<T> &std);
		template <typename T>
		void atModify(ft::vector<T> &ft, std::vector<T> &std, size_t n, typename identity<T>::type value);
		template <typename T>
		void atException(ft::vector<T> &ft, std::vector<T> &std, size_t n);
		template <typename T>
		void compareFrontBack(ft::vector<T> &ft, std::vector<T> &std, bool is_front);
		template <typename T>
		void dataLoop(ft::vector<T> &ft, std::vector<T> &std);
		template <typename T>
		void dataModify(ft::vector<T> &ft, std::vector<T> &std, size_t n, typename identity<T>::type value);
};

#include <vector_tpp/vector_element_access.tpp>

// /*----------------------------------------------------------------------------*/

// void resetTestCount(std::string test_type) {
// 	test_no = 1;
// 	std::cout << test_type;
// }

// void printTestResult(int result) {
// 	result == OK ? std::cout << test_no++ << "." GREEN "OK " DEFAULT:
// 	result == WARNING ? std::cout << test_no++ << "." YELLOW "WARNING " DEFAULT:
// 	std::cout << test_no++ << "." RED "KO " DEFAULT;
// }

// /*----------------------------------------------------------------------------*/

// template <typename T>
// void checkEmpty(ft::vector<T> &ft, std::vector<T> &std) { ft.empty() == std.empty() ? printTestResult(OK) : printTestResult(KO); }

// template <typename T>
// void checkEmpty(ft::vector<T> &lhs, ft::vector<T> &rhs) { lhs.empty() == rhs.empty() ? printTestResult(OK) : printTestResult(KO); }

// /*----------------------------------------------------------------------------*/

// template <typename T>
// void checkSize(ft::vector<T> &ft, std::vector<T> &std) { ft.size() == std.size() ? printTestResult(OK) : printTestResult(KO); }

// template <typename T>
// void checkSize(ft::vector<T> &lhs, ft::vector<T> &rhs) { lhs.size() == rhs.size() ? printTestResult(OK) : printTestResult(KO); }

// /*----------------------------------------------------------------------------*/

// template <typename T>
// void checkCapacity(ft::vector<T> &ft, std::vector<T> &std) { ft.capacity() == std.capacity() ? printTestResult(OK) : printTestResult(WARNING); }

// template <typename T>
// void checkCapacity(ft::vector<T> &lhs, ft::vector<T> &rhs) { lhs.capacity() == rhs.capacity() ? printTestResult(OK) : printTestResult(WARNING); }

// /*----------------------------------------------------------------------------*/

// #if __APPLE__
// template < class T >
// void checkMaxSize(ft::vector<T> &ft, std::vector<T> &std) {
// 	if (ft.max_size() == ULONG_MAX && std.max_size() == LONG_MAX) {
// 		std::cout << test_no++ << "." GREEN "OK " DEFAULT;
// 	} else if (ft.max_size() == std.max_size()) {
// 		std::cout << test_no++ << "." GREEN "OK " DEFAULT;
// 	} else {
// 		std::cout << test_no++ << "." RED "KO " DEFAULT;
// 	}
// }

// template < class T >
// void checkMaxSize(ft::vector<T> &lhs, ft::vector<T> &rhs) {
// 	if (lhs.max_size() == ULONG_MAX && rhs.max_size() == LONG_MAX) {
// 		std::cout << test_no++ << "." GREEN "OK " DEFAULT;
// 	} else if (lhs.max_size() == rhs.max_size()) {
// 		std::cout << test_no++ << "." GREEN "OK " DEFAULT;
// 	} else {
// 		std::cout << test_no++ << "." RED "KO " DEFAULT;
// 	}
// }
// #endif

// #if __linux__
// template <typename T>
// void checkMaxSize(ft::vector<T> &ft, std::vector<T> &std) { ft.max_size() == std.max_size() ? printTestResult(OK) : printTestResult(KO); }

// template <typename T>
// void checkMaxSize(ft::vector<T> &lhs, ft::vector<T> &rhs) { lhs.max_size() == rhs.max_size() ? printTestResult(OK) : printTestResult(KO); }
// #endif

// /*----------------------------------------------------------------------------*/

// template <typename T>
// void checkContent(ft::vector<T> &ft, std::vector<T> &std) {
// 	std::stringstream ft_ss, std_ss;

// 	for (size_t i = 0; i < ft.size(); i++) {
// 		ft_ss << ft[i] << " ";
// 	}
// 	for (size_t i = 0; i < std.size(); i++) {
// 		std_ss << std[i] << " ";
// 	}

// 	ft_ss.str() == std_ss.str() ? printTestResult(OK) : printTestResult(KO);
// }

// template <typename T>
// void checkContent(ft::vector<T> &lhs, ft::vector<T> &rhs) {
// 	std::stringstream lhs_ss, rhs_ss;
// 	for (size_t i = 0; i < lhs.size(); i++) {
// 		lhs_ss << lhs[i] << " ";
// 	}
// 	for (size_t i = 0; i < rhs.size(); i++) {
// 		rhs_ss << rhs[i] << " ";
// 	}

// 	lhs_ss.str() == rhs_ss.str() ? printTestResult(OK) : printTestResult(KO);
// }

// /*----------------------------------------------------------------------------*/

// template <typename T>
// void compareVectors(ft::vector<T> &ft, std::vector<T> &std, bool add_newline) {
// 	checkContent(ft, std);
// 	checkEmpty(ft, std);
// 	checkSize(ft, std);
// 	checkCapacity(ft, std);
// 	checkMaxSize(ft, std);

// 	if (add_newline) {
// 		std::cout << std::endl;
// 	}
// }

// template <typename T>
// void compareVectors(ft::vector<T> &lhs, ft::vector<T> &rhs, bool add_newline) {
// 	checkContent(lhs, rhs);
// 	checkEmpty(lhs, rhs);
// 	checkSize(lhs, rhs);
// 	checkCapacity(lhs, rhs);
// 	checkMaxSize(lhs, rhs);

// 	if (add_newline) {
// 		std::cout << std::endl;
// 	}
// }

// /*----------------------------------------------------------------------------*/

// /**
// ** @brief    pushes random values to both ft and std containers
// **
// ** @param ft             address of container with ft namespace
// ** @param std            address of container with std namespace
// ** @param len            desired vector size
// ** @param compare_vec    determines if the ft and std vector will be compared once
// **                       the push_back loop ends
// ** @param add_newline    checks if the function should print a newline after testing
// */
// template <typename T>
// void vectorPushLoop(ft::vector<T> &ft, std::vector<T> &std, size_t len,
//                     bool compare_vec, bool add_newline) {
// 	for (size_t i = 0; i < len; i++) {
// 		size_t random_value = std::rand() % 123456789;
// 		ft.push_back(random_value);
// 		std.push_back(random_value);
// 	}

// 	if (compare_vec) {
// 		compareVectors(ft, std, add_newline);
// 	}
// }

// /**
// ** @brief    pushes the exact same string to both ft and std containers according to
// **           the size of len
// **
// ** @param str    std::string to be pushed to the ft and std vectors
// */
// template <typename T>
// void vectorPushLoop(ft::vector<T> &ft, std::vector<T> &std, size_t len,
//                     std::string str, bool compare_vec, bool add_newline) {
// 	for (size_t i = 0; i < len; i++) {
// 		ft.push_back(str);
// 		std.push_back(str);
// 	}

// 	if (compare_vec) {
// 		compareVectors(ft, std, add_newline);
// 	}
// }

// /*----------------------------------------------------------------------------*/

// template <typename T>
// void compareAtOutput(ft::vector<T> &ft, std::vector<T> &std) {
// 	if (ft.size() != std.size()) {
// 		for (size_t i = 0; i < std::max(ft.size(), std.size()); i++) {
// 			printTestResult(KO);
// 		}
// 	} else {
// 		for (size_t i = 0; i < ft.size(); i++) {
// 			ft.at(i) == std.at(i) ? printTestResult(OK) : printTestResult(KO);
// 		}
// 	}
// 	std::cout << std::endl;
// }

#endif
