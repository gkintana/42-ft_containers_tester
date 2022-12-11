/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_templates.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:11:47 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/11 16:21:33 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TEMPLATES_HPP
#define MAP_TEMPLATES_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sys/time.h>
#include <map>
#include "map.hpp"

/*---------------------------------------------------------------------------------------------------------*/

template <typename key, typename value>
void printMapInfo(NAMESPACE::map<key, value> &map) {
	std::cout << "--------------------------------------------------" << std::endl
	          << "map::empty() = " << std::boolalpha << map.empty() << std::endl
	          << "map::size() = " << map.size() << std::endl
	          << "Contents:" << std::endl;
}

template <typename key, typename value>
void printContent(NAMESPACE::map<key, value> &map) {
	printMapInfo(map);
	for (typename NAMESPACE::map<key, value>::iterator it = map.begin(); it != map.end(); it++) {
		std::cout << "Key = " << it->first << "   |   Value = " << it->second << std::endl;
	}
	std::cout << std::endl;
}

template <typename key, typename value>
void printByIterator(NAMESPACE::map<key, value> &map,
                     typename NAMESPACE::map<key, value>::iterator start,
                     typename NAMESPACE::map<key, value>::iterator end,
                     bool increment = true) {
	printMapInfo(map);
	for (typename NAMESPACE::map<key, value>::iterator it = start; it != end; increment ? it++ : it--) {
		std::cout << "Key = " << it->first << "   |   Value = " << it->second << std::endl;
	}
	std::cout << std::endl;
}

template <typename key, typename value>
void printByConstIterator(NAMESPACE::map<key, value> &map,
                          typename NAMESPACE::map<key, value>::const_iterator start,
                          typename NAMESPACE::map<key, value>::const_iterator end,
                          bool increment = true) {
	printMapInfo(map);
	for (typename NAMESPACE::map<key, value>::const_iterator it = start; it != end; increment ? it++ : it--) {
		std::cout << "Key = " << it->first << "   |   Value = " << it->second << std::endl;
	}
	std::cout << std::endl;
}

template <typename key, typename value>
void printByReverseIterator(NAMESPACE::map<key, value> &map,
                            typename NAMESPACE::map<key, value>::reverse_iterator start,
                            typename NAMESPACE::map<key, value>::reverse_iterator end,
                            bool increment = true) {
	printMapInfo(map);
	for (typename NAMESPACE::map<key, value>::reverse_iterator it = start; it != end; increment ? it++ : it--) {
		std::cout << "Key = " << it->first << "   |   Value = " << it->second << std::endl;
	}
	std::cout << std::endl;
}

template <typename key, typename value>
void printByConstReverseIterator(NAMESPACE::map<key, value> &map,
                                 typename NAMESPACE::map<key, value>::const_reverse_iterator start,
                                 typename NAMESPACE::map<key, value>::const_reverse_iterator end,
                                 bool increment = true) {
	printMapInfo(map);
	for (typename NAMESPACE::map<key, value>::const_reverse_iterator it = start; it != end; increment ? it++ : it--) {
		std::cout << "Key = " << it->first << "   |   Value = " << it->second << std::endl;
	}
	std::cout << std::endl;
}

template <typename key, typename value, typename compare>
void printByKeyCompare(NAMESPACE::map<key, value, compare> &map,
                       typename NAMESPACE::map<key, value, compare>::key_compare comp) {
	std::cout << "--------------------------------------------------" << std::endl
	          << "map::empty() = " << std::boolalpha << map.empty() << std::endl
	          << "map::size() = " << map.size() << std::endl
	          << "Contents:" << std::endl;
	for (typename NAMESPACE::map<key, value, compare>::iterator it = map.begin(); comp(it->first, map.rbegin()->first); it++) {
		std::cout << "Key = " << it->first << "   |   Value = " << it->second << std::endl;
	}
}

template <typename key, typename value>
void printByValueCompare(NAMESPACE::map<key, value> &map) {
	printMapInfo(map);
	for (typename NAMESPACE::map<key, value>::iterator it = map.begin(); map.value_comp()(*it, *map.rbegin()); it++) {
		std::cout << "Key = " << it->first << "   |   Value = " << it->second << std::endl;
	}
}

/*---------------------------------------------------------------------------------------------------------*/

#define INSERT_BY_PAIR         1
#define INSERT_BY_MAKE_PAIR    2
#define INSERT_BY_OPERATOR     3

template <typename key, typename value>
void insertValue(NAMESPACE::map<key, value> &map, int insert_style,
                 typename NAMESPACE::map<key, value>::key_type first,
                 typename NAMESPACE::map<key, value>::mapped_type second) {
	if (insert_style == INSERT_BY_PAIR) {
		map.insert(NAMESPACE::pair<key, value>(first, second));
	} else if (insert_style == INSERT_BY_MAKE_PAIR) {
		map.insert(NAMESPACE::make_pair(first, second));
	} else if (insert_style == INSERT_BY_OPERATOR) {
		map[first] = second;
	} else {
		throw std::out_of_range("Incorrect insert style");
	}
}

template <typename key, typename value>
void insertValue(NAMESPACE::map<key, value> &map,
                 typename NAMESPACE::map<key, value>::iterator position,
                 typename NAMESPACE::map<key, value>::key_type first,
                 typename NAMESPACE::map<key, value>::mapped_type second) {
	map.insert(position, NAMESPACE::make_pair(first, second));
}

template <typename key, typename value>
void insertRandomValues(NAMESPACE::map<key, value> &map, size_t size) {
	for (size_t i = 0; i < size; i++) {
		insertValue(map, 1 + (std::rand() % 3), 10000 + (std::rand() % 20000), 10000 + (std::rand() % 30000));
	}
}

#endif
