with open('input.txt', 'w') as f:
	f.write('250000\n')
	for i in range(0, 25000):
		f.write('8 8\n1 2 3 4 5 6 7 8\n1 2\n1 3\n2 4\n2 5\n3 7\n3 8\n5 6\n7 4 5 8 1 6 3 2\n')