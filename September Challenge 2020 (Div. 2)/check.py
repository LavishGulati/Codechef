f = open('output.txt', 'r')
lines = f.readlines()
n = 1
for line in lines:
	line = line.strip()
	a = []
	for i in range(0, n):
		a.append(i+1)

	if (n*(n+1))%4 != 0:
		if int(line) != 0:
			print(n)
			break

	ans = 0
	for i in range(0, n):
		for j in range(i+1, n):
			temp = a[i]
			a[i] = a[j]
			a[j] = temp
			cum = 0
			for m in range(0, n):
				cum += a[m]
				if(cum == (n*(n+1))/2-cum):
					ans += 1
					break
			temp = a[i]
			a[i] = a[j]
			a[j] = temp

	if int(line) != ans:
		print(str(n)+": "+str(line)+", "+str(ans))
		break

	n += 1