import sys 
import math

def cal(N, dN):
    return [0.001715 * N + 4.502, 2.319*10**(-5)*dN]

if __name__ == '__main__':
    # Read the channels
    values = sys.argv
    values.pop(0)

    [N, dN] = cal(float(values[0]), float(values[1]))

    print(f"Contagens: {N:.3f} +- {dN:.3f}")
    #print(f"Taxa: {N/60:.3f} +- {abs(1 / (N * -219 / 2e+7 + 1) ** 2) * dN/60:.3f}")

