#include <stdio.h>
#include <stdlib.h>
struct Item {
    int profit;
    int weight;
    float ratio;
};

int compare(const void *a, const void *b) {
    float ra = ((struct Item*)a)->ratio;
    float rb = ((struct Item*)b)->ratio;
    return (ra < rb) ? 1 : (ra > rb) ? -1 : 0;
}
int main() {
    int n, capacity, i;
    float totalProfit = 0.0;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item *item = (struct Item*)malloc(n * sizeof(struct Item));
    if (item == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter profit and weight of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &item[i].profit, &item[i].weight);
        if (item[i].weight == 0) {
            printf("Warning: Item %d has zero weight. Skipping ratio calculation.\n", i+1);
            item[i].ratio = 0.0;
        } else {
            item[i].ratio = (float)item[i].profit / item[i].weight;
        }
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    qsort(item, n, sizeof(struct Item), compare);
    printf("\nItems selected (sorted by profit/weight ratio):\n");
    for (i = 0; i < n; i++) {
        if (capacity >= item[i].weight) {
            // Take full item
            printf("Item %d: profit %d, weight %d (full)\n", i+1, item[i].profit, item[i].weight);
            totalProfit += item[i].profit;
            capacity -= item[i].weight;
        } else if (capacity > 0) {
            // Take fraction of item
            float fraction = (float)capacity / item[i].weight;
            printf("Item %d: profit %d, weight %d (fraction %.2f)\n", i+1, item[i].profit, item[i].weight, fraction);
            totalProfit += item[i].profit * fraction;
            capacity = 0;
            break;
        }
    }
    printf("\nMaximum Profit = %.2f\n", totalProfit);
    free(item);  // Free allocated memory
    return 0;
}
