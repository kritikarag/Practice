#include<bits/stdc++.h>
using namespace std;

int transfer(int jug1, int jug2, int req)
{ 
    //Initialize the starting state of the jugs and the water 
    int from = jug1;
    int to = 0;
    //Initialize a variable step to keep the track of steps needed to fill the jug
    int step = 1;  

    // Run a loop until either of the jug is filled with required litres of water
    while (from != req && to != req)
    {   
        //Firstly find the max amount of water that can be transfered from jug1 to jug2 
        int temp = min(from, jug2 - to);

        //Transfer that amount of water from jug1 to jug2
        to += temp;
        from -= temp;

        //Increament the number of steps
        step++;

        //If either of the jug contains the required amount of water then break the loop
        if (from == req || to == req)
            break;
        
        //If jug 1 becomes empty then fill it
        if (from == 0)
        {
            from = jug1;
            step++;
        }

        // If jug2 becomes empty then fill it
        if (to == jug2)
        {
            to = 0;
            step++;
        }
    }
    return step;
} 

// Return the counts of min steps required to measure the req litres of water
int reqSteps(int m, int n, int req)
{ 
    if (m > n)
        swap(m, n);
    
    //Measuring the req litres of water is impossible in this case
    if (req > n)
        return -1;
    
    // If the gcd of both the capacity of jug is not a multiple of the req capacity of water
    //then also measuring is impossible
    if ((req % __gcd(n, m)) != 0)
        return -1;

    // Here we will consider two cases:
    // a. Transfering water from jug1 to jug2 only
    // b. Transfering water from jug2 to jug1 only
    // Lastly will return the minimum steps involved from the above two cases:
    return min(transfer(n, m, req),  // n to m
               transfer(m, n, req)); // m to n
}
 
int main()
{
    int n,m,req;
    //Take the user input for the capacity of Jug 1
    cout<<"Enter the capacity of Jug 1 : ";
    cin>>n;
    cout<<endl;

    //Take the user input for the capacity of Jug 1
    cout<<"Enter the capacity of Jug 2 : ";
    cin>>m;
    cout<<endl;

    // Take the user input for the capacity of water needed to be measured
    cout<<"Enter the capacity of water you want to measure : ";
    cin>>req;
    cout<<endl;

    //Print the final Results
    cout<<"Minimum number of steps required to measure the water : "<<reqSteps(m, n, req)<<endl;

    return 0;
}
