
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#define MAX_NAME_LEN 30
#define ANSI_BLACK "\x1b[30m"
#define ANSI_RED "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_BLUE "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN "\x1b[36m"
#define ANSI_WHITE "\x1b[37m"
#define ANSI_RESET "\x1b[0m"

struct Team
{
    char name[MAX_NAME_LEN];
    int wins;
    int draws;
    int losses;
    int goals;
    int points;
    int rank;
};

static void msleep(unsigned int ms)
{
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}

static void set_color(const char *ansi_color)
{
#ifdef _WIN32
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    if (ansi_color == NULL)
    {
        SetConsoleTextAttribute(h, 7);
        return;
    }
    if (strcmp(ansi_color, ANSI_BLACK) == 0)
        SetConsoleTextAttribute(h, 0);
    else if (strcmp(ansi_color, ANSI_RED) == 0)
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    else if (strcmp(ansi_color, ANSI_GREEN) == 0)
        SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    else if (strcmp(ansi_color, ANSI_YELLOW) == 0)
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    else if (strcmp(ansi_color, ANSI_BLUE) == 0)
        SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    else if (strcmp(ansi_color, ANSI_MAGENTA) == 0)
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    else if (strcmp(ansi_color, ANSI_CYAN) == 0)
        SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    else if (strcmp(ansi_color, ANSI_WHITE) == 0)
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    else
        SetConsoleTextAttribute(h, 7);
#else
    if (ansi_color)
        printf("%s", ansi_color);
#endif
}

static void reset_color(void)
{
#ifdef _WIN32
    set_color(NULL);
#else
    printf("%s", ANSI_RESET);
#endif
}

#define MAT_AT(mat, N, i, j) ((mat)[(size_t)(i) * (size_t)(N) + (size_t)(j)])

static int *alloc_matrix_int(size_t N)
{
    if (N == 0)
        return NULL;
    int *m = (int *)calloc(N * N, sizeof(int));
    return m;
}

static void free_matrix_int(int *m)
{
    free(m);
}

static int *alloc_int_array(size_t N)
{
    if (N == 0)
        return NULL;
    int *arr = (int *)calloc(N, sizeof(int));
    return arr;
}

static void free_int_array(int *arr)
{
    free(arr);
}

void painting(void);
void printMatchResult(struct Team *team1, struct Team *team2);

void printSchedule(int NofTeams, struct Team teams[], int *a, int *matchCount);

void schedule(int NofTeams, int *a);

void printTable(int NofTeams, struct Team teams[], int *matchCount);

int main(void)
{
    int NofTeams, location_choice, menu_choice;

    while (1)
    {
        set_color(ANSI_CYAN);
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**    Welcome To our Tournament System  **\n");
        printf("\t\t\t******************************************\n\n");
        reset_color();

        set_color(ANSI_MAGENTA);
        printf("Menu:\n");
        msleep(80);
        printf("1. Run the program\n");
        msleep(80);
        printf("2. Exit\n");
        msleep(80);
        reset_color();

        set_color(ANSI_MAGENTA);
        printf("Enter your choice: ");
        reset_color();
        if (scanf("%d", &menu_choice) != 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            continue;
        }

        if (menu_choice == 1)
        {
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            painting();

            set_color(ANSI_GREEN);
            printf("Choose the location of the tournament:\n");
            reset_color();
            msleep(20);

            set_color(ANSI_YELLOW);
            printf("1. Parc Des Princes, Paris\n");
            msleep(10);
            printf("2. Allianz Arena, Munich\n");
            msleep(10);
            printf("3. Anfield, Liverpool\n");
            msleep(10);
            printf("4. San Siro, Milan\n");
            msleep(10);
            printf("5. Old Trafford, Manchester\n");
            msleep(10);
            printf("6. Santiago Bernabeu, Madrid\n");
            msleep(10);
            reset_color();

            do
            {
                set_color(ANSI_GREEN);
                printf("Enter your choice (1-6): ");
                reset_color();
                if (scanf("%d", &location_choice) != 1)
                {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    location_choice = -1;
                }
            } while (location_choice < 1 || location_choice > 6);

            set_color(ANSI_RED);
            switch (location_choice)
            {
            case 1:
                printf("Welcome to Parc des Princes, Paris!\n");
                break;
            case 2:
                printf("Welcome to Allianz Arena, Munich!\n");
                break;
            case 3:
                printf("Welcome to Anfield, Liverpool!\n");
                break;
            case 4:
                printf("Welcome to San Siro, Milan!\n");
                break;
            case 5:
                printf("Welcome to Old Trafford, Manchester!\n");
                break;
            case 6:
                printf("Welcome to Santiago Bernabeu, Madrid!\n");
                break;
            }
            reset_color();

            do
            {
                set_color(ANSI_GREEN);
                printf("\nEnter the number of teams (10 to 20): ");
                reset_color();
                if (scanf("%d", &NofTeams) != 1)
                {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    NofTeams = 0;
                }
            } while (NofTeams < 10 || NofTeams > 20);

            struct Team *teams = (struct Team *)malloc(sizeof(struct Team) * NofTeams);
            if (!teams)
            {
                printf("Memory error: cannot allocate teams.\n");
                return 1;
            }

            for (int i = 0; i < NofTeams; i++)
            {
                set_color(ANSI_MAGENTA);
                printf("Enter the name of Team %d: ", i + 1);
                reset_color();

                scanf("%29s", teams[i].name);

                teams[i].wins = 0;
                teams[i].draws = 0;
                teams[i].losses = 0;
                teams[i].goals = 0;
                teams[i].points = 0;
                teams[i].rank = 0;
            }

            int *a = alloc_matrix_int(NofTeams);
            int *matchCount = alloc_int_array(NofTeams);

            if (!a || !matchCount)
            {
                printf("Memory error: cannot allocate schedule data.\n");
                free(teams);
                free_matrix_int(a);
                free_int_array(matchCount);
                return 1;
            }

            srand((unsigned int)time(NULL));
            schedule(NofTeams, a);
            printSchedule(NofTeams, teams, a, matchCount);

            free(teams);
            free_matrix_int(a);
            free_int_array(matchCount);
        }
        else
        {
            printf("Exiting the program. Goodbye!\n");
            return 0;
        }
    }
}

void schedule(int NofTeams, int *a)
{
    int rounds = (NofTeams % 2 == 0 ? NofTeams - 1 : NofTeams);
    int teams = (NofTeams % 2 == 0 ? NofTeams : NofTeams + 1);

    int *idx = (int *)malloc(sizeof(int) * teams);
    if (!idx)
        return;

    for (int i = 0; i < teams; i++)
        idx[i] = (i < NofTeams ? i : -1);

    for (int r = 0; r < rounds; r++)
    {
        for (int i = 0; i < teams / 2; i++)
        {
            int t1 = idx[i];
            int t2 = idx[teams - 1 - i];

            if (t1 == -1 || t2 == -1)
                continue;

            MAT_AT(a, NofTeams, t1, t2) = r + 1;
            MAT_AT(a, NofTeams, t2, t1) = 0;
        }

        int last = idx[teams - 1];
        for (int k = teams - 1; k > 1; k--)
            idx[k] = idx[k - 1];
        idx[1] = last;
    }

    free(idx);
}

void printMatchResult(struct Team *team1, struct Team *team2)
{
    int g1 = rand() % 5;
    int g2 = rand() % 5;

    set_color(ANSI_RED);
    printf("Goals: %d - %d ", g1, g2);
    reset_color();

    team1->goals += g1;
    team2->goals += g2;

    if (g1 > g2)
    {
        set_color(ANSI_YELLOW);
        printf("(Team %s wins!)", team1->name);
        reset_color();
        team1->wins++;
        team1->points += 3;
        team2->losses++;
    }
    else if (g1 < g2)
    {
        set_color(ANSI_YELLOW);
        printf("(Team %s wins!)", team2->name);
        reset_color();
        team2->wins++;
        team2->points += 3;
        team1->losses++;
    }
    else
    {
        printf("(It's a draw!)");
        team1->draws++;
        team2->draws++;
        team1->points++;
        team2->points++;
    }
}

void printSchedule(int NofTeams, struct Team teams[], int *a, int *matchCount)
{
    printf("\nSchedule:\n");

    int rounds = (NofTeams % 2 == 0 ? NofTeams - 1 : NofTeams);

    for (int day = 1; day <= rounds; day++)
    {
        printf("\nDay %d:\n", day);

        for (int i = 0; i < NofTeams; i++)
        {
            for (int j = 0; j < NofTeams; j++)
            {
                if (i != j && MAT_AT(a, NofTeams, i, j) == day)
                {
                    set_color(ANSI_CYAN);
                    printf("%s vs %s: ", teams[i].name, teams[j].name);
                    reset_color();

                    msleep(200);
                    printMatchResult(&teams[i], &teams[j]);
                    printf("\n");

                    matchCount[i]++;
                    matchCount[j]++;
                }
            }
        }
    }

    printTable(NofTeams, teams, matchCount);
}

void printTable(int NofTeams, struct Team teams[], int *matchCount)
{
    printf("\nScores:\n");

    set_color(ANSI_GREEN);
    printf("+------------------------------+-------+-------+-------+--------+-------+\n");
    printf("| Team                         | Wins  | Draws | Loss  | Points | Goals |\n");
    printf("+------------------------------+-------+-------+-------+--------+-------+\n");
    reset_color();

    for (int i = 0; i < NofTeams; i++)
    {
        printf("| %-28s | %5d | %5d | %5d | %6d | %5d |\n",
               teams[i].name,
               teams[i].wins,
               teams[i].draws,
               teams[i].losses,
               teams[i].points,
               teams[i].goals);

        msleep(40);
    }

    set_color(ANSI_GREEN);
    printf("+------------------------------+-------+-------+-------+--------+-------+\n");
    reset_color();

    int best = 0;
    for (int i = 1; i < NofTeams; i++)
    {
        if (teams[i].points > teams[best].points)
            best = i;
        else if (teams[i].points == teams[best].points &&
                 teams[i].goals > teams[best].goals)
            best = i;
    }

    set_color(ANSI_CYAN);
    printf("\nThe Winner is: %s\n", teams[best].name);
    printf("Wins: %d | Draws: %d | Losses: %d | Points: %d | Goals: %d\n",
           teams[best].wins,
           teams[best].draws,
           teams[best].losses,
           teams[best].points,
           teams[best].goals);
    reset_color();

    msleep(120);
}

void painting(void)
{
    set_color(ANSI_YELLOW);
    printf("               ,,,,,,,,,..., ,, ,. .....,,,,,**********************\n");
    msleep(80);
    printf("               ,,,   ,,,...,,, . .......,,,,,**************,   ***\n");
    msleep(80);
    printf("               ,,,    ,,,...,,,,.....,..,,,,,**************    **,\n");
    msleep(80);
    printf("               .,,,   ,,,...,,,,,,,,,,..,,,,,**************   ***\n");
    msleep(80);
    printf("                ,,,    ,,,...,,,,,,,,,..,,,,,*************    ***\n");
    msleep(80);
    printf("                 ,,,   ,,,...,,,,,,,,,..,,,,,************,   ***\n");
    msleep(80);
    printf("                  ,,,,  ,,,...,,,,,,,,..,,,,,************  ***,\n");
    msleep(80);
    printf("                    ,,,, ,,,...,,,,,,,..,,,,,*********** ****\n");
    msleep(80);
    printf("                      .,,,,,,..,,,,,,,..,,,,,*************\n");
    msleep(80);
    printf("                           ,,,,,,,,,,,..,,,,,*********\n");
    msleep(80);
    printf("                             ,,,,,,,,,..,,,,,*******\n");
    msleep(80);
    printf("                              ,,,,,,,,,***********\n");
    msleep(80);
    printf("                                 ,,,,,,,********\n");
    msleep(80);
    printf("                                     ,,,****\n");
    msleep(80);
    printf("                                       .,,\n");
    msleep(80);
    printf("                                      ..,,\n");
    msleep(80);
    printf("                                      ..,,,\n");
    msleep(80);
    printf("                                     ...,,,\n");
    msleep(80);
    printf("                                     ...,,,,\n");
    msleep(80);
    printf("                                    ....,,,,,\n");
    msleep(80);
    printf("                                  ......,,,,,,\n");
    msleep(80);
    printf("                                 .......,,,,,,,,,,\n");
    msleep(80);
    printf("                              ..........,,,,,,,,,,,\n");
    msleep(80);

    printf("\n\n\n");

    set_color(ANSI_CYAN);
    printf("                                    __      __    _                  \n");
    printf("                                    \\ \\    / /__ | | __ ___ _ __  ___ \n");
    printf("                                     \\ \\/\\/ / -_)| |/ _/ _ \\ '  \\/ -_)\n");
    printf("                                      \\_/\\_/\\___ |_ \\__\\___/_|_|_\\___|\n");
    printf("\n\n\n");
    reset_color();
}