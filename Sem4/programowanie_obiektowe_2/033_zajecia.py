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
        self._attr_prot = 2 * arg1
        self.__attr_priv = 10 * arg1
    def get_priv(self):
        return self.__attr_priv

def main():
    f = Foo(1, "a")
    print(f.attr1)
    print(f._attr_prot)
   #print(f.__attr_priv) -> błąd:     AttributeError: 'Foo' object has no attribute '__attr_priv'. Did you mean: '_attr_prot'?
    print(f.get_priv())

if __name__ == '__main__':
    main()