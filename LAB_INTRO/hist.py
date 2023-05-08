import matplotlib.pyplot as plt
import numpy as np

file1 = open('valoreshist_test_OneShot.txt', 'r')
Lines = file1.readlines()

sum = 0

x = [float(values) for values in Lines]
for values in Lines:
    sum += float(values)

print("Média = ")

plt.hist(x,bins = 20)
plt.show()