def bitInput():
  
  bitString1 = input('Введите bit string:')

  if len(bitString1)>8:
    print('Некорректный ввод! ')
    exit()

  for b in bitString1:
    if b!='0' and b!='1':
      print('Некорректный ввод!')
      exit()

  s1=8-len(bitString1)
  suffix = '0'*s1
  bitString1 = suffix + bitString1
  return bitString1

def filebitInput(filename):
  try:
    file = open(filename, 'r')
  except:
    print("Невозможно открыть файл")
    exit()

  bitString1 = file.readline()

  if len(bitString1)>8:
    print('Некорректный ввод! ')
    exit()

  for b in bitString1:
    if b!='0' and b!='1':
      print('Некорректный ввод!')
      exit()

  s1=8-len(bitString1)
  suffix = '0'*s1
  bitString1 = suffix + bitString1
  return bitString1
  
def conjaction(bitString1, bitString2):

  result = ''
  i=0
  while (i<8):
    if bitString1[i]== '1' and bitString2[i]== '1':
      result+='1'
    else:
      result+='0'
    i+=1
  return result

def filebitOutput(filename, bitString):
  try:
    file = open(filename, 'w')
  except:
    print("Невозможно открыть файл")
    exit()
  file.write(bitString)
  file.close()

a = filebitInput("a.txt")
print("bit string 1:", a)
b = bitInput()
print("bit string 2:", b)
c = conjaction(a, b)
filebitOutput("c.txt", c)
print('Результат: ', c)
