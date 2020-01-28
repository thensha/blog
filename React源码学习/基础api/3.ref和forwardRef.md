# 创建ref和forwardRef

## 创建ref共有三种方式

1. 字符串模式 (废弃, 当使用第三方库时多个ref无法组合; 根组件不生效; 元素更新时string ref会被封装为闭包导致性能问题)
2. 回调函数
3. React.createRef()

```jsx harmony
// string ref
class Foo extends React.Component {
  componentDidMount() {
    this.refs.inputEl.focus();
  }
  render() {
    return <input ref="inputEl" />;
  }
}
```

```jsx harmony
// callback ref
class Foo extends React.Component {
  componentDidMount() {
    this.inputEl.focus();
  }
  render() {
    return <input ref={el => {
      this.inputEl = el;
    }} />;
  }
}
```

```jsx harmony
// React.createRef
class Foo extends React.Component {
  constructor(props) {
    super(props);
    this.inputEl = React.createRef();
  }
  componentDidMount() {
    this.inputEl.current.focus();
  }
  render() {
    return <input ref={this.inputEl} />;
  }
}
```

## forwardRef解决跨组件传递ref问题

```jsx harmony
const Foo = React.forwardRef((props, ref) => {
  return <div ref={ref}>{props.value}</div>
})

export default class App extends React.Component {

  el = React.createRef()
  
  componentDidMount() {
    console.log(this.el.current)
    this.el.current.style.color = 'blue'
  }

  render() {
    return (
    <div className="App">
      <Foo value='hello' ref={this.el} />
    </div>
  );
  }
}
```


## 源码实现

```js
// 此处结合上例来看, forwardRef返回的是一个对象, 包括一个当前节点的$$typeof, 和一个调用时传入的render方法
export default function forwardRef<Props, ElementType: React$ElementType>(
  render: (props: Props, ref: React$Ref<ElementType>) => React$Node,
) {
  return {
    $$typeof: REACT_FORWARD_REF_TYPE,
    render,
  };
}
```
