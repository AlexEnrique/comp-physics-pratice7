function G(y, t, params) # y = [y1, y2]
    g = params[1]
    L = params[2]
    q = params[3]
    Fd = params[4]
    OmegaD = params[5]
    # questão de legibilidade apenas
    return [y[2], -(g/L)*sin(y[1]) - q*y[2] + Fd*sin(OmegaD*t)]
end

function main()
    Fd = .5
    OmegaD = 2/3
    q = .5
    g = 9.8
    L = g
    y = [.2, .0]
    dt = .04
    t = .0
    tF = 15.0
    params = [g, L, q, Fd, OmegaD] # apenas para tornar o código mais legível
    c = [[.0, .0], [.0, .0], [.0, .0], [.0, .0]] # inicialização dos c[i][j]

    while ((t+=dt) < tF)
        c[1] = dt * G(y, t, params)
        c[2] = dt * G(y + c[1]/2, t + dt/2, params)
        c[3] = dt * G(y + c[2]/2, t + dt/2, params)
        c[4] = dt * G(y + c[3], t + dt, params)
        y = y + (c[1] + 2*c[2] + 2*c[3] + c[4])/6
        @printf "%lf\t%lf\n" t y[2]
    end

end

main()
