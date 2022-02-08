bitString1 = input('Ввести bit string 1: ')
if len(bitString1)>8:
  print('Некорректный ввод')
  exit()

for b in bitString1:
  if (b != '0') and (b != '1'):
    print('Некорректный ввод')
    exit()
s1=8-len(bitString1)
suffix = '0'*s1
bitString1 = suffix + bitString1

bitString2 = input('Ввести bit string 2: ')
if len(bitString2)>8:
  print('Некорректный ввод')
  exit()

for b in bitString2:
  if (b!='0') and (b != '1'):
    print('Некорректный ввод')
    exit()
s1=8-len(bitString2)
suffix = '0'*s1
bitString2 = suffix + bitString2

bitString3=''
i=0
while i<8:
  if bitString1[i]=='1' and bitString2[i]=='1':
    bitString3+='1'
  else:
    bitString3+='0'
  i+=1
print('Результат: ', bitString3)
