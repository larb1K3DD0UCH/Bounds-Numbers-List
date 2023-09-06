# Bounds-Numbers-List
Bounds-Numbers List

The final application must meet the following functional requirements:
    1. User can create unlimited bound-numbers lists. Each list must associate with a unique bound value (i.e., two lists with same bound values are not allowed). See
    2. User can insert a new node in nested list. User inputs the bound value and then given two options to insert the node in the front or in the middle of the nested list.
    3. User can delete the front list from the nested list.
    4. User can delete an item (list) from nested list specified by the user. User inputs the bound value associated with the list to delete the item. If the list exists, then the user is prompted to enter the index of the item to delete. If the list does not exist an appropriate message is shown.
    5. User can merge two bound-numbers lists into a new list with maximum bound value from both lists and without duplicate numbers. For example, if we have “20” bound-numbers list with [5,10,20] and “30” bound-numbers list with [20,30], all integer numbers in both lists after removing duplicates should be merged into a new bound-numbers list so that this merged list will be “30” bound value with [5,10,20,30].
    6. User must be able to display the bound values of stored lists.
    7. User must be able to display the items (numbers) stored in a bound-numbers list specified by the user.
The bound-numbers list has the following functional requirements:
    1. Each node in the list stores an integer value that is entered by the user. The stored value is the integer number that is less than or equal the bound value associated with the list.
    2. There must be a way to insert an integer number in the list after specific node specified by the user, provided that this number is less than or equal to the bound value associated with that list. User inputs the bound value associated with the list to insert the number. If the list exists, then the user is prompted to enter the integer number for that specific node in order to insert the new number after it. If the list does not exist an appropriate message is shown.
    3. There must be a way to insert an integer number in the end of a list specified by the user, provided that this number is less than or equal to the bound value associated with that list.
    4. There must be a way to delete the last item in the list.
    5. There must be a way to delete all items in the list except a particular item.
    6. There must be a way to search the nested list for the list.
    7. There must be a way to print the numbers in the list specified by user in reverse order without reversing it. For example, if we have a bound-numbers list = [10,15,20], the output should be displayed as follows without reversing the list: 20,15,10.
