# 自定义 sort 函数排序标准

> 实现一个可设置排序准则的函数

```javascript
function compareStandard(key) {
    return function(obj1, obj2) {
        let val1 = obj1[key]
        let val2 = obj2[key]

        if (val1 < val2) {
            return -1
        } else if (val1 > val2) {
            return 1
        } else {
            return 0
        }
    }
}

const arr = [{ name: 'Tom', age: 22, height: 170 }, { name: 'Mary', age: 21, height: 165 }, { name: 'Mike', age: 18, height: 180 }]

arr.sort(compareStandard('age'))

//0: {name: "Mike", age: 18, height: 180}
//1: {name: "Mary", age: 21, height: 165}
//2: {name: "Tom", age: 22, height: 170}

arr.sort(compareStandard('height'))

//0: {name: "Mary", age: 21, height: 165}
//1: {name: "Tom", age: 22, height: 170}
//2: {name: "Mike", age: 18, height: 180}
```
