line = input().split()
hour = int(line[0])
minute = int(line[1])
minute -= 45
if(minute < 0):
  hour -= 1
  minute += 60
if(hour < 0):
  hour += 24
print(hour, minute, sep=' ')