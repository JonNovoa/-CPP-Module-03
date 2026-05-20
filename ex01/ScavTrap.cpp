#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void)
	: ClapTrap("Default")
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " is dead and can't attack!" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no energy points left!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target
			  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= amount)
	{
		this->_hitPoints = 0;
		std::cout << "ScavTrap " << this->_name << " takes " << amount << " points of damage! (now has 0 HP)" << std::endl;
	}
	else
	{
		this->_hitPoints -= amount;
		std::cout << "ScavTrap " << this->_name << " takes " << amount << " points of damage! (now has " << this->_hitPoints << " HP)" << std::endl;
	}
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " is dead and can't be repaired!" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no energy points left!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << "ScavTrap " << this->_name << " is repaired for " << amount << " points! (now has " << this->_hitPoints << " HP)" << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
}