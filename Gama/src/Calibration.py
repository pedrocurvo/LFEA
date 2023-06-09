import numpy as np
import matplotlib.pyplot as plt
import sys
import os
import pandas as pd
from scipy.optimize import curve_fit

def linear_fit(x: list, y: list):
    # Convert the lists to NumPy arrays
    x = np.array(x)
    y = np.array(y)
    
    # Perform linear regression
    slope, intercept = np.polyfit(x, y, 1)
    
    # Define the linear function
    def linear_func(x):
        #return slope * x + intercept
        return 1.562 * x - 15.04
    
    return linear_func

# Example usage
Energy = [32.2, 661.7, 1173.2, 1332.5] # Cs and Co energies
Channels = [28.8, 437.07, 760.24, 861.42] # Cs-137 and Co-60 channels

Channel_to_Energy = linear_fit(Channels, Energy)
Energy_to_Channel = linear_fit(Energy, Channels)

if __name__ == '__main__':
    # Read the channels
    values = sys.argv
    values.pop(0)
    channels = [Channel_to_Energy(float(value.replace(',', '.'))) for value in values]
    for number in channels:
        print(f"{number:.5f}", end = ' ')
