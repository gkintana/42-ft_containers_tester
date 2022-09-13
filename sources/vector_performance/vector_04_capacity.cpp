/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_04_capacity.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:34:51 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/13 19:33:53 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_performance.hpp>

int main() {
	using std::chrono::high_resolution_clock;
    using std::chrono::duration;
	auto start = high_resolution_clock::now();


	std::srand(time(NULL));
	// Resize Tests
	{
		NAMESPACE::vector<long> vec;

		vec.resize(7, 1234567890);
		vec.resize(12, 42);
		vec.resize(0, INT_MAX);
		vec.resize(25, 'A');
		vec.resize(5, 123);
		vec.resize(8, 'z');
		vec.resize(12, 789789789);
	}
	{
		NAMESPACE::vector<std::string> vec;

		vec.resize(7, "Lorem ipsum dolor sit amet");
		vec.resize(12, "Proin tellus sem, facilisis vel faucibus nec, convallis in ex");
		vec.resize(0, "Quisque accumsan fringilla eros, faucibus auctor leo gravida a. Maecenas sed mi sed tellus pulvinar mattis. Nulla auctor pretium nunc id auctor. Vivamus tincidunt leo sit amet est posuere tincidunt");
		vec.resize(25, "Sed a rutrum metus, vitae iaculis leo. Donec vulputate lacus nisl, et viverra quam blandit vitae. Mauris tempor mollis gravida. Morbi sed mauris at diam pretium rhoncus sit amet auctor odio. Ut sed nunc id leo ultrices dapibus sed a ligula. Fusce eget quam felis. Fusce dignissim elementum pretium. Quisque consectetur lectus non enim molestie efficitur");
		vec.resize(5, "Mauris in eros pharetra, congue sapien at, varius lorem. Aenean cursus nulla at lectus eleifend suscipit. Aliquam sed lectus sed ante sodales sagittis ut et erat. Aenean eu lacus est. Proin et libero ultrices, lacinia ipsum quis, ultricies lectus. Ut volutpat libero ac lobortis accumsan. Etiam purus quam, convallis non blandit eu, sollicitudin vel sem. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Vivamus eleifend euismod euismod. Curabitur interdum sollicitudin est ut volutpat. Suspendisse molestie, mauris sit amet ultricies pulvinar, ante nisl posuere lorem, vel aliquet velit eros quis erat. Aliquam vel neque eu massa rhoncus convallis a non augue. Praesent venenatis magna condimentum nibh pulvinar pretium. Etiam maximus malesuada hendrerit. Interdum et malesuada fames ac ante ipsum primis in faucibus. Mauris mollis erat ut risus mollis, a dictum diam tincidunt");
		vec.resize(8, "Hello World!");
		vec.resize(12, "012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
	}
	// Resize Exception Tests
	{
		NAMESPACE::vector<int> vec(10, 12345);
		
		vec.reserve(42);
		vec.reserve('a');
		vec.reserve(0);
		vec.reserve(999999999);
		vec.reserve(vec.capacity());
		vec.reserve(123456789);
		vec.reserve('Z' + 98765 - 12345);
		vec.reserve(*vec.begin() + (vec.size() / 2));
	}
	
	auto end = high_resolution_clock::now();
	duration<double, std::milli> ms_double = end - start;
	std::cout << std::setprecision(3) << ms_double.count() << " ms" << std::endl;

	return 0;
}
