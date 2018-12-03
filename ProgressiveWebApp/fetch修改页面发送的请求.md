# fetch拦截网络请求，修改后再发送

```javascript
//安装后立刻激活并执行serviceWorker
self.addEventListener('install', ev => {
    //waitUntil 允许一个异步的 Promise 在 Service Worker 上下文结束之前作出决策，然后缓存响应
    //一旦这个异步操作完成，waitUntil 将返回并终止操作
    ev.waitUntil(self.skipWaiting());
})

self.addEventListener('activated', ev => {
    ev.waitUntil(self.clients.claim())
})

//通过 fetch 拦截http请求，对其修改后重新发送，并用respondWith返回请求
self.addEventListener('fetch', ev => {
    //正则匹配页面发送的所有请求中以.jpg或.png结尾的请求
    if (/\.jpg$|.png$/.test(ev.request.url)) {

        var supportWebp = false;

        if (ev.request.headers.has('accept')) {
            //通过get获取 accept 的内容，再通过 includes 判断是否包含 'webp'，若包含则返回true
            supportWebp = ev.request.headers
                .get('accept')
                .includes('webp');
        }

        if (supportWebp) {
            //判断是否支持 webp 时已经用过一次request请求了，想再发需要复制一个
            var req = ev.request.clone();
            //截取原有请求，修改请求的文件格式
            var reviseUrl = req.url.substr(0, req.url.lastIndexOf('.')) + '.webp';

            //respondWith()接收一个 Promise，用来返回响应数据（或网络错误）给浏览器请求
            ev.respondWith(
                // fetch方法接收一个资源路径作为参数，第二参数可选(用于设置模式)，返回promise对象
                fetch(reviseUrl, {mode: 'no-cors'})
            )
        }
    }
})
```