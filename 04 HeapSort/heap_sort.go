package main

import (
	"log"
	"os"
	"strconv"
	"strings"
)

func main() {
	arrayToSort := readDataFromFile("C:\\Projects\\Maestria\\AyED\\Data_1000000.txt")

	heapSort(arrayToSort)

}

func readDataFromFile(filePath string) []int {
	var ints []int
	b, err := os.ReadFile(filePath)
	if err != nil {
		log.Print(err)
	}

	str := string(b)
	for index, element := range strings.Split(str, " ") {
		log.Println(index)

		intVar, err := strconv.Atoi(element)
		if err != nil {
			log.Print(err)
		}
		ints = append(ints, intVar)
	}

	return ints
}

func heapSort(arrayToHeap []int) {
	arraySize := len(arrayToHeap)

	for index := arraySize/2 - 1; index >= 0; index-- {
		heapify(arrayToHeap, arraySize, index)
	}

	for index := arraySize - 1; index >= 0; index-- {
		tempValue := arrayToHeap[0]
		arrayToHeap[0] = arrayToHeap[index]
		arrayToHeap[index] = tempValue
		heapify(arrayToHeap, index, 0)
	}
}

func heapify(arrayToSort []int, arraySize int, index int) {
	largest := index
	leftChild := 2*index + 1
	rightChild := 2*index + 2

	if leftChild < arraySize && arrayToSort[leftChild] > arrayToSort[largest] {
		largest = leftChild
	}

	if rightChild < arraySize && arrayToSort[rightChild] > arrayToSort[largest] {
		largest = rightChild
	}

	if largest != index {
		tempValue := arrayToSort[index]
		arrayToSort[index] = arrayToSort[largest]
		arrayToSort[largest] = tempValue

		heapify(arrayToSort, arraySize, largest)
	}
}
