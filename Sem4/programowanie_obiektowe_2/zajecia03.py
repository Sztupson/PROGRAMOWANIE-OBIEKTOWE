### Program dzialajacy na wierszach tekstu

''' 
class TextLines:
    def readLine(numer wiersza)                     -> wiersz o zadanym numerze
    def writeLine(line)                             -> dodanie wiersza na końcu
    def writeLine(numer wiersza, line)              -> dodanie wiersza w konkretnej pozycji

    -> nie pozwalamy na dodanie wiersza "z przerwą": jak mamy 1, 2, 3 to nie można dodać 5.
    -> gdy wiersz istnieje to zostaje nadpisany

    def deleteLine(numer wiersza)                   -> usunięcie wiersza

    
class IdentifiedTextLines: TextLines                -> (identyfikatory nie muszą być unikalne; pełnią rolę tagów, etykiet)
    readLine(identyfikator)                         -> wiersz(e) posiadające zadany identyfikator
    writeLine(identyfikator, line)                  -> dodanie wiersza na końcu z identyfikatorem
    writeLine(identyfikator, identyfikator, line)   -> dodanie wiersza w konkretnej pozycji z identyfikatorem
    deleteLine(identyfikator)                       -> usunięcie wiersza
    

### 4 koncepcje:
class UniquelyIdentifiedTextLines: TextLines
class UniquelyIdentifiedTextLines: IdentifiedTextLines
class UniquelyIdentifiedTextLines:
    container: IdentifiedTextLines

### Klasy "realne":

class TextLinesInMemory: TextLines
class TextLinesInFile: TextLines
class TextLinesInDB: TextLines

class IdentifiedTextLinesInMemory: IdentifiedTextLines
...

class UniquelyIdentifiedTextLinesInMemory: UniquelyIdentifiedTextLines
...

'''


# class Foo:
#     attr = "Common"

#     def __init__(self, arg1, arg2):
#         self.attr1 = arg1
#         self.attr2 = arg2

#     def use_me(self):
#         print("Foo: use_me")

#     def poly(self):
#         print("Foo: poly")


# class Bar(Foo):
#     def something_new(self):
#         print("Bar: something_new")
#     def poly(self):
#         print("Bar: poly")


# class XYZ:
#     def xyz(self):
#         print("XYZ: xyz")
#     def poly(self):
#         print("XYZ: poly")


# class Strange(Bar, XYZ):
#     pass



# def main():
#     f = Foo(1,3)
#     b = Bar(1,3)
#     xyz = XYZ()
#     s = Strange(1,3)

#     print("=========================\nBar:")

#     b.something_new()
#     b.use_me()

#     print("=========================\nStrange:")

#     s.something_new()
#     s.use_me()
#     s.xyz()

#     print("=========================")


# if __name__ == '__main__':
#     main()




# class Foo:
#     attr = "Common"

#     def __init__(self, arg1, arg2):
#         self.attr1 = arg1
#         self.attr2 = arg2

#     def use_me(self):
#         print("Foo: use_me")

#     def poly(self):
#         print("Foo: poly")


# class Bar(Foo):
#     def something_new(self):
#         print("Bar: something_new")
#     def poly(self):
#         print("Bar: poly")


# class XYZ:
#     def xyz(self):
#         print("XYZ: xyz")
#     def poly(self):
#         print("XYZ: poly")


# class Strange(Bar, XYZ):
#     pass



# def main():
#     f = Foo(1,3)
#     b = Bar(1,3)
#     xyz = XYZ()
#     s = Strange(1,3)



#     f.poly()
#     b.poly()

#     xyz.poly()

#     collection = [f,b,xyz]
#     for e in collection:
#         print(type(e))
#         e.poly()


# if __name__ == '__main__':
#     main()


# class Foo:
#     attr = "Common"

#     def __init__(self, arg1, arg2):
#         self.attr1 = arg1
#         self.attr2 = arg2
#         self._attr_prot = 2 * arg1
#         self.__attr_priv = 10 * arg1
        
#     def get_priv(self):
#         return self.__attr_priv

# def main():
#     f = Foo(1, "a")
#     print(f.attr1)
#     print(f._attr_prot)
#    #print(f.__attr_priv) -> błąd:     AttributeError: 'Foo' object has no attribute '__attr_priv'. Did you mean: '_attr_prot'?
#     print(f.get_priv())

# if __name__ == '__main__':
#     main()


# class Foo:
#     cls_attr = "Class attribute"

#     def __init__(self, arg1, arg2):
#         self.attr1 = arg1
#         self.attr2 = arg2

#     @classmethod
#     def method_1(cls):
#         print(cls.cls_attr)
#         return "class method"

#     @staticmethod
#     def method_2():
#         return "static method"

# def main():
#     ## tak robic
#     print(Foo.method_1())
#     print(Foo.method_2())

#     f = Foo(1, "a")
#     print("-----------")


#     ## tak nie robic
#     print(f.method_1())
#     print(f.method_2())

# if __name__ == '__main__':
#     main()





class Foo:
    attr = "Common"

    def __init__(self, arg1, arg2):
        self.attr1 = arg1
        self.attr2 = arg2


def main():
    f1 = Foo(1, "b")
    f2 = Foo(2, "a")

    print(f1.attr2)
    print(f2.attr2)

    f1.attr2 = "e"

    print(f1.attr2)
    print(f2.attr2)

    print(f1.attr)
    print(f2.attr)

    Foo.attr = "xxx"

    print(f1.attr)
    print(f2.attr)
    print(Foo.attr)

    f1.attr = "zzz"

    print(f1.attr)
    print(f2.attr)
    print(Foo.attr)




if __name__ == '__main__':
    main()