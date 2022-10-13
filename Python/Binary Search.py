elements = [int(item) for item in input("Enter the list items, separated with space \n>>> ").split()]
elements.sort()
target = int(input("Set the number to search \n>>>  "))

def BinarySearch(min_index,max_index):
    if min_index +1 == max_index:
        print(f"{target} isn't exist on the List")
        exit()
    else:
        guess_index=(max_index+min_index)//2

        if elements[guess_index]==target:
            print(f"{target} found at index {guess_index}")
            exit()

        if elements[guess_index]<target:
            min_index=guess_index
            BinarySearch(guess_index,max_index)

        elif elements[guess_index]>target:
            max_index=guess_index
            BinarySearch(min_index,guess_index)

BinarySearch(0,len(elements))
