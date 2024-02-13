#include <stdio.h>

#define MAX_ITEMS 5
#define MAX_WEIGHT 20

// Function to solve the Boolean Knapsack problem
int knapSack(int weights[], int values[], int selected_bool[]) {
    int dp[MAX_ITEMS + 1][MAX_WEIGHT + 1] = {0}; //Dynamic programing table for calculations

    //Updating the table
    for (int i = 0; i <= MAX_ITEMS; i++) {
        for (int w = 0; w <= MAX_WEIGHT; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                if (values[i - 1] + dp[i - 1][w - weights[i - 1]] > dp[i - 1][w]) {
                    dp[i][w] = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }
    }
    
    //Updating selected_bool
    int w = MAX_WEIGHT;
    for (int i = MAX_ITEMS; i > 0 && w > 0; i--) {
        if (i - 1 >= 0 && w - weights[i - 1] >= 0 && dp[i][w] != dp[i - 1][w]) {
            selected_bool[i - 1] = 1;
            w -= weights[i - 1];
        } else {
            selected_bool[i - 1] = 0;
        }
    }

    //Max value within MAX_WEIGHT limit
    return dp[MAX_ITEMS][MAX_WEIGHT];
}

int main() {
    char items[MAX_ITEMS];
    int values[MAX_ITEMS];
    int weights[MAX_ITEMS];

    // Read inputs in triples
    for (int i = 0; i < MAX_ITEMS; i++) {
        scanf("%c %d %d", &items[i], &values[i], &weights[i]);
    }

    int selected_bool[MAX_ITEMS];
    int max_profit = knapSack(weights, values, selected_bool);

    printf("Selected items (Boolean representation): ");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%d ", selected_bool[i]);
    }
    printf("\n");

    // Create and fill result array
    char result[MAX_ITEMS];
    int result_index = 0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (selected_bool[i]==1) {
            result[result_index] = items[i];
            result_index++;
        }
    }
    
    // Print maximum profit
    printf("Maximum profit: %d\n", max_profit);
    
    // Print selected items
    printf("Selected items: ");
    for (int i = 0; i < result_index; i++) {
        printf("%c ", result[i]);
    }

    printf("\n");

    return 0;
}
