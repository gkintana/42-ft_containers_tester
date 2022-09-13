/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_06_non_member.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:49:36 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/14 00:22:28 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_performance.hpp>

static void relationalOperator();
static void nonMemberSwap();

int main() {
	using std::chrono::high_resolution_clock;
    using std::chrono::duration;
	auto start = high_resolution_clock::now();

	std::srand(time(NULL));
	relationalOperator();
	nonMemberSwap();

	auto end = high_resolution_clock::now();
	duration<double, std::milli> ms_double = end - start;
	std::cout << std::setprecision(3) << ms_double.count() << " ms" << std::endl;
	return 0;
}

static void relationalOperator() {
	{
		NAMESPACE::vector<int> vec_1;
		pushLoop(vec_1, 500, RNG);
		NAMESPACE::vector<int> vec_2;
		pushLoop(vec_2, vec_1.size() * 3, RNG);
		size_t temp[2];

		vec_1 == vec_2 ? temp[0]++ : temp[1]++;
		vec_1 != vec_2 ? temp[0]++ : temp[1]++;
		vec_1 < vec_2 ? temp[0]++ : temp[1]++;
		vec_1 <= vec_2 ? temp[0]++ : temp[1]++;
		vec_1 > vec_2 ? temp[0]++ : temp[1]++;
		vec_1 >= vec_2 ? temp[0]++ : temp[1]++;
	}
	{
		NAMESPACE::vector<std::string> vec_1(500, "Hello");
		NAMESPACE::vector<std::string> vec_2(vec_1.size() * 3, "World!");
		size_t temp[2];

		vec_1 == vec_2 ? temp[0]++ : temp[1]++;
		vec_1 != vec_2 ? temp[0]++ : temp[1]++;
		vec_1 < vec_2 ? temp[0]++ : temp[1]++;
		vec_1 <= vec_2 ? temp[0]++ : temp[1]++;
		vec_1 > vec_2 ? temp[0]++ : temp[1]++;
		vec_1 >= vec_2 ? temp[0]++ : temp[1]++;
	}
}

static void nonMemberSwap() {
	{
		NAMESPACE::vector<int> vec_1;
		pushLoop(vec_1, 500, RNG);
		NAMESPACE::vector<int> vec_2;
		pushLoop(vec_2, vec_1.size() * 3, RNG);

		NAMESPACE::swap(vec_1, vec_2);
	}
	{
		NAMESPACE::vector<std::string> vec_1(500, "42 Abu Dhabi is Awesome!");
		NAMESPACE::vector<std::string> vec_2(vec_1.size() * 3, "Hello World!");

		NAMESPACE::swap(vec_1, vec_2);
	}
}
