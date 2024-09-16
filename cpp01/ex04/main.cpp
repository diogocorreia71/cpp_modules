/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:48:43 by diodos-s          #+#    #+#             */
/*   Updated: 2024/09/16 10:02:59 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return 1;
	}
	
	std::ifstream inFile(argv[1]);
	if (!inFile.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return 1;
	}

	inFile.seekg(0, std::ios::end);
	if (inFile.tellg() == 0)
	{
		std::cout << "Error: The input file is empty" << std::endl;
		return 1;
	}
	inFile.seekg(0, std::ios::beg);
	
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::string outputFileName = argv[1];
	outputFileName += ".replace";
	
	std::ofstream outFile(outputFileName.c_str());
	if (!outFile.is_open())
	{
		std::cout << "Error opening output file" << std::endl;
		return 1;
	}
	
	std::string line;
	while (getline(inFile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outFile	<< line << std::endl;
	}
	inFile.close();
	outFile.close();

	return 0;
}
