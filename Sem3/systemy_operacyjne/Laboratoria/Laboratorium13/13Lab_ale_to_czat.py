#!/usr/bin/python
import sys, csv

if len(sys.argv) < 3:
    print("Need 3 arguments (program, file, time).")
    sys.exit(1)

quantum = int(sys.argv[2])
processes = []

# Wczytanie procesów z pliku CSV
with open(sys.argv[1], newline='') as csvfile:
    reader = csv.DictReader(csvfile, fieldnames=['name', 'length', 'start'])
    for row in reader:
        processes.append({
            'name': row['name'],
            'length': int(row['length']),
            'start': int(row['start'])
        })

class Process:
    def __init__(self, name, length, start):
        self.name = name
        self.length = length
        self.start = start
        self.remaining_time = length

    def run(self, quantum):
        time_used = min(self.remaining_time, quantum)
        self.remaining_time -= time_used
        return time_used

class RoundRobinScheduler:
    def __init__(self, quantum, processes):
        self.quantum = quantum
        self.waiting_queue = sorted(
            [Process(p['name'], p['length'], p['start']) for p in processes],
            key=lambda x: x.start
        )
        self.active_queue = []
        self.time = 0

    def process_time(self):
        while self.waiting_queue or self.active_queue:
            # Sprawdź nowe procesy w czasie T
            while self.waiting_queue and self.waiting_queue[0].start <= self.time:
                process = self.waiting_queue.pop(0)
                print(f"T={self.time}: New process {process.name} is waiting for execution (length={process.length})")
                self.active_queue.append(process)

            if self.active_queue:
                current_process = self.active_queue.pop(0)
                print(f"T={self.time}: {current_process.name} will be running for {min(self.quantum, current_process.remaining_time)} time units. Time left: {max(0, current_process.remaining_time - self.quantum)}")
                time_used = current_process.run(self.quantum)
                self.time += time_used

                if current_process.remaining_time > 0:
                    self.active_queue.append(current_process)
                else:
                    print(f"T={self.time}: Process {current_process.name} has been finished")
            else:
                print(f"T={self.time}: No processes currently available")
                self.time += 1

scheduler = RoundRobinScheduler(quantum, processes)
scheduler.process_time()
