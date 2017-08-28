if __name__ == '__main__':
    n = int(raw_input())

integers = [value**2 for value in range(0,n)]

for value in integers:
    print value