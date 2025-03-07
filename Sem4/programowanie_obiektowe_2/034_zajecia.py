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
    cls_attr = "Class attribute"

    def __init__(self, arg1, arg2):
        self.attr1 = arg1
        self.attr2 = arg2

    @classmethod
    def method_1(cls):
        print(cls.cls_attr)
        return "class method"

    @staticmethod
    def method_2():
        return "static method"

def main():
    ## tak robic
    print(Foo.method_1())
    print(Foo.method_2())

    f = Foo(1, "a")
    print("-----------")


    ## tak nie robic
    print(f.method_1())
    print(f.method_2())

if __name__ == '__main__':
    main()