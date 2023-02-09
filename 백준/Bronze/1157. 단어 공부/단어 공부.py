inp = input().lower()
alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
alphabet_count = dict()

for a in alphabet:
  alphabet_count[a] = 0
for letter in inp:
  alphabet_count[letter] += 1
max_num = max(alphabet_count.values())
cnt = []
for letter in alphabet_count.keys():
  if alphabet_count[letter] == max_num:
    cnt.append(letter)
if len(cnt) >= 2:
  print('?')
else:
  print(cnt[0].upper())
  