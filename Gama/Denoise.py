import numpy as np
import sys
import os
import pandas as pd
import matplotlib.pyplot as plt
from skimage.restoration import denoise_wavelet
import pywt

def madev(d, axis=None):
    """ Mean absolute deviation of a signal """
    return np.mean(np.absolute(d - np.mean(d, axis)), axis)


def moving_average(noisy_signal, window_size):
    '''Apply moving average to remove noise'''
    new_signal = np.copy(noisy_signal)
    new_signal[:, 1] =  np.convolve(noisy_signal[:, 1], np.ones(window_size)/window_size, mode='same')
    return new_signal

def wavelet_denoising(noisy_signal: np.ndarray):
    '''Apply wavelet denoising'''
    threshold = np.sqrt(2 * np.log(len(noisy_signal[:, 1])))  # Threshold calculation
    coefficients = pywt.wavedec(noisy_signal[:, 1], 'db4', level=5)  # Wavelet decomposition
    coefficients[1:] = (pywt.threshold(c, threshold) for c in coefficients[1:])  # Thresholding
    denoised_signal = pywt.waverec(coefficients, 'db4')  # Wavelet reconstruction
    new_signal = np.copy(noisy_signal)
    new_signal[:, 1] = denoised_signal
    return new_signal

def read_mca(filename):
    """Reads a MCA file and returns a numpy array of the data"""
    with open(filename, 'r') as f:
        data = f.readlines()
    data = data[5:1029]
    data = np.array([line.split() for line in data], dtype=int)
    data[:, 0] = np.char.replace(data[:, 0].astype(str), ',', '').astype(int)
    data[:, 1] = np.char.replace(data[:, 1].astype(str), ',', '').astype(int)
    data = np.delete(data, 2, axis=1)
    return data

def write_to_file(filename, array):
    """Creates a file with the given filename and writes the content to it."""
    with open(filename, 'w') as file:
        file.write('# Chn Amplitude' + '\n')
        for row in array:
            file.write(f'{str(row[0])} {str(row[1])}' + '\n')
        


if __name__ == "__main__":
    name_of_file = sys.argv[1]
    
    x_noisy = read_mca(name_of_file)
    write_file = name_of_file.replace('.dat', '_Smoothed.dat')

    # Apply moving average to remove noise
    smoothed_signal = moving_average(x_noisy, 10)
    smoothed_signal = wavelet_denoising(smoothed_signal)
    # Write to file
    write_to_file(write_file, smoothed_signal)

    if len(sys.argv) > 2 and sys.argv[2] == 'plot':
        plt.plot(x_noisy[:, 0], x_noisy[:, 1], label='Noisy Signal')
        plt.plot(x_noisy[:, 0], smoothed_signal[:, 1], label='Smoothed Signal')
        plt.legend()
        plt.xlabel('Time')
        plt.ylabel('Amplitude')
        plt.show()
