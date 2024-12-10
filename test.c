#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if(argc < 3)
    {
        printf("input must be prompted as following: <num> <op> <num>.....");
        return 1;
    }

    double result = atof(argv[1]);

    for(int i = 2; i < argc; i += 2)
    {

        if(argc <= i + 1)
        {
            printf("error! no operand after operator.");
            return 1;
        }

        char op = argv[i][0];
        double num = atof(argv[i + 1]);

        switch (op)
        {
        case '+':
            result += num;
            break;
        case '-':
            result -= num;
            break;
        case '*':
            result *= num;
            break;
        case '/':
            if(num == 0)
            {
                printf("error! no division by zero.");
                return 1;
            }
            result /= num;
            break;
        
        default:
            printf("enter any valid operator:(+,-,*,/)");
            return 1;
        }
    }
    printf("%.2lf", result);
    return 0;
}    