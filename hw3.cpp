/*
Kevin Alvarez
CS 131
Hw #3
*/

#include <iostream>
#include <vector>

using namespace std;

/* Pesudo-Code
The maxWeight() function takes an array of weights weights[], the number of iteams n, and the weight
capacity of the container capacity. It uses a brute-force approach by iterating through all possible 
combinations of iteams using a bit mask. For each combinataion, it calulates the toal weight and checks 
if it is less than or equal to the capacity of the container. If it is, it compares it to the current maximum weigh
and then updates it if it greater. This function also now keeps track of the iteams that make the current maxiimum
weight. It does this by storing the indices of the current items in a vector 'current items'. If a new max is found, 
then 'max items' vextor is updated with the 'current items' vector. 

In the implimination code (int main), we define an array of weights for 20 items and a weight capacity of 100 lb. 
We then call the maxWeight()function with these parameters and print the result. 
*/



/*
The maxWeight() function takes an array of weights weights[], the number of items n, and the weight capacity of the container capacity. It uses a brute-force 
approach by iterating through all possible combinations of items using a bit mask. For each combination, it calculates the total weight and checks if it is less than 
or equal to the capacity of the container. If it is, it compares it to the current maximum weight and then updates it if it is's greater. This function also now keeps
track of the items that make the current maximum weight. It does this by storing the indices of the current items in a vector 'current items'. If a new max is found, then 'max items'
vector is updated with the 'current items' vector. 
*/



// function to calculate the maximum weight of the items that can fit in the container
int maxWeight(const vector<int>& weights, int capacity, vector<int>& max_items) {
    int n = weights.size();
    int max_weight = 0;
    int max_weightp = 1;
    

    // iterate through all possible combinations of items
    for (int i = 0; i < (1 << n); i++) {
        int current_weight = 0;
        vector<int> current_items;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                current_weight += weights[j];
                current_items.push_back(j);
            }
        }
        if (current_weight <= capacity && current_weight > max_weight) {
            max_weight = current_weight;
            max_items = current_items;
        }
    }

    return max_weight;
}

int main() {
    int n, capacity;
    vector<int> weights;
    vector<int> max_items;

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the weight capacity of the container: ";
    cin >> capacity;

    cout << "Enter the weights of the items:\n";
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        weights.push_back(w);
    }

    int result = maxWeight(weights, capacity, max_items);
    cout << "Maximum weight that can be stored in the container: " << result << " lb" << endl;

    cout << "Items that make the maximum weight: ";
    for (int i = 0; i < max_items.size(); i++) {
        cout << max_items[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}


/*
Output

Test 1:
Enter the number of items: 5
Enter the weight capacity of the container: 100
Enter the weights of the items:
1 2 3 4 5
Maximum weight that can be stored in the container: 15 lb
Items that make the maximum weight: 1 2 3 4 5 

Test 2:
Enter the number of items: 5
Enter the weight capacity of the container: 100
Enter the weights of the items:
90 10 80 10 50 
Maximum weight that can be stored in the container: 100 lb
Items that make the maximum weight: 1 2 

Test 3
Enter the number of items: 4
Enter the weight capacity of the container: 200
Enter the weights of the items:
100 90 20 40 
Maximum weight that can be stored in the container: 190 lb
Items that make the maximum weight: 1 2 



*/