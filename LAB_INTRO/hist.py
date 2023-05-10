import matplotlib.pyplot as plt
import numpy as np
from math import sqrt

file1 = open('valoreshist_test_OneShot.txt', 'r')
Lines = file1.readlines()

sum = 0
cardinal = 0

x = [float(values) for values in Lines]
for values in Lines:
    sum += float(values)
    cardinal += 1
    
media = sum/cardinal
desvio_padrao = sqrt(media)
print("Média = ", media)
print("Desvio Padrão =", desvio_padrao)

plt.hist(x,bins = 20)
plt.show()