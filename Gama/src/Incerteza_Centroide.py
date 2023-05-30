from math import sqrt

def incerteza(fwhm, roi_net):
    return fwhm / (2.355 * sqrt(roi_net))

if __name__ == '__main__':
    fwhm = float(input("FWHM: "))
    roi_net = float(input("ROI Net: "))
    print(f"Incerteza: {incerteza(fwhm, roi_net)}")
