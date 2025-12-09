
#include <iostream>
#include <fstream>
#include <string>

int main()
{
	auto file = std::ifstream("data.txt");

	int count = 0;
	int total = 50;
	long int change = 0;
	std::string str;
	while (std::getline(file, str))
	{
		std::cout << str << std::endl;
		if (str.substr(0, 1) == "L") 
			change = - std::stoi(str.substr(1));
		else 
			change = + std::stoi(str.substr(1));

		int numbers = change % 100;
		int full_rotations = std::abs((change - numbers)/100);
		count += full_rotations;

		if (total == 0 && numbers < 0) // check moving from 0 negative
			count --;

		total += numbers;

		if (total < 0)
		{
			total = 100 + total;
			count++;
		}
		else if (total>99)
		{
			total = total % 100;
			count+=1;
		}

		if (total == 0 && numbers < 0)
			count++;

		std::cout << "total = " << total << std::endl;
	}
	std::cout << "Count = " << count << std::endl;;
}
