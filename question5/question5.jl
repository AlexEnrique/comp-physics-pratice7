function main()
    # constantes
    Fd = [0.5, 1.2]
    OmegaD = 2/3
    q = .5
    theta0 = .2 # rad
    omega0 = 0.0 #rad/s
    g = 9.8 #m/s^2
    L = g
    dt = 0.04 # s
    t = 0.0 # tInicial
    tF = 15.0

    theta = theta0
    omega = omega0

    while (t < tF-dt)
        omega += (-(g/L)*sin(theta) -q*omega + Fd[2]*sin(OmegaD*t)) * dt
        theta += omega * dt
        t += dt
        @printf "%lf\t%lf\n" t theta
    end
end

main()
