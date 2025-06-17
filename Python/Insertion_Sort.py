# Insertion sort program in Python:

# Example list:
l = [0,4,2,5,6,4,73,7,33,56,37,14]

# List must have more than 1 element in order to not be sorted:
if len(l) > 1:
  
  # We iterate the list:
  for i in range(1, len(l)):
    
      # We set current element as the "key":
      k = l[i]
      j = i-1
    
      # We will move all the elements which are greater than the current one 1 position front:
      while j >= 0 and k < l[j]:

          # Shifting greater elements to front (right):
          l[j+1] = l[j]
          j -= 1

      # Inserting key after positions have shifted right:
      l[j+1] = k
