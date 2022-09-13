/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_05_modifiers.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:27:04 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/14 00:25:13 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_performance.hpp>

static void clear();
static void singleInsert();
static void rangedInsert();
static void iteratorInsert();
static void singleErase();
static void rangedErase();
static void pushPop();
static void swap();

int main() {
	using std::chrono::high_resolution_clock;
    using std::chrono::duration;
	auto start = high_resolution_clock::now();


	std::srand(time(NULL));
	clear();
	singleInsert();
	rangedInsert();
	iteratorInsert();
	singleErase();
	rangedErase();
	pushPop();
	swap();


	auto end = high_resolution_clock::now();
	duration<double, std::milli> ms_double = end - start;
	std::cout << std::setprecision(3) << ms_double.count() << " ms" << std::endl;
	return 0;
}


int int_array[] = { 16801, 19817, 48952, 20130, 73915, 23176, 42669, 82132, 42510, 54383,
                    81435, 2480, 46371, 64482, 89407, 5378, 46018, 33244, 16355, 88450,
                    95943, 88707, 14117, 11984, 42966, 4000, 28060, 78251, 93742, 39744, };
std::string str_array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };


static void clear() {
	{
		NAMESPACE::vector<int> vec;
		vec.clear();
		pushLoop(vec, TEST_SIZE, RNG);
		vec.clear();
	}
	{
		NAMESPACE::vector<char> vec(42, 'A');
		vec.clear();
		pushLoop(vec, TEST_SIZE, RNG);
		vec.clear();
	}
	{
		NAMESPACE::vector<std::string> vec(str_array, str_array + (sizeof(str_array) / sizeof(std::string)));
		vec.clear();
	}
}

static void singleInsert() {
	{
		NAMESPACE::vector<int> vec;
		pushLoop(vec, TEST_SIZE, RNG);

		vec.insert(vec.begin() + 0, RNG);
		vec.insert(vec.begin() + vec.size() / 2, RNG);
		vec.insert(vec.begin() + vec.size() - 1, RNG);
		vec.insert(vec.end() - 1, RNG);
		vec.insert(vec.end() - vec.size() / 2, RNG);
		vec.insert(vec.end() - vec.size(), RNG);
	}
	{
		NAMESPACE::vector<std::string> vec(str_array, str_array + (sizeof(str_array) / sizeof(std::string)));

		vec.insert(vec.begin() + 0, "Lorem ipsum dolor sit amet");
		vec.insert(vec.begin() + vec.size() / 2, "Quisque accumsan fringilla eros, faucibus auctor leo gravida a. Maecenas sed mi sed tellus pulvinar mattis. Nulla auctor pretium nunc id auctor. Vivamus tincidunt leo sit amet est posuere tincidunt");
		vec.insert(vec.begin() + vec.size() - 1, "Sed a rutrum metus, vitae iaculis leo. Donec vulputate lacus nisl, et viverra quam blandit vitae. Mauris tempor mollis gravida. Morbi sed mauris at diam pretium rhoncus sit amet auctor odio. Ut sed nunc id leo ultrices dapibus sed a ligula. Fusce eget quam felis. Fusce dignissim elementum pretium. Quisque consectetur lectus non enim molestie efficitur");
		vec.insert(vec.end() - 1, "Mauris in eros pharetra, congue sapien at, varius lorem. Aenean cursus nulla at lectus eleifend suscipit. Aliquam sed lectus sed ante sodales sagittis ut et erat. Aenean eu lacus est. Proin et libero ultrices, lacinia ipsum quis, ultricies lectus. Ut volutpat libero ac lobortis accumsan. Etiam purus quam, convallis non blandit eu, sollicitudin vel sem. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Vivamus eleifend euismod euismod. Curabitur interdum sollicitudin est ut volutpat. Suspendisse molestie, mauris sit amet ultricies pulvinar, ante nisl posuere lorem, vel aliquet velit eros quis erat. Aliquam vel neque eu massa rhoncus convallis a non augue. Praesent venenatis magna condimentum nibh pulvinar pretium. Etiam maximus malesuada hendrerit. Interdum et malesuada fames ac ante ipsum primis in faucibus. Mauris mollis erat ut risus mollis, a dictum diam tincidunt");
		vec.insert(vec.end() - vec.size() / 2, "Hello World! From 42 Abu Dhabi");
		vec.insert(vec.end() - vec.size(), "012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
	}
}

static void rangedInsert() {
	{
		NAMESPACE::vector<int> vec;

		pushLoop(vec, 42, RNG);
		vec.insert(vec.begin() + 0, 42, RNG);
		vec.insert(vec.begin() + (vec.size() / 2), 24, RNG);
		vec.insert(vec.begin() + (vec.size() / 3), 0, RNG);
		vec.insert(vec.begin() + (vec.size() / 3), 21, RNG);
		vec.insert(vec.begin() + (vec.size() / 4), 100, RNG);
		vec.insert(vec.begin() + (vec.size() / 5), 1, RNG);
		vec.insert(vec.begin() + (vec.size() - 1), 123, RNG);
		vec.insert(vec.end() - 1, 1, RNG);
		vec.insert(vec.end() - 1, 20, RNG);
		vec.insert(vec.end() - vec.size(), 42, RNG);
		vec.insert(vec.end() - vec.size() / 2, 12, RNG);
		vec.insert(vec.end() - vec.size() / 3, 8, RNG);
		vec.insert(vec.end() - vec.size() / 4, 0, RNG);
		vec.insert(vec.end() - vec.size() / 4, 15, RNG);
	}
	{
		NAMESPACE::vector<std::string> vec;

		vec.insert(vec.begin() + 0, 42, "My");
		vec.insert(vec.begin() + (vec.size() / 2), 24, "dentist");
		vec.insert(vec.begin() + (vec.size() / 3), 0, "tells");
		vec.insert(vec.begin() + (vec.size() / 3), 21, "me");
		vec.insert(vec.begin() + (vec.size() / 4), 100, "that");
		vec.insert(vec.begin() + (vec.size() / 5), 1, "chewing");
		vec.insert(vec.begin() + (vec.size() - 1), 123, "bricks");
		vec.insert(vec.end() - 1, 1, "is");
		vec.insert(vec.end() - 1, 20, "very");
		vec.insert(vec.end() - vec.size(), 42, "bad");
		vec.insert(vec.end() - vec.size() / 2, 12, "for");
		vec.insert(vec.end() - vec.size() / 3, 8, "your");
		vec.insert(vec.end() - vec.size() / 4, 0, "teeth");
		vec.insert(vec.end() - vec.size() / 4, 15, "😬");
	}
}

static void iteratorInsert() {
	{
		NAMESPACE::vector<int> vec;
		pushLoop(vec, 42, RNG);

		vec.insert(vec.begin(), int_array, int_array + (sizeof(int_array) / sizeof(int)));
	}
	{
		NAMESPACE::vector<std::string> vec(str_array, str_array + (sizeof(str_array) / sizeof(std::string)));
		
		std::string array[] = { "My", "dentist", "tells", "me", "that", "chewing", "bricks", "is", "very", "bad", "for", "your", "teeth", "😬" };

		vec.insert(vec.begin(), array, array + (sizeof(array) / sizeof(std::string)));
	}
}

template <typename T>
static void eraseCases(NAMESPACE::vector<T> &vec) {
	vec.erase(vec.begin());
	vec.erase(vec.begin() + (vec.size() / 2));
	vec.erase(vec.begin() + (vec.size() - 1));
	vec.erase(vec.end() - 1);
	vec.erase(vec.end() - (vec.size() / 2));
	vec.erase(vec.end() - vec.size());
}

static void singleErase() {
	{
		NAMESPACE::vector<int> vec;
		pushLoop(vec, TEST_SIZE, RNG);
		eraseCases(vec);
	}
	{
		NAMESPACE::vector<std::string> vec(str_array, str_array + (sizeof(str_array) / sizeof(std::string)));
		eraseCases(vec);
	}
}

static void rangedErase() {
	NAMESPACE::vector<int> vec;
	pushLoop(vec, TEST_SIZE, RNG);

	vec.erase(vec.begin(), vec.begin());
	pushLoop(vec, TEST_SIZE - vec.size(), RNG);
	vec.erase(vec.begin(), vec.begin() + vec.size());
	pushLoop(vec, TEST_SIZE - vec.size(), RNG);
	vec.erase(vec.begin(), vec.end());
	pushLoop(vec, TEST_SIZE - vec.size(), RNG);
	vec.erase(vec.begin() + (vec.size() / 2), vec.end());
	pushLoop(vec, TEST_SIZE - vec.size(), RNG);
	vec.erase(vec.begin() + (vec.size() - 1), vec.end());
	pushLoop(vec, TEST_SIZE - vec.size(), RNG);
	vec.erase(vec.begin() + vec.size(), vec.end());
	pushLoop(vec, TEST_SIZE - vec.size(), RNG);
	vec.erase(vec.end() - 1, vec.begin() + vec.size());
	pushLoop(vec, TEST_SIZE - vec.size(), RNG);
	vec.erase(vec.end() - 1, vec.end() - 1);
	pushLoop(vec, TEST_SIZE - vec.size(), RNG);
}

static void pushPop() {
	{
		NAMESPACE::vector<char> vec;
		pushLoop(vec, 42, RNG);
		pushLoop(vec, 0, RNG);
		pushLoop(vec, 24, RNG);
		pushLoop(vec, 50, RNG);
		pushLoop(vec, 100, RNG);

		popLoop(vec, 0);
		popLoop(vec, vec.size() / 8);
		popLoop(vec, vec.size() / 6);
		popLoop(vec, vec.size() / 4);
		popLoop(vec, vec.size() / 3);
		popLoop(vec, vec.size() / 2);
	}
	{
		NAMESPACE::vector<int> vec;
		pushLoop(vec, 42, RNG);
		pushLoop(vec, 0, RNG);
		pushLoop(vec, 24, RNG);
		pushLoop(vec, 50, RNG);
		pushLoop(vec, 100, RNG);

		popLoop(vec, 0);
		popLoop(vec, vec.size() / 8);
		popLoop(vec, vec.size() / 6);
		popLoop(vec, vec.size() / 4);
		popLoop(vec, vec.size() / 3);
		popLoop(vec, vec.size() / 2);
	}
	{
		NAMESPACE::vector<std::string> vec;
		pushLoop(vec, 42, "Hello World!");
		pushLoop(vec, 0, "!!!!!");
		pushLoop(vec, 24, "42 Abu Dhabi is Awesome!");
		pushLoop(vec, 50, "abcdefghijklm");
		pushLoop(vec, 100, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean condimentum tellus eget tellus molestie fringilla");

		popLoop(vec, 0);
		popLoop(vec, vec.size() / 8);
		popLoop(vec, vec.size() / 6);
		popLoop(vec, vec.size() / 4);
		popLoop(vec, vec.size() / 3);
		popLoop(vec, vec.size() / 2);
	}
}

static void swap() {
	{
		NAMESPACE::vector<int> vec_1;
		pushLoop(vec_1, TEST_SIZE, RNG);
		NAMESPACE::vector<int> vec_2;
		pushLoop(vec_2, vec_1.size() * 3, RNG);

		vec_1.swap(vec_2);
	}
	{
		NAMESPACE::vector<std::string> vec_1;
		pushLoop(vec_1, TEST_SIZE, "42 Abu Dhabi is Awesome!");
		NAMESPACE::vector<std::string> vec_2;
		pushLoop(vec_2, vec_1.size() * 3, "Hello World!");

		vec_1.swap(vec_2);
	}
}
