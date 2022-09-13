/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_05_modifiers.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:26:38 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/13 22:35:19 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

static void clearTests();
static void singleInsertTests();
static void rangedInsertTests();
static void iteratorInsertTests();
static void singleEraseTests();
static void rangedEraseTests();
static void pushPopTests();
static void swapTests();

int main() {
	std::srand(time(NULL));

	std::cout << PURPLE "Clear Tests" DEFAULT << std::endl;
	clearTests();

	std::cout << PURPLE "Single Insert Tests" DEFAULT << std::endl;
	singleInsertTests();

	std::cout << PURPLE "Ranged Insert Tests" DEFAULT << std::endl;
	rangedInsertTests();

	std::cout << PURPLE "Iterator Insert Tests" DEFAULT << std::endl;
	iteratorInsertTests();

	std::cout << PURPLE "Single Erase Tests" DEFAULT << std::endl;
	singleEraseTests();

	std::cout << PURPLE "Ranged Erase Tests" DEFAULT << std::endl;
	rangedEraseTests();

	std::cout << PURPLE "Push Back & Pop Back Tests" DEFAULT << std::endl;
	pushPopTests();

	std::cout << PURPLE "Swap Tests" DEFAULT << std::endl;
	swapTests();

	return 0;
}

/*----------------------------------------------------------------------------*/

static void clearTests() {
	vectorTester test;
	{
		ft::vector<char> ft(42, 'A');
		std::vector<char> std(42, 'A');
		test.clearVectors(ft, std);

		test.printTestResults("Char Vector   ");
	}

	{
		ft::vector<int> ft;
		std::vector<int> std;
		test.clearVectors(ft, std);
		test.pushLoop(ft, std, 42);
		test.clearVectors(ft, std);

		test.printTestResults("Int Vector    ");
	}

	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };
		ft::vector<std::string> ft_str(array, array + (sizeof(array) / sizeof(std::string)));
		std::vector<std::string> std_str(array, array + (sizeof(array) / sizeof(std::string)));
		test.clearVectors(ft_str, std_str);

		test.printTestResults("String Vector");
	}
}

static void singleInsertTests() {
	vectorTester test;
	{
		ft::vector<int> ft;
		std::vector<int> std;
		test.pushLoop(ft, std, 42);
		
		test.singleInsert(ft, std, BEGIN, 0, RNG);
		test.singleInsert(ft, std, BEGIN, ft.size() / 2, RNG);
		test.singleInsert(ft, std, BEGIN, ft.size() - 1, RNG);
		test.singleInsert(ft, std, END, 1, RNG);
		test.singleInsert(ft, std, END, ft.size() / 2, RNG);
		test.singleInsert(ft, std, END, ft.size(), RNG);
		
		test.printTestResults("Int Vector   ");	
	}

	{
		ft::vector<std::string> ft(10, "Hello!");
		std::vector<std::string> std(10, "Hello!");
		
		test.singleInsert(ft, std, BEGIN, 0, "lorem");
		test.singleInsert(ft, std, BEGIN, ft.size() / 2, "ipsum");
		test.singleInsert(ft, std, BEGIN, ft.size() - 1, "dolor");
		test.singleInsert(ft, std, END, 1, "sit");
		test.singleInsert(ft, std, END, ft.size() / 2, "amet");
		test.singleInsert(ft, std, END, ft.size(), ",");
		
		test.printTestResults("String Vector");	
	}
}

static void rangedInsertTests() {
	vectorTester test;
	{
		ft::vector<int> ft;
		std::vector<int> std;
		test.pushLoop(ft, std, 42);

		test.rangedInsert(ft, std, BEGIN, 0, 42, RNG);
		test.rangedInsert(ft, std, BEGIN, ft.size() / 2, 24, RNG);
		test.rangedInsert(ft, std, BEGIN, ft.size() / 3, 0, RNG);
		test.rangedInsert(ft, std, BEGIN, ft.size() / 3, 21, RNG);
		test.rangedInsert(ft, std, BEGIN, ft.size() / 4, 100, RNG);
		test.rangedInsert(ft, std, BEGIN, ft.size() / 5, 1, RNG);
		test.rangedInsert(ft, std, BEGIN, ft.size() - 1, 123, RNG);
		test.rangedInsert(ft, std, END, 1, 1, RNG);
		test.rangedInsert(ft, std, END, 1, 20, RNG);
		test.rangedInsert(ft, std, END, ft.size(), 42, RNG);
		test.rangedInsert(ft, std, END, ft.size() / 2, 12, RNG);
		test.rangedInsert(ft, std, END, ft.size() / 3, 8, RNG);
		test.rangedInsert(ft, std, END, ft.size() / 4, 0, RNG);
		test.rangedInsert(ft, std, END, ft.size() / 4, 15, RNG);

		test.printTestResults("Int Vector   ");
	}

	{
		ft::vector<std::string> ft(10, "Hello!");
		std::vector<std::string> std(10, "Hello!");

		test.rangedInsert(ft, std, BEGIN, 0, 42, "My");
		test.rangedInsert(ft, std, BEGIN, ft.size() / 2, 24, "dentist");
		test.rangedInsert(ft, std, BEGIN, ft.size() / 3, 0, "tells");
		test.rangedInsert(ft, std, BEGIN, ft.size() / 3, 21, "me");
		test.rangedInsert(ft, std, BEGIN, ft.size() / 4, 100, "that");
		test.rangedInsert(ft, std, BEGIN, ft.size() / 5, 1, "chewing");
		test.rangedInsert(ft, std, BEGIN, ft.size() - 1, 123, "bricks");
		test.rangedInsert(ft, std, END, 1, 1, "is");
		test.rangedInsert(ft, std, END, 1, 20, "very");
		test.rangedInsert(ft, std, END, ft.size(), 42, "bad");
		test.rangedInsert(ft, std, END, ft.size() / 2, 12, "for");
		test.rangedInsert(ft, std, END, ft.size() / 3, 8, "your");
		test.rangedInsert(ft, std, END, ft.size() / 4, 0, "teeth");
		test.rangedInsert(ft, std, END, ft.size() / 4, 15, "😬");

		test.printTestResults("String Vector");
	}
}

static void iteratorInsertTests() {
	vectorTester test;
	{
		ft::vector<int> ft;
		std::vector<int> std;
		test.pushLoop(ft, std, 42);

		int array[] = { 16801, 19817, 48952, 20130, 73915, 23176, 42669, 82132, 42510, 54383,
		                81435, 2480, 46371, 64482, 89407, 5378, 46018, 33244, 16355, 88450,
		                95943, 88707, 14117, 11984, 42966, 4000, 28060, 78251, 93742, 39744, };

		test.iteratorInsert(ft, std, BEGIN, 0, array, array + (sizeof(array) / sizeof(int)));

		test.printTestResults("Int Vector    ");
	}

	{
		std::string str[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };
		ft::vector<std::string> ft(str, str + (sizeof(str) / sizeof(std::string)));
		std::vector<std::string> std(str, str + (sizeof(str) / sizeof(std::string)));

		std::string array[] = { "My", "dentist", "tells", "me", "that", "chewing", "bricks", "is", "very", "bad", "for", "your", "teeth", "😬" };

		test.iteratorInsert(ft, std, BEGIN, 0, array, array + (sizeof(array) / sizeof(std::string)));

		test.printTestResults("String Vector");
	}
}


static void singleEraseTests() {
	vectorTester test;
	{
		ft::vector<int> ft;
		std::vector<int> std;
		test.pushLoop(ft, std, 42);

		test.singleErase(ft, std, BEGIN, 0);
		test.singleErase(ft, std, BEGIN, ft.size() / 2);
		test.singleErase(ft, std, BEGIN, ft.size() - 1);
		test.singleErase(ft, std, END, 1);
		test.singleErase(ft, std, END, ft.size() / 2);
		test.singleErase(ft, std, END, ft.size());

		test.printTestResults("Int Vector   ");
	}

	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };
		ft::vector<std::string> ft(array, array + (sizeof(array) / sizeof(std::string)));
		std::vector<std::string> std(array, array + (sizeof(array) / sizeof(std::string)));

		test.singleErase(ft, std, BEGIN, 0);
		test.singleErase(ft, std, BEGIN, ft.size() / 2);
		test.singleErase(ft, std, BEGIN, ft.size() - 1);
		test.singleErase(ft, std, END, 1);
		test.singleErase(ft, std, END, ft.size() / 2);
		test.singleErase(ft, std, END, ft.size());

		test.printTestResults("String Vector   ");
	}
}

static void rangedEraseTests() {
	vectorTester test;
	{
		ft::vector<int> ft;
		std::vector<int> std;
		test.pushLoop(ft, std, 256);

		test.rangedErase(ft, std, BEGIN, 0, BEGIN, 0);
		test.rangedErase(ft, std, BEGIN, 0, BEGIN, ft.size());
		test.rangedErase(ft, std, BEGIN, 0, END, 0);
		test.rangedErase(ft, std, BEGIN, ft.size() / 2, END, 0);
		test.rangedErase(ft, std, BEGIN, ft.size() - 1, END, 0);
		test.rangedErase(ft, std, BEGIN, ft.size(), END, 0);
		test.rangedErase(ft, std, END, 1, BEGIN, ft.size());
		test.rangedErase(ft, std, END, 1, END, 1);

		test.printTestResults("Int Vector   ");
	}
}

static void pushPopTests() {
	vectorTester test;
	{
		ft::vector<char> ft;
		std::vector<char> std;
		test.pushLoop(ft, std, 42);
		test.pushLoop(ft, std, 0);
		test.pushLoop(ft, std, 24);
		test.pushLoop(ft, std, 50);
		test.pushLoop(ft, std, 100);
		test.printTestResults("Char Vector (Push)");

		test.popLoop(ft, std, 0);
		test.popLoop(ft, std, ft.size() / 8);
		test.popLoop(ft, std, ft.size() / 6);
		test.popLoop(ft, std, ft.size() / 4);
		test.popLoop(ft, std, ft.size() / 3);
		test.popLoop(ft, std, ft.size() / 2);
		test.printTestResults("Char Vector (Pop)");
	}

	{
		ft::vector<int> ft;
		std::vector<int> std;
		test.pushLoop(ft, std, 42);
		test.pushLoop(ft, std, 0);
		test.pushLoop(ft, std, 24);
		test.pushLoop(ft, std, 50);
		test.pushLoop(ft, std, 100);
		test.printTestResults("Int Vector (Push)");

		test.popLoop(ft, std, 0);
		test.popLoop(ft, std, ft.size() / 8);
		test.popLoop(ft, std, ft.size() / 6);
		test.popLoop(ft, std, ft.size() / 4);
		test.popLoop(ft, std, ft.size() / 3);
		test.popLoop(ft, std, ft.size() / 2);
		test.printTestResults("Int Vector (Pop)");
	}

	{
		ft::vector<std::string> ft;
		std::vector<std::string> std;
		test.pushLoop(ft, std, 42, "Hello World!");
		test.pushLoop(ft, std, 0, "!!!!!");
		test.pushLoop(ft, std, 24, "42 Abu Dhabi is Awesome!");
		test.pushLoop(ft, std, 50, "abcdefghijklm");
		test.pushLoop(ft, std, 100, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean condimentum tellus eget tellus molestie fringilla");
		test.printTestResults("Str Vector (Push)");

		test.popLoop(ft, std, 0);
		test.popLoop(ft, std, ft.size() / 8);
		test.popLoop(ft, std, ft.size() / 6);
		test.popLoop(ft, std, ft.size() / 4);
		test.popLoop(ft, std, ft.size() / 3);
		test.popLoop(ft, std, ft.size() / 2);
		test.printTestResults("Str Vector (Pop)");
	}
}

static void swapTests() {
	vectorTester test;
	{
		ft::vector<int> ft1;
		std::vector<int> std1;
		test.pushLoop(ft1, std1, 24);
		ft::vector<int> ft2;
		std::vector<int> std2;
		test.pushLoop(ft2, std2, ft1.size() * 3);

		ft1.swap(ft2);
		std1.swap(std2);

		test.compareVectors(ft1, std1);
		test.compareVectors(ft2, std2);

		test.printTestResults("Int Vector   ");
	}

	{
		ft::vector<std::string> ft1;
		std::vector<std::string> std1;
		test.pushLoop(ft1, std1, 24, "42 Abu Dhabi is Awesome!");
		ft::vector<std::string> ft2;
		std::vector<std::string> std2;
		test.pushLoop(ft1, std1, 42, "Hello World!");

		ft1.swap(ft2);
		std1.swap(std2);

		test.compareVectors(ft1, std1);
		test.compareVectors(ft2, std2);

		test.printTestResults("String Vector");
	}
}
