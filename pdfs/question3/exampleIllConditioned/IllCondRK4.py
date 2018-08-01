import matplotlib.pyplot as plt

# lambda functions
f = lambda t, x: 10*x + 11*t - 5 * t**2 - 1 # f(t, x) = x'
exactFunc = lambda t: t**2 / 2 - t

def main():
    x = 0.0 # x(0) == 0
    t = 0.0
    tMax = 3.0
    h = 2**(-8)

    tData = [t]
    xData = [x]
    exactData = [x]

    while (t < tMax):
        K1 = h*f(t, x)
        K2 = h*f(t + h/2, x + K1/2)
        K3 = h*f(t + h/2, x + K2/2)
        K4 = h*f(t + h, x + K3)

        x += (K1 + 2*K2 + 2*K3 + K4) / 6
        t += h
        tData.append(t)
        xData.append(x)
        exactData.append(exactFunc(t))

    plt.plot(tData, xData, 'b--')
    # plt.plot(tData, exactData, 'r-') # exact solution 
    plt.show()

# end main()

main()
