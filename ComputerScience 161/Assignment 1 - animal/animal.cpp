/*********************************************
** Author: Peter Moldenhauer
** Date: 3/29/16
** Description: This program asks the user for
**a favorite animal and then prints the name
**of that animal back to the screen
*********************************************/

#include <iostream>
#include <string>

// a sample program

int main()
{
	std::string faveAnimal;
	std::cout << "Please enter your favorite animal." << std::endl;
	std::cin >> faveAnimal;
	std::cout << "Your favorite animal is the " << faveAnimal;
	std::cout << "." << std::endl;

return 0;
}
