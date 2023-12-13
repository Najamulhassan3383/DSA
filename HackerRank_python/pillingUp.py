
no_of_testcases = int(input())

while no_of_testcases:
    size = input()
    array = list(map(int, input().split()))
    length = len(array)
    last_index = length - 1
    first_index = 0
    prev_maxi = float('inf')
    for i in range (length):
        first_element = array[first_index]
        last_element = array[last_index]
        maxi = max(first_element, last_element)
        # print(maxi)
        if maxi > prev_maxi:
            # print(maxi, prev_maxi)
            print("No")
            break
        else:
            if maxi == first_element:
                first_index += 1
            else:
                last_index -= 1
            prev_maxi = maxi
    if maxi <= prev_maxi:
        print("Yes")
    no_of_testcases -= 1