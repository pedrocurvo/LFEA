import sys 
import math

def contagens_corrigidas(N):
    return N / (1 - ((N/60) * 657*10**(-6)))

if __name__ == '__main__':
    # Read the channels
    values = sys.argv
    values.pop(0)
    channels = [contagens_corrigidas(float(value)) for value in values]
    for number in channels:
        print(f"{number:.0f}", end = ' ')
    for number in channels:
        print(math.sqrt(number), end = ' ')

