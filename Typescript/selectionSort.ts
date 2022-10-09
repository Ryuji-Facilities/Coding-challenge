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

console.log(selectionSort([1,2,5,4,2,4,2,3,4]));