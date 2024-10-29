/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:36:41 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/29 09:38:17 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data myData;
	myData.value = 42;
	myData.name = "Serialization example";

	std::cout << "<--------Original Data-------->" << std::endl;
	std::cout << "Value: " << myData.value << std::endl;
	std::cout << "Name: " << myData.name << std::endl;

	uintptr_t raw = Serializer::serialize(&myData);
	std::cout << std::endl;
	
	std::cout << "Serialized Data (raw): " << raw << std::endl;
	std::cout << std::endl;
	
	Data* deserializedData = Serializer::deserialize(raw);

	std::cout << "<--------Deserialized Data-------->" << std::endl;
	std::cout << "Value: " << deserializedData->value << std::endl;
	std::cout << "Name: " << deserializedData->name << std::endl;

	return 0;
}