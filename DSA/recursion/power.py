#!/usr/bin/python3

#power solution

def power(base:int, pow:int) -> int:
  if pow == 0 or pow < 1: # applying base case
    return 1
  return base * power(base, pow - 1)

print(power(2,0)) # 1
print(power(2,2)) # 4
print(power(2,4)) # 16
