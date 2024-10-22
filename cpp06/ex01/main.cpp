/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:36:41 by diodos-s          #+#    #+#             */
/*   Updated: 2024/10/22 13:44:37 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data myData;
	myData.value = 42;
	myData.name = "Serialization example";

	std::cout << "Original Data:" << std::endl;
	std::cout << "Value: " << myData.value << std::endl;
	std::cout << "Name: " << myData.name << std::endl;

	uintptr_t raw = Serializer::serialize(&myData);

	std::cout << "Serialized Data (raw): " << raw << std::endl;
	
	Data* deserializedData = Serializer::deserialize(raw);

	std::cout << "Deserialized Data:" << std::endl;
	std::cout << "Value: " << deserializedData->value << std::endl;
	std::cout << "Name: " << deserializedData->name << std::endl;

	return 0;
}