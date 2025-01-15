#!/usr/bin/python
import sys, csv

if len(sys.argv) < 3:
    print("Need 3 arguments (program, file, time).")

kwantaCzasu = int(sys.argv[2])
queue = []

with open(sys.argv[1], newline='') as csvfile:
    reader = csv.DictReader(csvfile, fieldnames=['name', 'length', 'start'])
    for row in reader:
        queue.append({
            'name': row['name'],
            'length': int(row['length']),
            'start': int(row['start'])
        })

class Process:
    def __init__(self, name, length, start):
        self.name = name
        self.length = length
        self.start = start
    
class RoundRobinScheduler:
    def __init__(self, kwantaCzasu, queue):
        self.kwantaCzasu = kwantaCzasu
        self.queue = [Process(q['name'], q['length'], q['start']) for q in queue]
        self.running_queue = []
        
    def processing(self):
        while self.queue or self.running_queue:
            pass