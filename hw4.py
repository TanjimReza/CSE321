class Witchcraft:
  def __init__(self,spell,difficulty,effect):
    self.spell=spell
    self.spell=self.spell.split(' ')
    self.name=self.spell[0]
    self.category=self.spell[1]
    self.difficulty=difficulty
    self.effect=effect
    self.list1=['Simple','Standard','Advanced']
    self.dic={}
    if self.difficulty not in self.list1:
      print('We do not have Modern difficulty level.')
      self.difficulty='Advanced'
      print('Default set to Advanced.')
  def usedBy(self,char):
    char=char.split('-')
    if char[0] not in self.dic:
      self.dic[char[0]]=int(char[1])
    else:
      self.dic[char[0]]+=int(char[1])
  def showData(self):
    if self.difficulty not in self.list1:
      print('We do not have Modern difficulty level.')
      self.difficulty='Advanced'
      print('Default set to Advanced.')
    print(f'Name:{self.name}')
    print(f'Category:{self.category}')
    print(f'Effect:{self.effect}')
    print(f'Difficulty:{self.difficulty}')
    print('Users:')
    if len(self.dic)==0:
      print('Not yet used')
    else:
      for k,v in self.dic.items():
        print(f'{k} used {v} times')
  def equals(self,name2):
    print(self.difficulty, name2.difficulty)
    if self.category!=name2.category:
      s=f'{self.category} cannot be compared with {name2.category}'
      return s
    else:
      if self.category==name2.category:
        if self.difficulty=='Simple' and name2.difficulty=='Simple':
          s=(f'Both are same')
          return s
        elif self.difficulty=='Standard' and name2.difficulty=='Standard':
          s=(f'Both are same')
          return s
        elif self.difficulty=='Advanced' and name2.difficulty=='Advanced':
          s=(f'Both are same')
          return s
        elif self.difficulty=='Simple' and name2.difficulty=='Standard':
          s=(f'{self.name} is less difficult than {name2.name}')
          return s
        elif self.difficulty=='Simple' and name2.difficulty=='Advanced':
          s=(f'{self.name} is less difficult than {name2.name}')
          return s
        elif self.difficulty=='Standard' and name2.diffculty=='Advanced':
          s=(f'{self.name} is less difficult than {name2.name}')
          return s
        elif self.difficulty=='Standard' and name2.difficulty=='Simple':
          s=(f'{self.name} is more difficult than {name2.name}')
          return s
        elif self.difficulty=='Advanced' and name2.name=='Simple':
          s=(f'{self.name} is more difficult than {name2.name}')
          return s
        elif self.difficulty=='Advanced' and name2.name=='Standard':
            s = (f'{self.name} is more difficult than {name2.name}')
            return s
        elif self.difficulty=='Standard' and name2.name=='Advanced':
            s = (f'{name2.name} is more difficult than {self.name}')
            return s
    
        elif self.difficulty=='Advanced' and name2.name=='Standard':
          s=(f'{self.name} is more difficult than {name2.name}')
          return s
        elif self.difficulty=='Advanced' and name2.difficulty=='Standard':
            s = (f'{self.name} is more difficult than {name2.name}')
            return s
polyjuice=Witchcraft('Polyjuice Potion','Advanced','Transformation')
polyjuice.usedBy('Harry-2')
polyjuice.usedBy('Ron-1')
polyjuice.usedBy('Hermione-3')
print(f'-------1---------')
polyjuice.showData()
print(f'-------2---------')
polyjuice.usedBy('Ron-2')
polyjuice.showData()
print(f'-------3---------')
levitation=Witchcraft('Levitation Charm','Standard','Elevation')
levitation.showData()
print('--------4---------')
levitation.usedBy('Snape-1')
levitation.usedBy('McGonagall-2')
print(f'-----------------')
levitation.showData()
print(f'-------5---------')
print(polyjuice.equals(levitation))
print(f'-------6---------')
fidelius=Witchcraft('Fidelius Charm','Modern','Information Concealment')
print(f'-------7---------')
fidelius.showData()
print(f'-------8---------')
print(fidelius.equals(levitation))
amortentia=Witchcraft('Amortentia Potion','Simple','Infatuation')
print(amortentia.equals(polyjuice))
alohomora=Witchcraft('Alohomora Charm','Standard','Unlock')
witchcraft_list=[]
witchcraft_list.append(polyjuice)
witchcraft_list.append(levitation)
witchcraft_list.append(fidelius)
witchcraft_list.append(amortentia)
witchcraft_list.append(alohomora)