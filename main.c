#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//   structs
typedef struct
{
    int day;
    int month;
    int year;
} date;

typedef struct
{
    int id;
    char title[50];
    char description[100];
    char status[15];
    date deadline;
} task;

// Global variables
task list[50];
int total = 0, checker = 0;
int choice, id,  statusNum;


// Add task
void addTask()
{
    list[total].id = total + 1;

    printf("Please enter task title : \t");
    scanf(" %[^\n]", list[total].title);
    printf("Please enter task description : \t");
    scanf(" %[^\n]", list[total].description);
    printf("Please enter the deadline date as following format (day/month/year): \t");
    scanf(" %d/%d/%d", &list[total].deadline.day, &list[total].deadline.month, &list[total].deadline.year);

    printf("Please enter number of task status : \n");
    printf("\t1 - To Do\n");
    printf("\t2 - Doing\n");
    printf("\t3 - Done\n");
there:
    printf("Enter a number from (1-3) : ");
    scanf(" %d", &statusNum);

    if (statusNum >= 1 && statusNum <= 3)
    {
        if (statusNum == 1)
        {
            strcpy(list[total].status, "To Do");
        }
        else if (statusNum == 2)
        {
            strcpy(list[total].status, "Doing");
        }
        else if (statusNum == 3)
        {
            strcpy(list[total].status, "Done");
        }
    }
    else
    {
        goto there;
        printf("Invalide Choice, Please try again !!! \n");
    }
    printf("\t\t\tTask Added Successflly !!! \n");

    total++;
}
// Add Multiple task
void addMultipleTask()
{
    printf("Please enter how many task you want add : \n");
    scanf("%d", &choice);

    for (int i = 0; i < choice; i++)
    {
        addTask();
    }
}
// Display all tasks
void displayTasks()
{

    printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
    printf("| ID |       Title             |          Description          |  Deadline        |        Status        |\n");
    printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");

    for (int i = 0; i < total; i++)
    {
        printf("| %-2d | %-23s | %-29s | %04d-%02d-%02d\t  | %-21s|\n", list[i].id, list[i].title, list[i].description, list[i].deadline.year, list[i].deadline.month, list[i].deadline.day, list[i].status);
        printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
    }
}
// swap
void swap()
{
    task temp;
    int j;
    temp = list[j];
    list[j] = list[j + 1];
    list[j + 1] = temp;
}
// Sort by Aphabeticall order
void sortByAlphabeticall()
{
    int i, j;
    for (i = 0; i < total - 1; i++)
    {
        for (j = 0; j < total - i - 1; j++)
        {
            if (strcmp(list[j].title, list[j + 1].title) > 0)
            {
                swap();
            }
        }
    }
    for
}
// i have to create the deadline sorting function
// Searching ID / title
void searchingByID()
{

    printf("Please enter task ID to search : ");
    scanf("%d", &id);

    for (int i = 0; i < total; i++)
    {
        if (id == list[total].id)
        {

            checker = 1;
            printf("\t\t\tThe task exist \n");
            displayTasks();
        }
        else
        {
            checker = 0;
        }
    }
    if (checker == 0)
    {
        printf("\t\t\tID don't exist !!! \n");
    }
}
void searchingByTitle()
{

    char title[50];
    checker = 0;

    printf("Please enter task title to search : ");
    scanf("%[^\n]", title);

    for (int i = 0; i < total; i++)
    {
        if (strcmp(title, list[i].title) == 0)
        {
            checker = 1;
            printf("This Task exists on ID : %d", i + 1);
            displayTasks();
        }
        else
        {
            checker = 0;
        }
    }
    if (checker == 0)
    {
        printf("Title doesn't exist or incorrect try agin !!!");
    }
}
// Modify Task
void ModifyTask()
{

    checker = 0;
    printf("Please Enter ID task to modify : ");
    scanf("%d", &id);

    for (int i = 0; i < 0; i++)
    {
        if (id == list[total].id)
        {
            checker = 1;
            printf("\t\t\t *** Please fill the new information to modify ***\n");
            printf("New title : \t");
            scanf(" %[^\n]", list[total].title);
            printf("New Description : \t");
            scanf(" %[^\n]", list[total].description);
            printf("Please enter new deadline as following format (day/month/year): \t");
            scanf(" %d/%d/%d", &list[total].deadline.day, &list[total].deadline.month, &list[total].deadline.year);

            printf("Please enter number of task status : \n");
            printf("\t1 - To Do\n");
            printf("\t2 - Doing\n");
            printf("\t3 - Done\n");
        there:
            printf("Enter a number from (1-3) : ");
            scanf(" %d", &statusNum);

            if (statusNum >= 1 && statusNum <= 3)
            {
                if (statusNum == 1)
                {
                    strcpy(list[total].status, "To Do");
                }
                else if (statusNum == 2)
                {
                    strcpy(list[total].status, "Doing");
                }
                else if (statusNum == 3)
                {
                    strcpy(list[total].status, "Done");
                }
                printf("\t\t\tTask Modified Successflly !!! \n");
            }
            else
            {
                goto there;
                printf("Invalide Choice, Please try again !!! \n");
            }
        }
    }
    if (checker == 0){
        printf("ID Doesn't exist !!! \n");
    }
}
// Delete Task
void deleteByID (){
    printf("\t\t\t *** Delete a task *** \n");
    searchingByID();
    printf("%d", list[total].id);

}

int main()
{
    printf("%d", total);
     do
    {
        printf("\n**********************************\n");
        printf("*      Task Manager Menu         *\n");
        printf("**********************************\n");
        printf("1. Add a new task\n");
        printf("2. Add multiple tasks\n");
        printf("3. Display all tasks\n");
        printf("4. Sort tasks alphabetically\n");
        printf("5. Search task by ID\n");
        printf("6. Search task by title\n");
        printf("7. Delete task\n");
        printf("8. Modify task\n");
        printf("9. Display tasks with deadline within 3 days\n");
        printf("10. Remaining days for each task\n");
        printf("11. Display statistics\n");
        printf("0. Exit\n\n");
        printf("\t\t*** Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\e[1;1H\e[2J");
            addTask();
            break;
        case 2:
            printf("\e[1;1H\e[2J");
            addMultipleTask();
            break;
        case 3:
            printf("\e[1;1H\e[2J");
            displayTasks();
            break;
        case 4:
            printf("\e[1;1H\e[2J");
            sortByAlphabeticall();
            break;
        case 5:
            printf("\e[1;1H\e[2J");
            searchingByID();
            break;
        case 6:
            printf("\e[1;1H\e[2J");
            searchingByTitle();
            break;
        case 7:
            printf("\e[1;1H\e[2J");
            deleteByID();
            break;
        case 8:
            printf("\e[1;1H\e[2J");
            ModifyTask();
            break;
        case 9:
            printf("\e[1;1H\e[2J");
            //delete_task();
            break;
        case 10:
            printf("\e[1;1H\e[2J");
            //updating_task();
            break;
        case 11:
            printf("\e[1;1H\e[2J");
            //displayStatistic();
            break;
        case 0:
            break;
        default:
            printf("Invalid choice, Try again !!!\n");
            break;
        }
    } while (choice != 0);


    return 0;
}
