from Calibration import Channel_to_Energy
from Denoise import read_mca, write_to_file
import numpy as np
import matplotlib.pyplot as plt
import sys


def convert_to_energy(mca: np.ndarray, linear_func):
    """Converts the channels to energy"""
    new_mca = np.copy(mca)
    new_mca[:, 1] = mca[:, 1] 
    for row in new_mca:
        row[0] = round(linear_func(row[0]), 2)
    return new_mca



if __name__ == "__main__":
    name_of_file = sys.argv[1]
    write_file = name_of_file.replace('.dat', '_Energy.dat')
    
    mca_channels = read_mca(name_of_file)
    mca_energy = convert_to_energy(mca_channels, Channel_to_Energy)


    
    # Write to file
    write_to_file(write_file, mca_energy)

    if len(sys.argv) > 2 and sys.argv[2] == 'plot':
        plt.plot(mca_channels[:, 0], mca_channels[:, 1], label='Signal in Channels')
        plt.plot(mca_energy[:, 0], mca_channels[:, 1], label='Signal in Energy')
        plt.legend()
        plt.xlabel('Time')
        plt.ylabel('Amplitude')
        plt.show()