#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n===== TEST 1: DiamondTrap Constructor =====" << std::endl;
	DiamondTrap diamond("Badass");
	std::cout << std::endl;

	std::cout << "===== TEST 2: whoAmI() =====" << std::endl;
	diamond.whoAmI();
	std::cout << std::endl;

	std::cout << "===== TEST 3: DiamondTrap Attack (from ScavTrap) =====" << std::endl;
	diamond.attack("Enemy");
	std::cout << std::endl;

	std::cout << "===== TEST 4: guardGate() (from ScavTrap) =====" << std::endl;
	diamond.guardGate();
	std::cout << std::endl;

	std::cout << "===== TEST 5: highFivesGuys() (from FragTrap) =====" << std::endl;
	diamond.highFivesGuys();
	std::cout << std::endl;

	std::cout << "===== TEST 6: Take Damage =====" << std::endl;
	diamond.takeDamage(30);
	std::cout << std::endl;

	std::cout << "===== TEST 7: Be Repaired =====" << std::endl;
	diamond.beRepaired(15);
	std::cout << std::endl;

	std::cout << "===== TEST 8: Multiple Attacks (Drain Energy) =====" << std::endl;
	for (int i = 0; i < 52; i++)
		diamond.attack("Enemy");
	std::cout << std::endl;

	std::cout << "===== TEST 9: Try to act without energy =====" << std::endl;
	diamond.attack("Enemy");
	diamond.beRepaired(10);
	diamond.whoAmI();
	std::cout << std::endl;

	std::cout << "===== TEST 10: Drain to 0 HP =====" << std::endl;
	diamond.takeDamage(100);
	std::cout << std::endl;

	std::cout << "===== TEST 11: Try to act while dead =====" << std::endl;
	diamond.attack("Enemy");
	diamond.beRepaired(10);
	diamond.whoAmI();
	std::cout << std::endl;

	std::cout << "===== TEST 12: Destructor =====" << std::endl;
	return (0);
}