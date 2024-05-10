#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[50];
    char email[50];
    char mobile[10];
    char *row;
    int col;
    char movie_selected[50];
} Details;

typedef struct{
    char *movie_name;
    char seats[10][15][4];
} Theatre;

Theatre *list = NULL;

Details *dynamic_array = NULL;
int count = 0;

Theatre one, two, three, four, five;

void SetColor(int color)
{
    printf("\033[0;%dm", color);
}

void PrintMenu()
{
    printf(" ____________________________________________\n");
    printf("|============================================|\n");
    printf("|               BOOK YOUR SHOW               |\n");
    printf("|Please select an option from below>         |\n");
    printf("|     (1) Enter Details:                     |\n");
    printf("|     (2) Show Details:                      |\n");
    printf("|     (3) Book Movies:                       |\n");
    printf("|     (4) Generate Bill                      |\n");
    printf("|     (5) Exit                               |\n");
    printf("|============================================|\n");
    printf(">");
}

void InputDetails()
{
    Details *temp = realloc(dynamic_array, (count + 1) * sizeof(Details));
    if (temp == NULL)
    {
        printf("\n Memory allocation failed !");
        return;
    }
    dynamic_array = temp;

    printf(">>> Enter your name: ");
    scanf(" %[^\n]", dynamic_array[count].name);
    getchar();
    printf(">>> Enter your email address:");
    scanf("%s", dynamic_array[count].email);
    getchar();
    printf(">>> Enter mobile number: ");
    scanf("%s", dynamic_array[count].mobile);
    getchar();

    count++;
}

void ShowDetails()
{
    printf(">>> Enter first or last name: ");
    char search[50];
    scanf("%s", search);
    for (int i = 0; i < count; i++) {
        if (strstr(dynamic_array[i].name, search) != NULL) {
            printf("Name: %s\nMobile: %s\nEmail: %s\n", dynamic_array[i].name, dynamic_array[i].mobile, dynamic_array[i].email);
        }
    }
}

void Book()
{
    printf(">>> Enter your first or last name: ");
    char search[50];
    scanf("%s", search);
    for (int i = 0; i < count; i++)
    {
        if (strstr(dynamic_array[i].name, search) != NULL)
        {
            printf("Which Movie would you like to watch:\n");
            printf("\t(1) Dune 2\n");
            printf("\t(2) Transformers One\n");
            printf("\t(3) Oppenheimer\n");
            printf("\t(4) Inception\n");
            printf("\t(5) Tenet\n");
            printf(">>>");
            int n;
            scanf("%d", &n);
            char s;
            char *empty_seat = "[ ]";
            char *booked_seat = "[X]";
            if (n == 1)
            {
                strcpy(dynamic_array[i].movie_selected, "Dune 2");
                printf("You have chosen the movie Dune 2\n");
                printf("Following is the price for each row in the theatre:\n");

                printf("Recliner $500\n");
                for (int i = 9; i > 8; i--)
                {
                    for (int j = 0; j < 15; j++)
                    {
                        if (strcmp(one.seats[i][j], empty_seat) == 0)
                            printf("\033[1;32m");
                        else
                            printf("\033[1;31m");
                        printf("%s ", one.seats[i][j]);
                    }
                    printf("\033[0m");
                    printf("\n");
                }
                printf("Prime $300\n");
                for (int i = 8; i > 5; i--)
                {
                    for (int j = 0; j < 15; j++)
                    {
                        if (strcmp(one.seats[i][j], empty_seat) == 0)
                            printf("\033[1;32m");
                        else
                            printf("\033[1;31m");
                        printf("%s ", one.seats[i][j]);
                    }
                    printf("\033[0m");
                    printf("\n");
                }
                printf("Nomral $200\n");
                for (int i = 5; i >= 0; i--)
                {
                    for (int j = 0; j < 15; j++)
                    {
                        if (strcmp(one.seats[i][j], empty_seat) == 0)
                            printf("\033[1;32m");
                        else
                            printf("\033[1;31m");
                        printf("%s ", one.seats[i][j]);
                    }
                    printf("\033[0m");
                    printf("\n");
                }

                printf(">>> Enter the row you would like: ");
                scanf(" %c", &s);
                printf(">>> Enter the seat number you would like (1-15)");
                int num;
                scanf("%d", &num);

                int temp = s - 'A';
                strcpy(one.seats[temp][num - 1], booked_seat);

                dynamic_array[i].row = malloc(sizeof(char));
                *(dynamic_array[i].row) = s;
                dynamic_array[i].col = num;
            }
            if (n == 2)
            {
                strcpy(dynamic_array[i].movie_selected, "Transformers One");
                printf("You have chosen the movie Transformers One\n");
                printf("Following is the price for each row in the theatre:\n");

                printf("Recliner $500\n");
                for (int i = 9; i > 8; i--)
                {
                    for (int j = 0; j < 15; j++)
                    {
                        if (strcmp(two.seats[i][j], empty_seat) == 0)
                            printf("\033[1;32m");
                        else
                            printf("\033[1;31m");
                        printf("%s ", two.seats[i][j]);
                    }
                    printf("\033[0m");
                    printf("\n");
                }
                printf("Prime $300\n");
                for (int i = 8; i > 5; i--)
                {
                    for (int j = 0; j < 15; j++)
                    {
                        if (strcmp(two.seats[i][j], empty_seat) == 0)
                            printf("\033[1;32m");
                        else
                            printf("\033[1;31m");
                        printf("%s ", two.seats[i][j]);
                    }
                    printf("\033[0m");
                    printf("\n");
                }
                printf("Nomral $200\n");
                for (int i = 5; i >= 0; i--)
                {
                    for (int j = 0; j < 15; j++)
                    {
                        if (strcmp(two.seats[i][j], empty_seat) == 0)
                            printf("\033[1;32m");
                        else
                            printf("\033[1;31m");
                        printf("%s ", two.seats[i][j]);
                    }
                    printf("\033[0m");
                    printf("\n");
                }

                printf(">>> Enter the row you would like: ");
                scanf(" %c", &s);
                printf(">>> Enter the seat number you would like (1-15)");
                int num;
                scanf("%d", &num);

                int temp = s - 'A';
                strcpy(two.seats[temp][num - 1], booked_seat);

                dynamic_array[i].row = malloc(sizeof(char));
                *(dynamic_array[i].row) = s;
                dynamic_array[i].col = num;
            }
            if (n == 3)
                        {
                            strcpy(dynamic_array[i].movie_selected, "Oppenheimer");
                            printf("You have chosen the movie Oppenheimer\n");
                            printf("Following is the price for each row in the theatre:\n");

                            printf("Recliner $500\n");
                            for (int i = 9; i > 8; i--)
                            {
                                for (int j = 0; j < 15; j++)
                                {
                                    if (strcmp(three.seats[i][j], empty_seat) == 0)
                                        printf("\033[1;32m");
                                    else
                                        printf("\033[1;31m");
                                    printf("%s ", three.seats[i][j]);
                                }
                                printf("\033[0m");
                                printf("\n");
                            }
                            printf("Prime $300\n");
                            for (int i = 8; i > 5; i--)
                            {
                                for (int j = 0; j < 15; j++)
                                {
                                    if (strcmp(three.seats[i][j], empty_seat) == 0)
                                        printf("\033[1;32m");
                                    else
                                        printf("\033[1;31m");
                                    printf("%s ", three.seats[i][j]);
                                }
                                printf("\033[0m");
                                printf("\n");
                            }
                            printf("Nomral $200\n");
                            for (int i = 5; i >= 0; i--)
                            {
                                for (int j = 0; j < 15; j++)
                                {
                                    if (strcmp(three.seats[i][j], empty_seat) == 0)
                                        printf("\033[1;32m");
                                    else
                                        printf("\033[1;31m");
                                    printf("%s ", three.seats[i][j]);
                                }
                                printf("\033[0m");
                                printf("\n");
                            }

                            printf(">>> Enter the row you would like: ");
                            scanf(" %c", &s);
                            printf(">>> Enter the seat number you would like (1-15)");
                            int num;
                            scanf("%d", &num);

                            int temp = s - 'A';
                            strcpy(three.seats[temp][num - 1], booked_seat);

                            dynamic_array[i].row = malloc(sizeof(char));
                            *(dynamic_array[i].row) = s;
                            dynamic_array[i].col = num;
                        }
            if (n == 4)
                        {
                            strcpy(dynamic_array[i].movie_selected, "Inception");
                            printf("You have chosen the movie Inception\n");
                            printf("Following is the price for each row in the theatre:\n");

                            printf("Recliner $500\n");
                            for (int i = 9; i > 8; i--)
                            {
                                for (int j = 0; j < 15; j++)
                                {
                                    if (strcmp(four.seats[i][j], empty_seat) == 0)
                                        printf("\033[1;32m");
                                    else
                                        printf("\033[1;31m");
                                    printf("%s ", four.seats[i][j]);
                                }
                                printf("\033[0m");
                                printf("\n");
                            }
                            printf("Prime $300\n");
                            for (int i = 8; i > 5; i--)
                            {
                                for (int j = 0; j < 15; j++)
                                {
                                    if (strcmp(four.seats[i][j], empty_seat) == 0)
                                        printf("\033[1;32m");
                                    else
                                        printf("\033[1;31m");
                                    printf("%s ", four.seats[i][j]);
                                }
                                printf("\033[0m");
                                printf("\n");
                            }
                            printf("Nomral $200\n");
                            for (int i = 5; i >= 0; i--)
                            {
                                for (int j = 0; j < 15; j++)
                                {
                                    if (strcmp(four.seats[i][j], empty_seat) == 0)
                                        printf("\033[1;32m");
                                    else
                                        printf("\033[1;31m");
                                    printf("%s ", four.seats[i][j]);
                                }
                                printf("\033[0m");
                                printf("\n");
                            }

                            printf(">>> Enter the row you would like: ");
                            scanf(" %c", &s);
                            printf(">>> Enter the seat number you would like (1-15)");
                            int num;
                            scanf("%d", &num);

                            int temp = s - 'A';
                            strcpy(four.seats[temp][num - 1], booked_seat);

                            dynamic_array[i].row = malloc(sizeof(char));
                            *(dynamic_array[i].row) = s;
                            dynamic_array[i].col = num;
                        }
            if (n == 5)
                        {
                            strcpy(dynamic_array[i].movie_selected, "Tenet");
                            printf("You have chosen the movie Tenet\n");
                            printf("Following is the price for each row in the theatre:\n");

                            printf("Recliner $500\n");
                            for (int i = 9; i > 8; i--)
                            {
                                for (int j = 0; j < 15; j++)
                                {
                                    if (strcmp(five.seats[i][j], empty_seat) == 0)
                                        printf("\033[1;32m");
                                    else
                                        printf("\033[1;31m");
                                    printf("%s ", five.seats[i][j]);
                                }
                                printf("\033[0m");
                                printf("\n");
                            }
                            printf("Prime $300\n");
                            for (int i = 8; i > 5; i--)
                            {
                                for (int j = 0; j < 15; j++)
                                {
                                    if (strcmp(five.seats[i][j], empty_seat) == 0)
                                        printf("\033[1;32m");
                                    else
                                        printf("\033[1;31m");
                                    printf("%s ", five.seats[i][j]);
                                }
                                printf("\033[0m");
                                printf("\n");
                            }
                            printf("Nomral $200\n");
                            for (int i = 5; i >= 0; i--)
                            {
                                for (int j = 0; j < 15; j++)
                                {
                                    if (strcmp(five.seats[i][j], empty_seat) == 0)
                                        printf("\033[1;32m");
                                    else
                                        printf("\033[1;31m");
                                    printf("%s ", five.seats[i][j]);
                                }
                                printf("\033[0m");
                                printf("\n");
                            }

                            printf(">>> Enter the row you would like: ");
                            scanf(" %c", &s);
                            printf(">>> Enter the seat number you would like (1-15)");
                            int num;
                            scanf("%d", &num);

                            int temp = s - 'A';
                            strcpy(five.seats[temp][num - 1], booked_seat);

                            dynamic_array[i].row = malloc(sizeof(char));
                            *(dynamic_array[i].row) = s;
                            dynamic_array[i].col = num;
                        }
        }
    }
}

void GenerateBill()
{
    printf(">>> Enter first or last name: ");
    char search[50];
    scanf("%s", search);
    for (int i = 0; i < count; i++) {
        if (strstr(dynamic_array[i].name, search) != NULL)
        {
            printf("\n\n\n********************************\n");
            printf("* Name : %s\n", dynamic_array[i].name);
            printf("* Email id : %s\n", dynamic_array[i].email);
            printf("* Mobile No : %s\n", dynamic_array[i].mobile);
            time_t currentTime;
            struct tm *localTime;
            currentTime = time(NULL);
            localTime = localtime(&currentTime);
            printf("* %s", asctime(localTime));
            printf("* Movie Selected: %s\n", dynamic_array[i].movie_selected);
            printf("* Seat %c %d\n", *(dynamic_array[i].row), dynamic_array[i].col);
            if ('A'<=*(dynamic_array[i].row) && *(dynamic_array[i].row)<='F')
                printf("* Price = $200\n");
            else if('G'<=*(dynamic_array[i].row) && *(dynamic_array[i].row)<='I')
                printf("* Price = $300\n");
            else if (*(dynamic_array[i].row) == 'J')
                printf("* Price = $500\n");
            printf("********************************\n\n\n");
        }
    }
}

int main()
{
    one.movie_name = malloc(strlen("Dune 2") + 1);
    strcpy(one.movie_name, "Dune 2");
    two.movie_name = malloc(strlen("Transformers One") + 1);
    strcpy(two.movie_name, "Transformers One");
    three.movie_name = malloc(strlen("Oppenheimer") + 1);
    strcpy(three.movie_name, "Oppenheimer");
    four.movie_name = malloc(strlen("Inception") + 1);
    strcpy(four.movie_name, "Inception");
    five.movie_name = malloc(strlen("Tenet") + 1);
    strcpy(five.movie_name, "Tenet");

    char *empty_seat = "[ ]";
    char *booked_seat = "[X]";

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            strcpy(one.seats[i][j], empty_seat);
            strcpy(two.seats[i][j], empty_seat);
            strcpy(three.seats[i][j], empty_seat);
            strcpy(four.seats[i][j], empty_seat);
            strcpy(five.seats[i][j], empty_seat);
        }
    }

    dynamic_array = malloc(sizeof(Details));
       if (dynamic_array == NULL)
       {
           printf("Memory allocation failed!\n");
       }

       int flag = 0;
       while (flag != 1)
       {
           PrintMenu();
           int n;
           scanf("%d", &n);
           switch (n)
           {
           case 1:
               InputDetails();
               break;
           case 2:
               ShowDetails();
               break;
           case 3:
               Book();
               break;
           case 4:
               GenerateBill();
               break;
           case 5:
               flag = 1;
               break;
           default:
               printf("Invalid entry!!!\n");
               break;
           }
       }

       free(dynamic_array);
       return 0;

}
