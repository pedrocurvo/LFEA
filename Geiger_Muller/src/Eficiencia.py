import sys 
import math

def contagens_corrigidas(N):
    return N / (1 - ((N/60) * 657*10**(-6)))

def alpha(phi,d):
    return math.atan(phi/(2*d))
def dalpha(phi,d,dd):
    return abs(phi * -1 / 2 / d ** 2 / (phi ** 2 * (1 / 2 / d) ** 2 + 1)) * dd

def omega(phi,d):
    return 2*math.pi*(1-math.cos(alpha(phi,d)))
def domega(phi,d,dd):
    return abs(2 * math.pi * math.sin(alpha(phi,d))) * dalpha(phi, d, dd)

def eficiency(phi,d):
    return omega(phi,d)/(2*math.pi)*100
def deficiency(phi,d,dd):
    return domega(phi,d,dd)/(2*math.pi)*100



if __name__ == '__main__':
    # Read the channels
    values = sys.argv
    values.pop(0)

    d = 1.25*2.54/100
    dd = 0.125*2.54/100

    phi1 = 7.5*10**(-3)
    alpha1 = alpha(phi1,d)
    dalpha1= dalpha(phi1, d, dd)
    omega1 = omega(phi1,d)
    domega1 = domega(phi1, d, dd)
    eficiencia1 = eficiency(phi1,d)
    deficiencia1 = deficiency(phi1,d,dd)

    phi2 = 10*10**(-3)
    alpha2 = alpha(phi2,d)
    dalpha2= dalpha(phi2, d, dd)
    omega2 = omega(phi2,d)
    domega2 = domega(phi2, d, dd)
    eficiencia2 = eficiency(phi2,d)
    deficiencia2 = deficiency(phi2,d,dd)
    #12.07
    r = 1.5875/100
    h = 8.89/100/2+3.175/100
    dh = 0.32/100
    alpha3 = alpha(r,h)
    dalpha3= dalpha(r, h, dh)
    omega3 = omega(r,h)
    domega3 = domega(r, h, dh)
    eficiencia3 = eficiency(r,h)
    deficiencia3 = deficiency(r,h,dh)

    print(f"phi = 7.5 mm: alpha = {alpha1:.3f} +- {dalpha1:.3f}, omega = {omega1:.3f} +- {domega1:.3f}, eficiencia = {eficiencia1:.3f} +- {deficiencia1:.3f}")
    print(f"phi = 10 mm: {alpha2:.3f} +- {dalpha2:.3f}, omega = {omega2:.3f} +- {domega2:.3f}, eficiencia = {eficiencia2:.3f} +- {deficiencia2:.3f}")
    print(f"gamas: {alpha3:.3f} +- {dalpha3:.3f}, omega = {omega3:.3f} +- {domega3:.3f}, eficiencia = {eficiencia3:.3f} +- {deficiencia3:.3f}")


    A = 0.03*37000
    dA = 0.01*37000
    Rv = 7.94
    dRv = 0.38
    Etotal = Rv/A*100
    dEtotal = (abs(1 / A) * dRv + abs(-(Rv / A ** 2)) * dA)*100

    print(f"E total = {Etotal} +- {dEtotal}")
    print(f"E int = {Etotal/eficiencia2*100} +- {(abs(1 / eficiencia2) * dEtotal + abs(-(Etotal / eficiencia2 ** 2)) * deficiencia2)*100}")