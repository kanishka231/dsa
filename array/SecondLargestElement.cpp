class Solution {
  public:
    // Function returns the second largest element in the array
    int getSecondLargest(vector<int> &arr) {
        // Approach 1: Sorting
        // This approach sorts the array and then finds the second largest element.
        // Time Complexity: O(n log n) due to sorting.
        // Space Complexity: O(1) if we ignore the space used by the sorting algorithm.
        
        
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for(int i = n - 2; i >= 0; i--) {
            if(arr[i] != arr[n - 1]) {
                return arr[i]; // Return the first element that is not the largest
            }
        }
        return -1; // If no second largest element exists
        

        // Approach 2: Two-pass method
        // This approach finds the largest element in the first pass and then finds the second largest in the second pass.
        // Time Complexity: O(n) for two passes through the array.
        // Space Complexity: O(1) since we are using a constant amount of space.
        
        
        int n = arr.size();
        int largest = -1;
        for(int i = 0; i < n; i++) {
            if(arr[i] > largest) {
                largest = arr[i]; // Find the largest element
            }
        }
        int secondLargest = -1;
        for(int i = 0; i < n; i++) {
            if(arr[i] > secondLargest && arr[i] != largest) {
                secondLargest = arr[i]; // Find the second largest element
            }
        }
        return secondLargest; // Return the second largest element
        

        // Approach 3: Single-pass method
        // This approach finds both the largest and second largest elements in a single pass through the array.
        // Time Complexity: O(n) since we only traverse the array once.
        // Space Complexity: O(1) as we are using a constant amount of space.
        
        int n = arr.size();
        int largest = -1, secondLargest = -1;
        for(int i = 0; i < n; i++) {
            if(arr[i] > largest) {
                secondLargest = largest; // Update second largest before updating largest
                largest = arr[i]; // Update largest
            } else if(arr[i] > secondLargest && arr[i] != largest) {
                secondLargest = arr[i]; // Update second largest if current element is not equal to largest
            }
        }
        return secondLargest; // Return the second largest element
    }
};