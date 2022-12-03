#include <map>
#include "map.hpp"
#include <sys/time.h>

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;


	NAMESPACE::map<int, int> test_map;
	test_map.insert(NAMESPACE::make_pair(1, 10));
	test_map.insert(NAMESPACE::make_pair(2, 20));
	test_map.insert(NAMESPACE::make_pair(3, 30));

	for (NAMESPACE::map<int, int>::iterator it = test_map.begin(); it != test_map.end(); it++) {
		std::cout << "Key = " << it->first << "\t| Value = " << it->second << std::endl;
	}


	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << (end - start) / 1000 << " ms"<< std::endl;
	return 0;
}

