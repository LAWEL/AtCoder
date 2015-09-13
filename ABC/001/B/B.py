m = int(input())
if m < 100:
    m = 0
elif m <= 5000:
    m = m / 100
elif m <= 30000:
    m = m / 1000 + 50
elif m <= 70000:
    m = (m / 1000 - 30) / 5 + 80
else:
    m = 89
print("{0:02.0f}".format(m))
