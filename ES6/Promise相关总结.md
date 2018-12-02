# Promise

## 基本用法：

> 通过Promise构造函数实例化，立即执行（故通常包裹在函数中，便于调用时再执行），内部错误不返回到外部，无法取消
>> 接收一个函数作为参数，函数中有两个参数 resolve 和 reject，对应 promise 对象的两种状态——fulfilled 和 rejected
>> 在 then 方法中接收两个函数作为参数，分别对应 resolve 和 reject指定的回调函数，会在当前页面所有同步脚本执行完成后才执行

```javascript
function test(){
    let promise=new Promise(function(resolve,reject){
        let a=1;
        console.log('promise');
        if(a>2){
            resolve('resolved');
        }
        reject('rejected');
    })
    return promise;
}

// 以下两种方法都可以实现捕获错误，但在promise中错误会冒泡直到被捕获
// 当存在链式多次调用then时，末尾使用catch可收集前面的所有错误
// 同时也最接近同步的try-catch写法

// test().then(data=>{
//     console.log(data);
// },err=>{console.log(err)})

console.log('normal');

test().then(data=>{
    console.log(data);
}).catch(err=>{
    console.log(err)
})
// normal、promise、rejected
```

案例1：使用promise加载图片并插入页面：

```javascript
function loadImg(url){
    return new Promise(function(resolve,reject){
        let img=new Image();
        img.src=url;
        let someDiv=document.getElementById('domeDiv');
        someDiv.appendChild(img);

        img.onload=function(){
            resolve('image loaded')
        }

        img.onerror=function(){
            reject('load image failed: '+url)
        }
    })
}

loadImg('/').then((data)=>{
    console.log(data);
}).catch(err=>{
    console.log(err)
})

//"load image failed: /"
```

案例2：使用promise操作ajax

```javascript
function getJSON(url){
    return new Promise(function(resolve,reject){
        let xhr=new XMLHttpRequest();
        xhr.open("GET",url);
        xhr.onreadystatechange=handler;
        xhr.responseType="json";
        xhr.setRequestHeader("Accept", "application/json");
        xhr.send();

        function handler(){
            if(this.readyState!==4){
                return;
            }
            if(this.status===200){
                resolve(this.response)
            }else{
                reject('err: '+this.statusText);
            }
        }
    })
}

getJSON('/').then(json=>{
    console.log('Contents: '+json)
}).catch(err=>{
    console.log(err)
})
//"err: "
```

## Promise.all()：用于将多个 promise 实例包装成一个新的 promise 实例

> 接收一个数组作为参数，如果其中有不是promise实例的，则先调用Promise.resolve()方法转化为promise实例
> 生成的新对象的状态取决于每个参数的状态，所有元素均有状态后新实例才会有状态
>> 如果每个都是fulfilled的话，则新对象也是fulfilled
>> 如果有某个是rejected，则新对象返回第一个被rejected的实例的返回值

```javascript
function test1(){
    return new Promise(function(resolve,reject){
        let a=0;
        a===1?resolve('resolve1'):reject('reject1');
    })
}
function test2(){
    return new Promise(function(resolve,reject){
        let a=0;
        a===1?resolve('resolve2'):reject('reject2');
    })
}
function test3(){
    return new Promise(function(resolve,reject){
        let a=0;
        a===1?resolve('resolve3'):reject('reject3');
    })
}

Promise.all([test1(),test2(),test3()]).then(data=>{
    console.log(data)
}).catch(err=>{console.log(err)})
//reject1
//如果三个 test 函数中a都是1的话，则返回["resolve1", "resolve2", "resolve3"]
```

## Promise.race()：同上

> 接收数组参数，如果不是promise则先转换
> 整体状态受最先改变状态的元素影响

案例：限定时间内未获取到图片则报错

```javascript
let p1=fetch('/resource-that-may-take-a-while');
let p2=new Promise(function(resolve,reject){
        setTimeout(()=>{
            reject('request timeout')
        },5000)
    });

const p=Promise.race([p1,p2]);
p.then(response=>{
    console.log(response);
}).catch(err=>{
    console.log(err)
})

//"request timeout"
```

## Promise.resolve()：将对象转换为promise对象，返回值根据传入参数类型不同而不同

> 传入promise实例：直接返回，不做任何改动
> 传入带then方法的对象：转为 promise 对象后立即执行对象上的 then 方法
> 传入没有then方法的普通对象或非基本类型值：直接返回一个 resolved 状态的 promise 对象
> 传入空对象：直接返回 resolved 状态的 promise 对象，**但此时事件执行的时机是当前事件循环（event loop）的末位**

案例：promise对象执行顺序问题

```javascript
// a是 promise 对象，且立即执行
let a=new Promise(function(resolve,reject){resolve()})
// b是 promise 对象，在当前事件循环结束后立即执行
let b=new Promise(function(resolve,reject){ setTimeout(resolve,0)})


//普通同步事件
console.log(1);


//传入正常的promise对象
Promise.resolve(a).then(()=>{
    console.log(2)
})
//传入基本类型值对象
Promise.resolve(3).then(()=>{
    console.log(3)
})
//传入空对象
Promise.resolve().then(()=>{
    console.log(4)
})


//传入延迟执行的promise对象
Promise.resolve(b).then(()=>{
    console.log(5)
})
//异步事件
setTimeout(()=>{
    console.log(6)
},0)

//1、2、3、4、5、6
//执行顺序:普通同步事件、普通promise对象、基本类型、空对象、延迟的promise对象、普通异步事件
```

    总结：
      1.同步事件最先执行，不受位置影响
      2.立即执行的promise事件按顺序执行（本例中234谁靠前谁先执行）
      3.凡是有延迟的事件都在最后，当延迟时间相同时，谁在前谁先执行

## Promise.reject()：返回一个reject状态的promise对象

> 返回后立即执行