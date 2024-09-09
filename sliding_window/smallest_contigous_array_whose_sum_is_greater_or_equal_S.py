def smallest_contigous_array_whose_sum_is_greater_or_equal_S(arr, S):
    mini = 9999
    for i in range(len(arr)):
        sum = 0
        for j in range(i, len(arr)):
            sum += arr[j]
            
            if sum >= S:
                mini = min(mini, j-i+1)
                break

    return mini
    
def sliding_window_approach(arr, s):
    windowSum = 0
    minimumLength = float("inf")
    windowStart = 0
    
    for windowEnd in range(len(arr)):
        windowSum += arr[windowEnd]
        
        while windowSum >= s:  # Use a while loop to shrink the window
            minimumLength = min(minimumLength, windowEnd - windowStart + 1)
            windowSum -= arr[windowStart]
            windowStart += 1
    
    # If no valid subarray was found, return 0
    return minimumLength if minimumLength != float("inf") else 0

# Test case
arr = [3, 4, 1, 1, 6]
s = 8
print(sliding_window_approach(arr, s))
