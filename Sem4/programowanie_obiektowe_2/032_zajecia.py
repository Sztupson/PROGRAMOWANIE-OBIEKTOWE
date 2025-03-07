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


class Foo:
    attr = "Common"

    def __init__(self, arg1, arg2):
        self.attr1 = arg1
        self.attr2 = arg2

    def use_me(self):
        print("Foo: use_me")

    def poly(self):
        print("Foo: poly")


class Bar(Foo):
    def something_new(self):
        print("Bar: something_new")
    def poly(self):
        print("Bar: poly")


class XYZ:
    def xyz(self):
        print("XYZ: xyz")
    def poly(self):
        print("XYZ: poly")


class Strange(Bar, XYZ):
    pass



def main():
    f = Foo(1,3)
    b = Bar(1,3)
    xyz = XYZ()
    s = Strange(1,3)



    f.poly()
    b.poly()
    xyz.poly()

    collection = [f,Foo(b),xyz]
    for e in collection:
        print(type(e))
        e.poly()


if __name__ == '__main__':
    main()