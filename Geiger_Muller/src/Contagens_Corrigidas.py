import sys 
import math

def contagens_corrigidas(N):
    return N / (1 - ((N/60) * 657*10**(-6)))

if __name__ == '__main__':
    # Read the channels
    values = sys.argv
    values.pop(0)

    N = contagens_corrigidas(float(values[0]))
    dN = float(values[1])

    print(f"Contagens: {N:.3f} +- {abs(1 / (N * -219 / 2e+7 + 1) ** 2) * dN:.3f}")
    print(f"Taxa: {N/60:.3f} +- {abs(1 / (N * -219 / 2e+7 + 1) ** 2) * dN/60:.3f}")

