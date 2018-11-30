**要求**：实现一个 footer 页脚，内容不足一页时在底部显示，当内容超过一屏高度时在内容底部

**实现要点**：

> 1.html 要设置 height 为 100%
> 2.body 要设置 min-height 为 100% 3.必须直接将内容区包裹在 body 内，且 display: flex; 4.给需要占满整屏的元素添加 flex: 1;

```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <meta http-equiv="X-UA-Compatible" content="ie=edge" />
        <title>Document</title>
        <style>
            html {
                height: 100%;
            }

            body {
                min-height: 100%;
                display: flex;
                flex-direction: column;
            }

            .main {
                flex: 1;
            }
        </style>
    </head>
    <body>
        <div style="background-color:pink" class="header">title</div>
        <div style="background-color:lightgreen" class="main">main</div>
        <div style="background-color:lightblue" class="footer">footer</div>
    </body>
</html>
```
