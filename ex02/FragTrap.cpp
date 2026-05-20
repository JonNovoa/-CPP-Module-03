#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void)
	: ClapTrap("Default")
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_name << " destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "FragTrap " << this->_name << " is dead and can't attack!" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "FragTrap " << this->_name << " has no energy points left!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "FragTrap " << this->_name << " attacks " << target
			  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= amount)
	{
		this->_hitPoints = 0;
		std::cout << "FragTrap " << this->_name << " takes " << amount << " points of damage! (now has 0 HP)" << std::endl;
	}
	else
	{
		this->_hitPoints -= amount;
		std::cout << "FragTrap " << this->_name << " takes " << amount << " points of damage! (now has " << this->_hitPoints << " HP)" << std::endl;
	}
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "FragTrap " << this->_name << " is dead and can't be repaired!" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "FragTrap " << this->_name << " has no energy points left!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << "FragTrap " << this->_name << " is repaired for " << amount << " points! (now has " << this->_hitPoints << " HP)" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " requests a high five!" << std::endl;
}