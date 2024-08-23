# from math import gcd

def gcd(a, b):
    if a % b == 0:
        return b
    if a < b:
        return gcd(b, a)
    return gcd(a-b, b)

class Solution(object):
    def fractionAddition(self, expression):
        expression = expression.split("+")
        expression = [x.split("-") for x in expression]
        num = 0
        den = 1
        for x in expression:
            if x[0] != "":
                ab = x[0].split("/")
                a = int(ab[0])
                b = int(ab[1])
                (num, den) = (num*b + a*den, den*b)
            for i in range(1, len(x)):
                ab = x[i].split("/")
                a = int(ab[0])
                b = int(ab[1])
                (num, den) = (num*b - a*den, den*b)
            if(den < 0):
                num = -num
                den = -den
            g = gcd(abs(num), abs(den))
            (num, den) = (num/g, den/g)
        return str(num) + "/" + str(den)
        