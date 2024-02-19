#include <iostream>
#include <string>
#include <vector>


int main() 
{
	int count;		
	std::vector<std::string> words;

	std::cin >> count;
	for (int i = 0; i < count; i++)
	{
		std::string word;
		std::cin >> word;

		int Length = std::size(word);
		if (Length > 10)
		{
			char first = word[0];
			char last = word[Length - 1];
			words.push_back(first + std::to_string(Length - 2) + last);
		}
		else
		{
			words.push_back(word);
		}
	}
	for (int i = 0; i < count; i++)
	{
		std::cout << words[i] << std::endl;
	}
	
}
