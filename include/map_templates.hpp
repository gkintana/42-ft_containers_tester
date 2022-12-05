/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_templates.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:11:47 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/05 21:14:11 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TEMPLATES_HPP
#define MAP_TEMPLATES_HPP

#include <iostream>
#include <iomanip>
#include <sys/time.h>
#include <map>
#include "map.hpp"

template <typename key, typename value>
void printContent(NAMESPACE::map<key, value> &map) {
	std::cout << "map::empty() = " << std::boolalpha << map.empty() << std::endl
	          << "map::size() = " << map.size() << std::endl
	          << "Contents:" << std::endl;
	for (typename NAMESPACE::map<key, value>::iterator it = map.begin(); it != map.end(); it++) {
		std::cout << "Key = " << it->first << "\t\t| Value = " << it->second << std::endl;
	}
	std::cout << std::endl;
}

#endif
