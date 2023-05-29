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
        return slope * x + intercept
    
    return linear_func

# Example usage
Energy = [9, 78]
Channels = [2, 4]

Channel_to_Energy = linear_fit(Channels, Energy)
Energy_to_Channel = linear_fit(Energy, Channels)

if __name__ == '__main__':
    # Read the channels
    values = sys.argv
    values.pop(0)
    channels = [Channel_to_Energy(float(value.replace(',', '.'))) for value in values]
    for number in channels:
        print(f"{number:.5f}", end = ' ')
