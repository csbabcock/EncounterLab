#include <iostream>

void showAverageDamage(double avgDamage)
{
    std::cout << "Average damage: " << avgDamage << std::endl;
}

void showAverageCritDamage(double critAverageDamage)
{
    std::cout << "Average critical damage: " << critAverageDamage << std::endl;
}

void showHitChance(double hitChance)
{
    std::cout << "Hit chance: " << hitChance * 100 << '%' << std::endl;
}

void showExpectedDamage(double expectedDamage)
{
    std::cout << "Expected damage: " << expectedDamage << std::endl;
}

double calculateAverageDamage(int numDice, int numDiceSides, int damageBonus)
{
    return (1 + numDiceSides) / 2.0 * numDice + damageBonus;
}

double calculateHitChance(int attackBonus, int targetAC)
{
    int minimumRoll = targetAC - attackBonus;
    int successfulRolls = 20 - minimumRoll + 1;

    double hitChance = successfulRolls / 20.0;

    if (hitChance > 0.95)
    {
      hitChance = 0.95;
    }
    else if (hitChance < 0.05)
    {
        hitChance = 0.05;
    }

    return hitChance;
}

double calculateExpectedDamage(double averageDamage, double averageCritDamage, double hitChance)
{
    constexpr double critChance = 0.05;
    double normalHitChance = hitChance - critChance;
    double normalDamage = averageDamage * normalHitChance;
    double critDamage = averageCritDamage * critChance;
    return critDamage + normalDamage;
}

void getDamage()
{
    int numDice{};
    int numDiceSides{};
    int damageBonus{};
    int attackBonus{};
    int targetAC{};

    std::cout << "Number of dice: ";
    std::cin >> numDice;

    std::cout << "Number of dice sides: ";
    std::cin >> numDiceSides;

    std::cout << "Damage bonus: ";
    std::cin >> damageBonus;

    std::cout << "Attack Bonus: ";
    std::cin >> attackBonus;

    std::cout << "Target AC: ";
    std::cin >> targetAC;

    double avgDamage{calculateAverageDamage(numDice, numDiceSides, damageBonus)};
    double critAverageDamage{calculateAverageDamage(numDice * 2, numDiceSides, damageBonus)};

    showAverageDamage(avgDamage);
    showAverageCritDamage(critAverageDamage);

    double hitChance{calculateHitChance(attackBonus, targetAC)};
    double expectedDamage{calculateExpectedDamage(avgDamage, critAverageDamage, hitChance)};

    showHitChance(hitChance);
    showExpectedDamage(expectedDamage);
}

int main()
{
    getDamage();
    return 0;
}
