import math
def is_prime(num):
    i = int(1)
    a = int(0)
    while i < math.sqrt(num):
        i = i + 1
        if num%i == 0:
            return "false"
    return "true"


print(is_prime(37))
        
        
