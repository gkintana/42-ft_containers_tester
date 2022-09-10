/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_templates.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 22:11:55 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/10 23:31:39 by gkintana         ###   ########.fr       */
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


		// https://stackoverflow.com/questions/30835980/c-error-deduced-conflicting-types-for-parameter-t-string-vs-const-char
		template <typename T>
		struct identity { typedef T type; };


		/*---------------------------- Element Access Test Templates ----------------------------*/
		template <typename T>
		void KOLoop(ft::vector<T> &ft, std::vector<T> &std);

		template <typename T>
		void operatorLoop(ft::vector<T> &ft, std::vector<T> &std);

		template <typename T>
		void operatorModify(ft::vector<T> &ft, std::vector<T> &std, size_t n,
		                    typename identity<T>::type value);

		template <typename T>
		void atLoop(ft::vector<T> &ft, std::vector<T> &std);

		template <typename T>
		void atModify(ft::vector<T> &ft, std::vector<T> &std, size_t n,
		              typename identity<T>::type value);

		template <typename T>
		void atException(ft::vector<T> &ft, std::vector<T> &std, size_t n);

		template <typename T>
		void compareFrontBack(ft::vector<T> &ft, std::vector<T> &std, bool is_front);

		template <typename T>
		void dataLoop(ft::vector<T> &ft, std::vector<T> &std);

		template <typename T>
		void dataModify(ft::vector<T> &ft, std::vector<T> &std, size_t n,
		                typename identity<T>::type value);


		/*------------------------------- Iterator Test Templates -------------------------------*/
		#define FT_ITER         typename ft::vector<T>::iterator
		#define STD_ITER        typename std::vector<T>::iterator
		#define FT_REV_ITER     typename ft::vector<T>::reverse_iterator
		#define STD_REV_ITER    typename std::vector<T>::reverse_iterator

		template <typename T>
		void compareIterToStd(ft::vector<T> &ft, std::vector<T> &std, int offset, int option);

		template <typename T>
		void iterLoop(ft::vector<T> &ft, std::vector<T> &std, FT_ITER start, FT_ITER end);

		template <typename T>
		void revIterLoop(ft::vector<T> &ft, std::vector<T> &std, FT_REV_ITER start, FT_REV_ITER end);


		/*------------------------------- Capacity Test Templates -------------------------------*/
		template <typename T>
		void resizeAndCompare(ft::vector<T> &ft,std::vector<T> &std, size_t new_size,
		                      typename identity<T>::type value);

		template <typename T>
		void reserveAndCompare(ft::vector<T> &ft,std::vector<T> &std, size_t new_cap);

		template <typename T>
		void capacityExceptions(ft::vector<T> &ft,std::vector<T> &std, size_t new_size, bool is_resize);


		/*-------------------------------- Modifier Test Templates ------------------------------*/
		template <typename T>
		void clearVectors(ft::vector<T> &ft, std::vector<T> &std);

		template <typename T>
		void singleInsert(ft::vector<T> &ft, std::vector<T> &std, size_t option, size_t offset,
		                  typename identity<T>::type value);

		template <typename T>
		void rangedInsert(ft::vector<T> &ft, std::vector<T> &std, size_t option, size_t offset,
		                  size_t n, typename identity<T>::type value);

		template <typename T>
		void singleErase(ft::vector<T> &ft, std::vector<T> &std, size_t option, size_t offset);

		template <typename T>
		void rangedErase(ft::vector<T> &ft, std::vector<T> &std, size_t option1, size_t offset1,
		                 size_t option2, size_t offset2);

		template <typename T>
		void pushLoop(ft::vector<T> &ft, std::vector<T> &std, size_t len);

		template <typename T>
		void pushLoop(ft::vector<T> &ft, std::vector<T> &std, size_t len, std::string str);

		template <typename T>
		void popLoop(ft::vector<T> &ft, std::vector<T> &std, size_t len);


		/*------------------------------ Non-Member Test Templates ------------------------------*/
		#define EQUAL            1
		#define NOT_EQUAL        2
		#define LESS             3
		#define LESS_EQUAL       4
		#define GREATER          5
		#define GREATER_EQUAL    6

		template <typename T>
		void relationalOper(ft::vector<T> &ft1, std::vector<T> &std1, ft::vector<T> &ft2,
		                    std::vector<T> &std2, size_t option);
};

#include "vector_tpp/vector_element_access.tpp"
#include "vector_tpp/vector_iterator.tpp"
#include "vector_tpp/vector_capacity.tpp"
#include "vector_tpp/vector_modifier.tpp"
#include "vector_tpp/vector_non_member.tpp"

#endif
