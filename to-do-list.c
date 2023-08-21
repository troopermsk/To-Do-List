#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

//implementing the struct concept here for the to-do-list
typedef struct ToDo {
    char entry_str[200];
    int count_nodes;
    char time_str[50];
    //this helps us keep the time in check too
    //simple array implementation

} todo;
todo todo_main[200];
todo private_todo[200];
//as such, we can have the global variable of the todo set to null

void displaySplashScreen();
void beepsound();
void addToDOEntry(int *i);
void deleteToDoEntry(int *i);
//Global variables
static int maintodo_count = 0;
static int private_count = 0;
int check_splash = 0;
int pass_check = 1;
char password[6];

int main() {
    int a;
    //if condition to see if the screen is just opened
    if(check_splash ==0) {
        displaySplashScreen();

    }
    check_splash = 0;
    while(1) {
        system("Color 4E");
        system("cls");
        printf("Hello there! Welcome to the ToDo List");
        printf("You may choose from one of the following operations");
        printf("1. Add a ToDo entry\n 2. Delete a ToDo entry\n 3. Update a ToDo\n 4. View your ToDo List\n 5. Go Private\n 6. Exit the ToDo App\n ");
        scanf("%d", a);
        //we store the user entry and then proceed accordingly
        beepsound();
        switch (a)
        {
        case 1:
            //This will add a simple entry into the list which we have passed.
            addToDOEntry(& maintodo_count);
            break;
        case 2:
            //call the delete function
            deleteToDoEntry(&maintodo_count);
            break;
        default:
            printf("Invalid input! Please enter a number from one of the six options listed above. \n");
            getch();
        }

    }

}

void displaySplashScreen(){
    //implementation of a simple splash screen to greet the new user
    //configured so that the screen is paused until the user presses
    // any key and wishes to proceed or otherwise
    system("Color 6A");
    printf("\n");
    printf("\t-------------------------------------------------------\n");
    printf("\t-------------------------------------------------------\n\n");
    printf("\t * - * - * - * - * - * - * - * - * - * - * - * "
            "Welcome to To-DO listings Inc"
            "* - * - * - * - * - * - * - * - * - * - * - * \n\n");
    printf("\t-------------------------------------------------------\n");
    printf("\t-------------------------------------------------------\n\n");
    printf("\n\n\n\n\t\t\t\t\t "
            "@troopermsk\n"
            "M.Shaheer Malik");
    system("pause");
    
}

void beepsound() {
    Beep(800, 200);
}


void addToDOEntry(int *i) {
    //simple entry protocol to add an entry in the index provided since we're keeping count
    char entry[200];
    system("cls");
    if(check_splash==1) {
        //we're in the private mode
        system("Color 0F");
        pass_check = 1;
        printf("Please enter the ToDo you'd like to add: \n");
        fflush(stdin);
        gets(entry);
        beepsound();
        //Now that we have the entry, we can add it to the array
        strcpy(private_todo[*i].entry_str, entry);

        time_t t;
        //the above is the type we use to store time
        time(&t);
        //now we can add the time to the array we have defined as well. 
        strcpy(private_todo[*i].time_str, ctime(&t));
        //and we can increment the counter inside of the struct as well
        private_todo[*i].count_nodes = (*i) + 1;
        (*i)++;
    }
    else {
        //we're not in the private mode
        system("Color 31");
        printf("Please enter the ToDo you'd like to add: \n");
        fflush(stdin);
        gets(entry);
        beepsound();
        //we have the entry now, and we can add it to the main todoarray
        strcpy(todo_main[*i].entry_str, entry);
        //now we can repeat the time procedure
        time_t t;
        time(&t);
        strcpy(todo_main[*i].time_str, ctime(&t));
        todo_main[*i].count_nodes = (*i)+1;
        (*i)++;

    }
    printf("Operation done successfully! Press any key to go back to main menu \n");
        getch();
}
