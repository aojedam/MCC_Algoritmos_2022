import time
import datetime

def read_data_from_file(file_path):
	input_file = open(file_path, "r")
	return [float(item) for item in input_file.read().split(' ')]

def insertionSort(b):
	for i in range(1, len(b)):
		up = b[i]
		j = i - 1
		while j >= 0 and b[j] > up:
			b[j + 1] = b[j]
			j -= 1
		b[j + 1] = up	
	return b				

def bucketSort(list_to_sort):
	vector_size = len(list_to_sort)

	arr = []
	slot_num = vector_size 
	for i in range(slot_num):
		arr.append([])
		
	for j in list_to_sort:
		index_b = int(slot_num * j)
		arr[index_b].append(j)
		
	for i in range(slot_num):
		arr[i] = insertionSort(arr[i])
			
	k = 0
	for i in range(slot_num):
		for j in range(len(arr[i])):
			list_to_sort[k] = arr[i][j]
			k += 1
	return list_to_sort


def main():
	start_time = datetime.datetime.now()
	print(start_time)

	list_to_sort = read_data_from_file(r'sample_data/BucketSort_1000000.txt')
	bucketSort(list_to_sort)

	end_time = datetime.datetime.now()
	print(end_time)
	time_diff = (end_time - start_time)
	print(time_diff.total_seconds() * 1000.0)


main()