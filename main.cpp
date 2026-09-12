#include <iostream>

void showAverageDamage(double avgDamage)
{
    std::cout << "Average damage: " << avgDamage << std::endl;
}

double calculateAverageDamage(int numDice, int numDiceSides, int damageBonus)
{
    return (1 + numDiceSides) / 2.0 * numDice + damageBonus;
}

void getDamage()
{
    int numDice{};
    int numDiceSides{};
    int damageBonus{};

    std::cout << "Number of dice: ";
    std::cin >> numDice;

    std::cout << "Number of dice sides: ";
    std::cin >> numDiceSides;

    std::cout << "Damage bonus: ";
    std::cin >> damageBonus;

    double avgDamage{calculateAverageDamage(numDice, numDiceSides, damageBonus)};
    showAverageDamage(avgDamage);

}

int main()
{
    getDamage();
    return 0;
}
