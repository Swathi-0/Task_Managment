#!/bin/bash

MAX_TASKS=100
tasks=()
completed=()

function createTask() {
    if [ ${#tasks[@]} -ge $MAX_TASKS ]; then
        echo "Maximum number of tasks reached!"
        return
    fi

    echo "Enter task title: "
    read -r title

    echo "Enter assignee: "
    read -r assignee

    echo "Enter due date: "
    read -r dueDate

    tasks+=("$title|$assignee|$dueDate")
    completed+=(0)
    echo "Task created successfully!"
}

function viewTasks() {
    echo "Task List:"
    printf "%-5s %-20s %-20s %-10s\n" "No." "Title" "Assignee" "Status"
    echo "------------------------------------------------------"

    for i in "${!tasks[@]}"; do
        IFS='|' read -r title assignee dueDate <<< "${tasks[i]}"
        status="Pending"
        if [ ${completed[i]} -eq 1 ]; then
            status="Completed"
        fi
        printf "%-5d %-20s %-20s %-10s\n" $((i + 1)) "$title" "$assignee" "$status"
    done

    echo "------------------------------------------------------"
}

function markTaskComplete() {
    echo "Enter task number to mark as complete: "
    read -r taskNo

    if [ "$taskNo" -le 0 ] || [ "$taskNo" -gt ${#tasks[@]} ]; then
        echo "Invalid task number!"
        return
    fi

    completed[$((taskNo - 1))]=1
    echo "Task marked as complete!"
}

while true; do
    echo ""
    echo "Task Management System"
    echo "1. Create Task"
    echo "2. View Tasks"
    echo "3. Mark Task Complete"
    echo "4. Exit"
    echo "Enter your choice: "
    read -r choice

    case $choice in
        1)
            createTask
            ;;
        2)
            viewTasks
            ;;
        3)
            markTaskComplete
            ;;
        4)
            echo "Exiting..."
            exit 0
            ;;
        *)
            echo "Invalid choice! Please try again."
            ;;
    esac
done
