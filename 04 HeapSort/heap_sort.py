import time
import datetime

def read_data_from_file(file_path):
	input_file = open(file_path, "r")
	return [int(item) for item in input_file.read().split(' ')]


def heapify(list_to_sort, list_size, index):
	largest = index
	left_child = 2 * index + 1
	right_child = 2 * index + 2

	if left_child < list_size and list_to_sort[index] < list_to_sort[left_child]:
		largest = left_child

	if right_child < list_size and list_to_sort[largest] < list_to_sort[right_child]:
		largest = right_child

	if largest != index:
		list_to_sort[index], list_to_sort[largest] = list_to_sort[largest], list_to_sort[index]

		heapify(list_to_sort, list_size, largest)


def heap_sort(list_to_sort):
	vector_size = len(list_to_sort)
	for index in range(vector_size // 2 - 1, -1, -1):
		heapify(list_to_sort, vector_size, index)

	for index in range(vector_size - 1, 0, -1):
		list_to_sort[index], list_to_sort[0] = list_to_sort[0], list_to_sort[index]
		heapify(list_to_sort, index, 0)


def main():
	start_time = datetime.datetime.now()
	print(start_time)

	list_to_sort = read_data_from_file(r'C:\Projects\Maestria\AyED\Data_1000000.txt')
	heap_sort(list_to_sort)

	end_time = datetime.datetime.now()
	print(end_time)
	time_diff = (end_time - start_time)
	print(time_diff.total_seconds() * 1000.0)


main()
