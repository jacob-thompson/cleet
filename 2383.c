#include <stdio.h>

int
getInitialEnergyNecessary(int *energy, int energySize)
{
    int necessary = 0;

    for (int i = 0; i < energySize; ++i)
        necessary += *(energy + i);

    return necessary + 1;
}

int
getInitialExperienceNecessary(int *experience, int experienceSize)
{
    int sum, jump, longestJump;
    sum = longestJump = 0;

    for (int i = 0; i < experienceSize; ++i) {
        int curr = *(experience + i);
        if (curr > sum) jump = curr - sum + 1;
        if (jump > longestJump) longestJump = jump;
        sum += curr;
    }

    return longestJump;
}

int
minNumberOfHours(
    int initialEnergy,
    int initialExperience,
    int* energy,
    int energySize,
    int* experience,
    int experienceSize
)
{
    const int enNecessary = getInitialEnergyNecessary(energy, energySize);
    const int xpNecessary = getInitialExperienceNecessary(experience, experienceSize);

    const int needEnergy = initialEnergy < enNecessary;
    const int needExperience = initialExperience < xpNecessary;

    if (!needEnergy && !needExperience) return 0;
    else {
        int hours = 0;

        hours += needEnergy ? enNecessary - initialEnergy : 0;
        hours += needExperience ? xpNecessary - initialExperience : 0;

        return hours;
    }
}

int
main(void)
{
    int energySize = 17;
    int energy[] = {
        58, 47, 100, 71, 47, 6, 92, 82, 35, 16, 50, 15, 42, 5, 2, 45, 22
    };

    int experienceSize = 17;
    int experience[] = {
        77, 83, 99, 76, 75, 66, 58, 84, 44, 98, 70, 41, 48, 7, 10, 61, 28
    };

    printf(
        "%d\n",
        getInitialEnergyNecessary(
            energy,
            energySize
        )
    );

    printf(
        "%d\n",
        getInitialExperienceNecessary(
            experience,
            experienceSize
        )
    );

    printf(
        "%d\n",
        minNumberOfHours(
            94,
            70,
            energy,
            energySize,
            experience,
            experienceSize
        )
    );

    return 0;
}
