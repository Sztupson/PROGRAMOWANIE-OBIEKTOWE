# import os 
# import random
# from timeit import default_timer as timer

# #                            filesize, max wielkość losowanych liczb
# def generate_data(file_path, size,     max_value):
#     with open(file_path, "w") as file_out:
#         for i in range(size - 1):
#             number = random.randint(0, max_value)
#             file_out.writelines(str(number) + "\n")
#             if i % 100_000 == 0:
#                 print(f"{i} of {size}")

#         number = random.randint(0, max_value)
#         file_out.writelines(str(number))

# # def generate_data(file_path, size,     max_value):
# #     with open(file_path, "w") as file_out:
# #         for i in range(size - 1):
# #             number = random.randint(0, max_value)
# #             number2 = random.randint(0, max_value)
# #             file_out.writelines(str(number) + ", " + str(number2) + "\n")
            
# #             if i % 100_000 == 0:
# #                 print(f"{i} of {size}")

# #         number = random.randint(0, max_value)
# #         file_out.writelines(str(number) + ", " + str(number2))

# def divide_file(file_path, size, working_directory):
#     with open(file_path, "r") as file_data:
#         file_number = 1
#         end = False

#         while not end:
#             file_out_name  = f"data_{file_number}.dat"
#             file_out_path = os.path.join(working_directory, file_out_name)
#             file_number += 1
#             counter = 0

#             line = file_data.readline().strip()
#             if not line:
#                 break
            
#             with open(file_out_path, "w") as file_out:
#                 file_out.write(line)
#                 counter += 1
                
#                 while counter < size:
#                     line = file_data.readline().strip()
#                     if not line:
#                         end = True
#                         break

#                     file_out.write("\n" + line)
#                     counter += 1
#             if file_number % 10 == 0:
#                 print(f"{file_number} of {size}")

# def get_all_files_in_directory(working_directory):
#     files = []

#     for file in os.listdir(working_directory):
#         file_path = os.path.join(working_directory, file)

#         if not os.path.isdir(file_path):
#             files.append(file)

#     return files


# def sort_data_in_directory(working_directory):
#     files = get_all_files_in_directory(working_directory)
#     c = 1
#     number_of_files = len(files)

#     for file in files:
#         file_path = os.path.join(working_directory, file)
#         data = None
#         with open(file_path, "r") as source_file:
#             data = [int(line.strip()) for line in source_file]
#         data.sort()

#         with open(file_path, "w") as result_file:
#             for i in range(len(data) - 1):
#                 result_file.write(str(data[i]) + "\n")
#             result_file.write(str(data[-1]))
#         if c % 10 == 0:
#             print(f"{c} of {number_of_files}")


# def merge_two_files(working_directory,
#                     file_in_1_name,
#                     file_in_2_name,
#                     file_out_name):
    
#     file_in_1_path = os.path.join(working_directory, file_in_1_name)
#     file_in_2_path = os.path.join(working_directory, file_in_2_name)
#     file_out_path = os.path.join(working_directory, file_out_name)

#     with open(file_in_1_path, "r") as file_in_1:
#         with open(file_in_2_path, "r") as file_in_2:
#             with open(file_out_path, "w") as file_out:
#                 line_1 = file_in_1.readline().strip()
#                 line_2 = file_in_2.readline().strip()

#                 while True:
#                     if line_1 and line_2:


#                         v1 = int(line_1)
#                         v2 = int(line_2)

#                         if v1 < v2:
#                             file_out.write(str(v1))
#                             line_1 = file_in_1.readline().strip()
#                         else:
#                             file_out.write(str(v2))
#                             line_2 = file_in_2.readline().strip()


#                     elif line_1 and not line_2:
#                         file_out.write(line_1)
#                         line_1 = file_in_1.readline().strip()
#                     elif not line_1 and line_2:
#                         file_out.write(line_2)
#                         line_2 = file_in_2.readline().strip()
#                     else:
#                         break
                    
#                     if line_1 or line_2:
#                         file_out.write("\n")

# def merge_one_iteration(working_directory, files, iteration, remove_source_files = True):
#     dim = 2
#     list_of_pairs = [ files[i:i+dim] for i in range(0, len(files), dim) ]

#     p = 1

#     for pair in list_of_pairs:
#         if len(pair) == dim:
#             file_in_1_name = pair[0]
#             file_in_2_name = pair[1]
#             file_out_name = f"{iteration}_{p}.dat"
#             merge_two_files(working_directory, file_in_1_name, file_in_2_name, file_out_name)
#         else:
#             path_current = os.path.join(working_directory, pair[0])
#             path_new = os.path.join(working_directory, f"{iteration}_{p}.dat")
#             os.rename(path_current, path_new)
#         p += 1

#     if remove_source_files:
#         for file in files:
#             file_path = os.path.join(working_directory, file)
#             if not os.path.isdir(file_path):
#                 if os.path.exists(file_path):
#                     os.remove(file_path)



# def merge_all_files(working_directory):
#     files = get_all_files_in_directory(working_directory)
#     number_of_files = len(files)
#     iteration = 1
#     safe = 10

#     while number_of_files > 1 and safe > 0:
#         safe -= 1
#         merge_one_iteration(working_directory, files, iteration, True)
#         files = get_all_files_in_directory(working_directory)
#         number_of_files = len(files)
#         iteration += 1

# #####################################################################

# def count_occurrences(file_path):
#     with open(file_path, "r") as file:
#         occurrences = {}
#         for line in file:
#             num = int(line.strip())
#             if num in occurrences:
#                 occurrences[num] += 1
#             else:
#                 occurrences[num] = 1
#         return occurrences  

# def count_numbers(file_path_1, file_path_2):    
#     count_1 = count_occurrences(file_path_1)
#     count_2 = count_occurrences(file_path_2)
    
#     print("Liczba wystąpień w pliku pierwotnym:")
#     for number, count in count_1.items():
#         print(f"{number}: {count}")
    
#     print("\nLiczba wystąpień w pliku wynikowym:")
#     for number, count in count_2.items():
#         print(f"{number}: {count}")
    
#     if count_1 == count_2:
#         print("\nWszystkie liczby występują tyle samo razy.")
#     else:
#         print("\nLiczby nie zgadzają się.")


# def sort_check(file_path):
#     with open(file_path, "r") as file:
#         prev_number = None

#         is_sorted = True
#         for line in file:
#             current_number = int(line.strip())
#             if prev_number is not None and current_number < prev_number:
#                 is_sorted = False
#                 break

#             prev_number = current_number
#     if is_sorted:
#         print("Plik wynikowy posortowany.")
#     else:
#         print("Plik wynikowy nieposortowany.")


#     # begin = timer()
#     # # generate_data("Sem4/big_data/data.dat", 100000, 20)
#     # # divide_file("Sem4/big_data/data.dat", 4, "/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data")
#     # #sort_data_in_directory("/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data")
#     # #merge_two_files("/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data", "data_1.dat", "data_2.dat", "data_1_2.dat")
#     # merge_all_files("/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data")
#     # end = timer()
#     # print(f"Time: {end - begin} s")
# def main():
#     begin = timer()
#     generate_data("Sem4/big_data/data.dat", 1000000,20)
#     end = timer()
#     print(f"Generowanie: {end - begin}")
#     begin = timer()
#     divide_file("Sem4/big_data/data.dat", 20000, os.path.join(r"/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data"))
#     end = timer()
#     print(f"Dzielenie: {end- begin}")
#     begin = timer()
#     sort_data_in_directory(r"/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data")
#     end = timer()
#     print(f"Sortowanie: {end-begin}")
#     begin = timer()
#     merge_all_files(r"/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data")
#     end = timer()
#     print(f"Dzielenie: {end - begin} s")

    
    
#     print("------------------------")
#     count_numbers("Sem4/big_data/data.dat", "Sem4/big_data/data/6_1.dat")
#     print("------------------------")
#     sort_check("Sem4/big_data/data/6_1.dat")

#     ##############################################################################3


#     # generate_data("Sem4/big_data/data2.dat", 1000,20)
    
#     # divide_file("Sem4/big_data/data.dat", 4, os.path.join(r"/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data"))
#     # end = timer()
#     # print(f"Dzielenie: {end- begin}")
#     # begin = timer()
#     # sort_data_in_directory(r"/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data")
#     # end = timer()
#     # print(f"Sortowanie: {end-begin}")
#     # begin = timer()
#     # merge_all_files(r"/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data")
#     # end = timer()
#     # print(f"Dzielenie: {end - begin} s")


# if __name__ == "__main__":
#     main()

import os 
import random
from timeit import default_timer as timer

#                            filesize, max wielkość losowanych liczb
        
def generate_data(file_path, size,     max_value):
    with open(file_path, "w") as file_out:
        for i in range(size - 1):
            number = random.randint(0, max_value)
            s = str(number)
            file_out.writelines(f"{s},z{2*s}\n")
            
            if i % 100_000 == 0:
                print(f"{i} of {size}")
        
        number = random.randint(0, max_value)
        file_out.writelines(f"{s},z{2*s}")


def divide_file(file_path, size, working_directory):
    with open(file_path, "r") as file_data:
        file_number = 1
        end = False
        while not end:
            file_out_name  = f"data_{file_number}.dat"
            file_out_path = os.path.join(working_directory, file_out_name)
            file_number += 1
            counter = 0

            line = file_data.readline().strip()
            if not line:
                break
            
            with open(file_out_path, "w") as file_out:
                file_out.write(line)
                counter += 1
                
                while counter < size:
                    line = file_data.readline().strip()
                    if not line:
                        end = True
                        break

                    file_out.write("\n" + line)
                    counter += 1
            if file_number % 10 == 0:
                print(f"{file_number} of {size} ")

def get_all_files_in_directory(working_directory):
    files = []

    for file in os.listdir(working_directory):
        file_path = os.path.join(working_directory, file)

        if not os.path.isdir(file_path):
            files.append(file)

    return files


        
def condition(line):
    parts = line.split(',')
    return int(parts[0])
       
def sort_data_in_directory(working_directory):
    files = get_all_files_in_directory(working_directory)
    c = 1

    for file in files:
        file_path = os.path.join(working_directory, file)
        data = None
        
        with open(file_path, "r") as source_file:
            data = [line.strip() for line in source_file]
        data.sort(key = condition)

        with open(file_path, "w") as result_file:
            for i in range(len(data) - 1):
                result_file.write(data[i] + "\n")
            result_file.write(data[-1])
            
        if c % 10 == 0:
            print(f"{c}")
            
        c += 1

def merge_two_files(working_directory,
                    file_in_1_name,
                    file_in_2_name,
                    file_out_name):
    
    file_in_1_path = os.path.join(working_directory, file_in_1_name)
    file_in_2_path = os.path.join(working_directory, file_in_2_name)
    file_out_path = os.path.join(working_directory, file_out_name)

    with open(file_in_1_path, "r") as file_in_1:
        with open(file_in_2_path, "r") as file_in_2:
            with open(file_out_path, "w") as file_out:
                line_1 = file_in_1.readline().strip()
                line_2 = file_in_2.readline().strip()

                while True:
                    if line_1 and line_2:


                        v1 = int(line_1.split(",",1)[0])
                        v2 = int(line_2.split(",",1)[0])

                        if v1 < v2:
                            file_out.write(line_1)
                            line_1 = file_in_1.readline().strip()
                        else:
                            file_out.write(line_2)
                            line_2 = file_in_2.readline().strip()


                    elif line_1 and not line_2:
                        file_out.write(line_1)
                        line_1 = file_in_1.readline().strip()
                    elif not line_1 and line_2:
                        file_out.write(line_2)
                        line_2 = file_in_2.readline().strip()
                    else:
                        break
                    
                    if line_1 or line_2:
                        file_out.write("\n")

def merge_one_iteration(working_directory, files, iteration, remove_source_files = True):
    dim = 2
    list_of_pairs = [ files[i:i+dim] for i in range(0, len(files), dim) ]

    p = 1

    for pair in list_of_pairs:
        if len(pair) == dim:
            file_in_1_name = pair[0]
            file_in_2_name = pair[1]
            file_out_name = f"{iteration}_{p}.dat"
            merge_two_files(working_directory, file_in_1_name, file_in_2_name, file_out_name)
        else:
            path_current = os.path.join(working_directory, pair[0])
            path_new = os.path.join(working_directory, f"{iteration}_{p}.dat")
            os.rename(path_current, path_new)
        p += 1

    if remove_source_files:
        for file in files:
            file_path = os.path.join(working_directory, file)
            if not os.path.isdir(file_path):
                if os.path.exists(file_path):
                    os.remove(file_path)



def merge_all_files(working_directory):
    files = get_all_files_in_directory(working_directory)
    number_of_files = len(files)
    iteration = 1
    safe = 10

    while number_of_files > 1 and safe > 0:
        safe -= 1
        merge_one_iteration(working_directory, files, iteration, True)
        files = get_all_files_in_directory(working_directory)
        number_of_files = len(files)
        iteration += 1
        
def count_numbers_in_file(file_path):
    print("counting data in file:")
    number_counts = {}
    
    with open(file_path, "r") as file:
        for line in file:
            number = int(line.split(',',1)[0].strip())
            if number in number_counts:
                number_counts[number] += 1
            else:
                number_counts[number] = 1
    
    for number, count in sorted(number_counts.items()):
        print(f"{number}: {count}")
    
    return number_counts


def count_numbers_in_directory(working_directory):
    print("counting data in directory:")
    number_counts = {}
    
    for file_name in os.listdir(working_directory):
        file_path = os.path.join(working_directory, file_name)
        
        if os.path.isfile(file_path):  # Sprawdzamy, czy to plik
            with open(file_path, "r") as file:
                for line in file:
                    try:
                        number = int(line.split(',',1)[0].strip())
                        number_counts[number] = number_counts.get(number, 0) + 1
                    except ValueError:
                        pass 
    
    for number, count in sorted(number_counts.items()):
        print(f"{number}: {count}")
    
    return number_counts

def compare_number_counts(file1, working_directory):
    print("checking if files are sorted")
    sort_check(working_directory)
    print("comparing files")
    counts1 = count_numbers_in_file(file1)
    counts2 = count_numbers_in_directory(working_directory)
    
    numbers1 = sorted(counts1)
    numbers2 = sorted(counts2)
    
    i, j = 0, 0
    while i < len(numbers1) or j < len(numbers2):
        if i < len(numbers1):
            num1 = numbers1[i]
        else:
            num1 = None
        
        if j < len(numbers2):
            num2 = numbers2[j]
        else:
            num2 = None
        
        if num1 == num2:
            print(f"{num1}: {counts1[num1]} vs {counts2[num2]} ({'same' if counts1[num1] == counts2[num2] else '--different--'})")
            i += 1
            j += 1
        elif num1 is None or (num2 is not None and num2 < num1):
            print(f"{num2}: 0 vs {counts2[num2]} (--diffrerent--)")
            j += 1
        else:
            print(f"{num1}: {counts1[num1]} vs 0 (--different--)")
            i += 1
    
    return counts1 == counts2

def sort_check(working_directory):
    for file_name in os.listdir(working_directory):
        file_path = os.path.join(working_directory, file_name)
        
        if os.path.isfile(file_path): 
            with open(file_path, 'r') as file:
                prev_num = None
                for line in file:
                    num = int(line.split(',',1)[0].strip())
                    if prev_num is not None and num < prev_num:
                        print("---files not sorted---")
                        return
                    prev_num = num
            print("----files sorted---")
                

def main():
    begin = timer()
    # generate_data("Sem4/big_data/data.dat", 1000, 10)
    # divide_file("Sem4/big_data/data.dat", 5, "/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data")
    # sort_data_in_directory("/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data")
    # merge_all_files("/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data")
    end = timer()
    print(f"time: {end - begin} s")
    #count_numbers_in_file("Sem4/big_data/data.dat")
    #count_numbers_in_directory("/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data")
    sort_check("/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data")
    compare_number_counts("Sem4/big_data/data.dat", "/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data")
if __name__ == "__main__":
    main() 
