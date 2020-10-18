#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game(int x);
int random();
int start();
int randomNumber;
int count;

int main(void)
{

    printf("********************************\n");
    printf("********************************\n");
    printf("     THE GUESSING GAME           \n");
    printf("********************************\n");
    printf("********************************\n\n");

    printf("I have chosen a number between 0 and 20 which you must guess. Press 21 to quit\n\n\n");

    count = 5;

    random();

    start();

    return 0;
}

int start()
{
    int guess;

    printf("You have %d tries left.\n", count);
    count--;
    printf("Enter a guess:  ");
    scanf_s("%d", &guess);

    if (guess > 20 || guess < 0)
    {
        printf("number must be between 0 and 20");
    }
    if (guess == 21)
    {
        exit(0);
    }

    game(guess);
}

/*Geneating a random number */

int random()
{
    time_t t;
    srand((unsigned)time(&t));
    randomNumber = rand() % 21;
    return randomNumber;
}

void game(int x)
{
    if (x == randomNumber)
    {
        printf("Congratulations!! Yoou guessed it ! \n\n\n\n");
        main();
    }

    if (count == 0)
    {
        printf("You have no more attempts. You loose!  \n\n");
        main();
    }

    while (x != randomNumber && count != 0)
    {

        if (x < randomNumber)
        {
            printf("Sorry %d is wrong. My number is more than that.\n\n", x);
        }
        if (x > randomNumber)
        {
            printf("Sorry %d is wrong. My number is less than that.\n\n", x);
        }

        start();
    }

    return;
}
