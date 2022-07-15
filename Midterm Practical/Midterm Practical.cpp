
#include <iostream>
#include <string>
#include "Calculations.h"

int intInputValidationLocal()
{
    bool isNotNumber = true;
    int input;

    while (isNotNumber)
    {
        std::cin >> input;


        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Input is not a number. try again: ";
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            isNotNumber = false;
        }

    }

    return input;
}

int main()
{

    std::string questions[4] = {"What color is the sun?\n\n", "What is the mass of the sun if a car is driving 75 mph across the freeway?\n\n"
        , "Are the students having fun?\n\n", "How much does a water bottle cost?\n\n"};

    std::string answers[4] = { "1. Red\n2. Yellow\n3. Purple\n4. Orange\n\n", "1. 2.188 * 10^31 kg\n2. 1.989 * 10^30 kg\n3. 1.672 * 10^22 kg\n4. 1.024 * 10^26 kg\n\n",
        "1. Yes\n2. No\n3. Depends on the student you ask\n4. Mandatory fun\n\n","1. $2.00\n2. $1.00\n3. $5.00\n4. $0.50\n\n" };

    int answerNum[4] = { 4,2,3,1 };

    int corrects = 0;

    for (int i = 0; i < 4; i++)
    {
        bool loop = true;
        std::cout << questions[i];
        std::cout << answers[i];
        int choice;

        while (loop)
        {
            choice = intInputValidationLocal();
            if (choice >= 1 && choice <= 4)
            {
                loop = false;
            }
            else
            {
                std::cout << "Number not part of choice. Try again: ";
            }
        }

        if (choice == answerNum[i])
        {
            std::cout << "Correct!!";
            corrects += 1;
        }
        else {
            std::cout << "Sorry, that is incorrect :(";
        }

        std::cout << "\nPress Enter to continue...";
        std::cin.get();
        std::cin.clear();
        system("cls");
    }

    Calculations calc;

    std::cout << "You got " << corrects << " out of 4. the grade is:\n";
    std::cout << calc.result(corrects) << "%";
    std::cout << "\n\nThank you for taking this mini quiz!\nPress Enter to exit program...";
    std::cin.get();
    std::cin.clear();

}