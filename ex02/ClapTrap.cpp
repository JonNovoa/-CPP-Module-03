#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap&  ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and can´t attack!" << std::endl;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy points left!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(this->_hitPoints <= amount)
	{
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage! (now has 0 HP)" << std::endl;
	}
	else
	{
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage! (now has " << this->_hitPoints << " HP)" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and can't be repaired!" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy points left!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points! (now has " << this->_hitPoints << " HP)" << std::endl;
}