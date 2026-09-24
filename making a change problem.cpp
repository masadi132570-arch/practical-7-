#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of coins needed
int minCoins(int coins[], int numCoins, int amount) {
    // dp[i] will store the minimum coins needed for amount i
    int dp[amount + 1];

    // Base case: 0 coins are needed to make an amount of 0
    dp[0] = 0;

    // Initialize all other DP elements to a placeholder value representing infinity
    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
    }

    // Compute minimum coins for all values from 1 to amount
    for (int i = 1; i <= amount; i++) {
        // Check every coin denomination
        for (int j = 0; j < numCoins; j++) {
            if (coins[j] <= i) {
                int sub_res = dp[i - coins[j]];
                // Check if a valid solution exists for the remaining amount
                if (sub_res != INT_MAX && sub_res + 1 < dp[i]) {
                    dp[i] = sub_res + 1;
                }
            }
        }
    }

    // If dp[amount] is still INT_MAX, it means the change cannot be made
    if (dp[amount] == INT_MAX) {
        return -1;
    }

    return dp[amount];
}

int main() {
    // Example 1: Standard case
    int coins1[] = {1, 5, 10, 25};
    int numCoins1 = sizeof(coins1) / sizeof(coins1[0]);
    int amount1 = 30;
    
    int result1 = minCoins(coins1, numCoins1, amount1);
    printf("Minimum coins required for amount %d: %d\n", amount1, result1);

    // Example 2: Case where exact change is impossible
    int coins2[] = {2, 5};
    int numCoins2 = sizeof(coins2) / sizeof(coins2[0]);
    int amount2 = 3;
    
    int result2 = minCoins(coins2, numCoins2, amount2);
    printf("Minimum coins required for amount %d: %d\n", amount2, result2);

    return 0;
}
