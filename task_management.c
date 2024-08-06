#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_ASSIGNEE_LENGTH 50
#define MAX_DUE_DATE_LENGTH 20

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char assignee[MAX_ASSIGNEE_LENGTH];
    char dueDate[MAX_DUE_DATE_LENGTH];
    int completed;
} Task;

Task tasks[MAX_TASKS];
int numTasks = 0;

void createTask() {
    if (numTasks >= MAX_TASKS) {
        printf("Maximum number of tasks reached!\n");
        return;
    }

    printf("Enter task title: ");
    getchar(); // Clear the newline character from the input buffer
    fgets(tasks[numTasks].title, sizeof(tasks[numTasks].title), stdin);
    tasks[numTasks].title[strcspn(tasks[numTasks].title, "\n")] = '\0'; // Remove the newline character

    printf("Enter assignee: ");
    fgets(tasks[numTasks].assignee, sizeof(tasks[numTasks].assignee), stdin);
    tasks[numTasks].assignee[strcspn(tasks[numTasks].assignee, "\n")] = '\0'; // Remove the newline character

    printf("Enter due date: ");
    fgets(tasks[numTasks].dueDate, sizeof(tasks[numTasks].dueDate), stdin);
    tasks[numTasks].dueDate[strcspn(tasks[numTasks].dueDate, "\n")] = '\0'; // Remove the newline character

    tasks[numTasks].completed = 0;
    numTasks++;
    printf("Task created successfully!\n");
}

void viewTasks() {
    printf("Task List:\n");
    printf("%-5s %-20s %-20s %-10s\n", "No.", "Title", "Assignee", "Status");
    printf("------------------------------------------------------\n");

    for (int i = 0; i < numTasks; i++) {
        printf("%-5d %-20s %-20s %-10s\n", i + 1, tasks[i].title, tasks[i].assignee,
               tasks[i].completed ? "Completed" : "Pending");
    }

    printf("------------------------------------------------------\n");
}

void markTaskComplete() {
    int taskNo;
    printf("Enter task number to mark as complete: ");
    scanf("%d", &taskNo);

    if (taskNo <= 0 || taskNo > numTasks) {
        printf("Invalid task number!\n");
        return;
    }

    tasks[taskNo - 1].completed = 1;
    printf("Task marked as complete!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nTask Management System\n");
        printf("1. Create Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task Complete\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskComplete();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try");
}
}
return 0;
}
