function swapTwo(list: number [],a: number, b: number){
    [list[a], list[b]] = [list[b], list[a]];
}

function selectionSort(arr: number []):number [] {
    let min: number;
    for (let i = 0; i < arr.length; i++) {
        min = i;
        for (let j = i + 1; j < arr.length; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min !== i) {
          swapTwo(arr, min, i);
        }
    }
    return arr;
}

console.log(selectionSort([9,3,2,6,5,12,53,64,23,456,235,87,23,5,235,666,34,7,67]));
