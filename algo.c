//made by R00Tshahed

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Searching Algorithms

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Binary Search (requires sorted array)
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Sorting Algorithms

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Dynamic Programming Problems

// Longest Common Subsequence (LCS)
int lcs(char* X, char* Y, int m, int n) {
    int dp[m+1][n+1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
        }
    }
    return dp[m][n];
}

// Longest Decreasing Subsequence (LDS)
int lds(int arr[], int n) {
    int dp[n];
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] < arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int max = 1;
    for (int i = 0; i < n; i++) {
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    return max;
}

// Longest Increasing Subsequence (LIS)
int lis(int arr[], int n) {
    int dp[n];
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int max = 1;
    for (int i = 0; i < n; i++) {
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    return max;
}

// Coin Change Problem
int coinChange(int coins[], int m, int V) {
    int dp[V+1];
    for (int i = 0; i <= V; i++) {
        dp[i] = V + 1; // Initialize with an impossible large value
    }
    dp[0] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = coins[i-1]; j <= V; j++) {
            if (dp[j - coins[i-1]] + 1 < dp[j]) {
                dp[j] = dp[j - coins[i-1]] + 1;
            }
        }
    }

    return dp[V] > V ? -1 : dp[V];
}

// Main Menu
void printMenu() {
    printf("\n==================== Algorithm Project ====================\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("3. Sorting Algorithms\n");
    printf("4. Longest Common Subsequence (LCS)\n");
    printf("5. Longest Decreasing Subsequence (LDS)\n");
    printf("6. Longest Increasing Subsequence (LIS)\n");
    printf("7. Coin Change Problem\n");
    printf("8. Exit\n");
    printf("============================================================\n");
    printf("Enter your choice: ");
}

void inputArray(int arr[], int *n) {
    printf("Enter the number of elements in the array: ");
    scanf("%d", n);
    printf("Enter the elements: ");
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Clear screen based on system
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    int choice, key, value, n;
    int arr[100];

    while (1) {
        clearScreen();  // Clear the screen before showing the menu
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(arr, &n);
                printf("Enter element to search: ");
                scanf("%d", &key);
                printf("Linear Search Result: %d\n", linearSearch(arr, n, key));
                break;
            case 2:
                inputArray(arr, &n);
                printf("Enter element to search: ");
                scanf("%d", &key);
                bubbleSort(arr, n);  // Binary search requires sorted array
                printf("Binary Search Result: %d\n", binarySearch(arr, 0, n-1, key));
                break;
            case 3:
                inputArray(arr, &n);
                printf("\n--- Sorting Algorithms ---\n");
                printf("1. Bubble Sort\n");
                printf("2. Selection Sort\n");
                printf("3. Insertion Sort\n");
                printf("4. Merge Sort\n");
                printf("5. Quick Sort\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                switch (choice) {
                    case 1: bubbleSort(arr, n); break;
                    case 2: selectionSort(arr, n); break;
                    case 3: insertionSort(arr, n); break;
                    case 4: mergeSort(arr, 0, n-1); break;
                    case 5: quickSort(arr, 0, n-1); break;
                    default: printf("Invalid choice\n"); continue;
                }
                printf("Sorted Array: ");
                for (int i = 0; i < n; i++) printf("%d ", arr[i]);
                printf("\n");
                break;
            case 4:
                printf("Enter two strings (X and Y) for LCS: ");
                char X[100], Y[100];
                scanf("%s %s", X, Y);
                printf("Longest Common Subsequence: %d\n", lcs(X, Y, strlen(X), strlen(Y)));
                break;
            case 5:
                inputArray(arr, &n);
                printf("Longest Decreasing Subsequence: %d\n", lds(arr, n));
                break;
            case 6:
                inputArray(arr, &n);
                printf("Longest Increasing Subsequence: %d\n", lis(arr, n));
                break;
            case 7:
                printf("Enter value to make change: ");
                scanf("%d", &value);
                int coins[] = {1, 2, 3};
                int m = sizeof(coins) / sizeof(coins[0]);
                printf("Coin Change Minimum Coins: %d\n", coinChange(coins, m, value));
                break;
            case 8:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }

        printf("\nPress Enter to continue...\n");
        getchar(); // To wait for user input before continuing
        getchar(); // To consume the newline character
    }

    return 0;
}
