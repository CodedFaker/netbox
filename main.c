#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global string and token variables

char ip[13];
const char p[2] = ".";
char decimalNum[12];
char string[13];

// Function to convert a pre-calculated decimal 32-bit value to dotted decimal notation


const char * decimalToIp (unsigned int decimalVal)
{

    if ((decimalVal > 4294967295) || (decimalVal < 0))
    {

        printf("Value is out of bounds of a 32-bit number.");
        printf("Program will exit.");
        exit(EXIT_FAILURE);

    }

    unsigned int o1, o2, o3, o4;

    o1 = decimalVal >> 24;
    decimalVal = decimalVal - (o1 << 24);
    o2 = decimalVal >> 16;
    decimalVal = decimalVal - (o2 << 16);
    o3 = decimalVal >> 8;
    decimalVal = decimalVal - (o3 << 8);
    o4 = decimalVal;

    snprintf(string, sizeof(string), "%u.%u.%u.%u", o1, o2, o3, o4);

    return string;

}


// Function to convert given IP address to a 32-bit decimal number

unsigned int ipToDecimal(char *)
{

    char *token = strtok(ip, p);
    int count = 0;
    char octet1[4], octet2[4], octet3[4], octet4[4];

    while(token != NULL)
    {
        switch (count)
        {
            case 0:
                strcpy(octet1, token);
                if ((atoi(octet1)) > 255 || (atoi(octet1)) < 0)
                {
                    printf("Invalid octet value. Program will exit.");
                    exit(EXIT_FAILURE);
                }
                break;
            case 1:
                strcpy(octet2, token);
                if ((atoi(octet2)) > 255 || (atoi(octet2)) < 0)
                {
                    printf("Invalid octet value. Program will exit.");
                    exit(EXIT_FAILURE);
                }
                break;
            case 2:
                strcpy(octet3, token);
                if ((atoi(octet3)) > 255 || (atoi(octet3)) < 0)
                {
                    printf("Invalid octet value. Program will exit.");
                    exit(EXIT_FAILURE);
                }
                break;
            case 3:
                strcpy(octet4, token);
                if ((atoi(octet4)) > 255 || (atoi(octet4)) < 0)
                {
                    printf("Invalid octet value. Program will exit.");
                    exit(EXIT_FAILURE);
                }
                break;
        }

        token = strtok(NULL,p);
        count++;

    }

    unsigned int decimalValue = (atoi(octet1) * (256 * 256 * 256)) + (atoi(octet2) * (256 * 256)) + (atoi(octet3) * (256)) + (atoi(octet4));

    return decimalValue;
}


int main()
{
    for(;;)
    {

    printf("Select available options\n");
    printf("1 - Convert IP address to a decimal number.\n");
    printf("2 - Convert decimal number to an IP address.\n");
    printf("3 - Exit Program.\n");

    char choice[3];

    fgets(choice, sizeof(choice), stdin);
    printf("\n");


    switch(atoi(choice))
    {
        case 1:
            printf("Enter the IP address: \n");
            fgets(ip, sizeof(ip), stdin);
            printf("\nThe decimal value of the IP address is: %u\n\n\n", ipToDecimal(ip));
            break;
        case 2:
            printf("Enter the decimal value: \n");
            fgets(decimalNum, sizeof(decimalNum), stdin);
            printf("\nThe IP address of the decimal value is: %s\n\n\n", decimalToIp(atoi(decimalNum)));
            break;
        case 3:
            printf("Program will exit.\n");
            exit(EXIT_SUCCESS);
            break;
    }
    }
    return 0;
}
