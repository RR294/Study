
def find_max_numbers(arr, max_count):
    lst_size = len(arr)

    for max_ind in range(max_count):
        for ind in range(0, lst_size - 1 - max_ind):
            if arr[ind] > arr[ind + 1]:
                tmp = arr[ind]
                arr[ind] = arr[ind + 1]
                arr[ind + 1] = tmp

    return arr

main_arr = [1, 23, 12, 9, 30, 2, 50]
max_count = 2
main_arr = find_max_numbers(main_arr, max_count)
size = len(main_arr)
print(main_arr[size - max_count - 1 : ])