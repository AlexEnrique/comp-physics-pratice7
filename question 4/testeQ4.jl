function main()
    # constantes
    Fd = 0.0
    OmegaD = 0.0
    q = [0.0, 0.15625, 12.5]
    theta0 = .2 # rad
    omega0 = 0.0 #rad/s
    L = 1 #m
    g = 9.8 #m/s^2
    dt = 0.04 # s
    t = 0.0 # tInicial
    tF = 10.0

    theta = theta0
    omega = omega0

    while (t < tF-dt)
        omega += (-(g/L)*sin(theta) -q[3]*omega + Fd*sin(OmegaD*t)) * dt
        theta += omega * dt
        t += dt
        @printf "%lf\t%lf\n" t theta
    end
end

main()
