#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n===== TEST 1: ClapTrap Constructor Chain =====" << std::endl;
	ClapTrap clap("CL4P-TP");
	std::cout << std::endl;

	std::cout << "===== TEST 2: ScavTrap Constructor Chain =====" << std::endl;
	ScavTrap scavy("Serena");
	std::cout << std::endl;

	std::cout << "===== TEST 3: FragTrap Constructor Chain =====" << std::endl;
	FragTrap fraggy("Badass");
	std::cout << std::endl;

	std::cout << "===== TEST 4: ClapTrap Attack =====" << std::endl;
	clap.attack("Enemy");
	std::cout << std::endl;

	std::cout << "===== TEST 5: ScavTrap Attack =====" << std::endl;
	scavy.attack("Enemy");
	std::cout << std::endl;

	std::cout << "===== TEST 6: FragTrap Attack =====" << std::endl;
	fraggy.attack("Enemy");
	std::cout << std::endl;

	std::cout << "===== TEST 7: FragTrap highFivesGuys =====" << std::endl;
	fraggy.highFivesGuys();
	std::cout << std::endl;

	std::cout << "===== TEST 8: FragTrap Take Damage =====" << std::endl;
	fraggy.takeDamage(30);
	std::cout << std::endl;

	std::cout << "===== TEST 9: FragTrap Be Repaired =====" << std::endl;
	fraggy.beRepaired(15);
	std::cout << std::endl;

	std::cout << "===== TEST 10: Multiple Attacks (Drain Energy) =====" << std::endl;
	for (int i = 0; i < 102; i++)
		fraggy.attack("Enemy");
	std::cout << std::endl;

	std::cout << "===== TEST 11: Try to act without energy =====" << std::endl;
	fraggy.attack("Enemy");
	fraggy.beRepaired(10);
	fraggy.highFivesGuys();
	std::cout << std::endl;

	std::cout << "===== TEST 12: Drain to 0 HP =====" << std::endl;
	fraggy.takeDamage(100);
	std::cout << std::endl;

	std::cout << "===== TEST 13: Try to act while dead =====" << std::endl;
	fraggy.attack("Enemy");
	fraggy.beRepaired(10);
	fraggy.highFivesGuys();
	std::cout << std::endl;

	std::cout << "===== TEST 14: Destructor Chain =====" << std::endl;
	return (0);
}