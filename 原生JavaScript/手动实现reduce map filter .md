```js
function reduce(arr, combine, start) {
  let current = start

  for (let i = 0; i < arr.length; i++){
    current = combine(current, arr[i])
  }

  return current
}

let result1 = reduce([1, 2, 3], (a, b) => { return a + b }, 0)

// 6


function map(arr, transform) {
  let _arr = []

  for (let i = 0; i < arr.length; i++) {
    _arr.push(transform(arr[i]))
  }

  return _arr
}

let result2 = map([1, 2, 3], item => item * 2)

// [2, 4, 6]

function filter(arr, test) {
  let _arr = []

  for (let i = 0; i < arr.length; i++) {
    if (test(arr[i])) {
      _arr.push(arr[i])
    }
  }

  return _arr
}

let result3 = filter([1, 2, 3, 4, 5], item => item % 2 === 0)

// [2, 4]

```

    如果再完善一点的话可以给参数设置默认值, 防止报错
