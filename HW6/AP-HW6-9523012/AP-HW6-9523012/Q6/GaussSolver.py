import math

class GaussSolver:
    # constructor
    def __init__(self, a, b, function, n):
        self.__result = 0
        self.__a = a
        self.__b = b
        self.__func = function
        self.__n = n


    # legendre
    def Legendre(self, n , x):
        if n == 0:
            return 1
        elif n == 1:
            return x
        else:
            return ((2. * n - 1) * x * self.Legendre(n - 1, x) - (1.0 * n - 1) * self.Legendre(n - 2, x)) / ( n )

    # legendre derivatives
    def dLegendre(self, n, x):
        return (1.0 * n/(x**2-1))*(x*self.Legendre(n, x) - self.Legendre(n-1, x))

    # weights
    def Weight(self, n, x):
        return 2 / ((1 - x ** 2) * (self.dLegendre(n, x) ** 2))

    # legendre zeros
    def legendreZeroes(self, n, i):
        pi = 3.141592655
        xold1 = math.cos(pi * (i - 1/4) / (n + 1/2))
        iteration = 1
        xnew1 = xold1 - self.Legendre(n, xold1) / self.dLegendre(n, xold1)
        while (1 + math.fabs(xnew1 - xold1) > 1.0):
            xold1 = xnew1
            xnew1 = xold1 - self.Legendre(n, xold1) / self.dLegendre(n, xold1)
        return xnew1


    def exec(self):
        integral = 0
        for i in range(1, self.__n + 1):
            integral = integral + ( self.__func(self.legendreZeroes(self.__n, i)) * self.Weight(self.__n, self.legendreZeroes(self.__n, i)) )
        self.__result = ((self.__b - self.__a) / 2.) * integral

    def get_result(self):
        return self.__result