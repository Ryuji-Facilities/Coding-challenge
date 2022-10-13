function merge(list1: number[], list2: number[]):number [] {   
    let merged:number [] = [],
        i:number = 0,
        j:number = 0;
    while (i < list1.length && j < list2.length) {  
        if (list1[i] < list2[j]) {
            merged.push(list1[i]);
            i++;
        } else {
            merged.push(list2[j]);
            j++;
        }
    }
    while (i < list1.length) {
        merged.push(list1[i]);
        i++;
    }
    while (j < list2.length) {
        merged.push(list2[j]);
        j++;
    }
    return merged;
}

function mergeSort(list:number []):number [] {
    if (list.length <= 1) return list;
    let mid = Math.floor(list.length / 2);
    let left:number [] = mergeSort(list.slice(0, mid));
    let right:number [] = mergeSort(list.slice(mid));
    return merge(left, right);
}

console.log(mergeSort([1,2,44,3,2,33,2,5,664,1,8,7,4,5]))