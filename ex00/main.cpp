#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "=== Test 1: Constructor ===" << std::endl;
	ClapTrap clap("CL4P-TP");
	std::cout << std::endl;

	std::cout << "=== Test 2: Attack ===" << std::endl;
	clap.attack("Target");
	std::cout << std::endl;

	std::cout << "=== Test 3: Take Damage ===" << std::endl;
	clap.takeDamage(5);
	std::cout << std::endl;

	std::cout << "=== Test 4: Be Repaired ===" << std::endl;
	clap.beRepaired(3);
	std::cout << std::endl;

	std::cout << "=== Test 5: Multiple Attacks (drain energy) ===" << std::endl;
	for (int i = 0; i < 12; i++)
		clap.attack("Target");
	std::cout << std::endl;

	std::cout << "=== Test 6: Try to repair without energy ===" << std::endl;
	clap.beRepaired(5);
	std::cout << std::endl;

	std::cout << "=== Test 7: Reduce to 0 HP ===" << std::endl;
	clap.takeDamage(10);
	std::cout << std::endl;

	std::cout << "=== Test 8: Try to act while dead ===" << std::endl;
	clap.attack("Target");
	clap.beRepaired(5);
	std::cout << std::endl;

	std::cout << "=== Test 9: Destructor ===" << std::endl;
	return (0);
}