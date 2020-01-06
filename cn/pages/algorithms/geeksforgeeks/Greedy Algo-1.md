# Activity Selection Problem | Greedy Algo-1
Greedy is an algorithmic paradigm that builds up a solution piece by piece, always choosing the next piece that offers the most obvious and immediate benefit. Greedy algorithms are used for optimization problems. An optimization problem can be solved using Greedy if the problem has the following property: At every step, we can make a choice that looks best at the moment, and we get the optimal solution of the complete problem.
If a Greedy Algorithm can solve a problem, then it generally becomes the best method to solve that problem as the Greedy algorithms are in general more efficient than other techniques like Dynamic Programming. But Greedy algorithms cannot always be applied. For example, Fractional Knapsack problem (See this) can be solved using Greedy, but 0-1 Knapsack cannot be solved using Greedy.

Following are some standard algorithms that are Greedy algorithms.
1) Kruskal’s Minimum Spanning Tree (MST): In Kruskal’s algorithm, we create a MST by picking edges one by one. The Greedy Choice is to pick the smallest weight edge that doesn’t cause a cycle in the MST constructed so far.
2) Prim’s Minimum Spanning Tree: In Prim’s algorithm also, we create a MST by picking edges one by one. We maintain two sets: a set of the vertices already included in MST and the set of the vertices not yet included. The Greedy Choice is to pick the smallest weight edge that connects the two sets.
3) Dijkstra’s Shortest Path: The Dijkstra’s algorithm is very similar to Prim’s algorithm. The shortest path tree is built up, edge by edge. We maintain two sets: a set of the vertices already included in the tree and the set of the vertices not yet included. The Greedy Choice is to pick the edge that connects the two sets and is on the smallest weight path from source to the set that contains not yet included vertices.
4) Huffman Coding: Huffman Coding is a loss-less compression technique. It assigns variable-length bit codes to different characters. The Greedy Choice is to assign least bit length code to the most frequent character.

The greedy algorithms are sometimes also used to get an approximation for Hard optimization problems. For example, Traveling Salesman Problem is a NP-Hard problem. A Greedy choice for this problem is to pick the nearest unvisited city from the current city at every step. This solutions don’t always produce the best optimal solution but can be used to get an approximately optimal solution.

Let us consider the [Activity Selection problem](http://en.wikipedia.org/wiki/Activity_selection_problem) as our first example of Greedy algorithms. Following is the problem statement.
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Example:
```
Example 1 : Consider the following 3 activities sorted by
by finish time.
     start[]  =  {10, 12, 20};
     finish[] =  {20, 25, 30};
A person can perform at most two activities. The 
maximum set of activities that can be executed 
is {0, 2} [ These are indexes in start[] and 
finish[] ]

Example 2 : Consider the following 6 activities 
sorted by by finish time.
     start[]  =  {1, 3, 0, 5, 8, 5};
     finish[] =  {2, 4, 6, 7, 9, 9};
A person can perform at most four activities. The 
maximum set of activities that can be executed 
is {0, 1, 3, 4} [ These are indexes in start[] and 
finish[] ]
```
The greedy choice is to always pick the next activity whose finish time is least among the remaining activities and the start time is more than or equal to the finish time of previously selected activity. We can sort the activities according to their finishing time so that we always consider the next activity as minimum finishing time activity.

1) Sort the activities according to their finishing time
2) Select the first activity from the sorted array and print it.
3) Do following for remaining activities in the sorted array.
…….a) If the start time of this activity is greater than or equal to the finish time of previously selected activity then select this activity and print it.

In the following C implementation, it is assumed that the activities are already sorted according to their finish time.
```c++
// C++ program for activity selection problem. 
// The following implementation assumes that the activities 
// are already sorted according to their finish time 
#include<stdio.h> 
  
// Prints a maximum set of activities that can be done by a single 
// person, one at a time. 
//  n   -->  Total number of activities 
//  s[] -->  An array that contains start time of all activities 
//  f[] -->  An array that contains finish time of all activities 
void printMaxActivities(int s[], int f[], int n) 
{ 
    int i, j; 
  
    printf ("Following activities are selected n"); 
  
    // The first activity always gets selected 
    i = 0; 
    printf("%d ", i); 
  
    // Consider rest of the activities 
    for (j = 1; j < n; j++) 
    { 
      // If this activity has start time greater than or 
      // equal to the finish time of previously selected 
      // activity, then select it 
      if (s[j] >= f[i]) 
      { 
          printf ("%d ", j); 
          i = j; 
      } 
    } 
} 
  
// driver program to test above function 
int main() 
{ 
    int s[] =  {1, 3, 0, 5, 8, 5}; 
    int f[] =  {2, 4, 6, 7, 9, 9}; 
    int n = sizeof(s)/sizeof(s[0]); 
    printMaxActivities(s, f, n); 
    return 0; 
} 
```
Output:
```
Following activities are selected
0 1 3 4
```
How does Greedy Choice work for Activities sorted according to finish time?
Let the given set of activities be S = {1, 2, 3, ..n} and activities be sorted by finish time. The greedy choice is to always pick activity 1. How come the activity 1 always provides one of the optimal solutions. We can prove it by showing that if there is another solution B with the first activity other than 1, then there is also a solution A of the same size with activity 1 as the first activity. Let the first activity selected by B be k, then there always exist A = {B – {k}} U {1}.(Note that the activities in B are independent and k has smallest finishing time among all. Since k is not 1, finish(k) >= finish(1)).

How to implement when given activities are not sorted?
We create a structure/class for activities. We sort all activities by finish time (Refer sort in C++ STL). Once we have activities sorted, we apply same above algorithm.

Below image is an illustration of the above approach:
![](/ActivitySelectionProblem.png)
Below is the implementation of the above approach:
```c++
// C++ program for activity selection problem 
// when input activities may not be sorted. 
#include <bits/stdc++.h> 
using namespace std; 
  
// A job has a start time, finish time and profit. 
struct Activitiy 
{ 
    int start, finish; 
}; 
  
// A utility function that is used for sorting 
// activities according to finish time 
bool activityCompare(Activitiy s1, Activitiy s2) 
{ 
    return (s1.finish < s2.finish); 
} 
  
// Returns count of the maximum set of activities that can 
// be done by a single person, one at a time. 
void printMaxActivities(Activitiy arr[], int n) 
{ 
    // Sort jobs according to finish time 
    sort(arr, arr+n, activityCompare); 
  
    cout << "Following activities are selected n"; 
  
    // The first activity always gets selected 
    int i = 0; 
    cout << "(" << arr[i].start << ", " << arr[i].finish << "), "; 
  
    // Consider rest of the activities 
    for (int j = 1; j < n; j++) 
    { 
      // If this activity has start time greater than or 
      // equal to the finish time of previously selected 
      // activity, then select it 
      if (arr[j].start >= arr[i].finish) 
      { 
          cout << "(" << arr[j].start << ", "
              << arr[j].finish << "), "; 
          i = j; 
      } 
    } 
} 
  
// Driver program 
int main() 
{ 
    Activitiy arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, 
                                       {5, 7}, {8, 9}}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printMaxActivities(arr, n); 
    return 0; 
} 
```
Output:
```
Following activities are selected 
(1, 2), (3, 4), (5, 7), (8, 9), 
```
Time Complexity : It takes O(n log n) time if input activities may not be sorted. It takes O(n) time when it is given that input activities are always sorted.

Using STL we can solve it as follows:
```c++
// C++ program for activity selection problem 
// when input activities may not be sorted. 
#include <bits/stdc++.h> 
using namespace std; 
  
void SelectActivities(vector<int>s,vector<int>f){ 
// Vector to store results. 
    vector<pair<int,int>>ans; 
  
// Minimum Priority Queue to sort activities in ascending order of finishing time (f[i]). 
  
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p; 
  
    for(int i=0;i<s.size();i++){ 
        // Pushing elements in priority queue where the key is f[i] 
        p.push(make_pair(f[i],s[i])); 
    } 
  
    auto it = p.top(); 
    int start = it.second; 
    int end = it.first; 
    p.pop(); 
    ans.push_back(make_pair(start,end)); 
  
    while(!p.empty()){ 
        auto itr = p.top(); 
        p.pop(); 
        if(itr.second >= end){ 
            start = itr.second; 
            end = itr.first; 
            ans.push_back(make_pair(start,end)); 
        } 
    } 
    cout << "Following Activities should be selected. " << endl << endl; 
  
    for(auto itr=ans.begin();itr!=ans.end();itr++){ 
        cout << "Activity started at: " << (*itr).first << " and ends at  " << (*itr).second << endl; 
    } 
} 
  
// Driver program 
int main() 
{ 
    vector<int>s = {1, 3, 0, 5, 8, 5}; 
    vector<int>f = {2, 4, 6, 7, 9, 9}; 
    SelectActivities(s,f); 
  
    return 0; 
} 
```
