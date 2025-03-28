import os 
import random
from timeit import default_timer as timer

#                            filesize, max wielkość losowanych liczb
def generate_data(file_path, size,     max_value):
    with open(file_path, "w") as file_out:
        for i in range(size - 1):
            number = random.randint(0, max_value)
            number2 = random.randint(0, max_value)
            file_out.writelines(str(number) + ", " + str(number2) + "\n")
            
            if i % 100_000 == 0:
                print(f"{i} of {size}")

        number = random.randint(0, max_value)
        file_out.writelines(str(number) + ", " + str(number2))

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
                print(f"{file_number} of {size}")

def get_all_files_in_directory(working_directory):
    files = []

    for file in os.listdir(working_directory):
        file_path = os.path.join(working_directory, file)

        if not os.path.isdir(file_path):
            files.append(file)

    return files


def sort_data_in_directory(working_directory):
    files = get_all_files_in_directory(working_directory)
    c = 1
    number_of_files = len(files)

    for file in files:
        file_path = os.path.join(working_directory, file)
        data = None
        with open(file_path, "r") as source_file:
            data = [int(line.strip()) for line in source_file]
        data.sort()

        with open(file_path, "w") as result_file:
            for i in range(len(data) - 1):
                result_file.write(str(data[i]) + "\n")
            result_file.write(str(data[-1]))
        if c % 10 == 0:
            print(f"{c} of {number_of_files}")


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


                        v1 = int(line_1)
                        v2 = int(line_2)

                        if v1 < v2:
                            file_out.write(str(v1))
                            line_1 = file_in_1.readline().strip()
                        else:
                            file_out.write(str(v2))
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

def count_numbers(file_path_1, file_path_2):
    def count_occurrences(file_path):
        with open(file_path, "r") as file:
            numbers = []
            occurrences = {}
            for line in file:
                num = int(line.strip())
                numbers.append(num)
                if num in occurrences:
                    occurrences[num] += 1
                else:
                    occurrences[num] = 1
            return occurrences
    
    count_1 = count_occurrences(file_path_1)
    count_2 = count_occurrences(file_path_2)
    
    print("Liczba wystąpień w pliku pierwotnym:")
    for number, count in count_1.items():
        print(f"{number}: {count}")
    
    print("\nLiczba wystąpień w pliku wynikowym:")
    for number, count in count_2.items():
        print(f"{number}: {count}")
    
    if count_1 == count_2:
        print("\nWszystkie liczby występują tyle samo razy.")
    else:
        print("\nLiczby nie zgadzają się!")

def sort_check(file_path):
    with open(file_path, "r") as file:
        numbers = []
        for line in file:
            numbers.append(int(line.strip()))
    
    is_sorted = True
    for i in range(len(numbers) - 1):
        if numbers[i] > numbers[i + 1]:
            is_sorted = False
            break
    
    if is_sorted:
        print("Plik wynikowy jest poprawnie posortowany.")
    else:
        print("Plik wynikowy nie jest posortowany!")


    # begin = timer()
    # # generate_data("Sem4/big_data/data.dat", 100000, 20)
    # # divide_file("Sem4/big_data/data.dat", 4, "/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data")
    # #sort_data_in_directory("/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data")
    # #merge_two_files("/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data", "data_1.dat", "data_2.dat", "data_1_2.dat")
    # merge_all_files("/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data")
    # end = timer()
    # print(f"Time: {end - begin} s")
def main():
    # begin = timer()
    # generate_data("Sem4/big_data/data.dat", 2000000,20)
    # end = timer()
    # print(f"Generowanie: {end - begin}")
    # begin = timer()
    # divide_file("Sem4/big_data/data.dat", 20000, os.path.join(r"/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data"))
    # end = timer()
    # print(f"Dzielenie: {end- begin}")
    # begin = timer()
    # sort_data_in_directory(r"/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data")
    # end = timer()
    # print(f"Sortowanie: {end-begin}")
    # begin = timer()
    # merge_all_files(r"/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data")
    # end = timer()
    # print(f"Dzielenie: {end - begin} s")
    
    
    # count_numbers("Sem4/big_data/data.dat", "Sem4/big_data/data/7_1.dat")
    # print("------------------------")
    # sort_check("Sem4/big_data/data/7_1.dat")

    ##############################################################################3


    generate_data("Sem4/big_data/data2.dat", 20,20)
    
    divide_file("Sem4/big_data/data.dat", 4, os.path.join(r"/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data"))
    end = timer()
    print(f"Dzielenie: {end- begin}")
    begin = timer()
    sort_data_in_directory(r"/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data")
    end = timer()
    print(f"Sortowanie: {end-begin}")
    begin = timer()
    merge_all_files(r"/home/u335779/Pulpit/repo/PROGRAMOWANIE-OBIEKTOWE/Sem4/big_data/data")
    end = timer()
    print(f"Dzielenie: {end - begin} s")


if __name__ == "__main__":
    main()