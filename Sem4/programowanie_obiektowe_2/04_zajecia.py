from abc import ABC, abstractmethod

class TextLines:
    # BEGIN: Public methods
    @abstractmethod
    def get_number_of_lines(self):
        pass

    @abstractmethod
    def read_line(self, line_number):
        pass

    @abstractmethod
    def write_line(self, text, line_number = None):
        pass

    @abstractmethod
    def delete_line(self, line_number):
        pass




class TextLinesInMemory(TextLines):
    #BEGIN: Public methods
    def __init__(self):
        self.__lines = []


    def get_number_of_lines(self):
        return len(self.__lines)

    def read_line(self, line_number):
        if line_number >= 0 and line_number < self.get_number_of_lines():
            return self.__lines[line_number]
        else:
            raise IndexError("Line number out of range.")
                
        # Alternative version (possibly faster)
        # ======================================
        # if line_number < len(self.__lines):
        #     return self.__lines[line_number]
        # ======================================


    def delete_line(self, line_number):
        if line_number >= 0 and line_number < self.get_number_of_lines():
            self.__lines[line_number] = None
        else:
            raise IndexError("Line number out of range.")
        

    def write_line(self, text, line_number=None):
        if line_number is None:
            self.__write_line_at_end(text)
        else:
            self.__write_line_at_index(text, line_number)

    #BEGIN: Private methods
    def __write_line_at_end(self, text):
        if type(text) is not str:
            raise TypeError("Text must be a string type.")

        self.__lines.append(text)

    '''
    # Conservative variant
    def __write_line_at_index(self, text, line_number):
        if type(text) is not str:
            raise TypeError("Text must be a string type.")
        elif line_number >= 0 and line_number < self.get_number_of_lines():
            return self.__lines[line_number] = text
        else:
            raise IndexError("Line number out of range.")
        
    #Progressive variant
    def __write_line_at_index(self, text, line_number):
        if type(text) is not str:
            raise TypeError("Text must be a string type.")
        elif line_number >= 0 and line_number < self.get_number_of_lines():
            return self.__lines[line_number] = text
        else:
            for _ in range(line_number - self.get_number_of_lines()):
                self.__write_line_at_end("")
            self.__write_line_at_end(text)
    '''
    #Progressive variant
    def __write_line_at_index(self, text, line_number):
        if type(text) is not str:
            raise TypeError("Text must be a string type.")
        elif line_number >= 0 and line_number < self.get_number_of_lines():
            self.__lines[line_number] = text
        else:
            for _ in range(line_number - self.get_number_of_lines()):
                self.__write_line_at_end("")
            self.__write_line_at_end(text)

def test_TextLinesInMemory():
    tlim = TextLinesInMemory()
    line_number = tlim.get_number_of_lines()
    print(line_number)
    tlim.write_line("test text")
    line_number = tlim.get_number_of_lines()
    print(line_number)
    tlim.write_line("foo bar", 5)
    line_number = tlim.get_number_of_lines()
    print(line_number)
    tlim.write_line("baz bar", 2)
    line_number = tlim.get_number_of_lines()
    print(line_number)
    line = tlim.read_line(2)
    print(line)
    tlim.delete_line(2)
    line_number = tlim.get_number_of_lines()
    print(line_number)
    line = tlim.read_line(2)
    print(line)


    try:
        line = tlim.read_line(29)
        print(line)
    except IndexError:
        print("Bad index.")

class IdentifiedTextLines():
    def __init__(self):
        self.__lines = TextLinesInMemory()
        self.__ids = {}

    def get_identifiers(self):
        return [_id for _id in self.__ids]

    def write_line(self, text, identifier):
        if identifier not in self.__ids:
            self.__ids[identifier] = []
        
        self.__lines.write_line(text)
        line_number = self.__lines.get_number_of_lines() - 1

        self.__ids[identifier].append(line_number)

    def read_line(self, identifier):
        if identifier not in self.__ids:
            raise KeyError("Unknown identifier.")
        
        result = []

        for idx in self.__ids[identifier]:
            line = self.__lines.read_line(idx)
            result.append(line)

        return result

    def delete_line(self, identifier):
        if identifier not in self.__ids:
            raise KeyError("Unknown identifier.")
        
        for idx in self.__ids[identifier]:
            self.__lines.delete_line(idx)

        del self.__ids[identifier]


    def find_free_index(self):
        number_of_lines = self.__lines.get_number_of_lines()
        print(number_of_lines)
        seq = [n for n in range(number_of_lines)]
        print(seq)
        for key in self.__ids:
            print(f"Identifier: {key}")
            for idx in self.__ids[key]:
                print(idx)
                seq.remove(idx)
        print(seq)
        if len(seq) > 0:
            print(f"Use index {seq[0]}")
        else:
            print(f"Use without index {append}")



    def dump(self):
        print(self.__lines)

    

def test_IdentifiedTextLines():
    titl = IdentifiedTextLines()
    titl.write_line("foo 1", "f1")
    titl.write_line("bar 1", "b1")
    titl.write_line("foo 2", "f1")
    titl.write_line("bar 2", "b1")
    titl.write_line("foo 3", "f1")
    titl.write_line("bar 3", "b1")
    lines = titl.read_line("f1")
    for l in lines:
        print(l)
    titl.delete_line("f1")
    print(titl.get_identifiers())
    titl.dump()
    titl.find_free_index()

def main():
    #test_TextLinesInMemory()
    test_IdentifiedTextLines()


if __name__ == "__main__":
    main()