# 一、常见布局类型
1. **表格布局**：原始布局方式，利用表格的特性展示布局，没有页面逻辑且大量冗余代码，现在几乎不用
2. **固定宽**：常用960px，移动端缩放表现差，不友好
3. **流式**：使用float实现动态浮动，各分辨率下样式无法保证
4. **flex弹性盒子**：简洁且强大，主流使用
5. **css栅格布局（grid）**：将网页分成一系列行和列，将对应内容放入对应区域；新属性兼容性差

# 二、flex弹性盒子：
1.组成部分：弹性容器 + 弹性项目（必须为容器的子代）

2.可对容器进行设置的属性：flex-flow、justify-content、align-items、align-content

    flex-flow是flex-direction和flex-wrap的组合:
    flex-direction: row/row-reverse/column/column-reverse;
    flex-wrap: wrap/nowrap/wrap-reverse;


    flex-direction为row时，justify-content用与弹性项的横向分布;
    column时justify-content会失效，此时只能用align-items调整分布；
    justify-content：flex-start/flex-end/center/space-between（两端对齐）/space-around;


    flex-direction为row时，align-items用于弹性项在容器中的纵向分布；
    column时用于弹性项横向分布；
    align-items：flex-start/flex-end/center/baseline（内部第一个元素的基线）/strectch（拉伸）;


    当flex项允许折行，且确实有多行时，使用align-content属性调整格式：
    align-content: flex-start/flex-end/center/space-between/space-around/stretch
 3.对弹性项设置的属性：order、align-self、flex

    设置order属性来进行排序：数字越小越靠前，不必是连续的数字，类似z-index；

    设置align-self来覆盖align-item设置的纵向对其格式；
    *弹性项的flex很重要，灵活且强大，重点掌握flex-grow的值如何使用

    flex属性默认为flex: 0 1 auto;

    三个值分别表示flex-grow（伸展）、flex-shrink（收缩）、flex-basis（基数）;

    flex: 1; 是flex: 1 1 0%;的简写（0%表示弹性项宽度完全取决于grow的值）

    此三个属性，flex-basis只有当容器设置为可折行（wrap）时才生效，shrink当弹性项的basis值之和大于容器时生效（各项按设置的比例收缩）

 4.弹性项目的margin特殊作用：设置为auto时自动利用剩余空间

    <div class="box">
        <p class="logo">Title</p>
        <a href="">first</a>
        <a href="">second</a>
        <a href="">third</a>
        <a href="" >forth</a>
    </div>
    .box{
        display:flex;
        align-items:flex-end;
    }
    .logo{
        margin-right:auto;
        /* 此属性会让右侧四个a标签全部靠向最右侧 */
    }

# 三、响应式web设计

    是一种网页设计的理念，根本目的是在各种屏幕分辨率下尽可能为用户提供良好的网页视觉布局，主要实现方式是通过html和css相关技术的配合。

html角度：消除浏览器默认缩放页面

    <meta name='viewport' content='width=device-width, initial-scale=1.0>
css角度：媒体查询

    <link rel='stylesheet' href='***' media='(min-width: 481px) and (max-width: 768px)'>
    @import url('./') (min-width: 481px) and (max-width: 768px);
    @media (min-width:481px) and (max-width: 768px) {
        body{
            ***
        }
    }
弹性img：将图像宽高设置为百分比（缺点是移动端用户耗费额外的流量下载过大的图片）

# 四、栅格系统grid：

    使用方法：display: grid/ inline-grid;

    元素：容器、内容项

>个人感觉grid更侧重于整体布局，虽然能实现比flex更细粒度的页面控制，但相比于flex却也更复杂。可问题是这样更复杂的实现实用价值并不大，更何况还有兼容性问题。所以目前很少有大面积用grid布局的网页，看以后css社区如何开发grid的新用法吧。

参考：https://www.jianshu.com/p/d183265a8dad
