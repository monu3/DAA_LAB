#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A structure to represent a job
struct Job
{
    char id;      // Job ID
    int deadline; // Deadline of the job
    int profit;   // Profit if the job is completed
};

// Comparator function to sort jobs according to their profit in descending order
bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

// Function to find the maximum profit sequence of jobs
void jobSequencing(vector<Job> &jobs, int n)
{
    // Sort all jobs according to decreasing order of profit
    sort(jobs.begin(), jobs.end(), compare);

    vector<int> result(n, -1);   // To store the result (sequence of jobs)
    vector<bool> slot(n, false); // To keep track of free time slots

    // Iterate through all given jobs
    for (int i = 0; i < n; i++)
    {
        // Find a free slot for this job (starting from the last possible slot)
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--)
        {
            if (!slot[j])
            {
                result[j] = i;  // Assign this job to this slot
                slot[j] = true; // Mark this slot as occupied
                break;
            }
        }
    }

    // Print the result
    cout << "Job Sequence for maximum profit:\n";
    for (int i = 0; i < n; i++)
    {
        if (slot[i])
        {
            cout << jobs[result[i]].id << " ";
        }
    }
    cout << endl;
}

int main()
{
    // List of jobs (Job ID, Deadline, Profit)
    vector<Job> jobs = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    int n = jobs.size();

    jobSequencing(jobs, n);

    return 0;
}
