#include "stdafx.h"

#include<iostream>
#include<fstream>
#include<string>
#include <iomanip>
#include <vector>

int main()
{
	//test

	/*std::string text; // The string to be searched
	std::cout << "Enter some text terminated by *:\n";
	std::getline(std::cin, text, '*');
	const std::string separators{ " ,;:.\"!?'\n" }; // Word delimiters
	std::vector<std::string> words; // Words found
	size_t start{ text.find_first_not_of(separators) }; // First word start index
	size_t end{}; // Index for end of a word
	while (start != std::string::npos) // Find the words
	{
		end = text.find_first_of(separators, start + 1); // Find end of word
		if (end == std::string::npos) // Found a separator?
			end = text.length(); // No, so set to last + 1
		words.push_back(text.substr(start, end - start)); // Store the word
		start = text.find_first_not_of(separators, end + 1); // Find 1st character of next word
	}
	std::cout << "Your string contains the following " << words.size() << " words:\n";
	size_t count{}; // Number output
	for (const auto& word : words)
	{
		std::cout << std::setw(15) << word;
		if (!(++count % 5))
			std::cout << std::endl;
	}
	std::cout << std::endl;*/

	//Code
	std::string text{};
	std::ifstream myfile("Error_find.txt");
	int cnt{};
	bool cap{};
	if (myfile.is_open())
	{
		std::vector<std::string> ans{};
		while (std::getline(myfile, text))
		{
			const std::string separators{ " ,;:.\"!?'\n()" };
			std::vector<std::string> words{};
			size_t start{ text.find_first_not_of(separators) };
			size_t end{};
			while (start != std::string::npos)
			{
				end = text.find_first_of(separators, start + 1); // Find end of word
				if (end == std::string::npos) // Found a separator?
					end = text.length(); // No, so set to last + 1
				words.push_back(text.substr(start, end - start)); // Store the word
				start = text.find_first_not_of(separators, end + 1); // Find 1st character of next word
			}
			//std::cout << "Your string contains the following " << words.size() << " words:\n";
			for (const std::string& word : words)
			{
				if (word.size() > 4)
				{
					//std::cout << s << std::endl;
					for (int i{}; i < word.size(); i++) //97 111 101 117 105 , 97 - 122 , 65 - 90
					{
						if (int(word[i]) > 96 & int(word[i]) < 123)
						{
							cnt++;
							cap = true;
						}
						else if (int(word[i]) > 64 & int(word[i]) < 91)
						{
							cnt++;
						}
						else
						{
							cnt = 0;
							cap = false;
						}
						if (int(word[i]) == 97 || int(word[i]) == 111 || int(word[i]) == 101 || int(word[i]) == 117
							|| int(word[i]) == 105 || int(word[i]) == 65 || int(word[i]) == 79 || int(word[i]) == 69
							|| int(word[i]) == 85 || int(word[i]) == 73)
						{
							cnt = 0;
							cap = false;
						}

						if (cnt == 5 & cap)
						{
							//std::cout << word << std::endl;
							/*count++;
							std::cout << std::setw(15) << word;
							if (!(count % 5))
								std::cout << std::endl;*/
							ans.push_back(word);
							break;
						}
					}
					cnt = 0;
					cap = false;
				}
			}
		}
		size_t count{}; // Number output
		for (const std::string& a : ans)
		{
			std::cout << std::setw(15) << a;
			if (!(++count % 5))
				std::cout << std::endl;
		}
		if (count % 5)
			std::cout << std::endl;
	}
	else
		std::cout << "Unable to open file\n";
	myfile.close();



	//Original
	/*std::string s{};
	std::ifstream myfile("Error_find.txt");
	int cnt{};
	bool cap{};
	if (myfile.is_open())
	{
		while (myfile >> s)
		{
			if (s.size() > 4)
			{
				//std::cout << s << std::endl;
				for (int i{}; i < s.size(); i++) //97 111 101 117 105 , 97 - 122 , 65 - 90
				{
					if (int(s[i]) > 96 & int(s[i]) < 123)
					{
						cnt++;
						cap = true;
					}
					else if (int(s[i]) > 64 & int(s[i]) < 91)
					{
						cnt++;
					}
					else
					{
						cnt = 0;
						cap = false;
					}
					if (int(s[i]) == 97 || int(s[i]) == 111 || int(s[i]) == 101 || int(s[i]) == 117
						|| int(s[i]) == 105 || int(s[i]) == 65 || int(s[i]) == 79 || int(s[i]) == 69
						|| int(s[i]) == 85 || int(s[i]) == 73)
					{
						cnt = 0;
						cap = false;
					}

					if (cnt == 5 & cap)
					{
						std::cout << s << std::endl;
						break;
					}
				}
				cnt = 0;
				cap = false;
			}
		}
	}
	else
		std::cout << "Unable to open file\n";
	myfile.close();*/
    return 0;
}

