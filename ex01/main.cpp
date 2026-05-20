#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "===== TEST 1: Constructor Chain =====" << std::endl;
	ScavTrap scavy("Serena");
	std::cout << std::endl;

	std::cout << "===== TEST 2: ScavTrap Attack =====" << std::endl;
	scavy.attack("Enemy");
	std::cout << std::endl;

	std::cout << "===== TEST 3: ScavTrap guardGate =====" << std::endl;
	scavy.guardGate();
	std::cout << std::endl;

	std::cout << "===== TEST 4: Take Damage =====" << std::endl;
	scavy.takeDamage(30);
	std::cout << std::endl;

	std::cout << "===== TEST 5: Be Repaired =====" << std::endl;
	scavy.beRepaired(15);
	std::cout << std::endl;

	std::cout << "===== TEST 6: Multiple Attacks (Drain Energy) =====" << std::endl;
	for (int i = 0; i < 52; i++)
		scavy.attack("Enemy");
	std::cout << std::endl;

	std::cout << "===== TEST 7: Try to act without energy =====" << std::endl;
	scavy.attack("Energy");
	scavy.beRepaired(10);
	scavy.guardGate();
	std::cout << std::endl;

	std::cout << "===== TEST 8: Drain to 0 HP =====" << std::endl;
	scavy.takeDamage(100);
	std::cout << std::endl;

	std::cout << "===== TEST 9: Try to act while dead =====" << std::endl;
	scavy.attack("Enemy");
	scavy.beRepaired(10);
	scavy.guardGate();
	std::cout << std::endl;

	std::cout << "===== TEST 10: Destructor Chain =====" << std::endl;
	return (0);	
}