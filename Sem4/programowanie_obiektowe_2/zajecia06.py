# ### PIERWSZY PRZYKŁAD
# class Person:
#     def __new__(cls, name, age):
#         print("Creating a new Person object.")
#         instance = super().__new__(cls)
#         return instance
    
#     def __init__(self, name, age):
#         print("Initializing the Person object.")
#         self.name = name
#         self.age = age

# person = Person("John", 30)
# print(f"{person.name}, {person.age}")




# ### DRUGI PRZYKŁAD
# class Foo:
#     def __new__(cls):
#         print("Foo:__new__")
#         return super().__new__(cls)
    
#     def __init__(self):
#         print("Foo:__init__")

# class Bar:
#     def __new__(cls):
#         print("Bar:__new__")
#         return Foo()
    
#     def __init__(self):
#         print("Bar:__init__")

# b = Bar()
# print(isinstance(b, Foo))




# ### TRZECI PRZYKŁAD

# class Square:
#     def __init__(self, side_length):
#         self.side_length = side_length

# class Rectangle:
#     def __new__(cls, width, height):
#         if width == height:
#             return Square(width)
#         return super().__new__(cls)
    
#     def __init__(self, width, height):
#         self.width = width
#         self.height = height
        
# r1 = Rectangle(2,3)
# r2 = Rectangle(5,5)

# print(type(r1))
# print(type(r2))


# ### CZWARTY PRZYKŁAD

# class Singleton:
#     __ins = None

#     def __new__(cls):
#         if cls.__ins is None:
#             print("Create instance.")
#             cls.__ins = super().__new__(cls)

#         return cls.__ins
    
# obj1 = Singleton()
# obj2 = Singleton()
# obj3 = Singleton()

# print(obj1)
# print(obj2)
# print(obj3)

# ### PIĄTY PRZYKŁAD

# class Agent():
#     __agents = {}


#     def __new__(cls, name):
#         if name not in cls.__agents:
#             cls.__agents[name] = super().__new__(cls)
#         return cls.__agents[name]

#     def __init__(self, name):
#         self.name = name

# a1 = Agent("James")
# a2 = Agent("Lukas")
# a3 = Agent("Aston")
# a4 = Agent("Mr Bean")

# print(a1 == a3)

# a5 = Agent("Aston")

# print(a3 == a5)

# print(a1 == a5)

# print(a5.name)
# print(a3.name)


# ### SZÓSTY PRZYKŁAD

# class BaseClass:
#     def __new__(cls):
#         obj = super().__new__(cls)
#         obj._from_base_class = type(obj) == BaseClass
#         return obj
    
# class SubClass:
#     pass


# base_instance = BaseClass()
# sub_instance = SubClass()

# print(base_instance._from_base_class)
# print(sub_instance._from_base_class)


# ### SIÓDMY PRZYKŁAD

# class Person:
#     def __init__(self, name):
#         self.name = name
#         self.id = id

# class Employee(Person):
#     def __init__(self, name, id):
#         super().__init__("Best "+ name)
#         self.name_ = ">"+name+"<"
#         self.id = id

# e = Employee("John", "007")

# print(e.name_)
# print(e.name)
# print(e.id)


# ### ÓSMY PRZYKŁAD

# def something():
#     ff = Foo("Krzysio")

# class Foo:
#     def __init__(self, name):
#         self.name = name
#         print(f"Foo({self.name}):__init__")
#     def __del__(self):
#         print(f"Foo({self.name}):__del__")

# f = Foo("Aston")
# g = Foo("Lukas")

# del f

# x = input("Wpisz coś: ")

# something()

# y = []
# print(y[0])
# print("jestem tutaj")