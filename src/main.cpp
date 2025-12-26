#include <bits/stdc++.h>
using namespace std;

// Represents a single task with a deadline and required execution time
struct Task {
    int deadline;
    int duration;
};

int main() {
    cout << "Constraint-Aware Task Scheduler" << endl;
    cout << "-------------------------------" << endl;

    int numberOfTasks;
    cout << "Enter number of tasks: ";
    cin >> numberOfTasks;

    vector<Task> tasks(numberOfTasks);

    cout << "Enter each task as: deadline duration" << endl;
    for (int i = 0; i < numberOfTasks; i++) {
        cin >> tasks[i].deadline >> tasks[i].duration;
    }

    // Sort tasks by increasing deadline
    sort(tasks.begin(), tasks.end(), [](const Task &a, const Task &b) {
        return a.deadline < b.deadline;
    });

    // Max-heap to keep track of durations of selected tasks
    priority_queue<int> selectedTaskDurations;
    int totalTime = 0;

    // Greedily select tasks while respecting deadlines
    for (const Task &task : tasks) {
        totalTime += task.duration;
        selectedTaskDurations.push(task.duration);

        // If total time exceeds current deadline,
        // remove the longest task to restore feasibility
        if (totalTime > task.deadline) {
            totalTime -= selectedTaskDurations.top();
            selectedTaskDurations.pop();
        }
    }

    cout << endl;
    cout << "Maximum tasks completed: "
         << selectedTaskDurations.size() << endl;

    return 0;
}