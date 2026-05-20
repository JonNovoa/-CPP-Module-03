#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void)
	: ClapTrap("Default_clap_name"), ScavTrap("Default"), FragTrap("Default"), _name("Default")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	this->_hitPoints = 100;      // FragTrap
	this->_energyPoints = 50;    // ScavTrap
	this->_attackDamage = 30;    // FragTrap
	std::cout << "DiamondTrap " << this->_name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_name = other._name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->_name << " destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "DiamondTrap " << this->_name << " is dead and can't attack!" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "DiamondTrap " << this->_name << " has no energy points left!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "DiamondTrap " << this->_name << " attacks " << target
			  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= amount)
	{
		this->_hitPoints = 0;
		std::cout << "DiamondTrap " << this->_name << " takes " << amount << " points of damage! (now has 0 HP)" << std::endl;
	}
	else
	{
		this->_hitPoints -= amount;
		std::cout << "DiamondTrap " << this->_name << " takes " << amount << " points of damage! (now has " << this->_hitPoints << " HP)" << std::endl;
	}
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "DiamondTrap " << this->_name << " is dead and can't be repaired!" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "DiamondTrap " << this->_name << " has no energy points left!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << "DiamondTrap " << this->_name << " is repaired for " << amount << " points! (now has " << this->_hitPoints << " HP)" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "I am DiamondTrap " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}