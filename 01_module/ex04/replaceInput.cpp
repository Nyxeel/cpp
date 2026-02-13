/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceInput.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 01:22:13 by pjelinek          #+#    #+#             */
/*   Updated: 2026/02/13 12:17:09 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "fstream"

/*
std::string line;

	while (std::getline(inFile, line))
	{
		std::string finalString;
		size_t pos = line.find(str);

		if (pos == std::string::npos) // if nothing found, find returns size_t(-1)
		{
			finalString.append(line + '\n');
			outFile << finalString;
			continue;
		}

		std::string before;
		std::string after;
		size_t afterIndex;

		before = line.substr(0, pos); // String before str
		// std::cout << "\nBefore STRING: " << before << std::endl;

		afterIndex = pos + str.size();				  // Index to substr everything after str
		after = line.substr(afterIndex, line.size()); // string after str
		finalString = before + str2;				  // Final string to return

		if (afterIndex < line.size())
		{

			while (afterIndex < line.size())
			{
				size_t end = after.find(str);

				if (end == std::string::npos) // if find returns size_t(-1)
				{
					finalString.append(after + '\n');
					break;
				}
				before = after.substr(0, end);
				afterIndex = afterIndex + str.size(); // Index to substr everything after str
				after = after.substr(end + str.size(), after.size());
				finalString.append(before + str2);
			}
		}
		else
			finalString.append(after);
		outFile << finalString;
		std::cout << finalString;
	}
*/

void replaceInput(std::ifstream &inFile, std::ofstream &outFile,
				  const std::string str,
				  const std::string str2)
{

	std::string line;

	while (std::getline(inFile, line))
	{
		std::string finalString;
		std::string before;

		while (line.size())
		{
			size_t end = line.find(str);

			if (end == std::string::npos) // if find returns size_t(-1)
			{
				finalString.append(line + '\n');
				break;
			}
			before = line.substr(0, end);
			line = line.substr(end + str.size(), line.size());
			finalString.append(before + str2);
		}
		outFile << finalString;
		std::cout << finalString;
	}
}
